package Project_04.exercise_02;

public class Exercise_02 {
    public static void main(String[] args) {
        Stock stock = new Stock("ORCL", "OracleCorporation");
        stock.setPreviousClosingPrice(34.5);
        stock.setCurrentPrice(34.35);
        System.out.printf("The price change percentage is %.2f%%\n", stock.getChangePercent() * 100);
    }
}