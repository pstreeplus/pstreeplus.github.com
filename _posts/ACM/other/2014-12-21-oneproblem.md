---
title: 一道小题
layout: post

---

在网上看到了一道面试题，是下面这样的


>给定一个字符串的集合，格式如：{aaabbbccc}，{bbbddd}，{eeefff}，{ggg}，{dddhhh}要求将其中交集不为空的集合合并，要求合并完成后的集合之间无交集，例如上例应输出{aaabbbcccdddhhh}，{eeefff}，{ggg}。


网上给出的答案是


>集合使用hash_set来表示，这样合并时间复杂度比较低。

>1、给每个集合编号为0，1，2，3...

>2、创建一个hash_map，key为字符串，value为一个链表，链表节点为字符串所在集合的编号。遍历所有的集合，将字符串和对应的集合编号插入到hash_map中去。

>3、创建一个长度等于集合个数的int数组，表示集合间的合并关系。例如，下标为5的元素值为3，表示将下标为5的集合合并到下标为3的集合中去。开始时将所有值都初始化为-1，表示集合间没有互相合并。在集合合并的过程中，我们将所有的字符串都合并到编号较小的集合中去。

>遍历第二步中生成的hash_map，对于每个value中的链表，首先找到最小的集合编号（有些集合已经被合并过，需要顺着合并关系数组找到合并后的集合编号），然后将链表中所有编号的集合都合并到编号最小的集合中（通过更改合并关系数组）。


下面我给出我认为更优且更容易实现的方法，时间复杂度为O(len)，空间复杂度为O(n)，len为所有字符串长度之和。

>1.开一个长度26的数组（假设都是小写字母），记录每个字母出现的最早位置。

>2.根据第一步可以很容易确定每个字符串应该属于哪个集合，就是该字符串中字母出现最早的位置的最小值，并将其加入集合，可以用vector记录下下标。

>3.根据第二步，统计每个集合中每个字符出现的最多的次数，即为答案中该字符的数量。


实现如下

```cpp
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int p[26],cnt[26];
vector<string>v;
vector<int>u[1000];
int main(){
    string s;
    freopen("in.cc","r",stdin);
    v.clear(),s.clear();
    memset(p,-1,sizeof p);
    while(cin >> s){
        v.push_back(s);
        int minm = 0x7ffffff;
        for(int j = 0;j < s.size();j ++){
            int idx = s[j] - 'a';
            if(p[idx] == -1) p[idx] = v.size()-1;
            minm = min(minm,p[idx]);
        }
        for(int j = 0;j < s.size();j ++) 
            p[s[j]-'a'] = min(p[s[j]-'a'],minm);
    }
    for(int i = 0;i < v.size();i ++){
        int minm = 0x7fffffff;
        for(int j = 0;j < v[i].size();j ++) 
            minm = min(minm,p[v[i][j]-'a']);
        u[minm].push_back(i);
    }
    for(int i = 0;i < v.size();i ++){
        memset(p,0,sizeof p);
        for(int j = 0;j < u[i].size();j ++){
            memset(cnt,0,sizeof cnt);
            for(int k = 0;k < v[u[i][j]].size();k ++){
                int idx = v[u[i][j]][k] - 'a';
                cnt[idx] ++;
                p[idx] = max(p[idx],cnt[idx]);
            }
        }
        if(u[i].size()) printf("{");
        for(int j = 0;j < 26;j ++){
            for(int k = 0;k < p[j];k ++) 
                printf("%c",j + 'a');
        }
        if(u[i].size()) printf("}\n");
    }
    return 0;
}
```
