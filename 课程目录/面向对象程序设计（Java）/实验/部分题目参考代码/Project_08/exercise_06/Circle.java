package Project_08.exercise_06;

public class Circle {
    
    private double radius;

    Circle() {
        radius = 1.0;
    }

    Circle(int radius) {
        this.radius = radius;
    }

    public void setRadius(int radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public double calArea() {
        return Math.PI * radius * radius;
    }

    public double calPerimeter() {
        return 2 * Math.PI * radius;
    }
}
