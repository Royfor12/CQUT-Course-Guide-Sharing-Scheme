package Project_05.exercise_16;

import java.math.BigInteger;

public class Exercise_16 {
    public static void main(String[] args) {
        int count = 0; // 找到的数字个数
        BigInteger number = BigInteger.valueOf(10).pow(49);  // 最小的 50 位数是 10^49


        while (count < 10) {
            // 检查是否能被 2 或 3 整除
            if (number.mod(BigInteger.valueOf(2)).equals(BigInteger.valueOf(0)) || 
                number.mod(BigInteger.valueOf(3)).equals(BigInteger.valueOf(0))) 
            {
                System.out.println(number);
                count++;
            }
            number = number.add(BigInteger.valueOf(1));  // number不是基本数据类型，不能直接用++
        }
    }
}
