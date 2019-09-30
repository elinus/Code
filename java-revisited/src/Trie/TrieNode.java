package Trie;

public class TrieNode {

    public static final int ALPHABET_SIZE = 26;
    TrieNode children[];
    boolean isEndOfWord;

    public TrieNode() {
        children = new TrieNode[ALPHABET_SIZE];
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = null;
        }
    }
}
