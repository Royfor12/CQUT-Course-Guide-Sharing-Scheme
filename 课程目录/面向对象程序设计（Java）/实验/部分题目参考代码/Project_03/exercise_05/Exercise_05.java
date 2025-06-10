package Project_03.exercise_05;

import java.util.Random;

public class Exercise_05 {
    public static Random randomNumbers = new Random();
    public enum Status
    {
        CONTINUE, 
        WIN, 
        LOSE
    }  // 使用枚举类型

    public static int roll() {
        int touzi1 = 1 + randomNumbers.nextInt(6);
        int touzi2 = 1 + randomNumbers.nextInt(6);
        int sum = touzi1 + touzi2;
        System.out.printf("You rolled %d + %d = %d%n", touzi1, touzi2, sum);
        return sum;
    }

    public static void main(String[] args) {
        int point = 0;
        Status status;
        int sum = roll();

        switch (sum) {
            // 第一次扔出 7 和 11 为赢
            case 7:
            case 11:
                status = Status.WIN;
                break;
            // 第一次扔出 2、3、12 为输
            case 2:
            case 3:
            case 12:
                status = Status.LOSE;
                break;
            // 其他点数为继续
            default:
                status = Status.CONTINUE;
                point = sum;  // 保存点数
        }

        while (status == Status.CONTINUE) {
            System.out.println("point is " + point);
            sum = roll();
            if (sum == point) status = Status.WIN;
            else if (sum == 7) status = Status.LOSE;
        }

        if (status == Status.WIN) System.out.println("You win!");
        else System.out.println("You lose!");
    }
}