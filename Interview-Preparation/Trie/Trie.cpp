#include <iostream>
#include <string>
#include <vector>
#include <cassert>

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode *mChildren[ALPHABET_SIZE];
    bool mIsEndOfWord;
    TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            mChildren[i] = nullptr;
        }
        mIsEndOfWord = false;
    }
};

class Trie {
    private:
        TrieNode *mRoot;
        void TraverseUtil(TrieNode *node, std::string str) {
            if (node->mIsEndOfWord) {
                std::cout << str << "\n";
            }
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                if (node->mChildren[i]) {
                    str.push_back(i + 'a');
                    TraverseUtil(node->mChildren[i], str);
                    str.pop_back();
                }
            }
        }
    public:
        Trie() : mRoot(new TrieNode()) {} 
        ~Trie() {
            delete mRoot;
        }
        void Insert(std::string key) {
            int key_length = key.size();
            TrieNode *curr = mRoot;
            for (int i = 0; i < key_length; i++) {
                int index = key[i] - 'a';
                if (!curr->mChildren[index]) {
                    curr->mChildren[index] = new TrieNode();
                }
                curr = curr->mChildren[index];
            }
            curr->mIsEndOfWord = true;
        }

        bool Search(std::string key) {
            int key_length = key.size();
            TrieNode *curr = mRoot;
            for (int i = 0; i < key_length; i++) {
                int index = key[i] - 'a';
                if (!curr->mChildren[index]) 
                    return false;
                curr = curr->mChildren[index];
            }
            return curr != nullptr && curr->mIsEndOfWord;
        }


        void Traverse() {
            TrieNode *node = mRoot;
            TraverseUtil(node, "");
        }

};

int main (int argc, char *argv[]) {

    std::vector<std::string> keys { "the", "a", "there", 
        "answer", "any", "by", "bye", "their" };
    
    Trie trieObj;
    for (int i = 0; i < keys.size(); ++i) {
        trieObj.Insert(keys[i]);
    }
    
    assert(trieObj.Search("the") == true);
    assert(trieObj.Search("these") == false);
    assert(trieObj.Search("their") == true);
    assert(trieObj.Search("thaw") == false);

    trieObj.Traverse();

    return 0;
}

