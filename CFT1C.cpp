#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10; 
using namespace std;
string str;
int len;
int calc(char ch1,char ch2,char ch3)
{
    int cnt=0;
    for(int i=1;i<=len;i+=3){
        if(str[i]!=ch1)cnt++;
    }
    for(int i=2;i<=len;i+=3){
        if(str[i]!=ch2)cnt++;
    }
    for(int i=3;i<=len;i+=3){
        if(str[i]!=ch3)cnt++;
    }
    return cnt;
}
char ans[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cin>>str;
    str=' '+str;
    len=str.length()-1;
    int tmp=0x3f3f3f3f;
    int pos=0;
    int k;
    k=(calc('R','G','B'));
    if(k<tmp){
        pos=1;
        tmp=k;
    }
    k=(calc('R','B','G'));
    if(k<tmp){
        pos=2;
        tmp=k;
    }
    k=(calc('B','G','R'));
    if(k<tmp){
        pos=3;
        tmp=k;
    }
    k=(calc('B','R','G'));
    if(k<tmp){
        pos=4;
        tmp=k;
    }
    k=(calc('G','B','R'));
    if(k<tmp){
        pos=5;
        tmp=k;
    }
    k=(calc('G','R','B'));
    if(k<tmp){
        pos=6;
        tmp=k;
    }
    if(pos==1){
        ans[1]='R';ans[2]='G';ans[3]='B';
    }
    else if(pos==2){
        ans[1]='R';ans[2]='B';ans[3]='G';
    }
    else if(pos==3){
        ans[1]='B';ans[2]='G';ans[3]='R';
    }
    else if(pos==4){
        ans[1]='B';ans[2]='R';ans[3]='G';
    }
    else if(pos==5){
        ans[1]='G';ans[2]='B';ans[3]='R';
    }
    else{
        ans[1]='G';ans[2]='R';ans[3]='B';
    }
    cout<<tmp<<endl;
    for(int i=1;i<=len;i++){
        if(i<=3)cout<<ans[i];
        else{
            ans[i]=ans[i-3];
            cout<<ans[i-3];
        }
    }
    //cout<<endl;
    //system("pause");
    return 0;
}