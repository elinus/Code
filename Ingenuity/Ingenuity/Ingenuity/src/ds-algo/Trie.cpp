#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

constexpr int ALPHABET_SIZE = 26;

struct TrieNode {
	vector<TrieNode*> children;
	bool isEndWord;
	TrieNode() : children(ALPHABET_SIZE, nullptr), isEndWord {false}
	{}
};

class Trie {
private:
	TrieNode* root;
public:
	Trie() : root{ new TrieNode() }
	{}

	~Trie() {
		if (root) delete root;
		root = nullptr;
	}

	int getIndex(char ch) {
		return ch - 'a';
	}

	void insert(string key) {
	
		if (key.empty()) return;
		transform(key.begin(), key.end(), key.begin(), ::tolower);
		TrieNode* p = root;
		for (int i = 0; i < key.length(); i++) {
			int index = getIndex(key[i]);
			if (!p->children[index])
				p->children[index] = new TrieNode();
			p = p->children[index];
		}
		p->isEndWord = true;
	}

	bool search(string key) {	
		if (key.empty()) return false;
		transform(key.begin(), key.end(), key.begin(), ::tolower);

		TrieNode* p = root;
		for (int i = 0; i < key.length(); i++) {
			int index = getIndex(key[i]);
			if (!p->children[index])
				return false;
			p = p->children[index];
		}
		return p && p->isEndWord;
	}

	void remove(string key) {
		if (!root || key.empty()) return;
		transform(key.begin(), key.end(), key.begin(), ::tolower);

		removeHelper(root, key, 0);
	}

	bool isEmpty(TrieNode* trie_node) {
		for (int i = 0; i < ALPHABET_SIZE; ++i) 
			if (trie_node->children[i]) return false;
		return true;
	}

	TrieNode* removeHelper(TrieNode* trie_node, string key, int level) {
		if (level == key.length()) {
			if (trie_node->isEndWord) {
				trie_node->isEndWord = false;
			}
			if (isEmpty(trie_node)) {
				delete trie_node;
				trie_node = nullptr;
			}
			return trie_node;
		}
		int index = getIndex(key[level]);
		trie_node->children[index] = removeHelper(trie_node->children[index],
			key, level + 1);
		if (isEmpty(trie_node) && !trie_node->isEndWord) {
			delete trie_node;
			trie_node = nullptr;
		}
		return trie_node;
	}

	void display(TrieNode* trie_node, string &str) {
		if (trie_node->isEndWord) {
			cout << str << endl;
		}
		for (int i = 0; i < ALPHABET_SIZE; i++) {
			if (trie_node->children[i]) {
				str.push_back(static_cast<char>(i + 'a'));
				display(trie_node->children[i], str);
				str.pop_back();
			}
		}
	}

	void display() {
		cout << "----- Content of trie -----\n";
		string str;
		display(root, str);
		cout << "----- End -----\n";
	}
};

int main() {
	string keys[] = { "the", "a", "there",
					  "answer", "any", "by",
					  "bye", "their", "hero", "heroplane" };
	int n = sizeof(keys) / sizeof(keys[0]);
	
	Trie trie;
	
	for (int i = 0; i < n; i++)
		trie.insert(keys[i]);
	
	trie.display();

	trie.search("the") ? cout << "Yes\n" : cout << "No\n";
	trie.search("these") ? cout << "Yes\n" : cout << "No\n";

	trie.remove("heroplane");
	trie.display();
	trie.search("hero") ? cout << "Yes\n" : cout << "No\n";
	trie.remove("hero");
	trie.display();
	return 0;
}