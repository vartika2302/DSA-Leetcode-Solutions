
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //using hashmap- Brute force
        //time complexity: O(n)+O(n)
        //space complexity: O(n)

        // map<Node*,Node*>m;
        // Node*temp=head;
        // while(temp){
        //     m[temp]=new Node(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp){
        //     m[temp]->next=m[temp->next];
        //     m[temp]->random=m[temp->random];
        //     temp=temp->next;
        // }
        // return m[head];

        /*--------------------------------------------*/

        //Optimised approach
        //Time complexity: O(n)+O(n)+O(n)=O(3*n)==O(n)
        //Space complexity: O(1)

        Node*temp=head,*front=head;
        while(temp){
            Node* copy=new Node(temp->val);
            front=temp->next;
            temp->next=copy;
            copy->next=front;
            temp=front;
        }
        temp=head;
        while(temp){
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        temp=head;
        Node*pseudoNode=new Node(0);
        Node*copyNode=pseudoNode;
        while(temp){
            front=temp->next->next;
            copyNode->next=temp->next;
            temp->next=front;
            copyNode=copyNode->next;
            temp=front;
        }
        return pseudoNode->next;

    }
};
