package Project_06.exercise_03;


public class CheckingAccount extends Account {
    private double limit;  // 透支额度

    public CheckingAccount(long id, double balance, double limit) {
        super(id, balance);
        this.limit = limit;
    }

    public double getLimit() {
        return limit;
    }

    public void setLimit(double limit) {
        this.limit = limit;
    }

    @Override
    public void withdraw(double amount) {
        if (getBalance() + limit < amount) {
            System.out.println("取款失败：超出支票账户透支额度。");
        } else {
            setBalance(getBalance() - amount);
        }
    }

    @Override
    public String toString() {
        return "CheckingAccount[id=" + getId() + ", balance=" + getBalance() + ", overdraftLimit=" + limit + ", annualInterestRate=" + getAnnualInterestRate() + ", dateCreated=" + getDateCreated() + "]";
    }
}

