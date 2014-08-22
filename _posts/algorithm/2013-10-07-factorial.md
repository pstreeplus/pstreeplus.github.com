---
layout : post
category : 技术
title : THE FACTORIAL PROBLEM
description: 一个很有意思的题目。
image: 
        feature: soft-trees.jpg
---

在[codechef](http://www.codechef.com/problems/FCTRL)上发现一个挺有意思的[题目](http://www.codechef.com/problems/FCTRL)。大意是这样的：
<pre>
Problem Statement:
There is a single positive integer T on the first line of input (equal to about 100000). 
It stands for the number of numbers to follow. 
Then there are T lines, each containing exactly one positive integer number N, 1 <= N <= 1000000000.

Output
For every number N, output a single line containing the single non-negative integer Z(N).
Z(N) function outputs the number of Trailing Zero's in Factorial of N.

Sample Input:
6
3
60
100
1024
23456
8735373

Sample Output:
0
14
24
253
5861
2183837
</pre>

上面的Sample Input，第一行的6表示下面有六个数字，对于下面的这6个数字，我们假设他们某个数字阶乘的值是m，你需要计算的是m的最后面有几个0。

比如给你一个数字:5

我们很容易计算出它的阶乘：5! = ５×４×３×２×１＝120

１２０后面有１个０，　所以结果为１。

这样我们很容易得到下面这段代码。

<style type="text/css">
<!--
* { font-size: 1em; }
.Statement { color: #719e07; }
.Comment { color: #586e75; font-style: italic; }
.Constant { color: #2aa198; }
.PreProc { color: #cb4b16; }
.Identifier { color: #268bd2; }
-->
</style>
<pre style="font-family: monospace; color: #839496; background-color: #002b36;">
<span class="Comment">#! /usr/bin/python</span>
<span class="Comment"># -*- coding: utf-8 -*-</span>
<span class="PreProc">import</span> math

t = <span class="Identifier">input</span>()
<span class="Statement">while</span> t &gt; <span class="Constant">0</span>:
    t -= <span class="Constant">1</span>
    n = <span class="Identifier">input</span>()

    <span class="Comment">#计算阶乘</span>
    factorial_of_n = math.factorial(n)

    <span class="Comment">#计算后面有几个0</span>
    num_of_0 = <span class="Constant">0</span>
    tmp = <span class="Identifier">str</span>(factorial_of_n)[::-<span class="Constant">1</span>]    <span class="Comment">#把阶乘结果变成字符转并反转</span>
    <span class="Statement">for</span> bit <span class="Statement">in</span> tmp:
        <span class="Statement">if</span> <span class="Identifier">int</span>(bit) == <span class="Constant">0</span>:
            num_of_0 += <span class="Constant">1</span>
        <span class="Statement">else</span>:
            <span class="Statement">break</span>

    <span class="Identifier">print</span> num_of_0
</pre>

简单吧，可是它消耗时间的本领实在太强了，输入的上界可是10的9次方啊，解出它的阶乘是个繁重的工作，会消耗很多时间。所以，这不是个好办法。

既然计算阶乘消耗的时间和内存太多，有没有可能不计算阶乘就得出结果呢？

答案是肯定的。我们先来看看60这个数，它的阶乘是下面这60个数字相乘的结果：

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60

我还是先把它算出来吧：
8320987112741390144276341183223364380754172606361245952449277696409600000000000000 (容易得出结果是14)

我们知道几个数相乘，要让结果的后面有0，只有一种情况：这几个数的因子里有2和5。这样就方便了，我们只要计算着所有1~n这些数的因子中一共有多少的2，多少个5就行了，结果就是（2,5）这样的组合有多少对。也就是因子2的个数和因子5的个数的最小值。我们拿小一些的数字举例，比如5吧，1,2,3,4,5里，因子2的个数是3（2有一个，4有2个）；因子5的个数是1（只有5有一个）。那么，我们的结果就是1。

等等，是不是还有更简单的做法？不能忽略这样一个事实：因子2的个数总是不小于因子5的个数的！我们只要计算因子5的个数就行了，那就是我们要的结果！

那么，如何更快地计算因子5的个数呢？

我们继续拿60举例。

打眼一看，只有下面这些数有因子5：

5 10 15 20 25 30 35 40 45 50 55 60

它们的个数是m = 60 / 5。除以5就可以得到这些数的个数了，是12个。现在我们先记下12这个数，因为已经记下了12个因子5，那么我们就可以把它们删掉，上面的数每个去掉一个5，得到：

1 2 3 4 5 6 7 8 9 10 11 12

那么剩下的这几个数里有多少的因子5呢？

5 10

只要 12 / 5 除一下就出来了。现在结果是12+2=14在把上面剩下的数每个去掉一个5，得到：

1 2

没有了，因为2 / 5 = 0。

我们得到了结果：14。

回顾一下上面的步骤：
<pre>
60 / 5 = 12
12 / 5 = 2
2 / 5 = 0 
结果就是：12 + 2 + 0
</pre>

好了，可以给出代码了。一共两个，一个是网上找的，匪夷所思的写法。

代码一：
<style type="text/css">
<!--
.Type { color: #b58900; }
.Statement { color: #719e07; }
.PreProc { color: #cb4b16; }
.Constant { color: #2aa198; }
.Special { color: #dc322f; }
-->
</style>

<pre style="font-family: monospace; color: #839496; background-color: #002b36;">
<span class="PreProc">#include </span><span class="Constant">&quot;stdio.h&quot;</span>
<span class="PreProc">#include </span><span class="Constant">&quot;stdlib.h&quot;</span>

<span class="PreProc">#define MAXRANGE </span><span class="Constant">100000</span>

<span class="Type">long</span> <span class="Type">int</span> Display(<span class="Type">long</span> <span class="Type">int</span> n, <span class="Type">long</span> <span class="Type">int</span> v);
<span class="Type">long</span> <span class="Type">int</span> Divide(<span class="Type">long</span> <span class="Type">int</span> n, <span class="Type">long</span> <span class="Type">int</span> v);

<span class="Type">typedef</span> <span class="Type">long</span> <span class="Type">int</span> (*fMethod) (<span class="Type">long</span> <span class="Type">int</span> n, <span class="Type">long</span> <span class="Type">int</span> v);
fMethod job[<span class="Constant">2</span>] = { Display, Divide };

<span class="Type">long</span> <span class="Type">int</span> Display(<span class="Type">long</span> <span class="Type">int</span> n, <span class="Type">long</span> <span class="Type">int</span> v) {
    printf(<span class="Constant">&quot;</span><span class="Special">%d</span><span class="Special">\n</span><span class="Constant">&quot;</span>, n);
    <span class="Statement">return</span> <span class="Constant">0</span>;
}

<span class="Type">long</span> <span class="Type">int</span> Divide(<span class="Type">long</span> <span class="Type">int</span> n, <span class="Type">long</span> <span class="Type">int</span> v) {
    v = v/<span class="Constant">5</span>;
    <span class="Statement">return</span> job[v==<span class="Constant">0</span>?<span class="Constant">0</span>:<span class="Constant">1</span>](n+v,v);
}

<span class="Type">int</span> main() {
    <span class="Type">long</span> <span class="Type">int</span> nRange;
    <span class="Type">long</span> <span class="Type">int</span> nArray[MAXRANGE];
    <span class="Type">long</span> <span class="Type">int</span> i,j,k;
    scanf(<span class="Constant">&quot;</span><span class="Special">%ld</span><span class="Constant">&quot;</span>, &amp;nRange);

    <span class="Statement">for</span>(i = <span class="Constant">0</span>; i &lt; nRange; i++) {
        scanf(<span class="Constant">&quot;</span><span class="Special">%ld</span><span class="Constant">&quot;</span>, &amp;k);
        nArray[i] = k;
    }

    <span class="Statement">for</span>(j = <span class="Constant">0</span>; j &lt; nRange; j++) {
        <span class="Type">long</span> <span class="Type">int</span> n = (nArray[j]&lt;&lt;<span class="Constant">1</span>)/<span class="Constant">10</span>;
        job[n==<span class="Constant">0</span>?<span class="Constant">0</span>:<span class="Constant">1</span>](n, n);
    }

    <span class="Statement">return</span> <span class="Constant">0</span>;
}
</pre>

代码二：

<style type="text/css">
<!--
.Type { color: #b58900; }
.Statement { color: #719e07; }
.PreProc { color: #cb4b16; }
.Constant { color: #2aa198; }
.Special { color: #dc322f; }
-->
</style>

<pre style="font-family: monospace; color: #839496; background-color: #002b36;">
<span class="PreProc">#include </span><span class="Constant">&quot;stdio.h&quot;</span>
<span class="PreProc">#include </span><span class="Constant">&quot;stdlib.h&quot;</span>
<span class="PreProc">#define MAXRANGE </span><span class="Constant">100000</span>

<span class="Type">int</span> main() {
    <span class="Type">long</span> <span class="Type">int</span> nRange;
    <span class="Type">long</span> <span class="Type">int</span> nArray[MAXRANGE];
    <span class="Type">long</span> <span class="Type">int</span> i,j,k;
    scanf(<span class="Constant">&quot;</span><span class="Special">%ld</span><span class="Constant">&quot;</span>, &amp;nRange);

    <span class="Statement">for</span>(i = <span class="Constant">0</span>; i &lt; nRange; i++) {
        scanf(<span class="Constant">&quot;</span><span class="Special">%ld</span><span class="Constant">&quot;</span>, &amp;k);
        nArray[i] = k;
    }

    <span class="Statement">for</span>(j = <span class="Constant">0</span>; j &lt; nRange; j++) {
        <span class="Type">long</span> <span class="Type">int</span> m = nArray[j];
        <span class="Type">long</span> <span class="Type">int</span> n = <span class="Constant">0</span>;
        <span class="Statement">while</span>(m = m/<span class="Constant">5</span>) {
            n+=m;
        }
        printf(<span class="Constant">&quot;</span><span class="Special">%d</span><span class="Special">\n</span><span class="Constant">&quot;</span>, n);
    }

    <span class="Statement">return</span> <span class="Constant">0</span>;
}
</pre>
