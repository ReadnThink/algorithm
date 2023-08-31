package LeetCode.week2.first;

import java.util.HashMap;
import java.util.Map;

public class ContainsDuplicateII_219 {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            Integer cur = nums[i];
            if (map.containsKey(cur) && i - map.get(cur) <= k) {
                return true;
            }
            map.put(nums[i], i);
        }
        return false;
    }

    public static void main(String[] args) {
        ContainsDuplicateII_219 c = new ContainsDuplicateII_219();
        System.out.println(c.containsNearbyDuplicate(new int[]{1, 2, 3, 1}, 3));
    }
}
