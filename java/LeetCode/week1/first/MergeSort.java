package LeetCode.week1.first;

import java.util.Arrays;

public class MergeSort {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int tail1 = m - 1, tail2 = n - 1, finished = m + n - 1;
        while (tail1 >= 0 && tail2 >= 0) {
            nums1[finished--] = (nums1[tail1] > nums2[tail2]) ?
                    nums1[tail1--] : nums2[tail2--];
        }

        // nums1에 복사할것이고 nums1,2는 정렬되어있기 때문에 nums1이 남아있을때는 신경쓸 필요가 없다.
        while (tail2 >= 0) { //only need to combine with remaining nums2
            nums1[finished--] = nums2[tail2--];
        }
        System.out.println(Arrays.toString(nums1));
    }

    public static void main(String[] args) {
        MergeSort mergeSort = new MergeSort();
        mergeSort.merge(new int[]{1, 2, 3, 0, 0, 0}, 3, new int[]{2, 5, 6}, 3);
        mergeSort.merge(new int[]{1}, 1, new int[]{}, 0);
        mergeSort.merge(new int[]{0}, 0, new int[]{1}, 1);
        mergeSort.merge(new int[]{4,0,0,0,0,0}, 1, new int[]{1,2,3,5,6}, 5);

    }
}
