# 题目解析

## 题目一

用精度为 $1'$ 的分光计测量三棱镜的顶角 $A$，共测 8 次，其测得值分别为 $60^\circ24'$, $60^\circ25'$, $60^\circ26'$, $60^\circ30'$, $60^\circ31'$, $60^\circ32'$, $60^\circ31'$, $60^\circ25'$。设已定系统误差为 $4'$，测顶角时，仪器误差限 $\Delta_{ins}$ 为 $2'$，试写出顶角测量结果 $A = \bar{A} \pm \Delta$。

### 解析

1. **先求算术平均值**

   将所有测量值转换为分钟后求和：

   $3624 + 3625 + 3626 + 3630 + 3631 + 3632 + 3631 + 3625 = 29024\,\text{分}$

   算术平均值为：

   $\overline{A}_\text{测} = \frac{29024}{8} = 3628\,\text{分}$

   换算回度分制得到：

   $\overline{A}_\text{测} = 60^\circ28'$

2. **对已定系统误差 4′ 的修正**

   $A_{\text{修正}} = \overline{A}_\text{测} - 4' = 60^\circ24'$

3. **计算不确定度**

   仅考虑随机误差 $\Delta_{random}$ 与仪器误差限 $\Delta_{ins}$。

   - 随机误差由标准偏差估计：

     $\Delta_{random} = \frac{s}{\sqrt{n}}, \quad s = \sqrt{\frac{\sum (x_i - \bar{x})^2}{n - 1}}, \quad n = 8$

     计算偏差平方和：$\sum (x_i - \bar{x})^2 = 76$

     因此 $s = \sqrt{\frac{76}{7}} \approx 3.294'$, 从而 $\Delta_{random} = \frac{3.294'}{\sqrt{8}} \approx 1.165'$

   - 仪器误差限：$\Delta_{ins} = 2'$

   - 合成不确定度：

$$
   \begin{aligned}
   \Delta &= \sqrt{(\Delta_{random})^2 + (\Delta_{ins})^2} \\
   &= \sqrt{(1.165')^2 + (2')^2} \\
   &= \sqrt{5.357} \approx 2'
   \end{aligned}
$$

**最终结果：**

$$
A = 60^\circ24' \pm 2'
$$

---

## 题目二

已知长方体质量 $m = (1260.5 \pm 0.6) \; g$，长宽高分别为 $a = (8.25 \pm 0.02) \; cm$，$b = (6.65 \pm 0.03) \; cm$，$c = (10.87 \pm 0.06) \; cm$。分别写出体积 $V = \bar{V} \pm \Delta$ 和密度 $\rho = \bar{\rho} \pm \Delta$ 的测量结果。

### 解析

首先计算体积：

$$
\bar{V} = a \cdot b \cdot c = 8.25\,cm \times 6.65\,cm \times 10.87\,cm \approx 596.3\,cm^3
$$

乘积的相对不确定度为：

$$
\frac{\Delta V}{V} \approx \sqrt{\left(\frac{0.02}{8.25}\right)^2 + \left(\frac{0.03}{6.65}\right)^2 + \left(\frac{0.06}{10.87}\right)^2} \approx 0.00753
$$

因此绝对不确定度：

$$
\Delta V \approx 596.3 \times 0.00753 \approx 4.5\,cm^3
$$

体积结果可写为：

$$
V = (596.3 \pm 4.5)\,cm^3
$$

接下来计算密度：

$$
\bar{\rho} = \frac{m}{V} \approx \frac{1260.5\,g}{596.3\,cm^3} \approx 2.11\,g/cm^3
$$

质量的相对不确定度为 $\frac{0.6}{1260.5} \approx 0.00048$，体积的相对不确定度约为 $0.00753$，由除法的不确定度传播公式得到：

$$
\frac{\Delta \rho}{\rho} \approx \sqrt{(0.00048)^2 + (0.00753)^2} \approx 0.00754
$$

于是：

$$
\Delta \rho \approx 2.11 \times 0.00754 \approx 0.016\,g/cm^3
$$

最终结果：

1. 体积：$V = (596.3 \pm 4.5)\,cm^3$
2. 密度：$\rho = (2.11 \pm 0.016)\,g/cm^3$
