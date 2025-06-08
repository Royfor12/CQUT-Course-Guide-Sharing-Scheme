package Project_03.exercise_03;

public class Exercise_03 {

    public static boolean isPrime(int number) {
        if (number < 2) return false;
        for (int i = 2; i * i <= number; i++) 
            if (number % i == 0) return false;
        return true;
    }

    public static int reverse(int number) {
    // 好像没有专门翻转数字的方法，只能自己写了
        int reversed = 0;
        while (number != 0) {
            int digit = number % 10;  // 取出最后一位
            reversed = reversed * 10 + digit;  // 加到反转数的末尾
            number = number / 10;  // 去掉原数最后一位
        }
        return reversed;
    }

    public static void main(String[] args) {
        int count = 0;  // 已找到的反素数数量
        int num = 12;   // 从 13 开始检查

        System.out.println("前 100 个反素数是:");

        // 循环，直到找到足够数量的反素数
        while (count < 100) {
            num++;  // 检查下一个数

            int reversedNum = reverse(num); // 获取反转后的数

            if (num != reversedNum && isPrime(num) && isPrime(reversedNum)) {
            // 原数不等于反转数 且 原数是素数 且 反转数也是素数
                count++;

                System.out.print(num);

                if (count % 10 == 0) System.out.println();  // 如果当前计数是 10 的倍数，就换行
                else System.out.print(" ");
            }
        }
    }
}