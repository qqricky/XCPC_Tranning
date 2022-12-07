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
int a[N],c[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    char ch;
    for(int i=1;i<=n;i++){
        cin>>ch;
        c[i]=ch-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>ch;
        a[i]=ch-'0';
    }
    int cnta=0,cntt=0,cntc=0,cnt0=0;
    bool flag=1;
    int numc=0,num0=0,tot=0,numa=0;
    for(int i=1;i<=n;i++){
        if(a[i]&&c[i]){
            cntt++;
        }
        else if(a[i]){
            cnta++;
        }
        else if(c[i]){
            cntc++;
        }
        else{
            cnt0++;
        }
    }
    //cout<<cnta<<' '<<cntc<<' '<<cntt<<endl;
    if(cnta==cntc&&cnta==0){
        if(cntt&1)flag=0;
        else {
            numc=0;
            tot=cntt/2;
            num0=n/2-cntt;
        }
    }
    if(cnta<cntc){
        if(cnta+cntt<cntc){
            if(cntc>n/2)flag=0;
            numc=cnta+cntt;
            num0=n/2-numc;
        }
        else if(cnta+cntt>cntc){
            if((cnta+cntt-cntc+1)/2+cnta>n/2)flag=0;
            numc=cntc;
            tot=(cnta+cntt-cntc)/2;
            if((cnta+cntt-cntc)&1){
                numc--;
                tot++;
            }
            num0=n/2-numa-numc-tot;
        }
        else{
            numc=cntc;
            num0=n/2-cntc;
        }
    }
    else if(cnta>cntc){
        if(cntc+cntt<cnta){
            if(cnta>n/2)flag=0;
            numc=cntc;
            tot=cntt;
            numa=cnta-cntc-cntt;
            num0=n/2-numc-numa-tot;
        }
        else if(cntc+cntt>cnta){
            if((cntc+cntt-cnta+1)/2+cntc>n/2)flag=0;
            //cout<<cnta<<' '<<cntc<<' '<<cntt<<endl;
            numc=cntc;
            tot=(cntc+cntt-cnta)/2;
            if((cntc+cntt-cnta)&1){
                numa--;
                tot++;
            }
            num0=n/2-numa-numc-tot;
        }
        else{
            numc=cntc;
            tot=cntt;
            num0=n/2-numc-tot;
        }
    }
    else{
        numc=cntc;
        tot=(cntt+1)/2;
        if(cntt&1){
            tot--;
            numa++;
        }
        num0=n/2-numa-numc-tot;
    }
    if(!flag){
        cout<<"-1";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]&&c[i]){
            if(tot<=0)continue;
            cout<<i<<" ";
            tot--;
        }
        else if(a[i]){
            if(numa<=0)continue;
            cout<<i<<' ';
            numa--;
        }
        else if(c[i]){
            if(numc<=0)continue;
            cout<<i<<' ';
            numc--;
        }
        else{
            if(num0<=0)continue;
            cout<<i<<' ';
            num0--;
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}