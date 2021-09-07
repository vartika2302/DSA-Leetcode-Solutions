/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode*head){
        int cnt=0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int na=length(headA);
        int nb=length(headB);
        int diff=abs(na-nb);
        ListNode*tempA=headA;
        ListNode*tempB=headB;
        if(na>nb){
            while(diff--){
                tempA=tempA->next;
            }
        }
        else if(na<nb){
            while(diff--){
                tempB=tempB->next;
            }
        }
        ListNode* ans=NULL;
        while(tempA!=NULL && tempB!=NULL){
            if(tempA==tempB){
                ans=tempA;
                break;
            }
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return ans;

        //another approach
        // ListNode*tempA=headA;
        // ListNode*tempB=headB;
        // while(tempA!=tempB){
        //     tempA=(tempA)?(tempA->next):headB;
        //     tempB=(tempB)?(tempB->next):headA;
        // }
        // return tempA;

    }
};
