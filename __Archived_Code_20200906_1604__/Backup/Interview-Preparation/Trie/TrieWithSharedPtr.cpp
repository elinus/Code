#include <iostream>
#include <memory>
#include <vector>

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
  std::vector<std::shared_ptr<TrieNode>> children;
  bool is_word;
  TrieNode() {
    children = std::vector<std::shared_ptr<TrieNode>>(ALPHABET_SIZE);
    is_word = false;
  }
};

class Trie {
private:
  std::shared_ptr<TrieNode> root;
  void TraverseUtil(std::shared_ptr<TrieNode> node, std::string str) {
    if (node->is_word) {
      std::cout << str << "\n";
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
      if (node->children[i]) {
        str.push_back(i + 'a');
        TraverseUtil(node->children[i], str);
        str.pop_back();
      }
    }
  }

public:
  Trie() { root = std::make_shared<TrieNode>(); }

  void Insert(std::string key) {
    int key_length = key.size();
    std::shared_ptr<TrieNode> curr = root;
    for (int i = 0; i < key_length; i++) {
      int index = key[i] - 'a';
      if (!curr->children[index]) {
        curr->children[index] = std::make_shared<TrieNode>();
      }
      curr = curr->children[index];
    }
    curr->is_word = true;
  }

  void Traverse() {
    std::shared_ptr<TrieNode> node = root;
    TraverseUtil(root, "");
  }
};

int main(int argc, char const *argv[]) {
  std::vector<std::string> keys{"the", "a",  "there", "answer",
                                "any", "by", "bye",   "their"};

  Trie trieObj;
  for (int i = 0; i < keys.size(); ++i) {
    trieObj.Insert(keys[i]);
  }

  trieObj.Traverse();
  return 0;
}
