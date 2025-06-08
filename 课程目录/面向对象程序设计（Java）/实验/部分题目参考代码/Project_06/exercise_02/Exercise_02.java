package Project_06.exercise_02;

public class Exercise_02 {
    public static void main(String[] args) {
        Person person = new Person("张三", "北京", "11111111", "zhangsan@email.com");
        Student student = new Student("李四", "上海", "22222222", "lisi@email.com", Student.FRESHMAN);
        Employee employee = new Employee("王五", "广州", "33333333", "wangwu@email.com", "A101", 8000, new MyDate(2020, 5, 1));
        Faculty faculty = new Faculty("赵六", "深圳", "44444444", "zhaoliu@email.com", "B204", 12000, new MyDate(2018, 9, 1), "8:00-16:00", "教授");
        Staff staff = new Staff("钱七", "杭州", "55555555", "qianqi@email.com", "C512", 6000, new MyDate(2022, 3, 15), "实验员");

        System.out.println(person);
        System.out.println(student);
        System.out.println(employee);
        System.out.println(faculty);
        System.out.println(staff);
    }
}