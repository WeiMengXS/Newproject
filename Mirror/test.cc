/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
TreeNode *tmp=pRoot->left;
        if(pRoot==nullptr)
            return ;
        pRoot->left=pRoot->right;
        pRoot->right=tmp;
        
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        
        
        
    }
};<Paste>
