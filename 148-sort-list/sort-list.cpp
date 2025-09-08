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

 // Function to find the middle node of the linked list
    ListNode*middleNode(ListNode*head){
          ListNode*slow=head;
          ListNode*fast=head;
          
          while(fast->next!=NULL && fast->next->next!=NULL){
              slow=slow->next;
              fast=fast->next->next;
          }
          return slow;
    }
      
    ListNode*mergeSortedList(ListNode*p1, ListNode*p2){
        
        // If either list is empty, return the other
        if (p1 == NULL || p2 == NULL) {
            return (p1 == NULL) ? p2 : p1;
        }
          
         ListNode*dummyNode=new ListNode(0);
         ListNode*current=dummyNode;
          
          while(p1!=NULL && p2!=NULL){
            if(p1->val < p2->val) {
                current->next = p1;
                p1 = p1->next;
            }
            else {
                current->next = p2;
                p2 = p2->next;
            }
               current = current->next;
          }
          
          
        // Attach remaining nodes (only one of these will run)
          if(p1 != NULL) current->next = p1;
          if(p2 != NULL) current->next = p2;
          
        return dummyNode->next; // return merged list
    }

    ListNode* sortList(ListNode* head) {
       // Base case: 0 or 1 node → already sorted
        if(head==NULL || head->next==NULL) return head;
        
        ListNode*mid=middleNode(head); // Find middle node
        ListNode*newHead=mid->next;
        mid->next=NULL;
        
        // Recursive sort on both halves
        ListNode*leftHalf=sortList(head);
        ListNode*rightHalf=sortList(newHead);
        
        // Merge sorted halves
        return mergeSortedList(leftHalf,rightHalf);
    }
};