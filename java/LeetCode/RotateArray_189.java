package LeetCode;

import java.util.Arrays;

public class RotateArray_189 {
    public void rotate(int[] nums, int k) {
        int[] temp = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            temp[(i+k) % nums.length] = nums[i];
        }

        // System.out.println(Arrays.toString(temp));
        for (int i = 0; i < nums.length; i++) {
            nums[i] = temp[i];
        }

         System.out.println(Arrays.toString(nums));
    }

    public static void main(String[] args) {
        RotateArray_189 r = new RotateArray_189();
        r.rotate(new int[]{1,2,3,4,5,6,7}, 3);
        r.rotate(new int[]{-1,-100,3,99}, 2);
    }
}
