#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int divide(ll x,int *bit)
{
    int pos=0;
    while(x)
    {
        bit[++pos]=x%2;
        x>>=1;
    }
    return pos;
}
int bit1[150]={};
int bit2[150]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        int aa[150]={};
        memset(bit1,0,sizeof(bit1));
        memset(bit2,0,sizeof(bit2));
        memset(aa,0,sizeof(aa));
        if(a==b){
            cout<<"YES"<<endl;
            continue;
        }
        else if(a>b){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            int pos=divide(b,bit1);
            divide(a,bit2);
            int flag=1;
            for(int i=1;i<=pos;i++){
                if(bit1[i]<bit2[i]){
                    aa[i]=aa[i-1]+1;
                }
                else if(bit1[i]>bit2[i]){
                    aa[i]=aa[i-1]-1;
                    if(aa[i]<0){
                        flag=0;
                        break;
                    }
                }
                else{
                    aa[i]=aa[i-1];
                }
            }
            if(bit2[pos]&&aa[pos]){
                for(int j=pos;j>=1;j--){
                    if(aa[j]<aa[j-1])break;
                    else if(aa[j]>aa[j-1]){
                        flag=0;
                        break;
                    }
                }
            }
            if(flag)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    //system("pause");
    return 0;
}