package Project_06.exercise_03;

public class SavingsAccount extends Account {
    public SavingsAccount(long id, double balance) {
        super(id, balance);
    }

    @Override
    public void withdraw(double amount) {
        if (amount > getBalance()) {
            System.out.println("取款失败：储蓄账户不能透支。");
        } else {
            super.withdraw(amount);
        }
    }

    @Override
    public String toString() {
        return "Savings" + super.toString();
    }
}

