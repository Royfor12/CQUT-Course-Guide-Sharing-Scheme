package Project_06.exercise_02;

public class MyDate {
    /***************************** 数据域 ******************************/
    private int year;
    private int month;
    private int day;

    /**************************** 构造方法 *****************************/
    public MyDate(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }

    /**************************** 访问器 *****************************/
    public int getYear() {
        return year;
    }

    public int getMonth() {
        return month;
    }

    public int getDay() {
        return day;
    }

    /*********************** 普通方法（实例） ************************/
    @Override
    public String toString() {
        return year + "-" + month + "-" + day;
    }
}

