package Project_05.exercise_01;

public class Exercise_01 {
    public static void main(String[] args) {
        // 使用无参构造方法创建 Time 对象（获取当前时间）
        Time time1 = new Time();
        System.out.println("Current time:");
        System.out.println("Hour: " + time1.getHour());
        System.out.println("Minute: " + time1.getMinute());
        System.out.println("Second: " + time1.getSecond());
        System.out.println();

        // 使用特定毫秒数创建 Time 对象
        Time time2 = new Time(555550000L);
        System.out.println("Time for 555550000 milliseconds:");
        System.out.println("Hour: " + time2.getHour());
        System.out.println("Minute: " + time2.getMinute());
        System.out.println("Second: " + time2.getSecond());

        // 测试 setTime 方法
        System.out.println("\nSetting time1 using setTime(555550000L):");
        time1.setTime(555550000L);
        System.out.println("Hour: " + time1.getHour());
        System.out.println("Minute: " + time1.getMinute());
        System.out.println("Second: " + time1.getSecond());
    }
}
