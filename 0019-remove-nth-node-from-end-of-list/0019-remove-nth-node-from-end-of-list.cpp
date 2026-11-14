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
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        int upto = cnt-n;
        if(upto == 0){
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        temp = head;
        for(int i=0;i<upto-1;i++){
            temp = temp->next;
        }
        ListNode* remove = temp->next;
        temp->next = remove->next;
        delete remove;
        return head;
    }
};