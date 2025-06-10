package Project_08.exercise_06;

public class ComparableCircle extends Circle implements Comparable<ComparableCircle> {

    ComparableCircle() {}

    ComparableCircle(int radius) {
        super(radius);
    }

    @Override
    public int compareTo(ComparableCircle o) {
        if (this.calArea() > o.calArea()) {
            return 1;
        } else if (this.calArea() < o.calArea()) {
            return -1;
        } else {
            return 0;
        }
    }
}
