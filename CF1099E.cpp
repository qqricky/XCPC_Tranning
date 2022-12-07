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
vector<char>mp[N];
int n,m;
int tp=0;
vector<int>ans(N);
vector<int>ansv(N);
char c[10][10];
int calc_1(int r,char ch1,char ch2){
    int cnt1=0,cnt2=0;
    for(int j=1;j<=m;j++){
        if(j&1){
            cnt1+=(mp[r][j]!=ch1);
        }
        else{
            cnt1+=(mp[r][j]!=ch2);
        }
    }
    for(int j=1;j<=m;j++){
        if(j&1){
            cnt2+=(mp[r][j]!=ch2);
        }
        else{
            cnt2+=(mp[r][j]!=ch1);
        }
    }
    if(cnt1<cnt2)return cnt1*10;
    else return cnt2*10+1;
}
int calc_2(int l,char ch1,char ch2){
    int cnt1=0,cnt2=0;
    for(int j=1;j<=n;j++){
        if(j&1){
            cnt1+=(mp[j][l]!=ch1);
        }
        else{
            cnt1+=(mp[j][l]!=ch2);
        }
    }
    for(int j=1;j<=n;j++){
        if(j&1){
            cnt2+=(mp[j][l]!=ch2);
        }
        else{
            cnt2+=(mp[j][l]!=ch1);
        }
    }
    if(cnt1<cnt2)return cnt1*10;
    else return cnt2*10+1;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    mp[0].resize(m+2);
    for(int i=1;i<=n;i++){
        mp[i].resize(m+1);
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    char st[]={'A','C','G','T'};
    int anss=INF;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<=3;j++){
            int a=0,b;
            while(a==i||a==j)a=(a+1)%4;
            b=a+1;
            while(b==i||b==j)b=(b+1)%4;
            int tmp=0;
            for(int k=1;k<=n;k++){
                if(k&1){
                    int val=calc_1(k,st[i],st[j]);
                    ans[k]=val%10;
                    tmp+=val/10;
                }
                else{
                    int val=calc_1(k,st[a],st[b]);
                    ans[k]=val%10;
                    tmp+=val/10;
                }
            }
            if(tmp<anss){
                tp=1;
                anss=tmp;
                ansv=ans;
                c[1][0]=st[i];
                c[1][1]=st[j];
                c[0][0]=st[a];
                c[0][1]=st[b];
            }
            tmp=0;
            for(int k=1;k<=m;k++){
                if(k&1){
                    int val=calc_2(k,st[i],st[j]);
                    ans[k]=val%10;
                    tmp+=val/10;
                }
                else{
                    int val=calc_2(k,st[a],st[b]);
                    ans[k]=val%10;
                    tmp+=val/10;
                }
            }
            if(tmp<anss){
                tp=2;
                anss=tmp;
                ansv=ans;
                c[1][0]=st[i];
                c[1][1]=st[j];
                c[0][0]=st[a];
                c[0][1]=st[b];
            }
        }
    }
    if(tp==1){
        for(int i=1;i<=n;i++){
            int now=ansv[i];
            for(int j=1;j<=m;j++,now=(now+1)%2){
                mp[i][j]=c[i&1][now];
            }
        }
    }
    else{
        for(int i=1;i<=m;i++){
            int now=ansv[i];
            for(int j=1;j<=n;j++,now=(now+1)%2){
                mp[j][i]=c[i&1][now];
            }
        }
    }
    //cout<<anss<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<mp[i][j];
        }
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}