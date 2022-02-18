#include "bits/stdc++.h"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseL(ListNode* head, int k, int len){
        if(len < k)return head;
        ListNode* pre = nullptr;
        ListNode* cur;
        ListNode* rec = head;
        for(int i = 0;i < k;++i){
            cur = head;
            head = head->next;
            cur->next = pre;
            pre = cur;
        }
        rec->next = reverseL(head, k, len-k);
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;
        while(cur){
            cur = cur->next;
            len++;
        }
        return reverseL(head, k, len);
    }
};