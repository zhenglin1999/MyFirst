vector<string> generateParenthesis(int n) {
        string one;
        vector<string> all;
        if (n <= 0) return all;
        int left = 0, right = 0;
        backtracking(n, left, right, one, all);
        return all;
    }
    void backtracking(int n, int& left, int& right, string& one, vector<string>& all) {
        if (one.size() == 2*n && left == right) {
            all.push_back(one);
            return;
        }
        if (right > left) return;
        if (left < n) {
            one.push_back('(');
            left++;
            backtracking(n, left, right, one, all);
            one.pop_back();
            left--;            
        }
        if (right < n) {
            one.push_back(')');
            right++;
            backtracking(n, left, right, one, all);
            one.pop_back();
            right--;
        }
        return;
    }
    //我的方法是构建二叉树-》深度遍历二叉树-》判断信息
    //其实完全可以不建树的，比如上面。。。
    //我的代码
    struct node{
	char data;
	int level;
	bool isleft;
	node* left;
	node* right;
	node(char x,int y,bool _isleft) :data(x),level(y),isleft(_isleft),left(nullptr), right(nullptr){}
};
void create(bool branch,node*& root,int l,int r,int y ,int size){
	if ( y >= 2*size){
		root = nullptr;
	}
	else
	{
		if (branch)
		{
			root = new node('(', y + 1, true);
		}
		else
		{
			root = new node(')', y + 1, false);
		}
		if (l < size)
		{
			create(true,root->left, l + 1, r, y + 1, size);
		}
		if (l>r)
		{
			create(false,root->right, l, r + 1, y + 1, size);
		}
	}
}
void searchTree(vector<string>& res, node* root,int size){
	stack<node*> temp;
	temp.push(root);
	string s;
	while (!temp.empty())
	{
		node* p = temp.top();
		s += p->data;
		if (s.size() == 2*size)
		{
			res.push_back(s);
			int pre = temp.top()->level;
			temp.pop();
			if (temp.empty())
				break;
			int post = temp.top()->level;
			s = s.substr(0, 2 * size - 1 - pre + post);
			continue;
		}
		temp.pop();
		if (p->right)
		{
			temp.push(p->right);
		}
		if (p->left)
		{
			temp.push(p->left);
		}
	}
}
vector<string> generateParenthesis(int n) {
	int l = 0;
	int r = 0;
	node* root;
	vector<string> res;
	create(true, root, l+1, r, 0, n);
	searchTree(res, root, n);
	return res;
}
