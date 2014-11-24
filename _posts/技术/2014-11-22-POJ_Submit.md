---
title: POJ交题客户端
layout: post
category: 编程语言
tags: Python
---



花了一晚上时间写了个POJ的客户端交题的程序，Python写的，不需要使用浏览器登录，只要在终端输入用户名，密码，题号，源代码文件就行，并自动返回评测结果。感觉还是挺好玩的。


已经打包成exe了（放到了github上了），可以在没有Python环境的windows下运行。



        




```python
#-*- coding:utf8 -*-

import os
import sys
import time
import urllib2
import cookielib
import subprocess
from urllib import urlencode

class Poj_Submit_problem:

    def __init__(self):
        self.inputUserInfo()
        self.url = 'http://poj.org/login'
        self.submiturl = 'http://poj.org/submit'
        self.statusturl = 'http://poj.org/status'


    def inputUserInfo(self):
        self.postdata = {}
        self.postdata['B1'] = 'login'
        self.postdata['url'] = '/'
        self.postdata['user_id1'] = raw_input("输入用户名：")
        self.postdata['password1'] = raw_input("输入密码：")
        self.username = self.postdata['user_id1']
        self.postdata = urlencode(self.postdata)


    def login(self):
        cj = cookielib.CookieJar();
        opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj));
        urllib2.install_opener(opener)
        try:
            opener.open(self.url,self.postdata)
        except urllib2.URLError as e:
            raise e


    def getStatus(self,proid):
        time.sleep(0.5)
        time.sleep(0.5)
        reqs = urllib2.Request(self.statusturl)
        fd = urllib2.urlopen(reqs)
        htmlcode = fd.read()
        s = self.username + '</a></td><td><a href=problem?id=' + str(proid) + '>' + str(proid)
        pos = htmlcode.find(s)
        htmlcode = htmlcode[pos:]
        pos = htmlcode.find('color')
        htmlcode = htmlcode[pos:]
        l = htmlcode.find('>')
        r = htmlcode.find('<')
        result = htmlcode[l+1:r]
        if result == "":
            print "username or password is not correct"
            self.inputUserInfo()
            self.submit(self.prodate)
        else:
            print "Submiting ..."
            print "Running && Judging ..."
            time.sleep(4)
            htmlcode = htmlcode[r:]
            pos = htmlcode.find('<td>')
            htmlcode = htmlcode[pos+4:]
            r = htmlcode.find('<')
            memory = htmlcode[:r]
            htmlcode = htmlcode[htmlcode.find('<td>')+4:]
            r = htmlcode.find('<')
            t = htmlcode[:r]
            print "         -------------------------------"
            print ("          %s      %s      %s   \n") % ("Result","Memory","Time")
            print ("          %s     %s       %s   ") % (result ,memory,t)
            print "         -------------------------------"


    def submit(self,postdata = {}):
        try:
            self.login()
        except:
            print "network is not connect"
            exit(0)
        if  postdata == {}:
            postdata['language'] = 0
            postdata['submit'] = 'Submit'
            postdata['problem_id'] = int(raw_input("输入题号："))
            filename = raw_input("输入源文件名：")
            self.prodate = postdata
            code = ""
            try:
                for line in open(filename,'r'):
                    code += line
            except:
                print "the file is not exist!"
            postdata['source'] = code
        try:
            postdata = urlencode(postdata)
            proid = self.prodate['problem_id']
            reqs = urllib2.Request(self.submiturl,postdata)
            urllib2.urlopen(reqs)
            self.getStatus(proid)
        except:
            print "unknow error"


if __name__ == '__main__':
    submits = Poj_Submit_problem()
    submits.submit()

```
