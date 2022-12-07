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
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str1,str2;
        cin>>str1>>str2;
        int cnt[2][2]={};
        bool flag=1;
        for(int i=0;i<n;i++){
            if(str1[i]==str2[i]){
                cnt[0][str1[i]-'0']++;
            }
            else{
                flag=0;
                cnt[1][str1[i]-'0']++;
            }
        }
        if(flag){
            cout<<0<<'\n';
            continue;
        }
        int num=INF;
        if((cnt[0][0]+cnt[0][1])&1){
            if(cnt[0][1]-cnt[0][0]==1){
                if(cnt[0][1]>0){
                    flag=1;
                    num=cnt[0][0]+cnt[0][1];
                }
            }
        }
        if((cnt[1][0]+cnt[1][1])%2==0){
            if(cnt[1][1]==cnt[1][0]){
                if(cnt[1][1]>0){
                    flag=1;
                    num=min(num,cnt[1][1]+cnt[1][0]);
                }
            }
        }
        if(flag){
            cout<<num<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}