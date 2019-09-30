package Trie;

public class Trie {

    public void insert(TrieNode root, String key) {
        int length = key.length();
        TrieNode pCrawl = root;
        for (int i = 0; i < length; i++) {
            int index = key.charAt(i) - 'a';
            if (pCrawl.children[index] == null) {
                pCrawl.children[index] = new TrieNode();
            }
            pCrawl = pCrawl.children[index];
        }
        pCrawl.isEndOfWord = true;
    }

    public boolean search(TrieNode root, String key) {
        int length = key.length();
        TrieNode pCrawl = root;
        for (int i = 0; i < length; i++) {
            int index = key.charAt(i) - 'a';
            if (pCrawl.children[index] == null) return false;
            pCrawl = pCrawl.children[index];
        }
        return pCrawl != null && pCrawl.isEndOfWord;
    }

    public boolean isEndOfWord(TrieNode root) {
        return root.isEndOfWord;
    }

    void display(TrieNode root, char str[], int level) {
        if (isEndOfWord(root)) {
            str[level] = '\0';
            System.out.println(String.copyValueOf(str, 0, level));
        }
        for (int i = 0; i < TrieNode.ALPHABET_SIZE; i++) {
            if (root.children[i] != null) {
                 str[level] = (char)(i + 'a');
                 display(root.children[i], str, level + 1);
            }
        }
    }
}
