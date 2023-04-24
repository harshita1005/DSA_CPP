 
class Solution {
public:
     TreeNode* convertToBST(ListNode* start, ListNode* end){

         //reached the leaf nodes
         if(start == end){
             return NULL;
         }
         //Traversing the LL to find the mid by using fast and slow pointers
         ListNode* fast=start;
         ListNode* slow=start;

         if(fast!=end && fast->next!=end){
            slow = slow->next;
            fast = fast->next->next;
        }
        //Recursively building left and right subtree
        TreeNode* head = new TreeNode(slow->val);    //creating a new node for mid value (slow indicate mid value)
        head->left = convertToBST(start, slow);
        head->right = convertToBST(slow->next, end);
        return head;

     }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        return convertToBST(head,NULL);
        
    }
};
