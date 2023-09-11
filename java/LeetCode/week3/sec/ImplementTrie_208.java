package LeetCode.week3.sec;

public class ImplementTrie_208 {
    public static void main(String[] args) {
        Trie t = new Trie();
        var word = "word";
        t.insert(word);
        t.search(word);
        t.startsWith("wo");

    }


    static class Trie {
        private Node root;

        public Trie() {
            this.root = new Node();
        }

        public void insert(String word) {
            insert(this.root, word);
        }

        public void insert(Node node, String word) {
            if (word.length() == 0) {
                node.isEndOfWord = true;
                return;
            }

            final char c = word.charAt(0);
            Node child = node.children.get(c);

            if (child == null) {
                child = new Node();
                node.children.put(c, child);
            }

            insert(child, word.substring(1));
        }

        public boolean search(String word) {
            return search(this.root, word);
        }

        private boolean search(final Node node, final String word) {
            if (word.length() == 0) {
                return node.isEndOfWord;
            }

            char c = word.charAt(0);
            Node child = node.children.get(c);

            if (child == null) {
                return false;
            }

            return search(child, word.substring(1));
        }

        public boolean startsWith(String prefix) {
            return startsWith(this.root, prefix);
//            Node currentNode = this.root;
//
//            for (char c: prefix.toCharArray()) {
//                Node child = currentNode.children.get(c);
//
//                if (child == null) return false;
//
//                currentNode = child;
//            }
//            return true;
        }

        private boolean startsWith(final Node node, final String word) {
            if (word.length() == 0) {
                return true;
            }

            char c = word.charAt(0);
            Node child = node.children.get(c);

            if (child == null) {
                return false;
            }

            return startsWith(child, word.substring(1));
        }
    }

}
