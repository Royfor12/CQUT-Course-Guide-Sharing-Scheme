package Project_07.exercise_01;

public class CalculatorWithoutException {
    public static void main(String[] args) {

        double operand1 = handleOp(args[0]);  // 获取并解析第一个操作数
        
        String operator = args[1];  // 获取运算符
        
        double operand2 = handleOp(args[2]);  // 获取并解析第二个操作数
        
        double result = 0;

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
                // 处理除以零的情况
                if (operand2 == 0) {
                    System.err.println("错误: 除数不能为零。");
                    System.exit(1);
                }
                result = operand1 / operand2;
                break;
            default:
                System.err.printf("错误。'%s' 是不受支持的运算符。\n", operator);
                System.exit(1);
        }
        
        System.out.printf("%d %c %d = %d\n", operand1, operator, operand2, result);
    }
    
    // 解析操作数，如果无效则退出程序
    private static double handleOp(String argStr) {
        if (!isValidNumber(argStr)) {
            System.err.println("错误输入: " + argStr + " 不是有效的数字。");
            System.exit(1);
        }
        return Integer.parseInt(argStr);
    }

    // 检查字符串是否可以转换为数字
    private static boolean isValidNumber(String str) {
        // 如果字符串为空或为null，则返回false
        if (str == null || str.isEmpty()) {
            return false;
        }
        
        // 处理可能的正负号
        int i = 0;
        if (str.charAt(0) == '-' || str.charAt(0) == '+' || 
            str.charAt(0) == '*' || str.charAt(0) == '/')
        {  // 如果字符串以运算符开头，则检查是否只有一个字符
            if (str.length() == 1) {
                return false;
            }
            i = 1;
        }
        
        // 检查每个字符是否是数字或小数点
        boolean hasDecimal = false;
        for (; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c == '.') {
                if (hasDecimal) {
                    return false;  // 多于一个小数点
                }
                hasDecimal = true;
            } else if (c < '0' || c > '9') {
                return false;  // 不是数字
            }
        }
        
        return true;
    }
} 