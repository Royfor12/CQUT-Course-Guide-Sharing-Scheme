package Project_06.exercise_02;

public class Student extends Person {
    /***************************** 数据域 ******************************/
    public static final int FRESHMAN = 1;
    public static final int SOPHOMORE = 2;
    public static final int JUNIOR = 3;
    public static final int SENIOR = 4;

    private int status;

    /**************************** 构造方法 *****************************/
    public Student(String name, String address, String phoneNumber, String email, int status) {
        super(name, address, phoneNumber, email);
        this.status = status;
    }

    /**************************** 访问器 *****************************/
    public int getStatus() {
        return status;
    }

    /**************************** 修改器 *****************************/
    public void setStatus(int status) {
        this.status = status;
    }

    /*********************** 普通方法（实例） ************************/
    @Override
    public String toString() {
        String statusStr = switch (status) {
            case FRESHMAN -> "Freshman";
            case SOPHOMORE -> "Sophomore";
            case JUNIOR -> "Junior";
            case SENIOR -> "Senior";
            default -> "Unknown";
        };
        return "Student [name=" + name + ", status=" + statusStr + "]";
    }
}


