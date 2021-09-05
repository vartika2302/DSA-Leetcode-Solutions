/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1=l1;
        ListNode*temp2=l2;
        int carry=0;
         int sum=0;
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        while(temp1!=NULL || temp2!=NULL){
           sum=0;
            if(temp1){
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2){
                sum+=temp2->val;
                temp2=temp2->next;
            }
            sum+=carry;
            carry=(sum>9)?1:0;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
        }
        if(carry){
            temp->next=new ListNode(1);
            temp=temp->next;
        }
        temp->next=NULL;
        return dummy->next;
    }
};
