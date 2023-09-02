package LeetCode.week2.sec;

import java.util.Arrays;

public class FindPeakElement_162 {
    public int findPeakElement(int[] nums) {
        if (nums.length <= 1) {
            return 0;
        }
        int l = 0;
        int r = nums.length - 1;
        while (l < r) {
            int pivot = (l + r) / 2;
            int num = nums[pivot];
            int nextNum = nums[pivot + 1];

            if (num < nextNum) {
                l = pivot + 1;
            } else {
                r = pivot;
            }
        }

        return l;
    }
    
    public static void main(String[] args) {
        FindPeakElement_162 s = new FindPeakElement_162();
        s.findPeakElement(new int[]{1,2,3,1});
    }
}
