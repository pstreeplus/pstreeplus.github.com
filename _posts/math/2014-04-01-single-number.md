---
layout: post
title: single number
category: math
tags: [intro, math]
---

今天看到一个问题：

>Given an array of integers, every element appears twice except for one. Find that single one.

本能的想法是建立一个数组a[]，每个元素初始化为0，如果数字x出现，就让a[x]+=1。但是很多时候内存消耗太大了，因为x可以很大。

另一个想法是把所有数字保存到数组a中，然后排序，最后线性扫描一遍找出答案。比之前的方法更可行，但是我发现还有更好的方法。

这个方法需要运用位运算的知识。思路就是每位bit出现2次就清零，所以可以不断异或运算得出最终结果。

<style type="text/css">
.Number { color: #ae81ff; }
.Statement { color: #f92672; font-weight: bold; }
.Type { color: #66d9ef; }
.Repeat { color: #f92672; font-weight: bold; }
</style>

<pre id='vimCodeElement' style=" font-family: monospace; color: #f8f8f2; background-color: #1b1d1e; ">
<span class="Type">int</span> singleNumber(<span class="Type">int</span> A[], <span class="Type">int</span> n) {
    <span class="Type">int</span> ans = <span class="Constant">0</span>;
    <span class="Statement">for</span> (<span class="Type">int</span> i = <span class="Constant">0</span>; i &lt; n; i++) ans ^= A[i];
    <span class="Statement">return</span> ans;
}
</pre>

类似的问题还有很多，比如下面这个，稍微比之前的更难一些：

>Given an array with N integers where all elements appear three times except for one. Find out the one which appears only once.N($1\le N\le { 10 }^{ 5 }$),All elements are ranged in $\left[ 0,{ 2 }^{ 63 }-1 \right]$ .


对于每个二进制位，如果出现次数是3的倍数，就将其清零，剩下的就是最终的数。

用ones记录到当前计算的变量为止，二进制1出现“1次”的数位。用twos记录到当前计算的变量为止，二进制1出现“2次”的数位。当ones和twos中的某一位同时为1时表示二进制1出现3次，此时需要清零。最终ones记录的是最终结果。

<pre id='vimCodeElement' style=" font-family: monospace; color: #f8f8f2; background-color: #1b1d1e; ">
<span class="Type">int</span> singleNumber(<span class="Type">int</span> A[], <span class="Type">int</span> n) {
    <span class="Type">int</span> ones = <span class="Number">0</span>, twos = <span class="Number">0</span>, xthrees = <span class="Number">0</span>;
    <span class="Repeat">for</span>(<span class="Type">int</span> i = <span class="Number">0</span>; i &lt; n; ++i) {
        twos |= (ones &amp; A[i]);
        ones ^= A[i];
        xthrees = ~(ones &amp; twos);
        ones &amp;= xthrees;
        twos &amp;= xthrees;
    }

    <span class="Statement">return</span> ones;
}
</pre>




