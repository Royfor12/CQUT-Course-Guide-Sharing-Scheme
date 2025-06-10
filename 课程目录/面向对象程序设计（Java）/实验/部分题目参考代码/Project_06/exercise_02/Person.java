package Project_06.exercise_02;

public class Person {
    /***************************** 数据域 ******************************/
    protected String name;
    protected String address;
    protected String phoneNumber;
    protected String email;

    /**************************** 构造方法 *****************************/
    public Person(String name, String address, String phoneNumber, String email) {
        this.name = name;
        this.address = address;
        this.phoneNumber = phoneNumber;
        this.email = email;
    }

    /**************************** 访问器 *****************************/
    public String getName() {
        return name;
    }

    public String getAddress() {
        return address;
    }   

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public String getEmail() {
        return email;
    }

    /**************************** 修改器 *****************************/
    public void setAddress(String address) {
        this.address = address;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    /*********************** 普通方法（实例） ************************/
    @Override
    public String toString() {
        return "Person [name=" + name + ", address=" + address + ", phoneNumber=" + phoneNumber + ", email=" + email + "]";
    }
    
}
