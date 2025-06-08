package Project_05.exercise_01;

import java.time.LocalTime;

public class Time {
    /*********************************** 数据域 ***********************************/
    private int hour;
    private int minute;
    private int second;

    /*********************************** 访问器 ***********************************/
    public int getHour() {
        return hour;
    }

    public int getMinute() {
        return minute;
    }

    public int getSecond() {
        return second;
    }

    /********************************* 修改器 **********************************/
    /* 使用流逝毫秒数设置新时间 */
    public void setTime(long elapseTime) {
        long totalSeconds = elapseTime / 1000;
        this.second = (int)(totalSeconds % 60);
        long totalMinutes = totalSeconds / 60;
        this.minute = (int)(totalMinutes % 60);
        long totalHours = totalMinutes / 60;
        this.hour = (int)(totalHours % 24);
    }

    /********************************** 构造方法 **********************************/
    /* 获取当前时间 */
    public Time() {
        LocalTime now = LocalTime.now();
        this.hour = now.getHour();
        this.minute = now.getMinute();
        this.second = now.getSecond();
    }

    /* 获取Unix毫秒数 */
    public Time(long time) {
        long totalSeconds = time / 1000;  // 获取总秒数
        this.second = (int)(totalSeconds % 60);  // 获取当前秒数
        long totalMinutes = totalSeconds / 60;  // 获取总分钟数
        this.minute = (int)(totalMinutes % 60);  // 获取当前分钟数
        long totalHours = totalMinutes / 60;  // 获取总小时数
        this.hour = (int)(totalHours % 24);  // 获取当前小时数
    }

    /* 设定特定时间 */
    public Time(int hour, int minute, int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }
}