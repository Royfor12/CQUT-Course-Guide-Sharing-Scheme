package Project_08.exercise_06;

public class TestComparableCircle {
    public static void main(String[] args) {

        ComparableCircle circle1 = new ComparableCircle(5);
        ComparableCircle circle2 = new ComparableCircle(3);
        
        System.out.println("Circle 1: " + circle1);
        System.out.println("Circle 1 area: " + circle1.calArea());
        System.out.println("Circle 2: " + circle2);
        System.out.println("Circle 2 area: " + circle2.calArea());
        
        // 比较大小
        if (circle1.compareTo(circle2) > 0) {
            System.out.println("Circle 1 has larger area");
        } else if (circle1.compareTo(circle2) < 0) {
            System.out.println("Circle 2 has larger area");
        } else {
            System.out.println("Both them have same area");
        }
        
        // 新建一个圆，测试下相等的情况
        ComparableCircle circle3 = new ComparableCircle(5);
        System.out.println("\nCircle 3: " + circle3);
        System.out.println("Circle 3 area: " + circle3.calArea());
        
        if (circle1.compareTo(circle3) == 0) {
            System.out.println("Circle 1 and Circle 3 have the same area.");
        } else if (circle1.calArea() > circle3.calArea()) {
            System.out.println("Circle 1 has larger area");
        } else {
            System.out.println("Circle 3 has larger area");
        }
    }
} 