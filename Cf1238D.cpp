#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int ncnt=0;
int s[2*N];
int len,len2;
int p[2*N];
int sum[N];
int str[2*N];
void init(){
    s[0]=s[1]=N;
    for(int i=1;i<=len;i++){
        s[i*2]=str[i];
        s[i*2+1]=N;
    }
    len2=len*2+1;
}
void manacher(){
    int mid=0,mr=0;
    for(int i=1;i<=len2;i++){
        if(mr>i)p[i]=min(p[2*mid-i],mr-i);
        else p[i]=1;
        while(s[i+p[i]]==s[i-p[i]])p[i]++;
        if(p[i]+i>mr){
            mr=p[i]+i;
            mid=i;
        }
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll ans=0;
    cin>>n;
    string st;
    cin>>st;
    st=' '+st;
    int cnt=1;
    for(int i=2;i<st.length();i++){
        if(st[i]==st[i-1])cnt++;
        else{
            str[++ncnt]=cnt;
            cnt=1;
        }
    }
    str[++ncnt]=cnt;
    len=ncnt;
    // init();
    // manacher();
    sum[0]=0;
    str[len+1]=0;
    str[0]=0;
    for(int i=1;i<=ncnt;i++){
        sum[i]=(sum[i-1]+str[i]);
    }
    ans=1ll*n*(n-1)/2;
    for(int i=1;i<=len;i++){
        // int val=p[i*2]/2-1;
        // int val2=(p[i*2+1]-1)/2;
        // ans+=(sum[i+val]-sum[i]);
        // ans+=str[i]*(str[i]-1)/2;
        // ans+=(sum[i+val2]-sum[i])+min(str[i+val2+1],str[i-val2]);
        // ans+=str[i]*(str[i]-1)/2;
        // ans+=sum[i-1]*(sum[len]-sum[i]);
        // ans+=max(0,(str[i]-1)*(str[i+1]-1));
        ans-=(str[i-1]+str[i+1]);
    }
    ans+=(ncnt-1);
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}