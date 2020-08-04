/**
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
  public:
        TreeNode* reConstuct(vector<int>& pre,int start1,int end1,vector<int>& vin,int start2,int end2)
        {
                  if(start1>end1||start2>end2)
                                return nullptr;
                          TreeNode* root=new TreeNode(pre[start1]);
                                  for(int i=0;i<=end2;i++)
                                  {
                                                if(pre[start1]==vin[i])
                                                {
                                                                  root->left=reConstuct(pre, start1+1, i-start2+start1, vin, start2, i-1);
                                                                                  root->right=reConstuct(pre,  i-start2+start1+1,end1, vin, i+1, end2);
                                                                                                  break;
                                                                                                              
                                                }
                                                        
                                  }
                                          return root;
                                              
        }
        TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
              if(pre.empty()||vin.empty())
                        return nullptr;
                      
                      return reConstuct(pre,0,pre.size()-1,vin,0,vin.size()-1);
                              
                          
        }

};
 *   }
