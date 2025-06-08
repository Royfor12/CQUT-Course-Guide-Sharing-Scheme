package Project_01.exercise_05;

public class Exercise_05 {
    public static void main(String[] args) {
        System.out.println(cal(11));
        System.out.println(cal(13));
    }

    public static double cal(int num) {
        double sum = 0;
        for (int i = 1, flag = 1; i <= num; i += 2, flag *= -1) {
            // flag 控制正负号
            sum += flag * (1.0 / i);
        }
        return sum;
    }
}
