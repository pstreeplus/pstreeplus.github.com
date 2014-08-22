---
layout : post
category : 技术
title : GCC的预处理程序
tags : [C/C++, code]
---
预处理程序的概念来自于C编程语言的一部分。预处理程序读出源代码，对其中内嵌的指示字进行响应，产生源代码的修改版本，修改后的版本会被编译程序读入。预处理程序虽然是C、C++、Ojective-C中重要的一部分，但是也可以用它预处理其它的语言源代码。例如Fortran和Java的条件编译。

<h3 style="color:#90F597">1.指示字</h3>
源代码中的预处理指令叫做指示字，它们以“#”号开始:

<div style="background-color:#EBC5F7">
<h4>#define、#undef</h4>
<span>#define</span>定义宏名字，预处理程序会把这个宏扩展到使用该名字的位置,而<span>#undef</span>用于删除这个宏定义。
</div>
<div style="background-color:#9F81F9">
<h4>#elif、#if、#else、#ifdef、#ifndef、#endif</h4>
决定是否编译部分源文件。
</div>
<div style="background-color:#81C7F9">
<h4>#error</h4>
产生出错信息，挂起预处理程序。
</div>
<div style="background-color:#EAF88D">
<h4>#include</h4>
查找指示字列表，直到找到指定文件然后将文件内容插入，就好像在文本编辑器插入一样。
</div>
<div style="background-color:#F8AF8D">
<h4>#include_next</h4>
和<span>#include</span>一样但该指示字从找到当前文件的目录之后的目录开始查找。
</div>
<div style="background-color:#89FB74">
<h4>#line</h4>
指出行号以及可能的文件名，报告给编译程序，用于创建目标文件的调试信息。
</div>
<div style="background-color:#FA82AC">
<h4>#pragma</h4>
提供额外信息的标准方法，可以用来指出一个编译程序或一个平台。
</div>
<div style="background-color:#686DFF">
<h4>#waining</h4>
有预处理程序创建一个警告信号。
</div>
<div style="background-color:#2DA0A8">
<h4>##</h4>
将宏内的两个字符串连接成一个。
</div>

---
<h5>1.1.#define</h5>
大多数宏用于定义常数，一般用大写字母作为名字。例如的定义创建了宏ARRAY_SIZE，那么代码中出现该宏的地方都会把值512插入。

	#define ARRAY_SIZE 512

下面是一个众所周知的宏：

	#define min(a,b)  ((a) < (b) ? (a) : (b))

在源代码中，使用它的名字分配a,b的值：

result = min(44,uplim);

从这个宏中扩展出来的代码看起来就像这个样子：
	
	result = ((44) < (uplim) ? (44) : (uplim));

宏定义的规则：
<ul>
<li>宏定义包含一行。如果要写成多行，只需在每一行后面加上反斜杠"/"。例如下面这样：
<pre>#define rand(low,high)\
	((int)random() % (hight - low + 1))\
	+ low</pre>		
</li>
<li>预处理程序按照顺序处理这些文本。例如下面四行代码：
	<pre>
	#define A 1
	sum = A + B;
	#define B 2
	sum = A + B;</pre>
这四行代码的预处理结果如下：
	<pre>
	sum = 1 + B;
	sum = 1 + 2;</pre>
</li>
<li>宏是递归的，因此可以在一个宏中嵌入另一个宏。</li>
<li>要改变一个宏，需要删掉它再来一次：
	<pre>
	#define BE_FUKED FUCK_TIMES
	#define FUCK_TIMES 100
	#undef BE_FUKED
	#define BE_FUKED 0</pre>
</li>
<li>对于有参数的宏来说，宏的名字和括号之间不能有空格。</li>
<li>宏的名字在字符串中是不能被替换的：
	<pre>
	#define FMT_LEN 100
	printf("The FMT_LEN is a number.\n");</pre>
输出结果为:
	<pre>
	The FMT_LEN is a number.</pre>
