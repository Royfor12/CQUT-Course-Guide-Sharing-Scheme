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
# LARGE_THRESHOLD = 15 * 1024 * 1024

# 顶层排除目录
EXCLUDE_TOP_DIRS = {'.git', 'docs', '.vscode', '.circleci', 'site', 'image', '.github'}

# 生成 blob 链接
BLOB_EXTS = {'txt', 'c', 'cc', 'cpp', 'hpp', 'cs', 'h', 'py', 'java', 'js', 'ts', 'htm', 'html', 'css', 'xml', 'json', 'yaml', 'yml', 'sh', 'bat', 'ipynb', 'm'}


def auto_read(path: str):
    try:
        with open(path, "r", encoding="utf-8") as f:
            return f.read()
    except UnicodeDecodeError:
        pass

    for encoding in ("gbk", "gb2312", "gb18030", "cp1252", "latin1"):
        try:
            with open(path, "r", encoding=encoding) as f:
                return f.read()
        except UnicodeDecodeError:
            continue

    with open(path, "r", encoding="utf-8", errors="replace") as f:
        return "解码失败！\n" + f.read()

def process_directory(base_dir: str, rel_path: str):
    """
    将 base_dir(绝对路径) 对应的目录内容，递归生成到 docs/rel_path 目录下的 index.md 中。
    1. 根据目录内容写入合适的一级大标题。
    2. 分块写入所有的.md。
    3. 列出当前目录所有文件的链接，图片附加预览。
    4. 对各子文件夹，递归调用 process_directory，生成各自的 docs/rel_path/subfolder/index.md。
    """

    # 在 docs/ 下创建与原目录相同层级的文件夹
    docs_folder = os.path.join("docs", rel_path)
    if not os.path.exists(docs_folder):
        os.makedirs(docs_folder)

    items = sorted(os.listdir(base_dir))

    # 读取所有.md
    md_parts = []
    for md in [f for f in items if f.lower().endswith(".md")]:
        md_parts.append(f"## {md}\n\n{auto_read(os.path.join(base_dir, md)).strip()}")
    readme_content = "\n\n---\n\n".join(md_parts)

    # 收集文件链接列表
    file_links = []
    subdirs = []
    for item in items:
        full_item_path = os.path.join(base_dir, item)
        if os.path.isfile(full_item_path):
            if not item.lower().endswith(".md"):
                ext = item.split(".")[-1].lower() if "." in item else ""
                # file_size = os.path.getsize(full_item_path)

                # blob 类文件链接
                if ext in BLOB_EXTS:
                    file_url = BLOB_URL_PREFIX + quote(f"{rel_path}/{item}")
                    download_url = BIN_URL_PREFIX + quote(f"{rel_path}/{item}")
                    file_links.append((item, file_url, download_url))
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

    if not readme_content.strip() and not file_links:
        pass
    else:
        # 写出当前目录的 index.md
        index_md_path = os.path.join(docs_folder, "index.md")
        with open(index_md_path, "w", encoding="utf-8") as wf:
            # 一级标题
            if readme_content.strip() and file_links:
                wf.write("# 额外说明及文件下载\n\n")
            elif readme_content.strip():
                wf.write("# 额外说明\n\n")
            else:
                wf.write("# 文件下载\n\n")

            # 1) 写 README 内容（若有）
            if readme_content.strip():
                wf.write(readme_content.strip())
                wf.write("\n\n---\n\n")  # 加点空行，避免直接跟标题混在一起

            # 2) 输出标题 "文件列表"
            if file_links:
                wf.write("# 文件列表\n")

            # 3) 列出当前目录内的文件链接
            for link_info in file_links:
                if len(link_info) == 3:
                    fname, preview_url, download_url = link_info
                    wf.write(f"- [{fname}]({preview_url}) ([下载]({download_url}))\n")
                else:
                    fname, url = link_info
                    wf.write(f"- [{fname}]({url})\n")
                    if fname.lower().endswith((".jpg", ".jpeg", ".png", ".gif")):
                        wf.write(f"![{fname}]({url})\n")

    # 递归处理子目录
    for subdir in subdirs:
        sub_rel_path = os.path.join(rel_path, subdir)
        full_subdir_path = os.path.join(base_dir, subdir)
        process_directory(full_subdir_path, sub_rel_path)

def create_mathjax_support():
    js_dir = os.path.join("docs", "javascripts")
    if not os.path.exists(js_dir):
        os.makedirs(js_dir)

    mathjax_path = os.path.join(js_dir, "mathjax.js")
    mathjax_content = """window.MathJax = {
  tex: {
    inlineMath: [["\\\\(", "\\\\)"]],
    displayMath: [["\\\\[", "\\\\]"]],
    processEscapes: true,
    processEnvironments: true
  },
  options: {
    ignoreHtmlClass: ".*|",
    processHtmlClass: "arithmatex"
  }
};

document$.subscribe(() => { 
  MathJax.startup.output.clearCache()
  MathJax.typesetClear()
  MathJax.texReset()
  MathJax.typesetPromise()
})
"""

    with open(mathjax_path, "w", encoding="utf-8") as f:
        f.write(mathjax_content)


if __name__ == "__main__":

    # 确保 docs 目录存在
    if not os.path.exists("docs"):
        os.mkdir("docs")

    # MathJax 支持
    create_mathjax_support()

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
