package LeetCode.week1.sec;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;

public class LongestSubstringWithoutRepeatingCharacters_3 {
    public int lengthOfLongestSubstring(String s) {
        int max = 0;
        int end = 0;
        ArrayList<Character> list = new ArrayList<>();
        while (end < s.length()) {
            char cur = s.charAt(end);
            if (list.contains(cur)) {
                list.remove(0);
            } else {
                list.add(cur);
                end++;
                max = Math.max(max, list.size());
            }
        }
        return max;
    }

    public static void main(String[] args) {
        LongestSubstringWithoutRepeatingCharacters_3 l = new LongestSubstringWithoutRepeatingCharacters_3();
        System.out.println(l.lengthOfLongestSubstring("abcabcbb"));
        System.out.println(l.lengthOfLongestSubstring("pwwkew"));
    }
}
