package Project_07.exercise_02;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Inputmismatchexception {
    public static String operator;

    private static double getNumberInput(Scanner scanner, String prompt, boolean isSecondOp) {
        double number = 0.0;
        boolean validInput = false;

        while (!validInput) {
            try {
                System.out.print(prompt);
                number = scanner.nextDouble();

                if (isSecondOp && operator.equals("/") && number == 0) {
                    System.out.println("错误：除数不能为零。请重新输入第二个数字：");
                    continue;
                }

                validInput = true;
            } catch (InputMismatchException e) {
                System.out.println("错误：输入不是有效的数字格式。请重新输入。");
                scanner.nextLine();
            }
        }

        return number;
    }

    private static String getOperatorInput(Scanner scanner) {
        String op = "";
        boolean validInput = false;

        while (!validInput) {
            System.out.print("输入运算符 (+, -, *, /): ");
            op = scanner.next();

            if (op.equals("+") || op.equals("-") || op.equals("*") || op.equals("/")) {
                validInput = true;
                return op;
            } else {
                System.out.printf("错误。%s 是不受支持的运算符。请重新输入。\n", op);
                scanner.nextLine();
            }
        }

        return op;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double operand1, operand2, result = 0.0;

        operand1 = getNumberInput(scanner, "输入第一个数字: ", false);

        operator = getOperatorInput(scanner);

        operand2 = getNumberInput(scanner, "输入第二个数字: ", true);

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
                result = operand1 / operand2;
                break;
        }

        System.out.printf("%.2f %s %.2f = %.2f\n", operand1, operator, operand2, result);
        scanner.close();
    }
}
