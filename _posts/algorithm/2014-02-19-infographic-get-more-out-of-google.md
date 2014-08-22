---
layout: post
title: "如何使用Google"
category: 技巧
description: "一些使用搜索引擎的技巧,不用再被人骂伸手党了."
tags: [tools, Google]
---

图转自[开卷有益](http://kaijuan.org/%E6%96%87%E4%BB%B6:%E4%BF%A1%E6%81%AF%E5%9B%BE-%E4%BB%8E%E8%B0%B7%E6%AD%8C%E6%90%9C%E8%8E%B7%E6%9B%B4%E5%A4%9A.png),也可以查看[英文原图](http://www.hackcollege.com/blog/2011/11/23/infographic-get-more-out-of-google.html)

![Google picture](/images/google/google.gif)

---
##更多说明

###1.双引号

把搜索词放在双引号中，代表完全匹配搜索，也就是说搜索结果返回的页面包含双引号中出现的所有的词，连顺序也必须完全匹配。

---
###2.减号

减号代表搜索不包含减号后面的词的页面。使用这个指令时减号前面必须是空格，减号后面没有空格，紧跟着需要排除的词。

例如：大学 -马家沟军事工程学院

返回的则是包含“大学”这个词，却不包含“马家沟军事工程学院”这个词的结果

---
###3.星号
星号*是常用的通配符，也可以用在搜索中。

比如在Google 中搜索：搜索*擎

其中的*号代表任何文字。返回的结果就不仅包含“搜索引擎”，还包含了“搜索收擎”，“搜索巨擎”等内容。

---
###4.related
related: 返回的结果是与某个网站有关联的页面。比如搜索

related:http://zhihu.com

---
###5.site

site: 用来搜索某个域名下的所有文件。

例如 site:quant67.com 探险指南

可以搜索quant67网站上所有关于"探险指南"的内容。

---
###6.filetype

用于搜索特定文件格式。

比如搜索filetype:pdf Dijstra

返回的就是包含Dijstra这个关键词的所有pdf文件。

---
###7.intitle
intitle: 指令返回的是页面title中包含关键词的页面。

###8.allintitle
allintitle:搜索返回的是页面标题中包含关键词的文件。

例如 ：allintitle:DFA 正则表达式

返回的是标题中中既包含“DFA”，也包含“正则表达式”的页面

---
###9.inurl
inurl: 指令用于搜索查询词出现在url中的页面。这个指令支持中文。

