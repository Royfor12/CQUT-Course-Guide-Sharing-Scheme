package Project_05.exercise_03;

public class Exercise_03 {
    public static void main(String[] args) {
        // 创建 MyInteger 对象
        MyInteger n1 = new MyInteger(7);
        MyInteger n2 = new MyInteger(24);
        MyInteger n3 = new MyInteger(7);

        System.out.println("--- 测试 MyInteger 对象 n1 (value = " + n1.getValue() + ") ---");
        System.out.println("n1.getValue(): " + n1.getValue());
        System.out.println("n1.isEven(): " + n1.isEven());
        System.out.println("n1.isOdd(): " + n1.isOdd());
        System.out.println("n1.isPrime(): " + n1.isPrime());
        System.out.println("n1.equals(7): " + n1.equals(7));
        System.out.println("n1.equals(n2): " + n1.equals(n2));
        System.out.println("n1.equals(n3): " + n1.equals(n3));
        System.out.println("\n--- 测试 MyInteger 对象 n2 (value = " + n2.getValue() + ") ---");
        System.out.println("n2.isEven(): " + n2.isEven());
        System.out.println("n2.isOdd(): " + n2.isOdd());
        System.out.println("n2.isPrime(): " + n2.isPrime());

        System.out.println("\n--- 测试静态方法 (int 参数) ---");
        System.out.println("MyInteger.isEven(10): " + MyInteger.isEven(10));
        System.out.println("MyInteger.isOdd(10): " + MyInteger.isOdd(10));
        System.out.println("MyInteger.isPrime(10): " + MyInteger.isPrime(10));
        System.out.println("MyInteger.isEven(11): " + MyInteger.isEven(11));
        System.out.println("MyInteger.isOdd(11): " + MyInteger.isOdd(11));
        System.out.println("MyInteger.isPrime(11): " + MyInteger.isPrime(11));

        System.out.println("\n--- 测试静态方法 (MyInteger 参数) ---");
        System.out.println("MyInteger.isEven(n1): " + MyInteger.isEven(n1));
        System.out.println("MyInteger.isOdd(n1): " + MyInteger.isOdd(n1));
        System.out.println("MyInteger.isPrime(n1): " + MyInteger.isPrime(n1));
        System.out.println("MyInteger.isEven(n2): " + MyInteger.isEven(n2));
        System.out.println("MyInteger.isOdd(n2): " + MyInteger.isOdd(n2));
        System.out.println("MyInteger.isPrime(n2): " + MyInteger.isPrime(n2));

        System.out.println("\n--- 测试 parseInt 方法 ---");
        char[] numericChars = {'1', '2', '3'};
        String numericString = "456";
        System.out.println("MyInteger.parseInt({'1', '2', '3'}): " + MyInteger.parseInt(numericChars));
        System.out.println("MyInteger.parseInt(\"456\"): " + MyInteger.parseInt(numericString));
    }
}