#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    char ch;
    cin>>ch;
    char strr[10010];
    char c;
    scanf("%c",&c);
    int pos=0;
    while(c!='\n'){
        strr[++pos]=c;
        scanf("%c",&c);
    }
    string str;
    for(int i=0;i<10010;i++){
        if(strr[i]=='\n'){
            pos=i;
            break;
        }
    }
    for(int i=0;i<pos;i++)str+=strr[i];
    int len=str.size();
    cout<<len<<endl;
    for(int i=1;i<=n-len;i++)cout<<ch;
    if(len>=n){
        str=str.substr(len-1-n+1,n);
    }
    cout<<str;
    //system("pause");
    return 0;
}