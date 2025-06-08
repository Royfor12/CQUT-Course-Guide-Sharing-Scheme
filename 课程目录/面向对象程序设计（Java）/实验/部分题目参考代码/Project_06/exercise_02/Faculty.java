package Project_06.exercise_02;

public class Faculty extends Employee {
    /***************************** 数据域 ******************************/
    private String officeHours;
    private String level;

    /**************************** 构造方法 *****************************/
    public Faculty(String name, String address, String phoneNumber, String email, String office, double salary, MyDate hireDate, String officeHours, String level) {
        super(name, address, phoneNumber, email, office, salary, hireDate);
        this.officeHours = officeHours;
        this.level = level;
    }

    /**************************** 访问器 *****************************/
    public String getOfficeHours() {
        return officeHours;
    }

    public String getLevel() {
        return level;
    }
    /**************************** 修改器 *****************************/
    public void setOfficeHours(String officeHours) {
        this.officeHours = officeHours;
    }

    public void setLevel(String level) {
        this.level = level;
    }

    /*********************** 普通方法（实例） ************************/
    @Override
    public String toString() {
        return "Faculty [name=" + name + ", level=" + level + ", officeHours=" + officeHours + "]";
    }
}

