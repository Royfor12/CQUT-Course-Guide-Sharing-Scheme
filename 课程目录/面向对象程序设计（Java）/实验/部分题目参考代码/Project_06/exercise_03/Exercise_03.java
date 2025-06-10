package Project_06.exercise_03;


public class Exercise_03 {
    public static void main(String[] args) {
        Account account = new Account(12403010122L, 5000);  // 创建一个账户，存款5000
        account.setAnnualInterestRate(3.5);  // 设置年利率为3.5%
        System.out.println(account);

        SavingsAccount saveAcc = new SavingsAccount(12403010123L, 2000);  // 创建一个储蓄账户，存款2000
        saveAcc.setAnnualInterestRate(2.5);
        saveAcc.withdraw(2500);  // 取款超额，失败
        saveAcc.withdraw(1500);  // 成功
        System.out.println(saveAcc);

        CheckingAccount checkAcc = new CheckingAccount(12403010124L, 1000, 500);
        checkAcc.setAnnualInterestRate(4.0);
        checkAcc.withdraw(1200);  // 允许透支500
        checkAcc.withdraw(400);   // 超出透支额度，失败
        System.out.println(checkAcc);
    }
}