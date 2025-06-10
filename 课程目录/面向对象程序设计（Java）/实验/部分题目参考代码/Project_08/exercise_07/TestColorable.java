package Project_08.exercise_07;

public class TestColorable {
    public static void main(String[] args) {

        GeometricObject[] objects = new GeometricObject[5];
        
        // 初始化数组，全部为Square对象
        for (int i = 0; i < objects.length; i++) {
            objects[i] = new Square(i + 1);
            //((Square)objects[i]).setSide(i + 1);
        }
        
        // 如果对象是可着色的，则调用howToColor方法
        for (int i = 0; i < objects.length; i++) {
            System.out.println("对象 " + (i + 1) + ":");
            System.out.println("面积: " + objects[i].getArea());
            
            // 检查对象是否实现了Colorable接口
            if (objects[i] instanceof Colorable) {
                System.out.print("着色方法: ");
                ((Square)objects[i]).howToColor();
            }
            
            System.out.println();
        }
    }
} 