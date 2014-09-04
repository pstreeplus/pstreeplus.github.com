---
title: python学习笔记---字符串
layout: post

---


## 创建字符串

在`Python`中创建一个字符串很简单，可以像下面这样来创建:

>`S = "mystr"` 或 `S = 'mystr'`

当然`python`提供了很多字符串处理的工具，这里只列出常用的几个：

## 1.`find()`,`index()` 

>`find()` 和 `index()` 都可以检查一个字符串是否是另一个字符串的字串，所不同的是：在查找失败的时候`find()`返回`-1`，而`index()`抛出一个异常`(exceptions.ValueError)`。在查找成功是二者返回值是一样的，都是字串第一个字符出现的位置。

```python
S = 'this is a str'
S.find('is')          #value is 2
S.index('is')         #value also is 2
S.find('no')          #value is -1
S.index('no')         #exception.ValueError
```

##2.lstrip(),rstrip(),strip()

>如果不带任何参数，`lstrip()`,`rstrip()`,`strip()`分别会删除前导空白字符，结尾空白字符，和前后空白字符`(tab,enter,space...)`,它们的返回值都是处理后的字符串。如果带参数，那么它们会**删除参数中字符的任意组合，只要这个组合存在函数作用的位置上**。为了看清楚这一点，我们来看个例子：

```python
S = "<this is s str>"
S.lstrip('<')                    # "this is a str>"
S.rstrip('>')                    # "<this is a str"
S.strip('<')                     # "this is a str>"
S.strip('>')                     # "<this is a str"
S.strip('>').strip('<')          # "this is a str"
S.strip("<>")                    # "this is a str"
S.strip("><")                    # "this is a str"
S = "<<<this is a str>>>>"
S.lstrip('<')                    # "this is a str>>>"
S.rstrip('>')                    # "<<<this is a str"
S.strip('<')                     # "this is a str>>>"
S.strip('>')                     # "<<<this is a str"
S.strip("<>")                    # "this is a str"
S.strip("><")                    # "this is a str"
S.strip("<><>")                  # "this is a str"
```

##3.`upper()`,`lower()`

>它们把目标字符换转换成大/小写,并返回处理后字符串。

```python
S = "abs"
S.upper()                    # "ABC"
S = 'ABC'
S.lower()                    # "abc"
```

##4.`split()`

>它会按照指定的字符或字符串来分割目标字符串，返回一个列表。

```python
S = "a,b,c"
S.split(',')                 # ['a','b','c']
S = "aaXXXbbXXXccXXX"
S.split("XXX")               # ['aa','bb','cc']
S.split('XX')                # ['aa','Xbb','Xcc','X']
```

##5.`replace()`

>把一个字符串的一部分替换成另一个指定的串，返回处理后的字符串

```python
S = "abcdaaSS"
S.replace("b",'f')           # "afcdaaSS"
```
##6.`join()`

>与`split()`相反，它把多个字符串连接在一起，返回一个字符串。

```python
L = ['aa','bb','cc']
','.join(L)                  # "aa,bb,cc"
'|'.join(L)                  # "aa|bb|cc"
```
>`join()`参数需要一个字符序列，如果要出传递的一系列整数，会怎样呢？

```python
L = range(10)
','.join(L) 
# "exception.TypeError"
```

>因此需要将L中的数子转换成字符串

```python
','.join([str[i] for i in L])
# '0,1,2,3,4,5,6,7,8,9'
```

##总结

>学习这些很零碎的知识点关键是多加练习，另外还有一点就是，学习函数，一定要记清楚它们的参数以及**返回值**。
