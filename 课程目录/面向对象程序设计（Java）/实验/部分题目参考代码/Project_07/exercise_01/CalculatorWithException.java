package Project_07.exercise_01;

import java.util.InputMismatchException;
import java.util.Scanner;

public class CalculatorWithException {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double operand1 = 0;
        String operator = "";
        double operand2 = 0;
        double result = 0;

        try {
            System.out.print("输入第一个数字: ");
            operand1 = scanner.nextInt();

            System.out.print("输入运算符 (+, -, *, /): ");
            operator = scanner.next();

            System.out.print("输入第二个数字: ");
            operand2 = scanner.nextInt();

            switch (operator) {
                case "+":
                    result = operand1 + operand2;
                    break;
                case "-":
                    result = operand1 - operand2;
                    break;
                case "*":
                    result = operand1 * operand2;
                    break;
                case "/":
                    while (operand2 == 0) {
                        System.out.println("错误：除数不能为零。请重新输入第二个数字：");
                        operand2 = scanner.nextInt();
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    System.out.printf("错误。%c 是不受支持的运算符。", operator);
                    System.exit(1);
            }
            
            System.out.printf("%d %c %d = %d\n", operand1, operator, operand2, result);
            
        } catch (InputMismatchException e) {
            System.out.println("错误：输入不是有效的数字格式。");
            System.exit(1);
        } finally {
            scanner.close();
        }
    }
} 