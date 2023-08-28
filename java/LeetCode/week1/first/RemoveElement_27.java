package LeetCode.week1.first;

import java.util.Arrays;

public class RemoveElement_27 {
    public int removeElement(int[] nums, int val) {
        int cnt = nums.length;
        int[] temp = new int[nums.length];
        int tmpPointer = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == val) {
                nums[i] = -1;
                cnt--;
            } else {
                temp[tmpPointer++] = nums[i];
            }
        }

        System.out.println(Arrays.toString(temp));
        for (int i = 0; i < nums.length; i++) {
            nums[i] = temp[i];
        }
        return cnt;
    }

    public static void main(String[] args) {
        RemoveElement_27 removeElement = new RemoveElement_27();

        System.out.println(removeElement.removeElement(new int[]{3, 2, 2, 3}, 3));
        System.out.println(removeElement.removeElement(new int[]{0,1,2,2,3,0,4,2}, 2));
    }
}
