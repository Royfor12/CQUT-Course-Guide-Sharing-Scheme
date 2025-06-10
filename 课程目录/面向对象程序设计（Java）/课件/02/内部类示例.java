/*
 * Session1: 以下是一个测试类，用于在控制台显示某些信息
 */
class Test {
    public static void main(String[] args) {
        new Outer().show();
        System.out.println("---------------分界线【1】---------------");
        new Outer().new InnerA().show();
        System.out.println("---------------分界线【2】---------------");
        new Outer.InnerB().show();
        System.out.println("---------------分界线【3】---------------");
        //匿名内部类
        new Inter() {
            int num = 4;
            @Override
            public void show() {
                System.out.println("num=" + num);
                System.out.println("(5) 调用了匿名类中方法show()");
            }
        }.show();
        System.out.println("---------------分界线【4】---------------");
        //匿名内部类。并未重写方法
        new Inter() {
            // 这里没有重写方法，会调用接口中的默认方法
        }.show();
        System.out.println("---------------分界线【5】---------------");
    }
}

/*
 * Session2: 以下定义了一个接口。
 * 注意：java8 之后，接口中的方法允许在接口的定义时实现。这与我们的教材是有差异的
 */
interface Inter {
    int num = 1; //常量int 前面省略了：static final
    default void show() {
        System.out.println("num=" + num);
        System.out.println("(1) 调用了接口Inter 中方法show()");
    }
}

/*
 * Session3: 以下定义了一个普通的类Outer。Outer 是一个外部类
 */
class Outer {
    private int num = 2; //part1: 类Outer 的成员变量
    
    //part2: 类Outer 的成员内部类InnerA
    class InnerA {
        public void show() {
            System.out.println("num=" + num);
            System.out.println("(2) 调用了【成员内部类】InnerA 中的方法show()");
        }
    }
    
    //part3: 类Outer 的成员内部类InnerB，并且它是一个静态内部类
    static class InnerB implements Inter {
        //下面的代码重写了接口Inter 中的方法show()
        public void show() {
            System.out.println("num=" + num);
            System.out.println("(3) 调用了【静态成员类】InnerB 中的方法show()");
        }
    }
    
    //part4: 以下是Outer 类的一个成员方法show()（或者叫普通方法）
    public void show() {
        int num = 3; //part4-1: 定义局部变量
        
        //part4-2:内部类InnerC 定义在方法show()中，因此它是一个局部的内部类
        class InnerC implements Inter {
            // 下面的代码重写了接口Inter 中的方法show()
            public void show() {
                System.out.println("num=" + num);
                System.out.println("(4) 调用了【局部内部类】InnerC 中的方法show()");
            }
        }
        
        new InnerC().show(); //在这里调用了内部类某个实例的show()方法
    }
}