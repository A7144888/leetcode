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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyhead=new ListNode(0);
        dummyhead->next=head;//建立實際指向頭指針的虛擬頭指針
        ListNode* cur=dummyhead;//要刪的是指到的下一個所以是=dummyhead
        while(cur->next !=NULL){
            if(cur->next->val==val){
                ListNode* tmp=cur->next;
                cur->next=cur->next->next;
                delete tmp;//利用同樣指到cur->nxet的tmp指針來刪除cur->nxet的記憶體位置
            }
            else{
                cur=cur->next;//有請下面一位
            }
        }
        head=dummyhead->next;
        delete dummyhead;
        return head;
    }
};