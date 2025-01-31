#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import shutil
from urllib.parse import quote

# 从 GitHub Actions 环境变量里获取仓库所有者和仓库名、分支名
repo_full = os.environ.get("GITHUB_REPOSITORY", "defaultOwner/defaultRepo")
branch = os.environ.get("GITHUB_REF_NAME", "main")

# 文本文件走 blob 链接（在线查看），其他文件走 cdn 链接（便于直接下载），大文件反代加速
BLOB_URL_PREFIX = f"https://github.com/{repo_full}/blob/{branch}/"
BIN_URL_PREFIX = f"https://gh-proxy.com/raw.githubusercontent.com/{repo_full}/refs/heads/{branch}/"
# LARGE_URL_PREFIX = f"https://gh-proxy.com/raw.githubusercontent.com/{repo_full}/refs/heads/{branch}/"

# 大文件阈值 15MB
LARGE_THRESHOLD = 15 * 1024 * 1024

# 顶层排除目录
EXCLUDE_TOP_DIRS = {'.git', 'docs', '.vscode', '.circleci', 'site', 'image'}

# 视为 README 的文件名
README_CANDIDATES = {'README.md', 'readme.md', 'index.md'}

# 生成 blob 链接
BLOB_EXTS = {'md', 'txt', 'c', 'cpp', 'py'}


def process_directory(base_dir: str, rel_path: str):
    """
    将 base_dir(绝对路径) 对应的目录内容，递归生成到 docs/rel_path 目录下的 index.md 中。
    1. 若有 README_CANDIDATES 中任意文件，则将其内容原样写入。
    2. 新起一行后，输出大标题 "# 文件列表"。
    3. 列出当前目录所有文件的链接（md/txt -> blob，其它 -> cdn）。
    4. 对各子文件夹，递归调用 process_directory，生成各自的 docs/rel_path/subfolder/index.md。
    """

    # 在 docs/ 下创建与原目录相同层级的文件夹
    docs_folder = os.path.join("docs", rel_path)
    if not os.path.exists(docs_folder):
        os.makedirs(docs_folder)

    items = sorted(os.listdir(base_dir))

    # 尝试找到任意一个 README
    readme_content = ""
    for candidate in README_CANDIDATES:
        if candidate in items:
            readme_path = os.path.join(base_dir, candidate)
            with open(readme_path, "r", encoding="utf-8") as rf:
                readme_content = rf.read()
            break  # 找到一个就可以退出

    # 收集文件链接列表
    file_links = []
    subdirs = []
    for item in items:
        full_item_path = os.path.join(base_dir, item)
        if os.path.isfile(full_item_path):
            # 若是 README，则已处理过；否则纳入链接
            if item not in README_CANDIDATES:
                ext = item.split(".")[-1].lower() if "." in item else ""
                # file_size = os.path.getsize(full_item_path)

                # blob 类文件链接
                if ext in BLOB_EXTS:
                    file_url = BLOB_URL_PREFIX + quote(f"{rel_path}/{item}")
                else:
                    # 大文件链接
                    # if file_size > LARGE_THRESHOLD:
                    #     file_url = LARGE_URL_PREFIX + quote(f"{rel_path}/{item}")
                    # else:
                    file_url = BIN_URL_PREFIX + quote(f"{rel_path}/{item}")

                file_links.append((item, file_url))
        else:
            # 是子目录
            subdirs.append(item)

    # 写出当前目录的 index.md
    index_md_path = os.path.join(docs_folder, "index.md")
    with open(index_md_path, "w", encoding="utf-8") as wf:
        # 1) 写 README 内容（若有）
        if readme_content.strip():
            wf.write(readme_content.strip())
            wf.write("\n\n---\n\n")  # 加点空行，避免直接跟标题混在一起

        # 2) 输出大标题“# 文件列表”
        wf.write("# 文件列表\n")

        # 3) 列出当前目录内的文件链接
        for fname, url in file_links:
            wf.write(f"- [{fname}]({url})\n")

    # 递归处理子目录
    for subdir in subdirs:
        sub_rel_path = os.path.join(rel_path, subdir)
        full_subdir_path = os.path.join(base_dir, subdir)
        process_directory(full_subdir_path, sub_rel_path)


if __name__ == "__main__":

    # 确保 docs 目录存在
    if not os.path.exists("docs"):
        os.mkdir("docs")

    # 排除 EXCLUDE_TOP_DIRS
    top_dirs = []
    for d in sorted(os.listdir(".")):
        if os.path.isdir(d) and d not in EXCLUDE_TOP_DIRS:
            top_dirs.append(d)

    for d in top_dirs:
        # 绝对路径
        abs_path = os.path.abspath(d)
        # rel_path 就是顶层目录的名字 d
        process_directory(abs_path, d)

    # 若仓库根目录下存在 README.md，则复制到 docs/index.md 当主页
    if os.path.exists("README.md"):
        shutil.copyfile("README.md", "docs/index.md")
