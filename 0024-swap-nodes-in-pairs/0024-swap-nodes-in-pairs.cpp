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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode* cur=dummyHead;
        while(cur->next!=nullptr&&cur->next->next!=nullptr){
            ListNode* tmp1=cur->next;
            ListNode* tmp2=cur->next->next->next;//記錄當下的節點

            cur->next=cur->next->next;
            cur->next->next=tmp1;
            cur->next->next->next=tmp2;

            cur=cur->next->next;
        }
        ListNode* result=dummyHead->next;
        return result;//需要用dummyHead->next代表頭節點，因為原本的head已經不在原位
    }
};