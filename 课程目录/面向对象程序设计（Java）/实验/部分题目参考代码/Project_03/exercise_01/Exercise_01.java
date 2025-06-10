package Project_03.exercise_01;

import java.util.Scanner;

public class Exercise_01 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.println("Enter a password: ");
        String password = input.nextLine();

        if (isValid(password))
            System.out.println("Valid Password");
        else 
            System.out.println("Invalid Password");
    }

    public static boolean isValid(String password) {
    /* 这种方法只需要遍历一次字符串 */
        int digitCount = 0;
        for (char i : password.toCharArray()) {
            if (!Character.isLetterOrDigit(i)) return false;  // 不是字母或数字
            else if (Character.isDigit(i)) digitCount++;    // 是数字，计数加1
        }
        return (digitCount >= 2 && password.length() >= 8);  // 至少包含2个数字，且长度至少为8
    }
}