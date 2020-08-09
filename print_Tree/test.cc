truct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if(root==nullptr)
            return vector<int> ();
        
        queue<TreeNode*> q;
        vector<int> v;
        
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* father=q.front();
            q.pop();
            v.push_back(father->val);
            if(father->left)
            {
                q.push(father->left);
            }
            if(father->right)
            {
                q.push(father->right);
            }
        }
        return v;
    }
};
