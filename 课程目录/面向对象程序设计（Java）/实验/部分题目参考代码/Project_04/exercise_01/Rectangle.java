package Project_04.exercise_01;

public class Rectangle {
    private double width;
    private double height;

    public Rectangle() {
        this(1, 1);
    }

    public Rectangle(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    public double getArea() {
        return width * height;
    }

    public double getPerimeter() {
        return (width + height) * 2;
    }
}