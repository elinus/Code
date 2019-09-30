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
}
