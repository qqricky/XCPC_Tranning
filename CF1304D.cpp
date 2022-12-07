#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
/*
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
*/
int ans1[N];
int ans2[N];
int pre[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        str=' '+str;
        int l=0;
        int r=0;
        ans1[1]=0;
        int mi=0;
        for(int i=1;i<n;i++){
            if(str[i]=='<'){
                ans1[i+1]=++r;
            }
            else{
                ans1[i+1]=--l;
                mi=min(mi,l);
            }
        }
        for(int i=1;i<=n;i++){
            ans1[i]+=abs(mi)+1;
        }
        int num=0;
        int st=1;
        mi=0;
        str+='>';
        for(int i=n-1;i>=1;i--){
            if(str[i]=='>'){
                pre[i]=num;
            }
            else{
                if(str[i+1]=='>'){
                    num=0;
                }
                num++;
            }
        }
        ans2[1]=0;
        for(int i=2;i<=n;i++){
            if(str[i-1]=='>'&&str[i-2]!='>'){
                st=mi-pre[i-1];
                ans2[i]=st-1;
                mi=st-1;
            }
            else if(str[i-1]=='>'){
                ans2[i]=--mi;
            }
            else{
                ans2[i]=st++;
            }
        }
        for(int i=1;i<=n;i++)ans2[i]+=abs(mi)+1;
        for(int i=1;i<=n;i++)cout<<ans2[i]<<' ';
        cout<<"\n";
        for(int i=1;i<=n;i++)cout<<ans1[i]<<' ';
        cout<<endl;
    }
    //system("pause");
    return 0;
}