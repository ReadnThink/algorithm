package LeetCode.week3.sec;

import java.util.HashMap;
import java.util.Map;

class Node {
    public Map<Character, Node> children;

    public boolean isEndOfWord;

    public Node() {
        this.children = new HashMap<>();
        this.isEndOfWord = false;
    }
}
