package LeetCode.week1.sec;

import java.util.Arrays;

public class TwoSum2_167 {

    public int[] twoSum(int[] numbers, int target) {
        int start = 0;
        int end = numbers.length-1;

        while (start <= end){
            int cur = numbers[start] + numbers[end];
            System.out.println(cur + " " + start + " " + end);
            if (cur > target) {
                end--;
            } else if (cur < target) {
                start++;
            } else {
                return new int[]{start+1, end+1};
            }
        }

        return new int[]{};
    }

    public static void main(String[] args) {
        TwoSum2_167 t = new TwoSum2_167();
        System.out.println(Arrays.toString(t.twoSum(new int[]{2, 7, 11, 15}, 9)));
    }
}
