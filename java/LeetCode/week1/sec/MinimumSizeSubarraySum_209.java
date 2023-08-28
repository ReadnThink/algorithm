package LeetCode.week1.sec;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MinimumSizeSubarraySum_209 {
    public int minSubArrayLen(int target, int[] nums) {
        int min = Integer.MAX_VALUE;
        int left = 0;
        int sum = 0;
        for(int right = 0 ; right<nums.length ; right++){
            sum+=nums[right];
            while(sum>=target){
                min = Math.min(min,right-left+1);
                sum-=nums[left++];
            }
        }

        return min==Integer.MAX_VALUE?0:min;

    }

    public static void main(String[] args) {
        MinimumSizeSubarraySum_209 m = new MinimumSizeSubarraySum_209();
        System.out.println(m.minSubArrayLen(7, new int[]{2,3,1,2,4,3}));
        System.out.println(m.minSubArrayLen(4, new int[]{1,4,4}));
        System.out.println(m.minSubArrayLen(11, new int[]{1,1,1,1,1,1,1,1}));

    }

}
