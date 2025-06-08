package Project_06.exercise_04;

import java.util.ArrayList;
import java.util.Scanner;

public class MaxInteger {
    public static Integer max(ArrayList<Integer> list) {
        // 如果列表为 null或列表大小为0，返回null
        if (list == null || list.size() == 0) {
            return null;
        }
        
        Integer max = list.get(0);  // 初始化最大值
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i) > max) {
                max = list.get(i);
            }
        }
        
        return max;
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        ArrayList<Integer> numbers = new ArrayList<>();
        
        System.out.print("请输入一系列整数（以0结束）: ");
        
        int value;
        do {
            value = input.nextInt();
            if (value != 0) {
                numbers.add(value);  // 将输入的整数添加到列表
            }
        } while (value != 0);
        
        Integer maxValue = max(numbers);
        
        if (maxValue == null) {
            System.out.println("列表为空或无效");
        } else {
            System.out.println("最大值是: " + maxValue);
        }
        
        input.close();
    }
} 