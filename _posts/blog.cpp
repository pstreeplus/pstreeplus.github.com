#include<ctime> 
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iostream>
using namespace std;
int main(int argc,char **argv) {
    tm *ymd;
    ofstream ff;
    char cmd[100],filename[100];
    time_t t = time(0); 
    ymd=localtime(&t);
    sprintf(cmd,"gvim %d-%02d-%02d-%s.markdown",ymd->tm_year + 1900,ymd->tm_mon + 1,ymd->tm_mday,argv[1]);
    sprintf(filename,"%d-%02d-%02d-%s.markdown",ymd->tm_year + 1900,ymd->tm_mon + 1,ymd->tm_mday,argv[1]);
    ff.open(filename);
    ff << "---\ntitle: " << argv[1] << "\nlayout: post\n\n---\n\n";
    system(cmd);
    return 0;
}
