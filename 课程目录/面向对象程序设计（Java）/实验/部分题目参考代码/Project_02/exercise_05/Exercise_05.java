package Project_02.exercise_05;

import java.util.Scanner;

public class Exercise_05 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a character: ");
        char character = input.next().charAt(0);
        System.out.println("The Unicode for the character " + character + " is " + (int) character);
    }
}