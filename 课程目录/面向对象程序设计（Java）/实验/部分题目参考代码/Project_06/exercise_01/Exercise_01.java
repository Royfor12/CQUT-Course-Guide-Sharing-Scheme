package Project_06.exercise_01;

import java.util.Scanner;

class Exercise_01 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter three sides of the triangle: ");
        double side1 = input.nextDouble();
        double side2 = input.nextDouble();
        double side3 = input.nextDouble();
        System.out.print("Enter the color of the triangle (e.g., red): ");
        String color = input.next();
        System.out.print("Is the triangle filled (true/false)? ");
        boolean filled = input.nextBoolean();

        Triangle triangle = new Triangle(side1, side2, side3);
        triangle.setColor(color);
        triangle.setFilled(filled);

        System.out.println();
        System.out.println("--- Triangle ---");
        System.out.println("Area: " + triangle.getArea());
        System.out.println("Perimeter: " + triangle.getPerimeter());
        System.out.println("Sides: " + triangle.getSide1() + ", " + triangle.getSide2() + ", " + triangle.getSide3());
        System.out.println("Color: " + triangle.getColor());
        System.out.println("Filled: " + triangle.isFilled());
        System.out.println("Created on: " + triangle.getDateCreated());
        
        input.close();
    }
}