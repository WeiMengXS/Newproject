/*
 * struct TreeNode {
 *  int val;
 *    struct TreeNode *left;
 *      struct TreeNode *right;
 *        TreeNode(int x) :
 *              val(x), left(NULL), right(NULL) {
 *                }
 *                };*/
class Solution {
  public:
        bool Treetest(TreeNode* pRoot1, TreeNode* pRoot2)
        {
                  if(pRoot2==nullptr)
                                return true;
                          if(pRoot1==nullptr)
                                        return false;
                                  if(pRoot1->val!=pRoot2->val)
                                                return false;
                                          return Treetest(pRoot1->left,pRoot2->left)&&
                                                        Treetest(pRoot1->right,pRoot2->right);
                                              
        }
            bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
            {
                      if(pRoot1==NULL||pRoot2==NULL)
                                    return false;
                              bool result=false;
                                      if(pRoot1->val==pRoot2->val)
                                      {
                                                   result= Treetest(pRoot1,pRoot2);
                                                           
                                      }
                                              if(!result)
                                              {
                                                            result=Treetest(pRoot1->left,pRoot2);
                                                                    
                                              }
                                                       if(!result)
                                                       {
                                                                     result=Treetest(pRoot1->right,pRoot2);
                                                                             
                                                       }
                                                               return result;
                                                                   
            }

};
 *              }
 * }
