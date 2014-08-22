---
title: 简化markdown + Jekyll的操作
layout: post
---

使用`Jekyll`生成github page时，文件命名必须符合它的规范，它可以把你用`markdown`标记语言写的md文件动态的解析成html文本，用于生成轻量级Blog.

比如要写个名为`test`的文件，你必须以`2014-08-22(year-month-day)`的形式来命名，这样就显得有点麻烦。为了简化操作，我们可以自己写个脚本或者写个小程序来自动帮你完成这些乏味的操作，把精力放在有意义的事情上。



```CPP
#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;
int main(int agrc,char **argv){
    time_t t = time(0);
    tm* ymd = localtime(&t);
    char cmd[100],filename[100];
    int day = ymd->tm_mday;
    int y = ymd->tm_year + 1900;
    int month = ymd->tm_mon + 1;
    sprintf(cmd,"gvim %d-%02d-%02d-%s.md",y,month,day,argv[1]);
    sprintf(filename,"%d-%02d-%02d-%s.md",y,month,day,argv[1]);
    ofstream ff;
    ff.open(filename);
    ff << "---\ntitle: " << argv[1] << "\nlayout: post\n\n---\n\n";
    system(cmd);
    return 0;
}
```



