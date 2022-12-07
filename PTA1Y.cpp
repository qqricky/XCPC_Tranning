#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    cin>>n;
    char ch;
    cin>>ch;
    char strr[10010]={};
    int pos=0;
    cin.get();
    cin.get(strr,10010);
    for(int i=10009;i>=0;i--){
        if(strr[i]){
            pos=i;
            break;
        }
    }
    string str;
    for(int i=0;i<=pos;i++)str+=strr[i];
    int len=str.size();
    for(int i=1;i<=n-len;i++)cout<<ch;
    if(len>=n){
        str=str.substr(len-1-n+1,n);
    }
    cout<<str;
    //system("pause");
    return 0;
}