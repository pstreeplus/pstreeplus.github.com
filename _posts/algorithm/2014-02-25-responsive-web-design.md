---
layout : post
category : 技术
title : 响应式设计备忘录
tags: [design, web, css, HTML5]
description: "页面的设计与开发应当根据用户行为以及设备环境(系统平台、屏幕尺寸、屏幕定向等)进行相应的响应和调整。具体的实践方式由多方面组成，包括弹性网格和布局、图片、CSS media query的使用等。无论用户正在使用笔记本还是iPad，我们的页面都应该能够自动切换分辨率、图片尺寸及相关脚本功能等，以适应不同设备。"
---

#必要准备

为了不让浏览器自动缩放，必须加入下面一行

<style type="text/css">

.Constant { color: #2aa198; }
.Identifier { color: #268bd2; }
.LineNr { }
.Statement { color: #719e07; }
.Type { color: #b58900; }
.Special { color: #dc322f; }
</style>

<pre id='vimCodeElement' style="overflow:auto">
<span class="htmlTag">&lt;</span><span class="htmlTagName">meta</span><span class="htmlTag"> </span><span class="htmlArg">name</span><span class="htmlTag">=</span><span class="Constant">&quot;viewport&quot;</span><span class="htmlTag"> </span><span class="htmlArg">content</span><span class="htmlTag">=</span><span class="Constant">&quot;width=device-width,initial-scale=1.0&quot;</span><span class="htmlTag"> /&gt;</span>
</pre>


#媒体查询

可以将下面的代码插入任意CSS文件的最后查看效果

<pre id='vimCodeElement' style="overflow:auto">
<span class="Statement">body</span>: <span class="Identifier">{</span>
    <span class="Type">background-color</span>: <span class="Constant">grey</span>;
<span class="Identifier">}</span>
<span class="Special">@media</span> <span class="Special">screen</span> and <span class="Special">(</span><span class="Type">max-width</span><span class="Special">: </span><span class="Constant">960px</span><span class="Special">)</span> <span class="Identifier">{</span>
    <span class="Statement">body</span> <span class="Identifier">{</span>
        <span class="Type">background-color</span>: <span class="Constant">red</span>;
    <span class="Identifier">}</span>
<span class="Identifier">}</span>
<span class="Special">@media</span> <span class="Special">screen</span> ans (max-width: 768px) <span class="Identifier">{</span>
    body <span class="Identifier">{</span>
        <span class="Type">background-color</span>: <span class="Constant">orange</span>;
    <span class="Identifier">}</span>
<span class="Identifier">}</span>
<span class="Special">@media</span> <span class="Special">screen</span> and <span class="Special">(</span><span class="Type">max-width</span><span class="Special">: </span><span class="Constant">550px</span><span class="Special">)</span> <span class="Identifier">{</span>
    <span class="Statement">body</span> <span class="Identifier">{</span>
        <span class="Type">background-color</span>: <span class="Constant">yellow</span>;
    <span class="Identifier">}</span>
<span class="Identifier">}</span>
<span class="Special">@media</span> <span class="Special">screen</span> and <span class="Special">(</span><span class="Type">max-width</span><span class="Special">: </span><span class="Constant">320px</span><span class="Special">)</span> <span class="Identifier">{</span>
    <span class="Statement">body</span> <span class="Identifier">{</span>
        <span class="Type">background-color</span>: <span class="Constant">green</span>;
    <span class="Identifier">}</span>
<span class="Identifier">}</span>
</pre>




插入方式

<pre id='vimCodeElement' style="overflow:auto">
<span class="htmlTag">&lt;</span><span class="htmlTagName">link</span><span class="htmlTag"> </span><span class="htmlArg">rel</span><span class="htmlTag">=</span><span class="Constant">&quot;stylesheet&quot;</span><span class="htmlTag"> </span><span class="htmlArg">type</span><span class="htmlTag">=</span><span class="Constant">&quot;text/css&quot;</span><span class="htmlTag"> </span><span class="htmlArg">media</span><span class="htmlTag">=</span><span class="Constant">&quot;screen&quot;</span><span class="htmlTag"> </span><span class="htmlArg">href</span><span class="htmlTag">=</span><span class="Constant">&quot;style.css&quot;</span><span class="htmlTag"> /&gt;</span>
<span class="Comment">&lt;!</span><span class="Comment">--是屏幕才加载style.css文件--</span><span class="Comment">&gt;</span>

<span class="htmlTag">&lt;</span><span class="htmlTagName">link</span><span class="htmlTag"> </span><span class="htmlArg">rel</span><span class="htmlTag">=</span><span class="Constant">&quot;stylesheet&quot;</span><span class="htmlTag"> </span><span class="htmlArg">type</span><span class="htmlTag">=</span><span class="Constant">&quot;text/css&quot;</span><span class="htmlTag"> </span><span class="htmlArg">media</span><span class="htmlTag">=</span><span class="Constant">&quot;screen and (orientation: portrait)&quot;</span><span class="htmlTag"> </span><span class="htmlArg">href</span><span class="htmlTag">=</span><span class="Constant">&quot;portrait-style.css&quot;</span><span class="htmlTag"> /&gt;</span>
<span class="Comment">&lt;!</span><span class="Comment">--纵向放置的设备会加载portrait-style.css文件--</span><span class="Comment">&gt;</span>

<span class="htmlTag">&lt;</span><span class="htmlTagName">link</span><span class="htmlTag"> </span><span class="htmlArg">rel</span><span class="htmlTag">=</span><span class="Constant">&quot;stylesheet&quot;</span><span class="htmlTag"> </span><span class="htmlArg">type</span><span class="htmlTag">=</span><span class="Constant">&quot;text/css&quot;</span><span class="htmlTag"> </span><span class="htmlArg">media</span><span class="htmlTag">=</span><span class="Constant">&quot;screen and (orientation: portrait) ans (max-width: 800px)&quot;</span><span class="htmlTag"> </span><span class="htmlArg">href</span><span class="htmlTag">=</span><span class="Constant">&quot;800px-portrait-style.css&quot;</span><span class="htmlTag"> /&gt;</span>
<span class="Comment">&lt;!</span><span class="Comment">--进一步限制屏幕尺寸--</span><span class="Comment">&gt;</span>

<span class="htmlTag">&lt;</span><span class="htmlTagName">link</span><span class="htmlTag"> </span><span class="htmlArg">rel</span><span class="htmlTag">=</span><span class="Constant">&quot;stylesheet&quot;</span><span class="htmlTag"> </span><span class="htmlArg">type</span><span class="htmlTag">=</span><span class="Constant">&quot;text/css&quot;</span><span class="htmlTag"> </span><span class="htmlArg">media</span><span class="htmlTag">=</span><span class="Constant">&quot;screen and (orientation: portrait) ans (max-width: 800px), projection&quot;</span><span class="htmlTag"> </span><span class="htmlArg">href</span><span class="htmlTag">=</span><span class="Constant">&quot;800px-portrait-style.css&quot;</span><span class="htmlTag"> /&gt;</span>
<span class="Comment">&lt;!</span><span class="Comment">--都好分隔几个查询，这里会应用到所有的投影仪--</span><span class="Comment">&gt;</span>
</pre>


还可以使用import，下面的例子将为视口最大宽度为360像素的显示屏设备加载phone.css

<pre id='vimCodeElement' style="overflow:auto">
<span class="PreProc">@import </span><span class="Identifier">url(</span><span class="Constant">&quot;phone.css&quot;</span><span class="Identifier">)</span><span class="PreProc"> </span><span class="Special">screen</span><span class="PreProc"> and </span><span class="Special">(</span><span class="Type">max-width</span><span class="Special">: </span><span class="Constant">360px</span><span class="Special">)</span><span class="PreProc">;</span>
</pre>


但是这样会增加HTTP请求，影响加载速度。

#HTML全新语义

<pre id='vimCodeElement' style="overflow:auto">
&lt;<span class="Statement">section</span><span class="Special">&gt;</span>
文档中的区域或节

&lt;<span class="Statement">nav</span><span class="Special">&gt;</span>
主导航区域

&lt;<span class="Statement">article</span><span class="Special">&gt;</span>
一篇文章，一篇完整的内容

&lt;<span class="Statement">aside</span><span class="Special">&gt;</span>
侧边栏

&lt;<span class="Statement">hgroup</span><span class="Special">&gt;</span>
包裹一组h标签

&lt;<span class="Statement">header</span><span class="Special">&gt;</span>
刊头

&lt;<span class="Statement">footer</span><span class="Special">&gt;</span>
就是footer

&lt;<span class="Statement">address</span><span class="Special">&gt;</span>
标注其与最近祖先的联系信息

</pre>


#正文部分

<pre id='vimCodeElement' style="overflow:auto">
&lt;<span class="Statement">b</span><span class="Special">&gt;</span>加粗

&lt;<span class="Statement">em</span><span class="Special">&gt;</span>强调内容重点

&lt;<span class="Statement">i</span><span class="Special">&gt;</span>斜体
</pre>

