#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int cas=0;
    while(t--){
        cas++;
        int n;
        cin>>n;
        cout<<"Case #"<<cas<<": ";
        if(n<7){
            cout<<"Draw\n";
        }else{
            if(n&1){
                cout<<"Panda\n";
            }else if(n>=16){
                cout<<"Sheep\n";
            }else{
                cout<<"Draw\n";
            }
        }
    }
    // cout.flush();
    // system("pause");
    return 0;
}