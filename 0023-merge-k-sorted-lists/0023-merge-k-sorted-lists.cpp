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
    struct compVal{
        bool operator () (ListNode* first,ListNode* second){
            return first->val > second->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compVal>pq;
        for(ListNode* head : lists){
            if(head != NULL){
                pq.push(head);
            }
        }
        ListNode* newNode = new ListNode(-1);
        ListNode* temp = newNode;
        while(! pq.empty()){
            ListNode* smallest = pq.top();
            pq.pop();
            temp->next = smallest;
            temp = temp->next;
            if(smallest->next != nullptr){
                pq.push(smallest->next);
            }
        }
        temp->next = nullptr;
        return newNode->next;
    }
};