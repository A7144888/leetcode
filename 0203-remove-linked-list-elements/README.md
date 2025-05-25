<h2><a href="https://leetcode.com/problems/remove-linked-list-elements">203. Remove Linked List Elements</a></h2><h3>Easy</h3><hr><p>Given the <code>head</code> of a linked list and an integer <code>val</code>, remove all the nodes of the linked list that has <code>Node.val == val</code>, and return <em>the new head</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg" style="width: 500px; height: 142px;" />
<pre>
<strong>Input:</strong> head = [1,2,6,3,4,5,6], val = 6
<strong>Output:</strong> [1,2,3,4,5]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [], val = 1
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> head = [7,7,7,7], val = 7
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 50</code></li>
	<li><code>0 &lt;= val &lt;= 50</code></li>
</ul>

***<mark>心得:</mark>***

刪除節點就是**把指到下一個的箭頭改成指到下下一個，然後delete掉要刪除的node**

用虛擬頭節點的方式可以不管是不是頭節點，用同樣的方式實作每個節點，然後最後要return的是**頭節點**

```
	ListNode* dummyhead=new ListNode(0);
	dummyhead->next=head;//建立實際指向頭指針的虛擬頭指針
```

刪除過程
```
	ListNode* cur=dummyhead;//要刪的是指到的下一個，所以是=dummyhead
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
```
結束記得把dummyHead刪掉
```
        delete dummyhead;
```

下面是不用虛擬頭節點的方式，會需要分成頭和非頭節點，程式碼一樣源自代碼隨想錄
```
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
```
