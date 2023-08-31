package LeetCode.week2.first;

import java.util.HashMap;

public class RansomNote_383 {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < magazine.length(); i++) {
            char key = magazine.charAt(i);
            map.put(key, map.getOrDefault(key, 0) + 1);
        }

        for (int i = 0; i < ransomNote.length(); i++) {
            char key = ransomNote.charAt(i);
            if (map.containsKey(key) && map.get(key) > 0) {
                map.put(key, map.get(key) - 1);
            } else {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        RansomNote_383 r = new RansomNote_383();

        System.out.println(r.canConstruct("a","b"));
        System.out.println(r.canConstruct("aa","ab"));
        System.out.println(r.canConstruct("aa","aab"));
    }
}
