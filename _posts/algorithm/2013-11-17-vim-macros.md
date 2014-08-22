---
layout: post
title: vim基础笔记
description: "vim是一个出色的文本编辑器，给你更多便利的同时，你必须付出与之匹配的学习时间。使用vim，让你拥有健康的小拇指。"
categories: 技术
date: 2013-11-17
image: 
        feature: sansri.jpg
---

如果你是一个vim的初学者，想通过网上的文章掌握，说实话，那不是一个好办法，至少这篇文章不是一个好选择。最好的方法应该是在命令行里输入：
```
vimtutor
```
并随着那个教程练习直到熟练掌握那上面的命令。会使用vim并不是什么了不起的知识，不过是一种技能，熟练程度的不同会影响你编写各种文当的舒适度罢了。如果你不想看无聊的教程，有人写了一个小游戏，可以在[这个传送门里](http://vim-adventures.com/)学习。也有很多人写了一些vim的入门，就我而言，比较喜欢的是这个：[Learn Vim Progressively](http://yannesposito.com/Scratch/en/blog/Learn-Vim-Progressively/)。这时候估计又有人
在抱怨了：“为什么只推荐一个？”这个世界本来应该很简单的，我为什么要增加读者作选择的负担呢？上面的文章是英文的，我会在下面简单的传达一下文章的意思。

<h3>基础入门</h3>

[先在这里找到安装](http://www.vim.org/)

其实整篇文章都是基础入门，我实在找不出更好的词了。如果你已经完成了vimtutor的学习，应该知道下面的东西。

vim和其它的编辑器是不一样的，当你打开它，就会发现没有办法在上面打字。vim有三个模式，分别是 Normal, Insert,Visual。刚开始进入的应该是Normal模式，这个模式下可以输入一些命令, 在其它模式下只要按下[ESC]键就可以进入。如果你想在vim里面输入一些文字，需要进入Insert模式，按下i键就可以了。还有一个模式是Visual，按v键可以进入，用于选择一些部分。

上下左右也可以使用键盘上的上下左右键，更好的办法是使用hjkl。为什么使用这四个键呢？当你看到古老的UNIX终端的键盘就会明白了。有人反对使用这四个键代替上下左右，估计是不习惯吧。很多人对知识的态度就是简单的学的好就是好东西，自己学不会就喷，这可不是个好习惯。努力习惯这个改变，因为这个对我这个懒人来说是很有用的技巧。

如果在使用过程中遇到了什么问题，可以按公认的帮助键，也就是[F1]打开帮助文档。如果对哪个命令不清楚，可以进入Normal模式，输入':help [command][enter]'。其中冒号和回车是必须的，后面可以跟你需要查找的命令。 此外，我们还需要掌握一些必要的命令： 

<ul>
<li>x <small>Normal模式下删除一个字符。</small></li>
<li>:wq <small>保存并退出。</small></li>
<li>dd <small>删除一行。</small></li>
<li>p <small>粘贴vim默认粘贴版的内容。当你使用d命令或者y命令时，选中的内容会进入默认粘贴版。</small></li>
<li>yy <small>复制一行到默认粘贴版。</small></li>
<li>"+p <small>粘贴出系统粘贴版的内容。如果你在其它程序里复制了一些内容，可以使用这个命令粘贴到vim里。</small></li>
<li>"+y <small>复制到系统粘贴版。</small></li>
</ul>

好了，我们来练习一下吧，如果你已经安装了GCC，先写一段小程序：

在命令行中输入：gvim test.c

然后输入一个小程序：

{% highlight C linenos %}
#include<stdio.h> 
 
int main(int argc, char *argv[]) { 
    int flag = 0; 
    char passwd[10]; 
    memset(passwd,0,sizeof(passwd)); 
    strcpy(passwd, argv[1]); 
    if(0 == strcmp("LinuxGeek", passwd)) { 
        flag = 1; 
    } 
    if(flag) { 
        printf("\n Password cracked \n"); 
    } 
    else { 
        printf("\n Incorrect passwd \n"); 
    } 
    return 0; 
} 
{% endhighlight %}

进入Normal模式，输入命令:w保存。你当然可以输入终端命令，只要使用感叹号。我们先编译这个程序, 输入：:!gcc test.c -o testrun。

然后运行：:!testrun

如果你有兴趣的话，可以尝试不知道密码的情况下通过验证，不过这不是今天我们的重点。

<h3>应该有更高的追求</h3>

上面的东西只够在只有vim的环境下存活，要用的好，还有其它东西需要学。

[点击这里通向vim常用命令](http://quant67.com/%E6%8A%80%E6%9C%AF/VIM-cammand/)

<h3>使用特性</h3>

不管怎么说，我们都不应该把时间浪费在重复的事情上面。

<ul>
    <li>.(小数点)  可以重复上一次的命令。试着依次按下[ESC]iI am sorry![ESC]]  然后再按下99.(别忘记小数点), vim就可以帮你完成老师的处罚任务了。</li>
    <li>要完成上面的工作你也可以按照这个方式：[ESC]100iI am sorry![ESC], 在命令前面加上数字就表示重复次数。比如3p(不要想歪，粘贴3次默认寄存器的内容)，3dd(删除3行)。</li>
</ul>

还有一些需要重复的工作，但不是简单重复，我们就需要用到宏。玩过《魔兽世界》的朋友都应该知道宏这个概念吧，它可以记录你一系列键盘操作，当你调用宏 的时候，它就会把记录下的键盘操作释放出来。这在处理类似下面这张图片上的问题时很有用。

<figure>
	<img src="/images/vim-macro/vim-macros.gif">
	<figcaption>repeat the same editor commands over and over</figcaption>
</figure>

在Normal模式下按q，然后选择一个宏的名字，我通常选择q，然后vim就会开始记录你的键盘操作。当你再次在Normal模式下按q时，记录就会停止。如果要调用宏，使用'@+宏的名字'的方式。

举个例子，假设现在vim里已经有了下面这行字, 他在整个文件的第一行。

{% highlight C linenos %}
array[0] = "0"; 
{% endhighlight %}

按下[ESC]进入Normal模式，按gg到达第一行，按yy复制这一行，按p粘贴，按f[l移动光标到0的位置，按[c-a]（就是Ctrl+a）增加所在数字的大小，按f"l到达后面双引号的数字，按[c-a]增加它的值，然后按q结束录制，按99@q调用这个宏, 集就可以看到效果了。差点忘了，这个功能是不能递归调用的。

我最喜欢的vim命令是自动缩进，按v进入Visual模式，选择一些代码，然后按 = 给缩进，按 J 合并这些行。

使用过[sublimetext](http://www.sublimetext.com/)的朋友一定对它的大招很痴迷，就是在窗口内多处同时产生一个光标，然后同时统一修改, 酷毙了。sublime也支持我所习惯的vim操作，但是一直无限期试用或者直接破解是在不厚道，于是一直用vim，这才让我发现它的无所不能。

如果要查找一些词，比如errror, 只需要在Normal模式下输入/errror就可以了，按n调转到下一个, 如果需要查找的词在文件里，可以直接按*或者#。如果需要替换文件里所有的errror为error, 只需要输入":%s/errror/error/g"就可以了，这里面%意思是整个文件，你也可以使用Visual模式选择以代替它。

vim里有自动补全功能，只要按[C-p]或者[C-n]就行了，很少看到有人使用这个功能，即使是vim的老用户，也很少知道这个功能吧, 不过装了插件结果是一样的。

最后，split filename1 和:vsplit filename2是分屏命令，：tabnew filename 是分页命令。

