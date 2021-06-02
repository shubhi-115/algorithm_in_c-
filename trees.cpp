#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long int
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define endl "\n"
#define all(a) a.begin(),a.end()
#define vi vector<int>
#define pii pair<int,int>
#define fr first
#define sc second
#define INF (ll)1e18
#define pb push_back
#define ppb pop_back()
#define sz(x) (int)((x).size())
using namespace std;
//inorder traversal gives sorted output
// PREORDER- Root L R
// INORDER- L Root R
// POSTORDER- L R Root
class tree {
public:
	ll val;
	tree *left, *right;
public:
	tree(ll data) {
		this->val = data;
		this->left = this->right = NULL;
	}
	tree *insert(ll value, tree *root) {
		if (root == NULL)
			return new tree(value);
		if (value < root->val)
			root->left = insert(value, root->left);
		else
			root->right = insert(value, root->right);
		return root;
	}
	void inorder(tree *root) {
		if (root == NULL) return ;
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
	void preorder(tree *root) {
		if (root == NULL) return ;
		cout << root->val << " ";
		preorder(root->left);
		preorder(root->right);
	}
	void postorder(tree *root) {
		if (root == NULL) return;
		postorder(root->left);
		postorder(root->right);
		cout << root->val << " ";
	}
	void level_order_traversal(tree *root) {
		queue<tree*> q;
		q.push(root);
		while (!q.empty()) {
			auto temp = q.front();
			q.pop(); cout << temp->val << " ";
			if (temp->left != NULL) q.push(temp->left);
			if (temp->right != NULL) q.push(temp->right);
		}
	}
	void left_view(tree* root) {
		queue<tree *> q;
		q.push(root);
		while (!q.empty()) {
			int sz = q.size();
			for (int i = 1; i <= sz; i++) {
				auto temp = q.front();
				q.pop();
				if (i == 1) cout << temp->val << " ";
				if (temp->left) q.push(temp->left);
				if (temp->right) q.push(temp->right);
			}
		}
	}
	void right_view(tree *root) {
		queue<tree*>q;
		q.push(root);
		while (!q.empty()) {
			int sz = q.size();
			for (int i = 1; i <= sz; i++) {
				auto temp = q.front();
				q.pop();
				if (i == sz) cout << temp->val << " ";
				if (temp->left) q.push(temp->left);
				if (temp->right) q.push(temp->right);
			}
		}
	}
	//vertical level ki first node print krna
	void top_view(tree* root) {
		map<int, int> mp;
		queue<pair<tree*, int>> q;
		q.push({root, 0});
		while (!q.empty()) {
			auto temp = q.front();
			q.pop();
			int hd = temp.second;
			auto node = temp.first;
			if (mp.count(hd) == 0)
				mp[hd] = node->val;
			if (node->left) q.push({node->left, hd - 1});
			if (node->right) q.push({node->right, hd + 1});
		}
		for (auto x : mp) cout << x.second << " ";
	}
//vertical level ki last node print krna
	void bottom_view(tree* root) {
		queue<pair<tree*, int>> q;
		map<int, int> mp;
		q.push({root, 0});
		while (!q.empty()) {
			auto temp = q.front();
			q.pop();
			int hd = temp.second;
			auto node = temp.first;
			mp[hd] = node->val;
			if (node->left) q.push({node->left, hd - 1});
			if (node->right) q.push({node->right, hd + 1});
		}
		for (auto x : mp) cout << x.second << " ";
	}
//maximum depth(height of tree)
	ll get_tree_height(tree* root) {
		if (root == NULL) return 0;
		ll left = get_tree_height(root->left);
		ll right = get_tree_height(root->right);
		return 1 + max(left, right);
	}
//To convert a sorted array into Height Balanced BST
//difference between heights of left and right child should not be more than 1
	tree *array_to_bst(ll *a, ll st, ll end) {
		if (st > end) return NULL;
		ll mid = (st + end) >> 1; //divide by 2;
		tree *root = new tree(a[mid]);
		root->left = array_to_bst(a, st, mid - 1);
		root->right = array_to_bst(a, mid + 1, end);
		return root;
	}
	tree* create_tree_from_inpre(int &pre_idx, int st, int end, int *pre, unordered_map<int, int> &mp) {
		if (st > end) return NULL;
		tree *root = new tree(pre[pre_idx]);
		int search = pre[pre_idx];
		int idx = mp[search];
		pre_idx++;
		root->left = create_tree_from_inpre(pre_idx, st, idx - 1, pre, mp);
		root->right = create_tree_from_inpre(pre_idx, idx + 1, end, pre, mp);
		return root;
	}
	bool is_identical_trees(tree *root1, tree *root2) {
		//Both trees are empty
		if (root1 == NULL and root2 == NULL) return true;
		if (root1 == NULL || root2 == NULL) return false;
		if (root1->val != root2->val) return false;
		return is_identical_trees(root1->left, root2->left) and is_identical_trees(root1->right, root2->right);
	}
	bool is_mirror_tree(tree *root1, tree *root2) {
		if (root1 == NULL and root2 == NULL) return true;
		if (root1 == NULL || root2 == NULL) return false;
		if (root1->val != root2->val) return false;
		return is_mirror_tree(root1->left, root2->right) and is_mirror_tree(root1->right, root2->left);
	}
};
int main() {
	fast_io;
	// tree *root = NULL;
	// root = root->insert(7, root);
	// root = root->insert(5, root);
	// root = root->insert(8, root);
	// root = root->insert(4, root);
	// root = root->insert(6, root);
	// root = root->insert(9, root);
	// root->inorder(root);
	// cout << endl;
	// root->preorder(root);
	// cout << endl;
	// root->postorder(root); cout << endl;
	// root->level_order_traversal(root); cout << endl;
	// root->left_view(root); cout << endl;
	// root->right_view(root); cout << endl;
	// root->top_view(root); cout << endl;
	// root->bottom_view(root); cout << endl;
	// cout << root->get_tree_height(root);

	// ll a[] = {1, 2, 3, 4, 5};
	// tree *root = NULL;
	// root = root->array_to_bst(a, 0, 4);
	// root->inorder(root); cout << endl;
	// root->preorder(root); cout << endl;

//how to make a tree from inorder and preorder
	// int in[] = {3, 1, 4, 0, 5, 2}; //left Root right
	// int pre[] = {0, 1, 3, 4, 2, 5}; //Root left right
	// unordered_map<int, int> mp;//[value]=index
	// for (int i = 0; i < 6; i++)
	// 	mp[in[i]] = i;
	// int pre_idx = 0;
	// tree *root = root->create_tree_from_inpre(pre_idx, 0, 5, pre, mp);
	// root->inorder(root); cout << endl;

//Identical trees
	// tree *root = NULL;
	// tree *root1 = NULL, *root2 = NULL;
	// root1 = root1->insert(7, root1);
	// root1 = root1->insert(2, root1);
	// root1 = root1->insert(8, root1);
	// root1 = root1->insert(1, root1);
	// root1 = root1->insert(5, root1);

	// root2 = root2->insert(7, root2);
	// root2 = root2->insert(2, root2);
	// root2 = root2->insert(8, root2);
	// root2 = root2->insert(1, root2);
	// root2 = root2->insert(5, root2);
	// cout << root->is_identical_trees(root1, root2);
//mirror trees
	// tree *root = NULL;
	// tree *root1 = NULL, *root2 = NULL;
	// root1 = root1->insert(7, root1);
	// root1 = root1->insert(2, root1);
	// root1 = root1->insert(8, root1);
	// root1 = root1->insert(1, root1);
	// root1 = root1->insert(5, root1);
	// root2 = new tree(7);
	// root2->left = new tree(8);
	// root2->right = new tree(2);
	// root2->right->left = new tree(5);
	// root2->right->right = new tree(1);
	// cout << root1->is_mirror_tree(root1, root2);

//Serialize a Tree

}
