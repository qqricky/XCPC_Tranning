//minamoto
#include<cstdio>
#include<cstring>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
const int N=3e5+5;
char s[N];
int n,p,q,fail[N],cnt[N],len[N],tot,last,ch[N][26];
ll ans;
inline int newnode(int x){
	//建立一个新节点，长度为x 
    len[++tot]=x;return tot;
}
inline int getfail(int x,int n){
	//跳fail指针知道找到后缀回文为止 
    while(s[n-len[x]-1]!=s[n]) x=fail[x];
    return x;
}
int main(){
    scanf("%s",s+1);
    //一堆乱七八糟的初始化 
    s[0]=-1,fail[0]=1,last=0;
    len[0]=0,len[1]=-1,tot=1;
    for(int i=1;s[i];++i){
        s[i]-='a';
        //找到可以回文的位置 
        p=getfail(last,i);
        if(!ch[p][s[i]]){
        	//如果有了转移就不用建了，否则要新建 
            //前后都加上新字符，所以新回文串长度要加2 
            q=newnode(len[p]+2);
            //因为fail指向的得是原串的严格后缀，所以要从p的fail开始找起 
            fail[q]=ch[getfail(fail[p],i)][s[i]]; 
            //记录转移 
            ch[p][s[i]]=q;
        }
        ++cnt[last=ch[p][s[i]]];
    }
    for(int i=tot;i;--i)
    cnt[fail[i]]+=cnt[i],cmax(ans,1ll*cnt[i]*len[i]);
    printf("%lld\n",ans);
    system("pause");
    return 0;
}