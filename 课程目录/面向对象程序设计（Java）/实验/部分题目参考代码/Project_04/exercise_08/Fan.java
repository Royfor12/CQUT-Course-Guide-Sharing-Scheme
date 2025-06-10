package Project_04.exercise_08;

public class Fan {
    /* 风扇速度 */
    final static int SLOW = 1;
    final static int MEDIUM = 2;
    final static int FAST = 3;

    /* 风扇初始状态 */
    private int speed = SLOW;
    private boolean on = false;
    private double radius = 5;
    private String color = "blue";

    /* 风扇构造方法（无参） */
    public Fan() {
    }

    /* 风扇的构造方法 */
    public Fan(int speed, boolean on, double radius, String color) {
        this.speed = speed;
        this.on = on;
        this.radius = radius;
        this.color = color;
    }

    /* 各数据域的访问器和修改器 */
    public int getSpeed() {
        return speed;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public boolean isOn() {
        return on;
    }

    public void setOn(boolean on) {
        this.on = on;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override // 重写toString方法
    public String toString() {
        if (on) {
            String speedStr;
            switch (speed) {
                case SLOW:
                    speedStr = "SLOW";
                    break;
                case MEDIUM:
                    speedStr = "MEDIUM";
                    break;
                case FAST:
                    speedStr = "FAST";
                    break;
                default:
                    speedStr = "UNKNOWN";
            }
            return "Fan speed: " + speedStr + ", color: " + color + ", radius: " + radius;
        } else {
            return "Fan is off, color: " + color + ", radius: " + radius;
        }
    }
}