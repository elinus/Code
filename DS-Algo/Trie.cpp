#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

constexpr int ALPHABET_SIZE = 26;

struct TrieNode {
  vector<TrieNode *> children;
  bool isEndWord;
  TrieNode() : children(ALPHABET_SIZE, nullptr), isEndWord{false} {}
  void markAsLeaf() {}
  void unMarkAsLeaf() {}
};