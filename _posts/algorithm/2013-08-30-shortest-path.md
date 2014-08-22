---
layout: post
title: 最短路
description: 
category : 技术
tagline: "fail"
tags : [beginner, algorithm]
---

<h4 style="color: #68F7E4">关于代码高亮</h4>
我试过很多办法，但是都有一些神奇的问题，所以我直接上HTML整颜色，好混乱，要是出现一些奇怪的符号，怪我吧。我也会认真校对的。

<h4 style="color: #68ADF7">正题</h4>

最短路径问题是图论中最基础的问题。[![wikt](http://upload.wikimedia.org/wikipedia/commons/5/5b/6n-graf.svg)](http://en.wikipedia.org/wiki/Shortest_path_problem)

<h4 style="color: #B268F7">Bellman-Ford算法</h4>

先看代码吧。

<style type="text/css">
.Constant { color: #92d4ff; }
.Statement { color: #dcdc78; }
.Comment { color: #c0c0c0; }
.Type { color: #60f0a8; }
</style>
<pre style="font-family: monospace; color: #f0f0f0; background-color: #303030;">
<span class="Comment">//保存路径的结构体类型，路径从from到to，权值（长度）为cost</span>
<span class="Type">typedef</span> <span class="Type">struct</span> EDGE {
    <span class="Type">int</span> from;
    <span class="Type">int</span> to;
    <span class="Type">int</span> cost;
} edge;

edge es[MAX_E]; <span class="Comment">//边</span>

<span class="Type">int</span> d[MAX_V];   <span class="Comment">//从起点s到节i的最短路径是d[i]</span>
<span class="Type">int</span> V, E;

<span class="Type">void</span> shortest_path(<span class="Type">int</span> s) {
    <span class="Statement">for</span>(<span class="Type">int</span> i = <span class="Constant">0</span>; i &lt; V; i++)
        d[i] = INF;
    d[s] = <span class="Constant">0</span>;
    <span class="Type">bool</span> update;
    <span class="Statement">do</span>{
        update = <span class="Constant">false</span>;
        <span class="Statement">for</span>(<span class="Type">int</span> i = <span class="Constant">0</span>; i &lt; E; i++) {
            edge e = es[i];
            <span class="Statement">if</span>(d[e.from] != INF &amp;&amp; d[e.to] &gt; d[e.from] + d[e.cost]) {
                d[e.to] = d[e.from] + e.cost;
                update = <span class="Constant">true</span>;
            }
        }
    }<span class="Statement">while</span>(update);
}
</pre>

简单地说，方法就是:

	repeat {
		遍历每一条路径，试图更新它连接的点的最短路径	
	} until (不再能更新，d[i]里全都已经是最短的了)

具体地，刚开始，`d[i]`全都赋值为`INF`（无穷大），起点`s`的最短路径自然是`0`，即`d[s] = 0`，然后开始遍历所有边，对于每一个节点`i`，我们尽量让`d[i]`最小，所以要不要加入这条边`e`，就要看是否`d[e.to] > d[e.from] + e.cost`。


<h4 style="color: #8CF768">Dijkstra算法</h4>

其实我也不知道这个单词怎么读，如果你知道，请务必告诉[我](http://quant67.com//contact.html)。

方法是：

>找到最短路径已经确定的节点们，从他们出发更新相邻的节点的最短距离。

<style type="text/css">
.Constant { color: #92d4ff; }
.Statement { color: #dcdc78; }
.Comment { color: #c0c0c0; }
.Type { color: #60f0a8; }
</style>
<pre style="font-family: monospace; color: #f0f0f0; background-color: #303030;">
<span class="Comment">//保存边的结构体类型</span>
<span class="Type">typedef</span> <span class="Type">struct</span> EDGE {
    <span class="Type">int</span> to;       <span class="Comment">//边指向的节点的编号</span>
    <span class="Type">int</span> cost;     <span class="Comment">//边的权值</span>
} edge;
<span class="Type">typedef</span> pair&lt;<span class="Type">int</span>, <span class="Type">int</span>&gt; P;   <span class="Comment">//first是最短距离，second是顶点的编号</span>

<span class="Type">int</span> V; <span class="Comment">//节点的数量</span>
vector&lt;edge&gt; G[MAX_V];  <span class="Comment">//用邻接表保存图</span>
<span class="Type">int</span> d[MAX_V]; <span class="Comment">//从起点s到节点i的最短路径是d[i]</span>

<span class="Type">void</span> dijkstra(<span class="Type">int</span> s) {
    priority_queue&lt;P, vector&lt;P&gt;, greater&lt;P&gt;&gt; que; <span class="Comment">//最小堆</span>
    fill(d, d + V, INF);  <span class="Comment">//初始化d[]为INF</span>
    d[s] = <span class="Constant">0</span>;  <span class="Comment">//起点到起点的最短距离是0</span>
    que.push(P(<span class="Constant">0</span>, s)); <span class="Comment">//把起点放入最小堆</span>

    <span class="Statement">while</span>(!que.empty()) {
        P p = que.top();  <span class="Comment">//从最小堆取出最短距离的节点</span>
        que.pop();
        <span class="Type">int</span> v = p.second;
        <span class="Statement">if</span>(d[v] = p.first) <span class="Statement">continue</span>;
        <span class="Statement">for</span>(<span class="Type">int</span> i = <span class="Constant">0</span>; i &lt; G[v].size(); i++) {
            edge e = G[v][i];
            <span class="Statement">if</span>(d[e.to] &gt; d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
</pre>

这里我们用到了优先队列，如果不知道什么是优先队列，可以参考[关于堆的知识](http://quant67.com/adt/2013/08/03/heep/)。可能还要用到一些关于[邻接表](http://en.wikipedia.org/wiki/Adjacency_list)的知识。

<h4 style="color: #BFF499">Floyd-Warshall算法</h4>

可以计算任意两点间的最短路径。`i`到`j`的最短路径，有两种情况：经过`k`的，和不经过`k`的。我们用`d[i][j]`来表示从节点`i`到节点`j`的最短路径。

<style type="text/css">
.Constant { color: #92d4ff; }
.Statement { color: #dcdc78; }
.Comment { color: #c0c0c0; }
.Type { color: #60f0a8; }
</style>
<pre style="font-family: monospace; color: #f0f0f0; background-color: #303030;">
<span class="Type">int</span> d[MAX_V][MAX_V]; <span class="Comment">//d[u][v]表示边e=(u, v)的权值</span>
<span class="Type">int</span> V;

<span class="Type">void</span> warshall_floyd() {
    <span class="Statement">for</span>(<span class="Type">int</span> k = <span class="Constant">0</span>; k &lt; V; k++) {
        <span class="Statement">for</span>(<span class="Type">int</span> i = <span class="Constant">0</span>; i &lt; V; i++) {
            <span class="Statement">for</span>(<span class="Type">int</span> j = <span class="Constant">0</span>; j &lt; V; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
</pre>

<h4 style="color: #DD99F4">路径还原</h4>

如果最后要打印出最短路径，我们在找最短路径的时候只需要记录每一个节点的上一个节点就行了，用数组`pre[]`，`pre[i]`记录在最短路径中节点`i`的上一个节点。

<h3 style="color: pink">end</h3>
