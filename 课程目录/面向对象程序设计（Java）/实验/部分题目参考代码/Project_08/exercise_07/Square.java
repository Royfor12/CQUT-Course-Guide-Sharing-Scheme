package Project_08.exercise_07;

public class Square extends GeometricObject implements Colorable {
    private int side;
    
    public Square() {
        side = 1;
    }

    public Square(int side) {
        this.side = side;
    }

    public Square(int side, String color, boolean filled) {
        super(color, filled);
        this.side = side;
    }

    public double getHowManySides() {
        return side;
    }
    
    public void setSide(int side) {
        this.side = side;
    }
    
    @Override
    public double getArea() {
        return side * side;
    }
    
    @Override
    public double getPerimeter() {
        return 4 * side;
    }
    
    @Override
    public void howToColor() {
        System.out.println("color all sides");
    }
}