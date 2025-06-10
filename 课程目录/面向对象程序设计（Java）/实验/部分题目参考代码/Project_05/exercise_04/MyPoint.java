package Project_05.exercise_04;

public class MyPoint {
    /*********************************** 数据域 ***********************************/
    private double x;
    private double y;


    /*********************************** 访问器 ***********************************/
    /* 获取x坐标 */
    public double getX() {
        return x;
    }

    /* 获取y坐标 */
    public double getY() {
        return y;
    }

    /********************************** 构造方法 **********************************/
    /* 创建原点 */
    public MyPoint() {
        this.x = 0;
        this.y = 0;
    }

    /* 创建指定坐标的点 */
    public MyPoint(double x, double y) {
        this.x = x;
        this.y = y;
    }

    /********************************** 普通方法 **********************************/
    /* 该点到 MyPoint对象的距离 */
    public double distance(MyPoint point) {
        return Math.sqrt(Math.pow(this.x - point.getX(), 2) + Math.pow(this.y - point.getY(), 2));
    }

    /* 该点到指定坐标的距离 */
    public double distance(double x, double y) {
        return Math.sqrt(Math.pow(this.x - x, 2) + Math.pow(this.y - y, 2));
    }
}