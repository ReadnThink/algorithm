package LeetCode.week2.sec;

public class FindMinimumInRotatedSortedArray_153 {
    public int findMin(int[] nums) {
        int min = Integer.MAX_VALUE;;
        int n = nums.length;
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = (l + r)/ 2;
            min = Math.min(nums[m], min);

            if (nums[l] < nums[r] && nums[l] < nums[m]) {
                r = m - 1;
            } else{
                l = l + 1;
            }
        }
        return min;
    }

    public static void main(String[] args) {
        FindMinimumInRotatedSortedArray_153 f = new FindMinimumInRotatedSortedArray_153();

        System.out.println(f.findMin(new int[]{5,6,7,0,1,2,3}));
        System.out.println(f.findMin(new int[]{3,4,5,1,2}));
        System.out.println(f.findMin(new int[]{11,13,15,17}));

    }
}
