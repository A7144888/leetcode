<h2><a href="https://leetcode.com/problems/kids-with-the-greatest-number-of-candies">1528. Kids With the Greatest Number of Candies</a></h2>https://hackmd.io/rfm6CYyoR8CYj2fjj8LmLA<h3>Easy</h3><hr><p>There are <code>n</code> kids with candies. You are given an integer array <code>candies</code>, where each <code>candies[i]</code> represents the number of candies the <code>i<sup>th</sup></code> kid has, and an integer <code>extraCandies</code>, denoting the number of extra candies that you have.</p>

<p>Return <em>a boolean array </em><code>result</code><em> of length </em><code>n</code><em>, where </em><code>result[i]</code><em> is </em><code>true</code><em> if, after giving the </em><code>i<sup>th</sup></code><em> kid all the </em><code>extraCandies</code><em>, they will have the <strong>greatest</strong> number of candies among all the kids</em><em>, or </em><code>false</code><em> otherwise</em>.</p>

<p>Note that <strong>multiple</strong> kids can have the <strong>greatest</strong> number of candies.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> candies = [2,3,5,1,3], extraCandies = 3
<strong>Output:</strong> [true,true,true,false,true] 
<strong>Explanation:</strong> If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> candies = [4,2,1,1,2], extraCandies = 1
<strong>Output:</strong> [true,false,false,false,false] 
<strong>Explanation:</strong> There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> candies = [12,1,12], extraCandies = 10
<strong>Output:</strong> [true,false,true]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == candies.length</code></li>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= candies[i] &lt;= 100</code></li>
	<li><code>1 &lt;= extraCandies &lt;= 50</code></li>
</ul>


---

**<p style="font-size:24px;color:yellow">心得:</p>**
思路應該就那樣:
1. 找最大值
2. `vector<bool>result`用來儲存結果並return
3. 判斷true or false

但我原本code長這樣
```
auto max=max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>max||candies[i]+extraCandies==max){
                return true;
            }
            else{
                return false;
            }
        }
```
會編譯錯誤，問了gpt是因為:
1.返回類型不匹配： 方法應該返回一個vector<bool>類型的結果，但在你的實現中，你嘗試返回bool類型的值。 您應該建構並傳回一個vector<bool> 。

2.max 使用錯誤： 是一個反覆運算器，指向vector中的最大元素。 如果你想比較 和最大值，你需要解引用(*)以獲取最大值。(max_element前面要加 *)

3.錯誤的返回邏輯： 在迴圈中，你對每個元素進行檢查，並在第一次檢查後返回 或 。 這樣，函數只會檢查第一個元素的條件，而不會遍曆整個迴圈 。 你應該在循環結束後返回結果。(也就是返回之後就不繼續跑了)
    
然後記得`vector<bool> result`要在這後面設定他的大小:`vector<bool> result(candies.size())`
