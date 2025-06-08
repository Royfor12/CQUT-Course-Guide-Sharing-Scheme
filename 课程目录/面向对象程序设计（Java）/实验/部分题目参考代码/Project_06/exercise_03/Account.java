package Project_06.exercise_03;

import java.util.Date;

public class Account {
    /***************************** 数据域 ******************************/
    private long id;  // 账户ID
    private double balance;  // 账户余额
    private double annualInterestRate;  // 年利率
    private Date dateCreated;  // 创建日期

    /**************************** 构造方法 *****************************/
    public Account() {
        this(0, 0);
    }

    public Account(long id, double balance) {
        this.id = id;
        this.balance = balance;
        this.dateCreated = new Date();
    }

    /**************************** 访问器 *****************************/
    public long getId() {
        return id;
    }

    public double getBalance() {
        return balance;
    }

    public double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public Date getDateCreated() {
        return dateCreated;
    }

    public double getMonthlyInterestRate() {
        return annualInterestRate / 12;
    }

    public double getMonthlyInterest() {
        return balance * getMonthlyInterestRate() / 100;
    }

    /**************************** 修改器 *****************************/
    public void setId(long id) {
        this.id = id;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }

    /**************************** 普通方法 *****************************/
    public void withdraw(double amount) {
        balance -= amount;
    }

    public void deposit(double amount) {
        balance += amount;
    }

    @Override
    public String toString() {
        return "Account[id=" + id + ", balance=" + balance + ", annualInterestRate=" + annualInterestRate + ", dateCreated=" + dateCreated + "]";
    }
}

