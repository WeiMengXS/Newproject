truct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    int Getlength(ListNode* pHead)
    {
        int len=0;
        ListNode* pNode=pHead;
        while(pNode)
        {
            ++len;
            pNode=pNode->next;
        }
        return len;
    }
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1=Getlength(pHead1);
        int len2=Getlength(pHead2);
        int n=len1-len2;
        
        ListNode* Long=pHead1;
        ListNode* Short=pHead2;
        
        if(len2>len1)
        {
            Long=pHead2;
            Short=pHead1;
            n=len2-len1;
        }
        
        while(n--)
        {
            Long=Long->next;
        }
        while((Long!=nullptr)&&(Short!=nullptr)
             &&(Long!=Short))
        {
            Long=Long->next;
            Short=Short->next;

        }
        return Long;
    }
};
