<h2><a href="https://leetcode.com/problems/greatest-common-divisor-of-strings">1146. Greatest Common Divisor of Strings</a></h2><h3>Easy</h3><hr><p>For two strings <code>s</code> and <code>t</code>, we say &quot;<code>t</code> divides <code>s</code>&quot; if and only if <code>s = t + t + t + ... + t + t</code> (i.e., <code>t</code> is concatenated with itself one or more times).</p>

<mark>這個i.e.很重要</mark>

<p>Given two strings <code>str1</code> and <code>str2</code>, return <em>the largest string </em><code>x</code><em> such that </em><code>x</code><em> divides both </em><code>str1</code><em> and </em><code>str2</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> str1 = &quot;ABCABC&quot;, str2 = &quot;ABC&quot;
<strong>Output:</strong> &quot;ABC&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> str1 = &quot;ABABAB&quot;, str2 = &quot;ABAB&quot;
<strong>Output:</strong> &quot;AB&quot;
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> str1 = &quot;LEET&quot;, str2 = &quot;CODE&quot;
<strong>Output:</strong> &quot;&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= str1.length, str2.length &lt;= 1000</code></li>
	<li><code>str1</code> and <code>str2</code> consist of English uppercase letters.</li>
</ul>


---

<p style="font-size:24px,color:yellow"> 心得: </p>
<p>因為有提到(t is concatenated with itself one or more times)，也就是不會有其他字元，所以可以用 <b style="color: yellow;">str1+str2是否為str2+str1來檢驗，如果!=就代表沒有gcd，反之則有</b>，而輸出gcd的方式就是任一<code>str.substr(0,Gcd);</code> ，而變數Gcd=gcd(size(str1),size(str2))</p>
