#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) : value{value}, left{nullptr}, right{nullptr}
	{}
};

class BinarySearchTree {
private:
	TreeNode* root;
	
	TreeNode* insert_(TreeNode* ptr, int value) {
		 if (!ptr)
			 return new TreeNode(value);
		 else if (value < ptr->value)
			 ptr->left = insert_(ptr->left, value);
		 else if (value > ptr->value)
			 ptr->right = insert_(ptr->right, value);
		 return ptr;
	}

	TreeNode* remove_(TreeNode* ptr, int value) {
		if (ptr == nullptr) return ptr;
		if (value < ptr->value)
			ptr->left = remove_(ptr->left, value);
		else if (value > ptr->value)
			ptr->right = remove_(ptr->right, value);
		else {
			if (ptr->left == nullptr) {
				TreeNode* tmp = ptr->right;
				delete ptr;
				return tmp;
			}
			else if (ptr->right == nullptr) {
				TreeNode* tmp = ptr->left;
				delete ptr;
				return tmp;
			}
			TreeNode* tmp = get_inorder_succ_(ptr->right);
			ptr->value = tmp->value;
			ptr->right = remove_(ptr->right, tmp->value);
		}
		return ptr;
	}

	/* Utils */
	void inorder_recur_(TreeNode *ptr) {
		if (ptr) {
			inorder_recur_(ptr->left);
			std::cout << ptr->value << " ";
			inorder_recur_(ptr->right);
		}
	}

	void inorder_iter_(TreeNode* ptr) {
		std::stack<TreeNode*> st;
		while (true) {
			while (ptr) {
				st.push(ptr);
				ptr = ptr->left;
			}
			if (st.empty()) break;
			ptr = st.top();
			st.pop();
			std::cout << ptr->value << " ";
			ptr = ptr->right;
		}
	}

	void preorder_recur_(TreeNode* ptr) {
		if (ptr) {
			std::cout << ptr->value << " ";
			preorder_recur_(ptr->left);
			preorder_recur_(ptr->right);
		}
	}

	void preorder_iter_(TreeNode* ptr) {
		std::stack<TreeNode*> st;
		while (true) {
			while (ptr) {
				std::cout << ptr->value << " ";
				st.push(ptr);
				ptr = ptr->left;
			}
			if (st.empty()) break;
			ptr = st.top();
			st.pop();
			ptr = ptr->right;
		}
	}

	void postorder_recur_(TreeNode* ptr) {
		if (ptr) {
			postorder_recur_(ptr->left);
			postorder_recur_(ptr->right);
			std::cout << ptr->value << " ";
		}
	}

	void postorder_iter_(TreeNode* ptr) {
		std::stack<TreeNode*> st;
		std::vector<int> postorder;

		while (true) {
			while (ptr) {
				postorder.push_back(ptr->value);
				st.push(ptr);
				ptr = ptr->right;
			}
			if (st.empty()) break;
			ptr = st.top();
			st.pop();
			ptr = ptr->left;
		}
		std::reverse(postorder.begin(), postorder.end());
		for (auto it = postorder.begin(); it != postorder.end(); ++it) {
			std::cout << *it << " ";
		}
	}

	TreeNode* get_inorder_succ_(TreeNode *ptr) {
		TreeNode* curr = ptr, *succ = nullptr;
		while (curr) {
			succ = curr;
			curr = curr->left;
		}
		return succ;
	}

	TreeNode* get_inorder_pred_(TreeNode* ptr) {
		TreeNode* curr = ptr, *pred = nullptr;
		while (curr) {
			pred = curr;
			curr = curr->right;
		}
		return pred;
	}

public:
	BinarySearchTree() {
		root = nullptr;
	}



	void insert(int value) {
		TreeNode* node = new TreeNode(value);
		if (!root) {
			root = node;
		}
		else {
			TreeNode* curr = root, *parent = nullptr;
			while (curr) {
				parent = curr;
				if (value < curr->value) {
					curr = curr->left;
				}
				else if (value > curr->value) {
					curr = curr->right;
				}
				else {
					curr = nullptr;
				}
			}
			if (value < parent->value)
				parent->left = node;
			else if (value > parent->value)
				parent->right = node;
			else std::cerr << "Value already present!" << std::endl;
		}
	}

	void insert_recur(int value) {
		root = insert_(root, value);
	}

	void remove(int value) {
		root = remove_(root, value);
	}
	

	/* Tree Traversals Recursive */
	void inorder_recur() {
		if (!root) {
			std::cerr << "Tree not present!" << std::endl;
			return;
		}
		inorder_recur_(root);
		std::cout << std::endl;
	}

	void inorder_iter() {
		if (!root) {
			std::cerr << "Tree not present!" << std::endl;
			return;
		}
		inorder_iter_(root);
		std::cout << std::endl;
	}

	void preorder_recur() {
		if (!root) {
			std::cerr << "Tree not present!" << std::endl;
			return;
		}
		preorder_recur_(root);
		std::cout << std::endl;
	}

	void preorder_iter() {
		if (!root) {
			std::cerr << "Tree not present!" << std::endl;
			return;
		}
		preorder_iter_(root);
		std::cout << std::endl;
	}

	void postorder_recur() {
		if (!root) {
			std::cerr << "Tree not present!" << std::endl;
			return;
		}
		postorder_recur_(root);
		std::cout << std::endl;
	}

	void postorder_iter() {
		if (!root) {
			std::cerr << "Tree not present!" << std::endl;
			return;
		}
		postorder_iter_(root);
		std::cout << std::endl;
	}
};


//int main() {
//	BinarySearchTree bst;
//	
//	std::vector<int> tree_vals{ 11, 2, 9, 13, 57, 25, 1, 1, 90, 3, 17 };
//	
//	bst.inorder_recur();
//	bst.inorder_iter();
//
//	for (int i = 0; i < tree_vals.size(); i++) {
//		bst.insert(tree_vals[i]);
//		//bst.insert_recur(tree_vals[i]);
//	}
//
//	//bst.inorder_recur();
//	bst.inorder_iter();
//	//bst.preorder_recur();
//	bst.preorder_iter();
//	//bst.postorder_recur();
//	bst.postorder_iter();
//
//	bst.remove(17);
//	bst.inorder_recur();
//	bst.remove(13);
//	bst.inorder_recur();
//	bst.remove(2);
//	bst.inorder_recur();
//
//	return 0;
//}