---
layout : post
category : coding
title : 集合的整数表示
tags: [design, web, css, HTML5]
description: "在程序中表示集合的方法有很多种，当元素比较少时，用二进制码来表示比较方便。集合{0,1,...n-1}的子集S可以用如下方式编码成整数。"
---

在程序中表示集合的方法有很多种，当元素比较少时，用二进制码来表示比较方便。集合{0,1,...n-1}的子集S可以用如下方式编码成整数。

![pict001](/images/20140226/001.png)

像这样之后，一些集合运算可以对应写成如下方式。

<style type="text/css">
table, td, th { border:1px solid #333; }
</style>
<table style="border: 1px solid #333;border-collapse:collapse;">
<tr>
<td style="width: 20em">空集<img src="/images/20140226/002.png" /></td>
<td style="width: 20em; text-align: center;">0</td>
</tr>
<tr>
<td>只含有第i个元素的集合{i}</td>
<td style="text-align: center">1&lt;&lt;i</td>
</tr>
<tr>
<td>含有全部n个元素的集合{0,1,...,n-1}</td>
<td style="text-align: center">(1&lt;&lt;n)-1</td>
</tr>
<tr>
<td>判断第i个元素是否属于集合S</td>
<td style="text-align: center">if(S&gt;&gt;i&amp;1)</td>
</tr>
<tr>
<td>向集合中加入第i个元素<img src="/images/20140226/003.png" /></td>
<td style="text-align: center">S|1&lt;&lt;i</td>
</tr>
<tr>
<td>从集合S中去除第i个元素S-{i}</td>
<td style="text-align: center">S&amp;~(1&lt;&lt;i)</td>
</tr>
<tr>
<td>S和T的并集<img src="/images/20140226/004.png" /></td>
<td style="text-align: center">S|T</td>
</tr>
<tr>
<td>S和T的交集<img src="/images/20140226/005.png" /></td>
<td style="text-align: center">S&T</td>
</tr>
</table>

将集合{0,1,...,n-1}的所有子集枚举出来，可以像这样写

<style type="text/css">
pre { font-family: monospace; color: #839496; background-color: #002b36; }
* { font-size: 1em; }
.Constant { color: #2aa198; }
.Statement { color: #719e07; }
.LineNr { }
.Comment { color: #586e75; font-style: italic; }
.Type { color: #b58900; }
</style>
<pre id='vimCodeElement'style="font-family: monospace; color: #839496; background-color: #002b36;">
<span class="Statement">for</span>(<span class="Type">int</span> S = <span class="Constant">0</span>; S &lt; <span class="Constant">1</span> &lt;&lt; n; S++) {
    <span class="Comment">//处理子集</span>
}
</pre>

枚举集合sup的子集。sup是一个二进制码，可能不是全集，其本身也是某个集合的子集。例如给定01101101这样的集合，要将01100000或者00101101等这样的子集枚举出来。

<pre id='vimCodeElement' style=" font-family: monospace; color: #839496; background-color: #002b36; ">
<span class="Type">int</span> sub = sup;
<span class="Statement">do</span> {
    <span class="Comment">//处理子集</span>
    sub = (sub - <span class="Constant">1</span>) &amp; sup;
} <span class="Statement">while</span>(sub != sup); <span class="Comment">//处理完0之后，会有-1&amp;sup=sup</span>
</pre>

枚举{0,1,...,n-1}的所有容量为k的子集

<pre id='vimCodeElement' style=" font-family: monospace; color: #839496; background-color: #002b36; ">
<span class="Type">int</span> comb = (<span class="Constant">1</span> &lt;&lt; k) - <span class="Constant">1</span>;
<span class="Statement">while</span> (comb &lt; <span class="Constant">1</span> &lt;&lt; n) {
    <span class="Comment">//处理组合</span>
    <span class="Type">int</span> x = comb &amp; -comb, y = comb + x;
    comb = ((comb &amp; ~y) / x &gt;&gt; <span class="Constant">1</span>) | y;
}
</pre>

从(1<<k)-1开始，求出其后的集合的方法。

<ol>
<li>求出最低位的1开始的连续的1区间(0101110->0001110)</li>
<li>将这一区间全部变成0，并将区间左侧的那个0变成1(0101110->0110000)</li>
<li>将第一步的区间右移，知道剩下的1的个数减少了1个(0001110->0000011)</li>
<li>将第二步和第三步的结果按位区或(0110000|0000011=0110011)</li>
</ol>

x=comb&-comb 就是最低位的1独立出来后的值。-comb对应(~comb)+1。
y=comb+x 将最低位从1开始，连续的1都置零，区间左侧的那个0变成1。
z=comb&~y 得到最低位从1开始的连续区间。
z/x 将z不断右移，直到最低位为1，只要再向右移一位就是第三步的结果。

例如

<pre color="#000">
comb = 0101110
   x = 0000010
   y = 0110000
   z = 0001110
</pre>

