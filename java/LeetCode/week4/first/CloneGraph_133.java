package LeetCode.week4.first;

import java.util.*;

public class CloneGraph_133 {
    class Node {
        public int val;
        public List<Node> neighbors;

        public Node() {
            val = 0;
            neighbors = new ArrayList<Node>();
        }

        public Node(int _val) {
            val = _val;
            neighbors = new ArrayList<Node>();
        }

        public Node(int _val, ArrayList<Node> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    }

    public Node cloneGraphBFS(Node node) {
        if (node == null) {
            return null;
        }
        Node graph = new Node(node.val);


        HashMap<Node, Node> mp = new HashMap<>();
        mp.put(node, graph);

        Queue<Node> q = new LinkedList<>();
        q.offer(node);

        while (!q.isEmpty()) {
            Node cur = q.poll();
            System.out.println("현재 노드 : " + cur.val);
            for (Node neighbor : cur.neighbors) {
                System.out.println("이웃 노드 : " + neighbor.val);
                if (!mp.containsKey(neighbor)) {
                    System.out.println("visited인 Map/ Queue에 추가할 노드 : " + neighbor.val);
                    mp.put(neighbor, new Node(neighbor.val));
                    q.offer(neighbor);
                }
                // 현재노드의 이웃들을 전부 추가
                final Node temp = mp.get(cur);
                temp.neighbors.add(mp.get(neighbor));
                System.out.println("현재노드 : " + temp.val + " 추가할 노드 : " + mp.get(neighbor).val);
            }
            System.out.println();
        }
        return graph;
    }

    HashMap<Node, Node> mpDFS = new HashMap<>();
    public Node cloneGraphDFS(Node node) {
        if (node == null) return null;
        if (mpDFS.containsKey(node)) return mpDFS.get(node);

        mpDFS.put(node, new Node(node.val));
        for (Node val : node.neighbors) {
            mpDFS.get(node).neighbors.add(cloneGraphDFS(val));
        }

        return mpDFS.get(node);
    }

}
