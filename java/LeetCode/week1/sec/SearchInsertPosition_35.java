package LeetCode.week1.sec;

public class SearchInsertPosition_35 {
    public int searchInsert(int[] nums, int target) {

        int l = 0;
        int r = nums.length-1;
        int mid = -1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

    public static void main(String[] args) {
        SearchInsertPosition_35 s = new SearchInsertPosition_35();
        System.out.println(s.searchInsert(new int[]{1,3,5,6}, 5));
        System.out.println(s.searchInsert(new int[]{1,3,5,6}, 2));
        System.out.println(s.searchInsert(new int[]{1,3,5,6}, 7));
    }
}
