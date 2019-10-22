#include <iostream>
#include <map>
#include <string>

struct TrieNode {
    std::map<char, TrieNode*> m_childrens;
    bool m_endOfWord;
    TrieNode() {
        m_childrens = {};
        m_endOfWord = false;
    }
};

void insert(TrieNode* root, const std::string& key) {
    int key_len = key.size();
    TrieNode* curr = root;
    for (int i = 0; i < key_len; ++i) {
        if (curr->m_childrens.empty() || curr->m_childrens.find(key[i]) == curr->m_childrens.end()) {
            curr->m_childrens[key[i]] = new TrieNode();
        }
        curr = curr->m_childrens[key[i]];
    }
    curr->m_endOfWord = true;
}

bool search(TrieNode* root, const std::string& key) {
    int key_len = key.size();
    TrieNode* curr = root;
    for (int i = 0; i < key_len; ++i) {
        if (curr->m_childrens.empty() || curr->m_childrens.find(key[i]) == curr->m_childrens.end())
            return false;
        curr = curr->m_childrens[key[i]];
    }
    return !curr->m_childrens.empty() && curr->m_endOfWord == true;
}

bool search_prefix(TrieNode* root, const std::string& key) {
    int key_len = key.size();
    TrieNode* curr = root;
    for (int i = 0; i < key_len; ++i) {
        if (curr->m_childrens.empty() || curr->m_childrens.find(key[i]) == curr->m_childrens.end())
            return false;
        curr = curr->m_childrens[key[i]];
    }
    return true;
}

TrieNode* remove(TrieNode* root, const std::string& key, int depth) {
    if (root == nullptr) return root;
    if (depth == key.size()) {
        if (root->m_endOfWord) {
            root->m_endOfWord = false;
        }
        if (root->m_childrens.empty()) {
            root = nullptr;
            return root;
        }
    }
    root->m_childrens[key[depth]] = remove(root->m_childrens[key[depth]], key, depth + 1);
    if (root->m_childrens.empty() && !root->m_endOfWord) {
        root = nullptr;
    }
    return root;
}

void display(TrieNode* root, char str[], int level) {
    if (root == nullptr) return;
    if (root->m_endOfWord) {
        str[level] = '\0';
        std::cout << str << "\n";
    }
    for (auto it = root->m_childrens.begin(); it != root->m_childrens.end(); ++it) {
        str[level] = it->first;
        display(it->second, str, level + 1);
    }
}

int count(TrieNode* root) {
    int result = 0;
    if (root->m_endOfWord) result++;
    for (auto it = root->m_childrens.begin(); it != root->m_childrens.end(); ++it) {
        result += count(it->second);
    }
    return result;
}

int main(int argc, char const *argv[]) {
    std::string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their", 
        "qwerty", "qweaz", "qweyrt"};
    TrieNode *trie = new TrieNode();
    for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); ++i) {
        insert(trie, keys[i]);
    }
    std::cout << "the = " << search(trie, "the") << "\n";
    std::cout << "these = " << search(trie, "these") << "\n";

    std::cout << "----- TRIE -----\n";
    char* trie_strs = new char[20];
    display(trie, trie_strs, 0);

    std::cout << "Trie word count = " << count(trie) << "\n";
    std::cout << "prefix(the) = " << search_prefix(trie, "the") << "\n";
    std::cout << "prefix(thx) = " << search_prefix(trie, "thx") << "\n";

    remove(trie, "qwerty", 0);
    std::cout << "----- TRIE (remove = \"qwerty\") -----\n";
    display(trie, trie_strs, 0);

    remove(trie, "qwe", 0);
    std::cout << "----- TRIE (remove = \"qwe\") -----\n";
    display(trie, trie_strs, 0);

    return 0;
}

