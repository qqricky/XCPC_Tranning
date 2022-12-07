#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int g[]={1869,1968,1689,6198,1698,1986,1896};
int mo[]={1,3,2,6,4,5};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    int len=str.length();
    str=' '+str;
    int cnt=0;
    int f1=1;
    int f2=1;
    int f3=1;
    int f4=1;
    int k=len-1;
    for(int i=1;i<=len;i++){
        if(f1&&str[i]=='1'){f1=0;continue;}
        if(f2&&str[i]=='6'){f2=0;continue;}
        if(f3&&str[i]=='8'){f3=0;continue;}
        if(f4&&str[i]=='9'){f4=0;continue;}
        cout<<str[i];
        cnt=(cnt+(str[i]-'0')*mo[k%6])%7;
        k--;
    }
    if(cnt==0)cnt=7;
    cout<<g[7-cnt];
    //cout.flush();
    //system("pause");
    return 0;
}