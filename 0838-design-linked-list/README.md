<h2><a href="https://leetcode.com/problems/design-linked-list">707. Design Linked List</a></h2><h3>Medium</h3><hr><p>Design your implementation of the linked list. You can choose to use a singly or doubly linked list.<br />
A node in a singly linked list should have two attributes: <code>val</code> and <code>next</code>. <code>val</code> is the value of the current node, and <code>next</code> is a pointer/reference to the next node.<br />
If you want to use the doubly linked list, you will need one more attribute <code>prev</code> to indicate the previous node in the linked list. Assume all nodes in the linked list are <strong>0-indexed</strong>.</p>

<p>Implement the <code>MyLinkedList</code> class:</p>

<ul>
	<li><code>MyLinkedList()</code> Initializes the <code>MyLinkedList</code> object.</li>
	<li><code>int get(int index)</code> Get the value of the <code>index<sup>th</sup></code> node in the linked list. If the index is invalid, return <code>-1</code>.</li>
	<li><code>void addAtHead(int val)</code> Add a node of value <code>val</code> before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.</li>
	<li><code>void addAtTail(int val)</code> Append a node of value <code>val</code> as the last element of the linked list.</li>
	<li><code>void addAtIndex(int index, int val)</code> Add a node of value <code>val</code> before the <code>index<sup>th</sup></code> node in the linked list. If <code>index</code> equals the length of the linked list, the node will be appended to the end of the linked list. If <code>index</code> is greater than the length, the node <strong>will not be inserted</strong>.</li>
	<li><code>void deleteAtIndex(int index)</code> Delete the <code>index<sup>th</sup></code> node in the linked list, if the index is valid.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;MyLinkedList&quot;, &quot;addAtHead&quot;, &quot;addAtTail&quot;, &quot;addAtIndex&quot;, &quot;get&quot;, &quot;deleteAtIndex&quot;, &quot;get&quot;]
[[], [1], [3], [1, 2], [1], [1], [1]]
<strong>Output</strong>
[null, null, null, null, 2, null, 3]

<strong>Explanation</strong>
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1-&gt;2-&gt;3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1-&gt;3
myLinkedList.get(1);              // return 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= index, val &lt;= 1000</code></li>
	<li>Please do not use the built-in LinkedList library.</li>
	<li>At most <code>2000</code> calls will be made to <code>get</code>, <code>addAtHead</code>, <code>addAtTail</code>, <code>addAtIndex</code> and <code>deleteAtIndex</code>.</li>
</ul>

***<mark>心得:</mark>***

***這是第707.!***

第一次遇到這情況害我以為LeetHub沒抓到，搞了好久結果是題號不對，真邪門。

這題要做的事情蠻多的，但基本上能分為:**1.查2.增3.刪**三種，

還有就是這題要自己寫LinkedList的struct跟初始化，初始化時要**建立虛擬頭節點**

以及記得size(條件檢查時使用)要做++或--
```
struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(nullptr){}
 };
    
 MyLinkedList() {
        dummyHead=new LinkedNode(0);//虛擬頭節點
        size=0;
 }
```

**查**

先走到那個index再返回他的值

走到第index個node的方法就是**每往前就把index-1**(這邊一定要index--而不是--index，執行的順序問題)

也可以用for來做，總之能到就行。**到了之後直接return值**就好
```
int get(int index) {
        if(index>(size-1)||index<0) return -1;//檢查是否超出範圍
        
        LinkedNode* cur=dummyHead->next;
        
        while(index--){
            cur=cur->next;
        }
        return cur->val;
}
```

**增**

這題分三種add:加在<mark>頭、尾和特定index</mark>

加在頭就是把新節點指到虛擬頭節點的下一個，再把虛擬頭節點指到新節點，可以看到順序不能反過來

```
	newNode->next=dummyHead->next;
        dummyHead->next=newNode;
```

尾是把最後面的節點指到新節點，但要用`cur`先走到最後的節點

```
	LinkedNode* cur=dummyHead;
        while(cur->next!=nullptr){
            cur=cur->next;//讓cur走到最後面
        }
        cur->next=newNode;
```

特定index則是把新節點指到原本的下一個，再把原本的節點指到新節點，一樣先走到index

```
	LinkedNode* cur=dummyHead;
        while(index--){
            cur=cur->next;//讓cur走到第index個
        }
        newNode->next=cur->next;
        cur->next=newNode;
```

**刪**

跟203.差不多，只是改成了刪除對應index的節點，先用一個tmp紀錄當前的下一個，待會要用他刪掉，然後把指到下一個改成指到下下一個

```
	LinkedNode* tmp=cur->next;
	cur->next=cur->next->next;
        delete tmp;
        tmp=nullptr;//delete只會釋放記憶體 要手動把指針設成NULL 不然會變野指針
```