</li>
<li>加上#号传递宏参数的名字，将其字符串化：
	<pre>
	#define MONCK(ARGTERM) \
		printf("The term " #ARGTERM " is a string.\n")
	MONCK(A to B);</pre>
输出结果为：
	<pre>
	The term A to B is a string.</pre>
</li>
<li>可以定义没有值得宏，尽管没有值，但他们还是可以作为#ifdef测试的标记。</li>
<li>可变参数数目的宏：
	<pre>
	#define err(...) fprintf(stderr,__VA_ARGS__)
	err("%s %d\n","The error code: ", 48);</pre>
预处理后的输出结果为：
<pre>
	fprintf(stderr,"The error code: ", 48);</pre>
</li>
</ul>

---

<h5>1.2.#error和#warning</h5>
`#error`会引起预处理程序报告致命错误或中断。例如下面的例子只有在定义了`__unix__`的情况下才能编译成功。
<pre>
	#ifndef __unix__
	#error "This section will only work on UNIX system"
	#endif</pre>
<span>#warning</span>和<span>#error</span>原理一样，只是它的条件不是致命性错误，而且预处理程序发出消息之后还会继续进行下去。

---

<h5>1.3.#if、#elif、#else、#endif</h5>
`#if`会计算一个数学表达式，并检查它的结果。如果不为零，就认为条件为真，并编译条件代码，否则不编译。例如下面的字符串只有在宏`COUNT`未被定义为零的情况下才会声明：

	#if COUNT
	char *desc = "The count is non-zero";
	#endif

下面是他们的特征和规则：
<ul>
<li>表达式的要求和`if`的表达式一样。</li>
<li>defined 操作符用于确定一个宏是否被定义。例如下面这句话，定义了MINXP就为真：
<pre>#if defined</pre>
</li>
<li>标识符符未被定义的宏，返回结果零。</li>
<li>#else 用于提供用于编译的可选代码与else类似，而#elif与else if类似，记住有#if的地方就有#endif。</li>
</ul>

---

<h5>1.4.#ifdef,#else,endif</h5>

这组指示字用于判断宏是否被定义。每个指示字都要和`#endif`对应。

---

<h5>1.5.#include</h5>

查找相应文件，将它的内容插入文本。
include的指示字有两种形式，一种常用于系统头文件，名字由尖括号包围，另一种是用户自己定义的头文件，用引号包围：

	#include <syshead.h>
	#include "userhead.h"

下面是他的规则：

<ul>
<li>尖括号包围的文件名会另查找从-I选项说明的目录开始，然后继续查找系统目录的标准集合。由引号包围的文件名会导致首先查找当前工作目录，然后再查找尖括号应该查找的地方。</li>
<li>GCC编译C++程序，预处理器会先查找/include/g++v3。</li>
<li>可以用相对路径。不管在什么系统下，斜线总是路径的分隔符。</li>
<li>可以用#define定义文件名。</li>
</ul>

---

<h5>1.6.#include_next</h5>

它用在头文件内部来包含其它头文件，会令新头文件的查找从当前头文件的目录之后的目录开始。

这个指示字可以用于修改系统头文件的定义，但不会修改系统头文件本身。例如，系统头文件stdio.h包含宏定义getc，从输入流中读出一个字节，要改变这个宏定义，让它总是返回同一个字符，但保留头文件的其它内容，可以创建自己的stdio.h头文件，包含下面的内容：
	
	#include_next "stdio.h"
	#undef getc
	#define getc(fp) ((int)'x')

使用这个头文件会包含系统的stdio.h和自己重定义的getc。

---

<h5>1.7.#line</h5>

编译程序在编译插入目标代码中的表但时会使用行号。

例如，实现SQL语句的方法通常就是将他们写成宏，然后用特殊的处理器将这些宏扩展为具体的SQL函数调用。这些扩展可以在很多行中进行运行，这样计算行号就很困难。我们需要通过在输出中插入#line进行更正。

下面是它的规则：

<ul>
<li>为#line指定一个数字，会令预处理程序将当前行号替换为指定行号。例如，下面的例子设置当前行号为129：
<pre>#line 129</pre>
</li>
<li>为#line指定文件名，会改变行号以及当前文件的名字，例如，下面的例子会设置当前位置为文件muggles.h的第一行：
<pre>#line 1 "mugggles.h"</pre>
</li>
<li>会修改预定义宏__LINE__和__FILE__的内容。</li>
<li>对#include没影响。</li>
</ul>

---

<h5>1.8.#pragma和_Pragma</h5>

dependency pragma测试当前文件的时间戳，对比其他文件的时间戳。如果其他文件更新，就发出警告信息。例如下面的例子测试文件lexgen.tbl的时间戳：

	#pragma GCC dependency "lexgen.tbl"

如果lexgen.tbl文件比当前文件新，处理器就会产生如下信息：

`warning: current file is older than "lexgen.tbl`

可以加入其他信息：
	
	#pragma GCC dependency "lexgen.tbl" Header lex.h needs to be updated

它会创建下面的警告消息：

	show.c:26:warning: current file is older than "lexgen.tbl
	show.c:26:warning: Header lex.h needs to be updated

poison pagma在每次使用指定名字的时候都会发出消息。下面的例子在调用memcpy副本函数式就会发出警告消息：

	#pragma GCC poison memcpy memmove
	memcpy(target,source,size);

产生如下警告信息：

`show.c:38:9: attempt to use poisoned "memcpy"`

一般的宏不能包含#pagma，所以设计了_Pragma：

	 _Pragma("GCC poison printf")

---

<h5>1.9.#undef</h5>

就是去掉宏。

---

<h5>1.10.##</h5>

链接符：

	#define PASTE(a) a##house
	result = PASTE(farm);
结果为：
	result = formhouse;


---

<h3 style="color:#706BF5">2.预定义的宏</h3>

执行
<pre class="prettyprint">
cpp -dM /dev/null
</pre>
就行了。详细可以查看[么刚的专栏
](http://blog.csdn.net/sealyao/article/details/6169568)。

---

<h3 style="color:#EEFF87">3.只包含一次头文件</h3>

程序可能多次包含同样的头文件，可以用下面的方法避免多次编译：

	/*myheader.h*/
	#ifndef _MYHEADER_H_
	#define _MYHEADER_H_
	/*
	**body here
	*/
	#endif /*_MYHEADER_H_*/


---

<h3 style="color:#DF7AF8">4.在出错信息中包含定位信息</h3>

使用预定义的宏就可以了，例如：

	#define msg(str) \
		fprintf(stderr,"File: %s Lie: %d Function: %s\n%s\n",\
		__FILE__,__line__,__func__,str);

---

<h3 style="color:#FC8E34">5.去掉适当的源代码</h3>

不是注释掉，注释终有一天会出问题的,因为注释不能互相嵌套。用下面的方法：

	#if 0
	/*code to be remove*/
	#endif

---

<h3 style="color:#5111F1">6.产生make程序描述文件</h3>

没用过，以后再写。基本是这个用法：
	
	gcc -E -M strick.c

---

<h3 style="color:pink">end</h3>
