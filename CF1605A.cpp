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
    string str;
    while(t--){
        int n;
        cin>>n;
        int ans=INF;
        cin>>str;
        str=' '+str;
        int cnt2=0,cnt1=0;
        int pre=0;
        int st=1;
        while(str[st]!='a'&&st<=n)st++;
        st++;
        for(int i=st;i<=n;i++){
            if(str[i]=='a'){
                if(cnt1==1&&cnt2==1){
                    ans=min(ans,4);
                }
                else if(cnt1+cnt2<2){
                    ans=min(ans,2+cnt1+cnt2);
                }
                else if(cnt1==2&&cnt2==0){
                    if(pre==2){
                        ans=min(ans,7);
                    }
                    pre=1;
                }
                else if(cnt2==2&&cnt1==0){
                    if(pre==1){
                        ans=min(ans,7);
                    }
                    pre=2;
                }
                else{
                    pre=0;
                }
                cnt1=cnt2=0;
            }
            else{
                if(str[i]=='b')cnt1++;
                else cnt2++;
            }
        }
        cout<<(ans==INF ? -1 : ans)<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}