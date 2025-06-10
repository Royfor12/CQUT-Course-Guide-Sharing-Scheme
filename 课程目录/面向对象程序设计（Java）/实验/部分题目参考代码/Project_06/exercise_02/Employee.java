package Project_06.exercise_02;

public class Employee extends Person {
    /***************************** 数据域 ******************************/
    private String office;
    private double salary;
    private MyDate hireDate;

    /**************************** 构造方法 *****************************/
    public Employee(String name, String address, String phoneNumber, String email, String office, double salary, MyDate hireDate) {
        super(name, address, phoneNumber, email);
        this.office = office;
        this.salary = salary;
        this.hireDate = hireDate;
    }

    /**************************** 访问器 *****************************/
    public String getOffice() {
        return office;
    }

    public double getSalary() {
        return salary;
    }

    public MyDate getHireDate() {
        return hireDate;
    }

    /**************************** 修改器 *****************************/
    public void setOffice(String office) {
        this.office = office;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }


    public void setHireDate(MyDate hireDate) {
        this.hireDate = hireDate;
    }

    /*********************** 普通方法（实例） ************************/
    @Override
    public String toString() {
        return "Employee [name=" + name + ", office=" + office + ", salary=" + salary + ", hireDate=" + hireDate + "]";
    }
}
