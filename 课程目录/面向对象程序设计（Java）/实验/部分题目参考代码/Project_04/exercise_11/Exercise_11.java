package Project_04.exercise_11;

import java.util.Scanner;

public class Exercise_11 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter a: ");
        double a = input.nextDouble();
        System.out.print("Enter b: ");
        double b = input.nextDouble();
        System.out.print("Enter c: ");
        double c = input.nextDouble();
        System.out.print("Enter d: ");
        double d = input.nextDouble();
        System.out.print("Enter e: ");
        double e = input.nextDouble();
        System.out.print("Enter f: ");
        double f = input.nextDouble();

        LinearEquation equation = new LinearEquation(a, b, c, d, e, f);

        if (equation.isSolvable()) {
            System.out.println("The equation has a solution:");
            System.out.printf("x = %.2f\n", equation.getX());
            System.out.printf("y = %.2f\n", equation.getY());
        } else {
            System.out.println("The equation has no solution.");
        }
    }
}