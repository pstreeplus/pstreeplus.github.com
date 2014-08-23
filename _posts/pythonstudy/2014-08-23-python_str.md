---
title: python学习笔记---字符串
layout: post

---


## 创建字符串

在`Python`中创建一个字符串很简单，可以像下面这样来创建:

>`S = "mystr"` 或 `S = 'mystr'`

当然python提供了很多字符串处理的工具，这里只列出常用的几个：

## `find()` 和 `index()` 

>`find()` 和 `index()` 都可以检查一个字符串是否是另一个字符串的字串，所不同的是：在查找失败的时候 `find()` 返回 `-1`，而 `index()`抛出一个异常`(exceptions.ValueError)`。在查找成功是二者返回值是一样的，都是字串第一个字符出现的位置。

###Example:
```python
S = 'this is a str'
find('is')  #value is 2
#value is 2
index('is') #value also is 2
value also is 2
find('no')  #value is -1
index('no') #exception.ValueError
```
