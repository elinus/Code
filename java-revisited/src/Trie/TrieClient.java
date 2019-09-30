package Trie;

public class TrieClient {

    public static void main(String[] args) {
        String keys[] = {"the", "a", "there", "answer", "any",
                "by", "bye", "their" };

        Trie trie = new Trie();
        TrieNode root = new TrieNode();
        for (int i = 0; i < keys.length; i++) {
            trie.insert(root, keys[i]);
        }

        System.out.println("the = " + trie.search(root, "the"));
        System.out.println("these = " + trie.search(root, "these"));

        int level = 0;
        char str[] = new char[20];
        System.out.println("\nContent of Trie:");
        trie.display(root, str, level);
    }
}
