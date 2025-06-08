package Project_04.exercise_07;

public class Exercise_07 {
    public static void main(String[] args) {

        Account.setAnnualInterestRate(4.5);


        Account account = new Account(1122, 20000);

        account.withdraw(2500);
        account.deposit(3000);
        account.deposit(3000);

        System.out.println("Account Details for ID: " + account.getId());
        System.out.printf("Balance: $%.2f\n", account.getBalance());
        System.out.printf("Monthly Interest: $%.2f\n", account.getMonthlyInterest());
        System.out.println("Date Created: " + account.getDateCreated());
    }
}