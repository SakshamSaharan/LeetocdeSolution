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
        if(head == NULL || head->next == NULL) return head;
        ListNode* sz = head;
        int size = 0;
        while(sz != NULL){
            size++;
            sz = sz->next;
        }
        k = k%size;
        while(k > 0){
            ListNode* temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
                ListNode* front = temp->next;
                front->next = head;
                head = front;
                temp->next = NULL;
                k--;
        }
        return head;
    }
};