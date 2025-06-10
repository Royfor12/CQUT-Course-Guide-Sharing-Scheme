package Project_02.exercise_11;

import java.util.Scanner;

public class Exercise_11 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter string s1: ");
        String s1 = scanner.nextLine();

        System.out.print("Enter string s2: ");
        String s2 = scanner.nextLine();

        if (s1.contains(s2)) 
        // boolean java.lang.String.contains(CharSequence s)
        // Returns true if and only if this string contains the specified sequence of char values.
            System.out.println(s2 + " is a substring of " + s1);
        else 
            System.out.println(s2 + " is not a substring of " + s1);
    }
}