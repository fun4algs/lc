/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head == nullptr) return head;
        unordered_set<int>_us{head->val};
        ListNode* pre = head, cur = nullptr;
        while(pre->next != nullptr){
            cur = pre->next;
            if(_us.find(cur->val) != _us.end())
                pre->next = pre->next->next;
            else{
                _us.insert(cur->val);
                pre = cur;
            }
        }
        return head;
    }
};
