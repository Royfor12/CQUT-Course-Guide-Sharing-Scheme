package Project_04.exercise_02;

public class Stock {
    private String symbol;
    private String name;
    private double previousClosingPrice;
    private double currentPrice;

    public Stock(String symbol, String name) {
        this.symbol = symbol;
        this.name = name;
    }

    public String getSymbol() {
        return symbol;
    }

    public String getName() {
        return name;
    }

    public double getPreviousClosingPrice() {
        return previousClosingPrice;
    }

    public double getCurrentPrice() {
        return currentPrice;
    }

    public void setPreviousClosingPrice(double previousClosingPrice) {
        this.previousClosingPrice = previousClosingPrice;
    }

    public void setCurrentPrice(double currentPrice) {
        this.currentPrice = currentPrice;
    }

    public double getChangePercent() {
        // Avoid division by zero if previousClosingPrice is 0
        if (previousClosingPrice == 0) {
            return 0.0; // Or throw an exception, depending on requirements
        }
        return (currentPrice - previousClosingPrice) / previousClosingPrice;
    }
} 