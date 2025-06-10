package Project_01.exercise_07;

public class Exercise_06 {
    public static void main(String[] args) {
        final double KILOMETERS_TO_MILES = 1.0 / 1.6;

        int distanceKM = 14;
        int minutes = 45;
        int seconds = 30;
        double totalTimeHours = minutes / 60.0 + seconds / 3600.0;  // 时间统一为小时

        double distanceMILE = distanceKM * KILOMETERS_TO_MILES;

        System.out.println(distanceMILE / totalTimeHours);
    }
}
