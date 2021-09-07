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
    ListNode* midPoint(ListNode* head){
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reverseLL(ListNode*&head){
        ListNode*curr=head;
        ListNode*nex;
        ListNode*prev=NULL;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        head=prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*mid=midPoint(head);
        ListNode*temp1=head;
        ListNode*temp2=mid->next;
        reverseLL(temp2);
        mid->next=NULL;
        while(temp2!=NULL){
            if(temp1->val!=temp2->val){
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;

        }
        return true;
    }
};
