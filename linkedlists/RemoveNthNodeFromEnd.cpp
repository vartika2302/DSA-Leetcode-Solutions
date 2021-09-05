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
    // int length(ListNode*head){
    //     int cnt=0;
    //     while(head!=NULL){
    //         cnt++;
    //         head=head->next;
    //     }
    //     return cnt;
    // }
    ListNode* removeNthFromEnd(ListNode* &head, int n) {
        //Brute force
        // int l=length(head);
        // if(n==l){
        //     head=head->next;
        //     return head;
        // }
        // ListNode*temp=head;
        // int times=(l-n-1);
        // while(times--){
        //     temp=temp->next;
        // }
        // temp->next=temp->next->next;
        // return head;

        //Runner Technique
        ListNode*slow=head;
        ListNode*fast=head;
        while(n--){
            fast=fast->next;
        }
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(fast==NULL){
            return head->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
