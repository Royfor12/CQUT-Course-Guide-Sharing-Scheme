package Project_04.exercise_01;

class Exercise_01 {
    public static void main(String[] args) {
        Rectangle rectangle1 = new Rectangle(4, 40);
        System.out.println("Project4.Rectangle 1 Area: " + rectangle1.getArea());
        System.out.println("Project4.Rectangle 1 Perimeter: " + rectangle1.getPerimeter());

        Rectangle rectangle2 = new Rectangle(3.5, 35.9);
        System.out.println("Project4.Rectangle 2 Area: " + rectangle2.getArea());
        System.out.println("Project4.Rectangle 2 Perimeter: " + rectangle2.getPerimeter());
    }
}