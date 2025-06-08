package Project_08.exercise_01;

import java.util.Scanner;

public class TestTriangle {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("请输入三角形的三条边长：");
        double side1 = input.nextDouble();
        double side2 = input.nextDouble();
        double side3 = input.nextDouble();

        System.out.print("请输入三角形的颜色：");
        String color = input.next();

        System.out.print("三角形是否填充（true/false）：");
        boolean filled = input.nextBoolean();

        Triangle triangle = new Triangle(side1, side2, side3, color, filled);

        System.out.println("\n三角形信息：");
        System.out.println("面积：" + triangle.getArea());
        System.out.println("周长：" + triangle.getPerimeter());
        System.out.println("颜色：" + triangle.getColor());
        System.out.println("是否填充：" + triangle.isFilled());

        input.close();
    }
}
