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
    void add(int val, ListNode*& head, ListNode*& tail) {
        ListNode* newNode = new ListNode(val);
        if(!head) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        multiset<int> st;
        for(auto& it: lists) {
            while(it) {
                st.insert(it->val);
                it = it->next;
            }
        }
        for(auto& it: st) {
            add(it, head, tail);
        }
        return head;
    }
};