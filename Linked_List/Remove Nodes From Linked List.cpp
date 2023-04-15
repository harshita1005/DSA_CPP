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
    ListNode* reverse(ListNode* head){

        ListNode* curr= head;
        ListNode* prev= NULL;
        ListNode* next= NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {

        //first reverse the list
        head= reverse(head);
        ListNode* curr= head;
        int maxi= head->val;
        ListNode* prev=head;
        head=head->next;

        while(head!=NULL){

            if(maxi <= head->val){   //right side is smaller , add that node
                  maxi= head->val;
                  prev= head;
                  head=head->next;
            }
            else{        //delete that node and point to next node
            prev->next=head->next;
            head=prev->next;

            }
        }
        head=reverse(curr);
        return head;
        
    }
};
