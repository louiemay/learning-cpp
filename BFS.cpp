#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	TreeNode(int _val) { val = _val; }
	~TreeNode() {}
	int val;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
};

vector<vector<int>> levelOrder(TreeNode* root)
{
	if (root == nullptr)
		return vector<vector<int>>();
	vector<vector<int>> res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int count = q.size();
		vector<int> list;
		while (count > 0) {
			TreeNode* node = q.front();
			q.pop();
			list.push_back(node->val);
			if (node->left != nullptr)
				q.push(node->left);
			if (node->right != nullptr)
				q.push(node->right);
			count--;
		}
		res.push_back(list);
	}
	return res;
}

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(8);

	auto res = levelOrder(root);

	for (const auto& i : res) {
		for (const auto& j : i)
			cout << j << " ";
		cout << endl;
	}


	return 0;
}


