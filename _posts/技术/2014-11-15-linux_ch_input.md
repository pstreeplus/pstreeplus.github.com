---
title: ubuntu无法输入中文的问题
layout: post
catagory: 技术
tags: 输入法
---


ubuntu本身自带中文输入法，但是当你装其他的输入法时（比如rime，搜狗等）, 可能引发不兼容的问题，导致无法输入中文，研究了下发现ubuntu输入法时基于ibus框架，而我们装得rime和搜狗等是fcitx框架（当然rime也有ibus框架），如果装一者另一者貌似必须卸载掉（至少在我机子上是。。。）。

因为我之前装过搜狗输入法，把ibus卸掉了，今天装rime不小心装了ibus-rime，装完之后就无法输入中文了，弄了好久，后来才发现是装了ibus，然后果断卸掉再安装fcitx-rime，然后就可以输入中文了。


##安装及卸载命令：


```sh
sudo apt-get install ibus-rime
sudo apt-get install fcitx-rime
sudo apt-get install ibus　　　　　
sudo apt-get remove ibus

```


##利益相关


貌似ubuntu下没有太好的中文输入法，而且搜狗输入法ubuntu下有点屎啊。。。，另外rime比起搜狗么确实挺好用的。
