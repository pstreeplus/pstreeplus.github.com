---
title: 优才网自动签到
layout: post
category: 编程语言
tags: Python
---


写了个忧才网[http://www.ucai.cn/]的自动签到程序，玩玩，就当Python练手吧。


```
#!/usr/bin/env python
# -*- coding:utf-8 -*-

import urllib
import urllib2
import cookielib

class SignUcai:
    def inputInfo(self):
        self.postdate = {}
        self.loginpostdate = {}
        self.username = raw_input("输入用户名：")
        self.password = raw_input("输入密码：")
        self.loginpostdate['remember'] = 1
        self.loginpostdate['email'] = self.username
        self.loginpostdate['password'] = self.password
        self.content = raw_input("输入签到内容: ")
        self.postdate['xq'] = 'kx'
        self.postdate['say'] = self.content
        self.postdate = urllib.urlencode(self.postdate)
        self.loginpostdate = urllib.urlencode(self.loginpostdate)


    def login(self):
        self.loginurl = 'http://www.ucai.cn/index.php?app=home&mod=Public&act=doAjaxLogin'
        self.url = 'http://www.ucai.cn/index.php?app=home&mod=Widget&act=addonsRequest&addon=V63qiandao&hook=qddo'
        self.cj = cookielib.CookieJar();
        self.opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(self.cj))
        urllib2.install_opener(self.opener)
        self.inputInfo()
        self.opener.open(self.loginurl,self.loginpostdate)


    def work(self):
        self.login()
        reqs = urllib2.Request(self.url)
        fd = urllib2.urlopen(reqs)
        print fd.read()


if __name__ == '__main__':
    ucai = SignUcai()
    ucai.work()

```
