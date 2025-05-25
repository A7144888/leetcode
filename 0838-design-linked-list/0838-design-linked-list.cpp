class MyLinkedList {

public:
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(nullptr){}
    };
    
    MyLinkedList() {
        dummyHead=new LinkedNode(0);//虛擬頭節點
        size=0;
    }
    
    int get(int index) {
        if(index>(size-1)||index<0) return -1;
        
        LinkedNode* cur=dummyHead->next;
        
        while(index--){
            cur=cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode=new LinkedNode(val);
        newNode->next=dummyHead->next;
        dummyHead->next=newNode;
        size++;
    }
    
    void addAtTail(int val) {    
        LinkedNode* newNode=new LinkedNode(val);
        LinkedNode* cur=dummyHead;
        while(cur->next!=nullptr){
            cur=cur->next;//讓cur走到最後面
        }
        cur->next=newNode;
        size++;
        
    }
    
    void addAtIndex(int index, int val) {
        if (index>size)return;
        if(index<0)index=0;//插在頭
        
        LinkedNode* newNode=new LinkedNode(val);
        LinkedNode* cur=dummyHead;
        while(index--){
            cur=cur->next;//讓cur走到第index個
        }
        newNode->next=cur->next;
        cur->next=newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>(size-1)||index<0)return;
        LinkedNode* cur=dummyHead;
        while(index--){
            cur=cur->next;//讓cur走到第index個
        }
        LinkedNode* tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
        tmp=nullptr;//delete只會釋放記憶體 要手動把指針設成NULL 不然會變野指針
        size--;
    }
        /*void printLinkedList(){
            LinkedNode* cur=dummyHead;
            while(cur->next!=nullptr){
                cout<<cur->next->val<<" ";
                cur=cur->next;
            }
            cout<<endl;
        }*/
private:
    int size;
    LinkedNode* dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */