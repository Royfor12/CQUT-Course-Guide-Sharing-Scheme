package Project_03.exercise_04;

public class Exercise_04 {

    public static boolean isPrime(long number) {
        if (number < 2) return false;
        for (long i = 2; i * i <= number; i++) 
            if (number % i == 0) return false;
        return true;
    }

    public static void main(String[] args) {
        System.out.println("p       2^p - 1");
        System.out.println("-----------------");
        for (long p = 2; p <= 31; p++) {
            if (isPrime(p)) {
                long mNumber = 1;
                for (long i = 0; i < p; i++) mNumber *= 2;
                mNumber -= 1;

                if (isPrime(mNumber)) System.out.println(p + "\t" + mNumber);
            }
        }
    }
}