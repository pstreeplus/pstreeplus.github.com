---
title: ��markdown + Jekyll�Ĳ���
layout: post
---

ʹ��`Jekyll`����github pageʱ���ļ���������������Ĺ淶�������԰�����`markdown`�������д��md�ļ���̬�Ľ�����html�ı�����������������Blog.

����Ҫд����Ϊ`test`���ļ����������2014-08-22(year-month-day)����ʽ���������������Ե��е��鷳��Ϊ�˼򻯲��������ǿ����Լ��¸��ű�����д��С�������Զ����������Щ��ζ�Ĳ�������������ֻ��Ҫ��ע�ص㼴�ɡ�

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
    sprintf(cmd,"gvim %d-%02d-%02d-%s.md",ymd->tm_year+1900,ymd->tm_mon+1,ymd->tm_mday,argv[1]);
    sprintf(filename,"%d-%02d-%02d-%s.md",ymd->tm_year+1900,ymd->tm_mon+1,ymd->tm_mday,argv[1]);
    ofstream ff;
    ff.open(filename);
    ff << "---\ntitle: " << argv[1] << "\nlayout: post\n\n---\n\n";
    system(cmd);
    return 0;
}
```
