package LeetCode.week1.first;

import java.util.HashMap;

public class MajorityElement_169 {
    public int majorityElement(int[] nums) {
        int limit = nums.length / 2;
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (var i : nums) {
            hashMap.put(i, hashMap.getOrDefault(i, 0) + 1);
        }

        int ret = 0;
        int max = 0;
        for (Integer key : hashMap.keySet()) {
            if (hashMap.get(key) > max) {
                max = hashMap.get(key);
                ret = key;
            }
        }

        return ret;
    }

    public static void main(String[] args) {
        MajorityElement_169 m = new MajorityElement_169();

        System.out.println(m.majorityElement(new int[]{3,2,3}));
        System.out.println(m.majorityElement(new int[]{2,2,1,1,1,2,2}));
    }
}
