package Project_06.exercise_12;

import java.util.ArrayList;
import java.util.Scanner;

public class SumArrayList {
    public static double sum(ArrayList<Double> list) {
        // 如果列表为 null或列表大小为0，返回0
        if (list == null || list.isEmpty()) {
            return 0;
        }
        
        double sum = 0;
        for (Double number : list) {
            sum += number;
        }
        
        return sum;
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        ArrayList<Double> numbers = new ArrayList<>();
        
        System.out.print("请输入5个数字: ");
        
        for (int i = 0; i < 5; i++) {
            double value = input.nextDouble();
            numbers.add(value);
        }
        
        double total = sum(numbers);
        System.out.println("数字的和是: " + total);
        
        input.close();
    }
} 