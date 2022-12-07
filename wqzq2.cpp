#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
int f[N];
int main()
{
    freopen("TestCase.in","r",stdin);
    freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int pos;
    string str;
    cin>>str;
    int len=str.length();
    str=' '+str;
    int ans=0;
    f[0]=0;
    for(int i=1;i<=len;i++){
        f[i]=1;
        if(str[i-f[i-1]-1]==str[i]){
            f[i]=f[i-1]+2;
            if(f[i]>ans){
                ans=f[i];
                pos=i;
            }
        }
        else if(str[i]==str[i-2]){
            f[i]=max(f[i],3);
            if(f[i]>ans){
                ans=f[i];
                pos=i;
            }
        }
        else if(str[i]==str[i-1]){
            f[i]=max(f[i],2);
            if(f[i]>ans){
                ans=f[i];
                pos=i;
            }
        }
    }
    cout<<pos<<endl<<ans<<endl;
    for(int i=pos-ans+1;i<=pos;i++)cout<<str[i];
    //cout<<endl;
    //system("pause");
    return 0;
}