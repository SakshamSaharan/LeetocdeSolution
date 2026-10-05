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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next == NULL){
            return NULL;
        }
            ListNode* slow = head;
            ListNode* fast = head;
            for(int i=0;i<n;i++){
                fast = fast->next;
            }
            if(fast == NULL){
                ListNode* remove = head;
                head = head->next;
                delete remove;
                return head;
            }
            while(fast->next != NULL){
                slow = slow->next;
                fast = fast->next;
            }

            ListNode* remove = slow->next;
            slow->next = slow->next->next;
            remove->next = NULL;
            delete remove;
            return head;
    }
};