package Project_02.exercise_13;

import java.util.Scanner;
import java.util.Arrays;

public class Exercise_13 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String[] cities = new String[3];

        System.out.print("Enter the first city: ");
        cities[0] = scanner.nextLine();

        System.out.print("Enter the second city: ");
        cities[1] = scanner.nextLine();

        System.out.print("Enter the third city: ");
        cities[2] = scanner.nextLine();

        Arrays.sort(cities);
        // Sorts the specified array of objects into ascending order, according to the natural ordering of its elements.

        System.out.print("The three cities in alphabetical order are ");
        boolean isFirst = true;  // 格式化输出
        for (String i : cities) {
        // (元素类型 变量名 : 要遍历的数组或集合)
            if (isFirst) {
                System.out.print(i);
                isFirst = false;
            } else {
                System.out.print(" " + i);
            }
        }
    }
}