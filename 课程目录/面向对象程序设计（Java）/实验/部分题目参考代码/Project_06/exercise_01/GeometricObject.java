package Project_06.exercise_01;

import java.util.Date;

public abstract class GeometricObject {
    /***************************** 数据域 ******************************/
    private String color = "white";
    private boolean filled;
    private Date dateCreated;

    /**************************** 构造方法 *****************************/
    protected GeometricObject() {
        dateCreated = new Date();
    }


    protected GeometricObject(String color, boolean filled) {
        dateCreated = new Date();
        this.color = color;
        this.filled = filled;
    }

    /**************************** 访问器 *****************************/
    public String getColor() {
        return color;
    }

    public Date getDateCreated() {
        return dateCreated;
    }

    /**************************** 修改器 *****************************/
    public void setColor(String color) {
        this.color = color;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    public boolean isFilled() {
        return filled;
    }

    /*********************** 普通方法（实例） ************************/
    @Override
    public String toString() {
        return "created on " + dateCreated + "color: " + color + " and filled: " + filled;
    }
} 