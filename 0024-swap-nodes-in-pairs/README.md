<h2><a href="https://leetcode.com/problems/swap-nodes-in-pairs">24. Swap Nodes in Pairs</a></h2><h3>Medium</h3><hr><p>Given a&nbsp;linked list, swap every two adjacent nodes and return its head. You must solve the problem without&nbsp;modifying the values in the list&#39;s nodes (i.e., only nodes themselves may be changed.)</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">head = [1,2,3,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">[2,1,4,3]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg" style="width: 422px; height: 222px;" /></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">head = []</span></p>

<p><strong>Output:</strong> <span class="example-io">[]</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">head = [1]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1]</span></p>
</div>

<p><strong class="example">Example 4:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">head = [1,2,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">[2,1,3]</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the&nbsp;list&nbsp;is in the range <code>[0, 100]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
</ul>

***<mark>心得</mark>***

用dummyHead處理會比較輕鬆，不用分頭或非頭節點的情況，用文字有點難說，引用一下代碼隨想錄的圖片

![68747470733a2f2f66696c65312e6b616d61636f6465722e636f6d2f692f616c676f2f32342e254534254238254134254534254238254134254534254241254134254536253844254132254539253933254245254538254131254138254534254238254144254537253941253834 (1)](https://github.com/user-attachments/assets/bc82a104-694c-4c67-95b7-fbdf560851d5)


![68747470733a2f2f66696c65312e6b616d61636f6465722e636f6d2f692f616c676f2f32342e2545342542382541342545342542382541342545342542412541342545362538442541322545392539332542452545382541312541382545342542382541442545372539412538342545](https://github.com/user-attachments/assets/78a5763e-9603-4ef6-a966-2d8819662c58)

可以看到步驟一會把2的連接斷掉，而步驟二會把3的連接斷掉，所以要

```
	ListNode* tmp1=cur->next;
	ListNode* tmp2=cur->next->next->next;//記錄當下的節點
```

判斷條件是下一個和下下一個都不是nullptr就交換，交換完就把cur前進兩步

```
while(cur->next!=nullptr&&cur->next->next!=nullptr){
            ListNode* tmp1=cur->next;
            ListNode* tmp2=cur->next->next->next;//記錄當下的節點

            cur->next=cur->next->next;
            cur->next->next=tmp1;
            cur->next->next->next=tmp2;

            cur=cur->next->next;
        }
```
最後回傳的是dummyHead->next，因為head已經被移動了，這樣寫比較無腦

```
 	ListNode* result=dummyHead->next;
        return result;//需要用dummyHead->next代表頭節點，因為原本的head已經不在原位
```

