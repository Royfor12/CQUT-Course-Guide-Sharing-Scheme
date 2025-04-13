# 题目、解析及其他文件

###### ps：请在仓库[前端网页](https://royfor12.github.io/CQUT-Course-Guide-Sharing-Scheme/%E8%AF%BE%E7%A8%8B%E7%9B%AE%E5%BD%95/%E5%A4%A7%E5%AD%A6%E7%89%A9%E7%90%86%E5%AE%9E%E9%AA%8C/%E5%AE%9E%E9%AA%8C0-%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9%26%E6%B5%8B%E9%87%8F%E8%AF%AF%E5%B7%AE%E4%B8%8E%E5%AE%9E%E9%AA%8C%E6%95%B0%E6%8D%AE%E5%A4%84%E7%90%86/)中预览该文档，以免公式渲染不正确！

## 题目一
用精度为 $1'$ 的分光计测量三棱镜的顶角 $A$，共测 8 次，其测得值分别为  
$60^\circ24'$, $60^\circ25'$, $60^\circ26'$, $60^\circ30'$, $60^\circ31'$, $60^\circ32'$, $60^\circ31'$, $60^\circ25'$。  
设已定系统误差为 $4'$，测顶角时，仪器误差限 $\Delta_{ins}$ 为 $2'$，试写出顶角 $A$ 测量结果 $A = \bar{A} \pm \Delta$。

### 解析
1. **先求算术平均值**  
   先把它们都转化为分钟形式后再加总除以 8，得到平均值：  
   <br>
   $3624+3625+3626+3630+3631+3632+3631+3625 \;=\; 29024\,(\text{分})$  
   <br>
   $\overline{A}_\text{测} \;=\;\frac{29024}{8} \;=\;3628\,(\text{分})$  
   <br>
   转换回度分制：  
   <br>
   $\overline{A}_{\text{测}} \;=\; 60^\circ28'$

2. **对已定系统误差 4′ 的修正**  
   $A_{\text{修正}} \;=\; \overline{A}_{\text{测}} \;-\; 4'$  
   <br>
   因此得到  
   <br>
   $A_{\text{修正}} = 60^\circ28' - 4' = 60^\circ24'$

3. **计算不确定度**  
   由于系统误差已修正，我们只需考虑修正后测量值的随机误差$\Delta_{random}$和仪器误差限$\Delta_{ins}$。  
   <br>
   (1) 随机误差 $\Delta_{random}$  
   随机误差可以通过测量值的标准偏差估计：  
   <br>
   $\Delta_{random} = \frac{s}{\sqrt{n}}$  
   <br>
   其中 $s = \sqrt{\frac{\sum (x_i - \bar{x})^2}{n - 1}}$ 是修正后测量值的标准偏差，$n = 8$ 是测量次数。  
   这里 $\bar{x} = A_{\text{修正}}$，计算各测量值与平均值的偏差平方和并求和：  
   <br>
   $\sum (x_i - \bar{x})^2 = 16 + 9 + 4 + 4 + 9 + 16 + 9 + 9 = 76$  
   <br>
   标准偏差：  
   <br>
   $s = \sqrt{\frac{76}{8 - 1}} = \sqrt{\frac{76}{7}} \approx \sqrt{10.857} \approx 3.294'$  
   <br>
   标准误差：  
   <br>
   $\Delta_{random} = \frac{s}{\sqrt{n}} = \frac{3.294'}{\sqrt{8}} \approx \frac{3.294}{2.828} \approx 1.165'$  
   <br>
   (2) 仪器误差 $\Delta_{ins}$  
   由于系统误差已单独给出并修正，我们假设 $\Delta_{ins} = 2'$ 是额外的系统性不确定度，对平均值直接贡献 $2'$。  
   <br>
   (3) 总不确定度 $\Delta$  

$$
   \begin{align*}
   \Delta &= \sqrt{(\Delta_{random})^2 + (\Delta_{ins})^2} \\
   &= \sqrt{(1.165')^2 + (2')^2} \\
   &= \sqrt{1.357 + 4} \\
   &= \sqrt{5.357} \approx 2'
   \end{align*}
$$

**最终答案：**  
将系统误差扣除后的修正值作为测量值，并结合上一步得到的不确定度：

$$
A \;=\; 60^\circ24' \;\pm\; 2'
$$

---

## 题目二
已知长方体质量 $m = (1260.5 \pm 0.6) \; g$，长宽高分别为：  
$a = (8.25 \pm 0.02) \; cm$，  
$b = (6.65 \pm 0.03) \; cm$，  
$c = (10.87 \pm 0.06) \; cm$，  
分别写出间接测量结果：

(1) 体积 $V = \bar{V} \pm \Delta$  
(2) 密度 $\rho = \bar{\rho} \pm \Delta$

### 解析
首先计算长方体的体积：

$$
\bar{V}=a\cdot b\cdot c=8.25\;cm\times6.65\;cm\times10.87\;cm\approx596.3\;cm^3
$$

由乘积的不确定度传播公式，其相对不确定度为：

$$
\frac{\Delta V}{V}\approx\sqrt{\left(\frac{0.02}{8.25}\right)^2+\left(\frac{0.03}{6.65}\right)^2+\left(\frac{0.06}{10.87}\right)^2}\approx0.00753
$$

从而绝对不确定度为：

$$
\Delta V\approx596.3\times0.00753\approx4.5\;cm^3
$$

因此体积结果可写为：

$$
V=(596.3\pm4.5)\;cm^3
$$

接下来求密度：

$$
\bar{\rho}=\frac{m}{V}\approx\frac{1260.5\;g}{596.3\;cm^3}\approx2.11\;g/cm^3
$$

质量的相对不确定度为 $\frac{0.6}{1260.5}\approx0.00048$，体积的相对不确定度约为 $0.00753$，由除法的不确定度传播公式可得：

$$
\frac{\Delta \rho}{\rho}\approx\sqrt{(0.00048)^2+(0.00753)^2}\approx0.00754
$$

故

$$
\Delta\rho\approx2.11\times0.00754\approx0.016\;g/cm^3
$$

综上，密度写为：

$$
\rho=(2.11\pm0.016)\;g/cm^3
$$

最终结果为：

1. 体积：$V=(596.3\pm4.5)\;cm^3$
2. 密度：$\rho=(2.11\pm0.016)\;g/cm^3$
