package Project_05.exercise_04;

public class Exercise_04 {
    public static void main(String[] args) {
        MyPoint point1 = new MyPoint(0, 0);
        MyPoint point2 = new MyPoint(10, 30.5);
        System.out.println("Distance between point1 and point2: " + point1.distance(point2));
    }
}