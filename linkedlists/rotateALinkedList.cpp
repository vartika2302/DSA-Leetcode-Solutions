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
    ListNode* rotateRight(ListNode* head, int k) {
       /* naive approach */
       /* Time complexity: O(n*k) */
       /* Space complexity: O(1)*/

        // if(head==NULL || head->next==NULL || k==0){
        //     return head;
        // }
        // int len=0;
        // ListNode*lenn=head;
        // while(lenn!=NULL){
        //     len++;
        //     lenn=lenn->next;
        // }
        // k=k%len;
        // while(k--){
        //     ListNode*prev=NULL;
        // ListNode*curr=head;
        // while(curr->next!=NULL){
        //     prev=curr;
        //     curr=curr->next;
        // }
        // prev->next=NULL;
        // curr->next=head;
        //     head=curr;
        // }
        // return head;

        /* Optimised approach*/
        /* Time complexity: O(n)+O(n-(k%n))*/
        /* Space complexity: O(1)*/
        if(head==NULL || head->next==NULL){
            return head;
        }
        int len=1;
        ListNode*lenn=head;
        while(lenn->next!=NULL){
            len++;
            lenn=lenn->next;
        }
        lenn->next=head;
        ListNode*temp=head;
        k=len-(k%len)-1;
        while(k--){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;

    }
};
