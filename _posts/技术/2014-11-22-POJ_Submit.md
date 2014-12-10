---
title: POJ交题客户端
layout: post
category: 编程语言
tags: Python
---



POJ的客户端交题的程序，Python实现，不需要使用浏览器登录，只要在终端输入用户名，密码，题号，源代码文件就行，并自动返回评测结果。


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
        self.postdata['user_id1'] = raw_input("username: ")
        self.postdata['password1'] = raw_input("password: ")
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
        print "Submiting ..."
        time.sleep(3.5)
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
            print "submited"
            time.sleep(1.5)
            print "Running && Judging ..."
            time.sleep(1.5)
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
            postdata['language'] = raw_input("language: 0:G++ 1:Gcc 2:Java 3:Pascal 4:C++ 5:C 6:Fortran\nselect: ")
            postdata['submit'] = 'Submit'
            postdata['problem_id'] = int(raw_input("problem id: "))
            filename = raw_input("source file name: ")
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
            print "submit failed,unknow error"


if __name__ == '__main__':
    submits = Poj_Submit_problem()
    submits.submit()

```
