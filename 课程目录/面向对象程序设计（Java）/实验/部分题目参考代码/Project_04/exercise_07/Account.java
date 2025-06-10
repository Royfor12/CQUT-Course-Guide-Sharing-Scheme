package Project_04.exercise_07;

import java.util.Date;

public class Account {
    private int id = 0;
    private double balance = 0.0;
    private static double annualInterestRate = 0.0;  // 当前利率
    private Date dateCreated;  // 开户日期

    /* 创建默认账户 */
    public Account() {
        dateCreated = new Date();
    }

    public Account(int id, double balance) {
        this();
        this.id = id;
        this.balance = balance;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public static double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public static void setAnnualInterestRate(double annualInterestRate) {
        Account.annualInterestRate = annualInterestRate;
    }

    public Date getDateCreated() {
        return dateCreated;
    }

    public double getMonthlyInterestRate() {
        return (annualInterestRate / 100) / 12;
    }

    public double getMonthlyInterest() {
        return balance * getMonthlyInterestRate();
    }

    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            System.out.println("Withdrawal amount invalid or exceeds balance.");
        }
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
             System.out.println("Deposit amount must be positive.");
        }
    }
}