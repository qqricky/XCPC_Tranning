#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
const int N=2070;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
bitset<2070>bsp[N];
bitset<2070>bsq[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        for(int i=1;i<=n;i++){
            cin>>str;
            str=' '+str;
            bsp[i].reset();
            bsq[i].reset();
            for(int j=1;j<=n;j++){
                if(str[j]=='P'){
                    bsp[i][j]=1;
                }else if(str[j]=='Q'){
                    bsq[i][j]=1;
                }
            }
        }
        bool flag=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(bsq[i][j]){
                    bitset<2070>tmp=bsq[i]|bsq[j];
                    if(tmp!=bsq[i]){
                        flag=0;
                        break;
                    }
                }
                if(bsp[i][j]){
                    bitset<2070>tmp=bsp[i]|bsp[j];
                    if(tmp!=bsp[i]){
                        flag=0;
                        break;
                    }
                }
            }
        }
        if(flag){
            cout<<"T\n";
        }else{
            cout<<"N\n";
        }
    }
    // cout.flush();
    // system("pause");
    return 0;
}