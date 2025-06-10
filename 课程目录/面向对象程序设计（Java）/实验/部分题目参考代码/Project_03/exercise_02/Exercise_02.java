package Project_03.exercise_02;

import java.util.Scanner;

public class Exercise_02 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        System.out.println(sqrt(n));
    }

    public static double sqrt(int n) {
        double lastGuess = 1;
        double nextGuess = (lastGuess + n / lastGuess) / 2;
        while (Math.abs(nextGuess - lastGuess) > 0.0001) {
            lastGuess = nextGuess;
            nextGuess = (lastGuess + n / lastGuess) / 2;
        }
        return nextGuess;
    }
}