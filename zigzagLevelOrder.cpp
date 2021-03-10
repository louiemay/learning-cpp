#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
struct TreeNode {
	TreeNode(int _val) { val = _val; }
	~TreeNode() {}
	int val;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
};
vector<vector<int>> zigzagLevelOrder(TreeNode* root){
	vector<vector<int>> res;
	if (root == nullptr)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	bool reverse = false;
	while (!q.empty()) {
		int size = q.size();
		vector<int> list;
		for (int i = 0; i < size; ++i) {
			TreeNode* cur = q.front();
			q.pop();
			if (cur->left != nullptr)
				q.push(cur->left);
			if (cur->right != nullptr)
				q.push(cur->right);
			if (reverse)
				list.insert(list.begin(), cur->val);
			else
				list.push_back(cur->val);
		}
		reverse = !reverse;
		res.push_back(list);
	}

	return res;
}
int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(8);

	auto res = zigzagLevelOrder(root);

	for (const auto& i : res) {
		for (const auto& j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}


