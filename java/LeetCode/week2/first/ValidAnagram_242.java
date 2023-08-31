package LeetCode.week2.first;

import java.util.Arrays;
import java.util.HashMap;

public class ValidAnagram_242 {

    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        HashMap<Character, Integer> map = new HashMap<>();
        int cnt = 0;

        for (int i = 0; i < s.length(); i++) {
            char key = s.charAt(i);
            map.put(key, map.getOrDefault(key, 0) + 1);
        }

        for (int i = 0; i < t.length(); i++) {
            char key = t.charAt(i);
            if (map.containsKey(key) && map.get(key) > 0) {
                cnt++;
                map.put(key, map.get(key) - 1);
            }
        }

        System.out.println("s.length() <= cnt : " + s.length() + " " + cnt);
        return s.length() == cnt;
    }

    public static void main(String[] args) {
        ValidAnagram_242 v = new ValidAnagram_242();
        System.out.println(v.isAnagram("anagram", "nagaram"));
        System.out.println(v.isAnagram("rat", "car"));
        System.out.println(v.isAnagram("a", "ab"));
    }
}
