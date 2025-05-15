<h2><a href="https://leetcode.com/problems/squares-of-a-sorted-array">1019. Squares of a Sorted Array</a></h2><h3>Easy</h3><hr><p>Given an integer array <code>nums</code> sorted in <strong>non-decreasing</strong> order, return <em>an array of <strong>the squares of each number</strong> sorted in non-decreasing order</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [-4,-1,0,3,10]
<strong>Output:</strong> [0,1,9,16,100]
<strong>Explanation:</strong> After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [-7,-3,2,3,11]
<strong>Output:</strong> [4,9,9,49,121]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code><span>1 &lt;= nums.length &lt;= </span>10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> is sorted in <strong>non-decreasing</strong> order.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Squaring each element and sorting the new array is very trivial, could you find an <code>O(n)</code> solution using a different approach?

---

***<mark>心得:</mark>***

暴力法很直觀，就是for迴圈裡面把每個都平方，結束迴圈後sort，時間複雜度是O(nlogn)

優化的寫法也是用雙指針，和上題不一樣的是這題要把**兩個指針分別設在頭尾來比較誰大**(因為題目是把數字降序排列，所以平方後最大值不是最前就是在最後)
```
	vector<int> result(nums.size());
        int k=nums.size()-1;//-1是因為最大index=容量-1(從0開始數的關係)
        for(int head=0,tail=nums.size()-1;head<=tail; ){
            if(pow(nums[head],2)>pow(nums[tail],2)){
                result[k--]=(pow(nums[head],2));
                head++;
            }
            else{
                result[k--]=(pow(nums[tail],2));
                tail--;
            }
        }
```
時間複雜度變成O(n)

小細節是要從後存進新array，因為要由小到大排，而我們找大的放進去，所以要讓`k=nums.size()-1;`來從尾放到頭，如果是找小的放進去**有可能因為負數平方後的大小導致順序錯誤**，最後一樣得sort，跟沒優化一樣

##### btw原本想用push_front的，但撇開array裡會有一堆0不談，這東西vector不給用，又學到了。 #####
