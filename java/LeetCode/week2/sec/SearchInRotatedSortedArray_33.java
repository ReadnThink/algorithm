package LeetCode.week2.sec;

public class SearchInRotatedSortedArray_33 {
    public int search(int[] nums, int target) {
        return binarySearch(nums, target, 0, nums.length-1);
    }

    private static int binarySearch(final int[] nums, final int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            // 오른쪽은 정렬되어있는 상태
            if (nums[mid] <= nums[right]) {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else { // 왼쪽 정렬된 상태
                if (target < nums[mid] && nums[left] <= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        SearchInRotatedSortedArray_33 r = new SearchInRotatedSortedArray_33();
        System.out.println(r.search(new int[]{4,5,6,7,0,1,2}, 0));
        System.out.println(r.search(new int[]{4,5,6,7,0,1,2}, 3));
    }
}
