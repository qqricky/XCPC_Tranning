#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
const int mod=11380;
int f[12][12][12][32]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int l1,l2,l3,D;
    cin>>l1>>l2>>l3>>D;
    for(int i=0;i<=D;i++)f[0][0][0][i]=1;
    for(int d=1;d<=D;d++){
        for(int la=0;la<=l1;la++)for(int lb=0;lb<=l2;lb++)for(int lc=0;lc<=l3;lc++){
            if(la+lb+lc==0)continue;
            ll sum=0;
            for(int p=1;p<=la;p++)for(int q=0;q<=lb;q++)for(int r=0;r<=lc;r++){
                sum=(sum+f[p-1][q][r][d-1]*f[la-p][lb-q][lc-r][d]%mod)%mod;
            }
            for(int q=1;q<=lb;q++)for(int r=0;r<=lc;r++){
                sum=(sum+f[0][q-1][r][d-1]*f[la][lb-q][lc-r][d]%mod)%mod;
            }
            for(int r=1;r<=lc;r++){
                sum=(sum+f[0][0][r-1][d-1]*f[la][lb][lc-r][d]%mod)%mod;
            }
            f[la][lb][lc][d]=sum;
        }
    }
    cout<<(f[l1][l2][l3][D]-f[l1][l2][l3][D-1]+mod)%mod<<endl;
    //system("pause");
    return 0;
}