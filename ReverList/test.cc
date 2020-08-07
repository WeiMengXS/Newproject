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
    ListNode* ReverseList(ListNode* pHead) {
              if(pHead==NULL)
                            return nullptr;
                      ListNode* newhead=NULL;
                              while(pHead)
                              {
                                            ListNode* p=pHead;
                                                        pHead=pHead->next;
                                                                    
                                                                    p->next=newhead;
                                                                                newhead=p;
                                                                                        
                              }
                                      pHead=newhead;
                                              return pHead;
                                                  
    }

};
 *            }
 * }
