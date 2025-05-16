<h2><a href="https://leetcode.com/problems/minimum-size-subarray-sum">209. Minimum Size Subarray Sum</a></h2><h3>Medium</h3><hr><p>Given an array of positive integers <code>nums</code> and a positive integer <code>target</code>, return <em>the <strong>minimal length</strong> of a </em><span data-keyword="subarray-nonempty"><em>subarray</em></span><em> whose sum is greater than or equal to</em> <code>target</code>. If there is no such subarray, return <code>0</code> instead.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> target = 7, nums = [2,3,1,2,4,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The subarray [4,3] has the minimal length under the problem constraint.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> target = 4, nums = [1,4,4]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> target = 11, nums = [1,1,1,1,1,1,1,1]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> If you have figured out the <code>O(n)</code> solution, try coding another solution of which the time complexity is <code>O(n log(n))</code>.

---

***<mark>心得:</mark>***

暴力解就是用兩個for枚舉全部的情況，聽說是會超時，程式碼一樣引用代碼隨想錄的
```
		class Solution {
	public:
	    int minSubArrayLen(int s, vector<int>& nums) {
	        int result = INT32_MAX; // 最终的结果
	        int sum = 0; // 子序列的数值之和
	        int subLength = 0; // 子序列的长度
	        for (int i = 0; i < nums.size(); i++) { // 设置子序列起点为i
	            sum = 0;
	            for (int j = i; j < nums.size(); j++) { // 设置子序列终止位置为j
	                sum += nums[j];
	                if (sum >= s) { // 一旦发现子序列和超过了s，更新result
	                    subLength = j - i + 1; // 取子序列的长度
	                    result = result < subLength ? result : subLength;
	                    break; // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
	                }
	            }
	        }
	        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
	        return result == INT32_MAX ? 0 : result;
	    }
	};
```
優化作法是用**滑動窗口**，類似雙指針但他關注的是**兩個指針之間的區間**(這題有包含指針在的位置)，會這麼做是因為題目並不需要我們每次移動終點位置時都再次從頭遍歷。

思想是兩個指針(start,end)都先放在起點，藉由end的位置，讓這個窗口裡的值逐漸變大，當>=target時就更新此時的最小符合長度(result)，然後讓start位置前進的同時更新窗口內的sum值
```
	for(end=0;end<nums.size();end++){
            sum+=nums[end];
            while(sum>=target){
                sublength=end-start+1;//+1是因為index從0開始
                result=min(result,sublength);
                sum-=nums[start++];
            }
        }
```
<mark>簡而言之就是小了就擴大，大了就縮小</mark>，以此來找最小的符合情況

**至於為甚麼start不用回頭**，我的理解是end++之後如果沒滿足，加上那個回頭的start才滿足的話，窗口長度也比之前還長，所以沒這個必要，就不用說end++之後就滿足的情況了，基本上<mark>只長不短</mark>
