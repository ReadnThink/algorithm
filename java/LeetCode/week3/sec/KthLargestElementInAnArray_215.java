package LeetCode.week3.sec;

import org.junit.jupiter.api.Test;

import java.util.PriorityQueue;

public class KthLargestElementInAnArray_215 {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(((o1, o2) -> o2 - o1));
        for (int num : nums) {
            pq.add(num);
        }

        int ret = -1;
        for (int i = 0; i < k; i++) {
            ret = pq.poll();
        }

        return ret;
    }
}
