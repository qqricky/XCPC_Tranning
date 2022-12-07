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
ll f[30][2]={};
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string str;
    int tmp1=0;
    for(int i=1;i<=n;i++){
        int now=i&1;
        cin>>str;
        if(tmp1==0)
        tmp1=str.length();
        bool is=1;
        for(int j=1;j<str.length();j++){
            if(str[j]!=str[j-1]){
                is=0;
                break;
            }
        }
        if(is){
            // if(n==4&&tmp1>20){
            //     cout<<f[str[0]-'a'][now^1];
            //     cout<<" "<<str.length()<<'\n';
            // }
            f[str[0]-'a'][now]=f[str[0]-'a'][now^1]*(str.length()+1)+str.length();
            for(int j=0;j<=25;j++){
                if(j==str[0]-'a')continue;
                if(f[j][now^1])f[j][now]=1;
            }
        }
        else{
            int ptr1=1;
            int cnt1=1,cnt2=1;
            while(str[ptr1]==str[ptr1-1]){
                cnt1++;
                ptr1++;
            }
            int ptr2=str.length()-2;
            while(str[ptr2]==str[ptr2+1]){
                cnt2++;
                ptr2--;
            }
            set<int>s;
            s.insert(str[0]-'a');
            s.insert(str[str.length()-1]-'a');
            if(str[0]==str[str.length()-1]){
                if(f[str[0]-'a'][now^1]){
                    f[str[0]-'a'][now]=cnt1+cnt2+1;
                }
                else{
                    f[str[0]-'a'][now]=max(cnt1,cnt2);
                }
                goto ne;
            }
            f[str[0]-'a'][now]=cnt1;
            f[str[str.length()-1]-'a'][now]=cnt2;
            if(f[str[0]-'a'][now^1])f[str[0]-'a'][now]++;
            if(f[str[str.length()-1]-'a'][now^1])f[str[str.length()-1]-'a'][now]++;
            ne:;
            //cout<<i<<' '<<cnt1<<' '<<cnt2<<'\n';
            for(int j=0;j<=25;j++){
                if(s.count(j)==0){
                    f[j][now]=min(1ll,f[j][now^1]);
                }
            }
            ll num=1;
            char ch=str[ptr1];
            s.insert(ch-'a');
            for(int j=ptr1+1;j<=ptr2;j++){
                if(str[j]==str[j-1]){
                    num++;
                }
                else{
                    f[ch-'a'][now]=max(f[ch-'a'][now],num);
                    num=1;
                    ch=str[j];
                    s.insert(ch-'a');
                }
            }
            f[ch-'a'][now]=max(f[ch-'a'][now],num);
        }
        // cout<<i<<'\n';
        // cout<<f[0][now]<<' '<<f[1][now]<<'\n';
    }
    ll ans=1;
    for(int i=0;i<=25;i++){
        ans=max(ans,f[i][n&1]);
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}