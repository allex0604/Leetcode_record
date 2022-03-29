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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)return head;
        ListNode* pre = head;
        ListNode* curr = head;
        while(curr != NULL){
            if(curr->val == pre->val){
                if(curr == pre){
                    curr = curr->next;
                }
                else{
                    curr = curr->next;
                    pre->next = curr;   
                }
            }
            else{
                curr = curr->next;
                pre = pre->next;
            }
        }
        return head;
    }
};