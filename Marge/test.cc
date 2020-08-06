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
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
        {
                  if(pHead1==NULL)
                                return pHead2;
                          if(pHead2==NULL)
                                        return pHead1;
                                  ListNode* head=NULL;
                                          ListNode* tail=NULL;
                                                  while(pHead1&&pHead2)
                                                  {
                                                                ListNode* p=pHead1->val<pHead2->val?pHead1:pHead2;
                                                                            if(p==pHead1)
                                                                            {
                                                                                              pHead1=pHead1->next;
                                                                                                          
                                                                            }
                                                                                        else
                                                                                        {
                                                                                                          pHead2=pHead2->next;
                                                                                                                      
                                                                                        }
                                                                                                    if(head==NULL)
                                                                                                    {
                                                                                                                      head=p;
                                                                                                                                      tail=p;
                                                                                                                                                  
                                                                                                    }
                                                                                                                else
                                                                                                                {
                                                                                                                                  tail->next=p;
                                                                                                                                                  tail=p;
                                                                                                                                                              
                                                                                                                }
                                                                                                                            
                                                                                                                            
                                                                                                                        
                                                  }
                                                          
                                                          if(pHead1==NULL)
                                                          {
                                                                        tail->next=pHead2;
                                                                                
                                                          }
                                                                  else if(pHead2==NULL)
                                                                  {
                                                                                tail->next=pHead1;
                                                                                        
                                                                  }
                                                                              
                                                                          return head;
                                                                              
        }

};
 *            }
 * }
