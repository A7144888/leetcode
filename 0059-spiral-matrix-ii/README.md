<h2><a href="https://leetcode.com/problems/spiral-matrix-ii">59. Spiral Matrix II</a></h2><h3>Medium</h3><hr><p>Given a positive integer <code>n</code>, generate an <code>n x n</code> <code>matrix</code> filled with elements from <code>1</code> to <code>n<sup>2</sup></code> in spiral order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> [[1,2,3],[8,9,4],[7,6,5]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> [[1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
</ul>

---

***<mark>心得:</mark>***

蠻腦力激盪的一題，主要是**照著統一的規則移動**，像我就用左閉右開區間 **[頭,尾)**，也就是每邊都處理到尾的前一個，然後把尾當成另一邊的頭，最後就能接成一圈。
值得注意的點我覺得有3點

1.每圈要走的格數不同，offset的用處就是在這裡

2.n為奇數的話要別處裡中間那格

3.走的圈數為n/2
