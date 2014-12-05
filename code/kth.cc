#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<string>
#include<climits>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#define LL long long
#define pb push_back
using namespace std;
template <class T>
inline void insertSort(T sit,T eit){
    for(T i = sit + 1;i < eit;i ++){
        T j = i;
        while(j > sit && *j < *(j-1)) swap(*j,*(j-1)),j--;
    }   
}
template <class T>
int find_Kth(T sit,T eit,int k){
    int size = (eit - sit);
    if(k <= 0 || k > size) k = 1;
    if(size <= 20){
        insertSort(sit,sit + size);
        return *(sit + k - 1);
    }
    vector<int>tmp; 
    for(int i = 0;i < size / 5;i ++){
        int t = find_Kth(sit+i*5,sit+(i+1)*5,3);
        tmp.pb(t);
    }
    int base = find_Kth(tmp.begin(),tmp.end(),(size / 5 + 1) / 2 );
    T pos = sit-1;
    for(T i = sit;i < eit;i ++){
        if(*i <= base) ++pos,swap(*pos,*i);
    }
    int rank = pos - sit + 1;
    if(rank == k) return *pos;
    else if(rank > k) return find_Kth(sit,pos,k);
    else return find_Kth(pos + 1,eit,k - rank);
}
inline void input(int &X){cin >> X;}
int main(){
    int n,cnt(1);
    //freopen("in.txt","r",stdin); 输入文件。
    while(~scanf("%d",&n)){
        vector<int>V(n);
        for_each(V.begin(),V.end(),input);
        /*
         *　 输入数据有重复元素时，需要用下面两行代码去重。
         * 　sort(V.begin(),V.end()); 
         * 　V.erase(unique(V.begin(),V.end()),V.end()); 
        */
        for(int j = 0;j < 10;j ++){
            int k = rand() % n + 1;
            int my_ans = find_Kth(V.begin(),V.end(),k);
            /*
             * 　判段结果是否正确。
             * 　直接通过快排验证。
            */
            sort(V.begin(),V.end());
            if(my_ans != V[k-1]){
                printf("Wrong Answer\n");
                printf("in %d-th test\n",cnt);
                printf("The answer should be %d but found %d\n",V[k-1],my_ans);
                return 0;
            }
        }
        cnt ++;
    }
    printf("Correct answer\n");
    return 0;
}
