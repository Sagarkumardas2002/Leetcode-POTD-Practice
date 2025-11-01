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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Step1: Store the nums in a set
        set<int> st;
        for (auto& it : nums) {
            st.insert(it);
        }

        // Step2:  Create  dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step3: Use prev and current pointer
        ListNode* current = head;
        ListNode* prev = dummy;

        while (current) {
            // If we have to skip the node
            if (st.find(current->val) != st.end()) {
                prev->next = current->next;
            } else {
                // When we have to keep the node in the list
                prev = current;
            }
            current = current->next;
        }
        // Step4: return the new head
        return dummy->next;
    }
};