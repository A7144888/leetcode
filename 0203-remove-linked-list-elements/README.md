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

---
***<mark>心得:</mark>***

有兩種解法:
1.分成頭跟非頭節點兩種刪除方式(一樣源自代碼隨想錄 我懶得打)
```
	// 删除头结点，把下一個叫做head然後刪掉自己
        while (head != NULL && head->val == val) { // 注意这里不是if
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        // 删除非头结点，直接指到下下一個
        ListNode* cur = head;
        while (cur != NULL && cur->next!= NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
```

2.創建一個虛擬頭節點，指到頭節點，這樣所有節點都是**用非頭節點的方式刪除**

(學習之後自己寫的code)
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
        delete dummyhead;//用完要記得刪除
        return head;
```
時間複雜度： O（n）
空間複雜度： O（1）
兩個都是

註解是我覺得要注意的地方和知識點，就不重打了
