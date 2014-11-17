---
title: 后缀数组
layout: post
category: 数据结构
tags: 字符串
---


最近学习后缀数组，啃论文啃了快俩星期了（中间有间断），真尼玛觉得智商严重不够用了，论文看得好费劲。。。，题目也不会做。。。，真是弱爆了。

先仍个模板放这。。。

```cpp
struct SuffixArray{
    int rank[MAXN],sa[MAXN],r[MAXN];
    int wa[MAXN],wb[MAXN],wv[MAXN],wd[MAXN],height[MAXN];
    inline bool cmp(int *r,int a,int b,int len){
        return r[a] == r[b] && r[a+len] == r[len+b];
    }
    inline void da(int *r,int *sa,int n,int m){
        int i,j,p,*x = wa,*y = wb,*t;
        for(i = 0;i < m;i ++) wd[i] = 0;
        for(i = 0;i < n;i ++) wd[x[i] = r[i]] ++;
        for(i = 0;i < m;i ++) wd[i] += wd[i-1];
        for(i = n-1;i >= 0;i --) sa[--wd[x[i]]] = i;
        for(j = 1,p = 1;p < n;j *= 2,m = p){
            for(p = 0,i = n-j;i < n;i ++) y[p++] = i;
            for(i = 0;i < n;i ++) if(sa[i] >= j) y[p++] = sa[i] - j;
            for(i = 0;i < n;i ++) wv[i] = x[y[i]];
            for(i = 0;i < m;i ++) wd[i] = 0;
            for(i = 0;i < n;i ++) wd[wv[i]] ++;
            for(i = 0;i < m;i ++) wd[i] += wd[i-1];
            for(i = n-1;i >= 0;i --) sa[--wd[wv[i]]] = y[i];
            for(t = x,x = y,y = t,p = 1,x[sa[0]]=0,i=1;i < n;i ++)
                x[sa[i]] = cmp(y,sa[i-1],sa[i],j) ? p - 1 : p ++;
        }
    }
    inline void calHeight(int *r,int *sa,int n){
        int i,j,k = 0;
        for(i = 1;i <= n;i ++) rank[sa[i]] = i;
        for(i = 0;i < n; height[rank[i++]] = k)
            for(k ? k -- : 0,j = sa[rank[i]-1];r[i+k] == r[j+k];k ++);
    }
    inline void work(int *r,int *sa,int n,int m){
        da(r,sa,n+1,m);
        calHeight(r,sa,n);
    }
```
