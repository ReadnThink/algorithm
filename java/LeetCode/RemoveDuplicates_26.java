package LeetCode;

public class RemoveDuplicates_26 {
    public int removeDuplicates(int[] nums) {
        int count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }

    public static void main(String[] args) {
        RemoveDuplicates_26 r = new RemoveDuplicates_26();
        System.out.println(r.removeDuplicates(new int[]{1, 1, 2}));
        System.out.println(r.removeDuplicates(new int[]{0,0,1,1,1,2,2,3,3,4}));
    }
}
