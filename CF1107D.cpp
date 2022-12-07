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
int gcd(int x,int y){
    return y ? gcd(y,x%y) : x;
}
int a[5270];
int mp[500];
void init(){
    for(int i=0;i<=9;i++){
        mp['0'+i]=i;
    }
    for(int i='A';i<='F';i++){
        mp[i]=i-'A'+10;
    }
}
char str[5240*5040/4];
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    int n;
    scanf("%d",&n);
    int cnt1,cnt0;
    int row=0;
    int line=0;
    int cnt=0;
    char ch;
    init();
    for(int i=1;i<=n*(n/4);i++){
        str[i]=getchar();
    }
    if(str[1]=='2'){
        cout<<clock()/CLOCKS_PER_SEC<<endl;
    }
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<=n/4;j++){
            tmp=tmp*16+mp[str[(n/4)*(i-1)+j]];
        }
        if(row==1){
            break;
        }
        a[i]=tmp;
        if(a[i]!=a[i-1]||i==1){
            line=gcd(line,cnt);
            cnt=1;
        }
        else{
            cnt++;
            continue;
        }
        cnt1=cnt0=0; 
        int val=a[i];
        int tot=0;
        while(val){
            if(val&1){
                tot=gcd(tot,cnt0);
                cnt0=0;
                cnt1++;
            }
            else{
                tot=gcd(tot,cnt1);
                cnt1=0;
                cnt0++;
            }
            // cout<<cnt1<<' '<<cnt0<<endl;
            val>>=1;
        }
        // cout<<tot<<endl;
        tot=gcd(tot,gcd(cnt1,cnt0)); 
        row=gcd(row,tot);
        // if(clock()/CLOCKS_PER_SEC>=2){
        //     cout<<'!'<<i<<endl;
        //     break;
        // }
    }
    line=gcd(line,cnt);
    cout<<gcd(row,line);
    //cout<<row<<' '<<line<<endl;
    cout.flush();
    //system("pause");
    return 0;
}