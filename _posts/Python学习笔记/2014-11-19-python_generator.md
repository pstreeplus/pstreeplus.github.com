---
title: Python Generator(生成器) 
layout: post
category: 编程语言
tags: Python
---

###生成器是什么



生成器是一个这样的函数：它包含yield表达式，可以随着时间**返回一系列值**。


与普通的函数所不同的是：普通函数包含return语句，返回一个值之后就结束函数，而生成器返回一个值后不会结束函数（直达引发异常或碰到return语句），生成器yield一个值之后，向它的调用这返回这个值，函数自动挂起，然后保存足够的状态信息（例如：本地变量的值）使得函数下次可以从此处恢复继续运行。


在Python中，生成器被自动用作实现迭代协议，因此它只能够在迭代语境中出现。



###实例



看下面一段代码

```python
#!/usr/bin/env python
# -*- coding:utf-8 -*-

def myGenerator():
    for i in range(3):
        yield i

for i in myGenerator():
    print i

#0
#1
#2
```

如果想要看看for循环里面发生了什么，终端里面直接调用生成看看

```python
>>> def myGenerator():
        print "foo"
...     for i in range(3):
...             yield i
... 
>>> myGenerator()
<generator object myGenerator at 0xb741a0cc>
>>> 
```

并没有执行函数。得到的是个生成器对象，它支持迭代协议，也就是说它具有next()方法，可以对它进行迭代直到产生异常

```python
#!/usr/bin/env python
# -*- coding:utf-8 -*-

def myGenerator():
    for i in range(3):
        yield i

f = myGenerator()

print f.next()
print f.next()
print f.next()
print f.next()

# 0
# 1
# 2
# Traceback (most recent call last):
#   File "1.py", line 13, in <module>
#     print f.next()
# StopIteration
```


###for循环工作机制


使用for循环来遍历一个对象发生以下事情:

>1.如果对象支持迭代协议，那么for循环自动反复调用其next()方法，直到产生异常时循环结束。

>2.如果对象不支持迭代协议，那么for循环就会使用索引协议对其进行迭代

>3.for循环通过调用对象的\__iter\__()方法来判断对象是否支持迭代协议


生成器支持迭代协议，所以用for对生成器进行迭代时，自动反复调用next()方法，这就是为什么for和生成器在一起可以工作的原因。


清楚这一点之后，我们完全利用它自己实现一个可迭代对象，用for遍历，原则就是：**这个对象要有next()方法供for循环调用**。

```
#!/usr/bin/env python
# -*- coding:utf-8 -*-

class myClass:

    def __iter__(self):
        self.i = 0
        return self

    def next(self):
        if self.i > 3:
            raise StopIteration
        self.i += 1
        return self.i


T = myClass()

for i in T:
    print i

# 1
# 2
# 3
# 4
```

**生成器具有next()方法，使用它我们可以获得一系列值**。
