#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll f[100][2];
int cnt1[10];
int cnt2[10];
void init(){
    for(int i=0;i<=9;i++){
        cnt1[i]=i+1;
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(i+j<10)continue;
            cnt2[(i+j)%10]++;
        }
    }
    f[0][0]=1;
    f[0][1]=1;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    init();
    while(t--)
    {
        string str;
        cin>>str;
        int pos=str.size();
        ll ans=0;
        int num[12];
        // for(int k=pos-1;k>=0;k--){
        //     num[k]=str[pos-k-1]-'0';
        // }
        // for(int i=0;i<pos;i++){
        //     ans*=cnt1[num[i]];
        // }
        for(int i=0;i<=(1<<(pos-2))-1||i==0;i++){
            for(int k=pos-1;k>=0;k--){
                num[k]=str[pos-k-1]-'0';
            }
            ll tans=1;
            bool fl=0;
            for(int j=0;j<pos;j++){
                if(num[j]<0){
                    if((i>>j)&1){
                        tans*=cnt1[9];
                        num[j+2]--;
                    }
                    else{
                        fl=1;
                        break;
                    }
                    continue;
                }
                if((i>>j)&1){
                    if(num[j]==9){
                        fl=1;
                        break;
                    }
                    tans*=cnt2[num[j]];
                    num[j+2]--;
                }
                else{
                    tans*=cnt1[num[j]];
                }
            }
            if(!fl)
                ans+=tans;
        }
        ans-=2;
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}