package Project_06.exercise_02;

public class Staff extends Employee {
    /***************************** 数据域 ******************************/
    private String title;

    /**************************** 构造方法 *****************************/
    public Staff(String name, String address, String phoneNumber, String email, String office, double salary, MyDate hireDate, String title) {
        super(name, address, phoneNumber, email, office, salary, hireDate);
        this.title = title;
    }

    /**************************** 访问器 *****************************/
    public String getTitle() {
        return title;
    }

    /**************************** 修改器 *****************************/
    public void setTitle(String title) {
        this.title = title;
    }

    /*********************** 普通方法（实例） ************************/
    @Override
    public String toString() {
        return "Staff [name=" + name + ", title=" + title + "]";
    }
}

