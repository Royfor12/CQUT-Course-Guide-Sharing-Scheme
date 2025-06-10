package Project_05.exercise_03;

public class MyInteger {
    /*********************************** 数据域 ***********************************/
    /* 存储 MyInteger 对象的值 */
    private int value;

    /********************************** 构造方法 **********************************/
    /* 构造方法，为指定的int值创建 MyInteger对象 */
    public MyInteger(int value) {
        this.value = value;
    }

    /*********************************** 访问器 ***********************************/
    /* 获取 MyInteger 对象的值 */
    public int getValue() {
        return value;
    }

    /*********************************  静态方法 **********************************/
    /* 是否为偶数 */
    public static boolean isEven(int value) {
        return value % 2 == 0;
    }

    /* 指定对象的值是否为偶数 */
    public static boolean isEven(MyInteger myInt) {
        return isEven(myInt.getValue());
    }

    /* 是否为奇数 */
    public static boolean isOdd(int value) {
        return value % 2 != 0;
    }

    /* 指定对象的值是否为奇数 */
    public static boolean isOdd(MyInteger myInt) {
        return isOdd(myInt.getValue());
    }

    /* 是否为素数 */
    public static boolean isPrime(int value) {
        if (value <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(value); i++) {
            if (value % i == 0) {
                return false;
            }
        }
        return true;
    }

    /* 将数字字符数组转换为int值 */
    public static int parseInt(char[] num) {
        int result = 0;
        for (char c : num) {
            result = result * 10 + (c - '0');
        }
        return result;
    }

    /* 指定对象的值是否为素数 */
    public static boolean isPrime(MyInteger myInt) {
        return isPrime(myInt.getValue());
    }



    /* 判断当前对象的值是否等于指定的MyInteger对象的值 */
    public boolean equals(MyInteger myInt) {
        return this.value == myInt.getValue();
    }

    /*********************************  实例方法 **********************************/
    /* 当前对象的值是否为偶数 */
    public boolean isEven() {
        return isEven(this.value);
    }

    /* 当前对象的值是否为奇数 */
    public boolean isOdd() {
        return isOdd(this.value);
    }

    /* 当前对象的值是否为素数 */
    public boolean isPrime() {
        return isPrime(this.value);
    }

    /* 当前对象的值是否等于指定的int值 */
    public boolean equals(int value) {
        return this.value == value;
    }

    /* 将字符串转换为int值 */
    public static int parseInt(String s) {
        return parseInt(s.toCharArray());  // 先转换为数字字符数组，再调用上面的方法
    }
}