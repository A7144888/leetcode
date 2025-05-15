<h2><a href="https://leetcode.com/problems/remove-element">27. Remove Element</a></h2><h3>Easy</h3><hr><p>Given an integer array <code>nums</code> and an integer <code>val</code>, remove all occurrences of <code>val</code> in <code>nums</code> <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank"><strong>in-place</strong></a>. The order of the elements may be changed. Then return <em>the number of elements in </em><code>nums</code><em> which are not equal to </em><code>val</code>.</p>

<p>Consider the number of elements in <code>nums</code> which are not equal to <code>val</code> be <code>k</code>, to get accepted, you need to do the following things:</p>

<ul>
	<li>Change the array <code>nums</code> such that the first <code>k</code> elements of <code>nums</code> contain the elements which are not equal to <code>val</code>. The remaining elements of <code>nums</code> are not important as well as the size of <code>nums</code>.</li>
	<li>Return <code>k</code>.</li>
</ul>

<p><strong>Custom Judge:</strong></p>

<p>The judge will test your solution with the following code:</p>

<pre>
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i &lt; actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
</pre>

<p>If all assertions pass, then your solution will be <strong>accepted</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,2,3], val = 3
<strong>Output:</strong> 2, nums = [2,2,_,_]
<strong>Explanation:</strong> Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,2,2,3,0,4,2], val = 2
<strong>Output:</strong> 5, nums = [0,1,4,0,3,_,_,_]
<strong>Explanation:</strong> Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 50</code></li>
	<li><code>0 &lt;= val &lt;= 100</code></li>
</ul>

---

***<mark>心得</mark>***

一開始想用
```
	for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
             nums.erase(nums.begin() + i) ;
            } 
        }
```
後來run了一次才發現碰到連續==val時會因為i++了而下一個val值不在原本的index的情況
###### btw順便學到erase會改變大小不改變容量，remove則都不變，算是意外的收穫吧

原本的想法是暴力解，爬文得知這樣能過但複雜度太高，懶得多寫引用一下代碼隨想錄的
```
	// 时间复杂度：O(n^2)
	// 空间复杂度：O(1)
	class Solution {
	public:
	    int removeElement(vector<int>& nums, int val) {
	        int size = nums.size();
	        for (int i = 0; i < size; i++) {
	            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
	                for (int j = i + 1; j < size; j++) {
	                    nums[j - 1] = nums[j];
	                }
	                i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
	                size--; // 此时数组的大小-1
	            }
	        }
	        return size;
	
	    }
	};
```
也是看了他的講解才知道可以用雙指針，在這題長這樣
```
	int fast,slow;
	for(fast=0,slow=0;fast<nums.size();fast++){
		if(nums[fast]!=val){
			nums[slow]=nums[fast];
			slow++;
		}
	 }
	return slow;
```
時間複雜度O(n)、空間複雜度O(1)
核心思想就是用fast slow兩個指<mark>分別遍歷array中每個元素和作為新的array的下標，只是都在這個nums[]上執行而已</mark>，這段的意思是把 ***「把其中的val值刪掉」反向想成「留下不是val值的元素」***，並把這些元素給到新的array，也就是用slow作為下標來維護的array。
