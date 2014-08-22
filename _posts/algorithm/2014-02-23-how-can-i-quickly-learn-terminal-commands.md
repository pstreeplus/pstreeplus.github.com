---
layout: post
title: 如何快速学习终端命令？
category : 技巧
description: "在我看来，学习如何使用终端是学习如何使用Ubuntu的先决条件。所以我试图找出最好的学习方法。"
tags : [terminal, os, computer]
---

[在lifehacker上查看原文](http://lifehacker.com/how-can-i-quickly-learn-terminal-commands-1494082178)

![pict](/images/terminal-commans/ku-xlarge.jpg)

到目前为止拿鼠标点来点去只会让你远离Ubuntu。对于那些真的想使用"另一个操作系统"的人，学习终端命令是重要的一步。在 [Ask Ubuntu](http://askubuntu.com/?utm_source=lifehacker&utm_medium=syndication&utm_campaign=crowdhacker&utm_content=ubuntu-99)上，专家们提供了学习shell最好的方法。

在我看来，学习如何使用终端是学习如何使用Ubuntu的先决条件。所以我试图找出最好的学习方法。

在[这里](http://askubuntu.com/questions/337300/are-there-any-games-which-can-train-people-to-learn-terminal-commands)查看原始问题。

##随机学习（[Answered by Radu Rădeanu](http://askubuntu.com/questions/337300/are-there-any-games-which-can-train-people-to-learn-terminal-commands/337382#337382)）

你可以在你的·~/.bashrc·文件的结尾添加下面这行命令：

    echo "Did you know that:"; whatis $(ls /bin | shuf -n 1)

每次你打开终端，都会随机地学到一个命令。

如果你想找一些乐子，可以使用cowsay。运行下面的命令可以安装：

    sudo apt-get install cowsay

然后在你的·~/.bashrc·文件结尾添加下面一行：

    cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1)

或者可以用别名 ，添加到·~/.bash_aliases·里。我加入了下面一行：

    alias ?='cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1)'

无论何时，当你觉得无聊的时候，就可以在终端里输入："?"（后面跟一个回车）。 这就像自己玩骰子。

##whatis（[Answered by Achu](http://askubuntu.com/questions/337300/are-there-any-games-which-can-train-people-to-learn-terminal-commands/337303#337303)）

我经常玩"whatis"。这不是一个游戏，但它是学习终端命令的相对简单的方法。举个例子，输入：

    whatis sudo apt-get update

它返回的是：

![pict](/images/terminal-commans/ku-xlarge.png)

在运行命令之前，我都会用"whatis"。我学习了我要做的事，这样我会满怀信心地使用这些命令。

如果"whatis"没有提供足够的信息，或者描述不够清楚，我接着就会查看文档（man），比如：

    man sudo

关于这个问题，Google给了你很多，不管是来自[AskUbuntu](http://askubuntu.com/?utm_source=lifehacker&utm_medium=syndication&utm_campaign=crowdhacker&utm_content=ubuntu-99)或者其它。在这里，LMGTFY:[best way to learn terminal commands on Ubuntu](http://www.google.co.uk/search?&q=best%20way%20to%20learn%20terminal%20commands%20on%20ubuntu&cad=h)。

##一个游戏（[Answered by snim2](http://askubuntu.com/questions/337300/are-there-any-games-which-can-train-people-to-learn-terminal-commands/337507#337507)）

Terminus就是这样一个游戏，能帮助你学习终端命令。[这里](http://web.mit.edu/mprat/Public/web/Terminus/Web/main.html)是它的一个还运行的版本。它的代码托管在在[Github](https://github.com/mprat/Terminus)上。这是个好点子，虽然我期望它的代码更容易拓展。

##终端不是学习Ubuntu的先决条件（[Answered by avernet](http://askubuntu.com/questions/337300/are-there-any-games-which-can-train-people-to-learn-terminal-commands/337424#337424)）

Ubuntu的设计是用户友好的。学习如何使用终端并不是学习如何使用Ubuntu的先决条件。除非你想成为一个超级用户或者想自己排除故障。

关于你的问题，我没听说过任何设计出来教别人学习终端命令的游戏，但是我强烈推荐下面bash和系统管理的相关资源：

[UNIX Tutorial for Beginners](http://www.ee.surrey.ac.uk/Teaching/Unix/) （注意，这个教程使用Red Hat,而且引用了一些只适用于Surrey大学学生的路径。）

[BASH Programming - Introduction HOW-TO](http://www.tldp.org/HOWTO/Bash-Prog-Intro-HOWTO.html)（托管在Linux文档项目里，作者是Mike G。）

[Bash Shell Scripting](http://en.wikibooks.org/wiki/Bash_Shell_Scripting)（Wikipedia）

[Study manuals](http://www.nongnu.org/lpi-manuals/manual/)（LPI）

[GNU Bash Reference Manual](http://www.gnu.org/software/bash/manual/bashref.html)

[Advanced Bash-Scripting Guide](http://linux.die.net/abs-guide/)（Mendel Cooper）


