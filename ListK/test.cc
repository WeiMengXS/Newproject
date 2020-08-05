/*
 * struct ListNode {
 *  int val;
 *    struct ListNode *next;
 *      ListNode(int x) :
 *            val(x), next(NULL) {
 *              }
 *              };*/
class Solution {
  public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
          if(pListHead==NULL)
                    return nullptr;
                  int n=k;
                          ListNode* cur=pListHead;
                                  ListNode* ptr=pListHead;
                                          
                                          while(k>0&&cur)
                                          {
                                                        k--;
                                                                    cur=cur->next;
                                                                            
                                          }
                                                  while(cur)
                                                  {
                                                                cur=cur->next;
                                                                            ptr=ptr->next;
                                                                                    
                                                  }
                                                          return k>0?nullptr:ptr;
                                                              
    }

};
 *            }
 * }
