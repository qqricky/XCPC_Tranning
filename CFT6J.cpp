#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int v[200]={};
struct ept
{
    int l,r;
    int len;
    int num;
};
vector<ept>v1;
vector<ept>v2;
bool cmp(ept a,ept b)
{
    return a.len<b.len;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int od=(n+1)/2;
    int ev=n/2;
    int a[150];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]&1){od--;a[i]=1;}
        else if(a[i]==0){a[i]=-1;v[i];}
        else {ev--;a[i]=0;}
    }
    a[0]=114514;
    a[n+1]=114514;
    int flag=1;
    for(int i=1;i<=n;i++){
        int pos;
        if(a[i]==1){
            if(flag){
                flag=0;
                if(i>1){
                    v1.push_back((ept){1,i-1,i-1,1});
                    continue;
                }
            }
            pos=i+1;
            while(a[pos]==-1){
                pos++;
            }
            pos--;
            if(pos!=i){
                if(a[pos+1]==1||pos==n){
                    v1.push_back((ept){i+1,pos,pos-i,1});
                }
            }
            i=pos;
        }
        else if(a[i]==0){
            if(flag){
                flag=0;
                if(i>1){
                    v2.push_back((ept){1,i-1,i-1,0});
                    continue;
                }
            }
            flag=0;
            pos=i+1;
            while(a[pos]==-1){
                pos++;
            }
            pos--;
            if(pos!=i){
                if(a[pos+1]==0||pos==n){
                    v2.push_back((ept){i+1,pos,pos-i,0});
                }
            }
            i=pos;
        }
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    int po=0;
    //cout<<v1.size()<<endl;
    while(po<v1.size()&&od>=v1[po].len)
    {
        //cout<<v1[po].l<<'Q'<<v1[po].r<<endl;
        for(int j=v1[po].l;j<=v1[po].r;j++)a[j]=1;
        od-=v1[po].len;
        po++;
    }
    po=0;
    while(po<v2.size()&&ev>=v2[po].len)
    {
        for(int j=v2[po].l;j<=v2[po].r;j++)a[j]=0;
        ev-=v2[po].len;
        po++;
    }
    int poss=1;
    while(a[poss]==-1){
        poss++;
    }
    int pos2=n;
    while(a[pos2]==-1){
        pos2--;
    }
    int fla=0;
    int f1=0;
    if(n-pos2>poss-1){
        fla=1;
        goto paris;
    }
    gg:;
    if(poss!=1){
        if(a[poss]==1){
            for(int j=poss-1;j>=1;j--){
                if(od>0){
                    a[j]=1;
                    od--;
                }
                else{
                    ev--;
                    a[j]=0;
                }
            }
        }
        else if(a[poss]==0){
            for(int j=poss-1;j>=1;j--){
                if(ev>0){
                    a[j]=0;
                    ev--;
                }
                else{
                    od--;
                    a[j]=1;
                }
            }
        }
    }
    if(f1)goto gg2;
    paris:;
    if(pos2!=n){
        if(a[pos2]==1){
            for(int j=pos2+1;j<=n;j++){
                if(od>0){
                    a[j]=1;
                    od--;
                }
                else{
                    ev--;
                    a[j]=0;
                }
            }
        }
        else if(a[pos2]==0){
            for(int j=pos2+1;j<=n;j++){
                if(ev>0){
                    a[j]=0;
                    ev--;
                }
                else{
                    od--;
                    a[j]=1;
                }
            }
        }
    }
    if(fla){
        fla=0;
        f1=1;
        goto gg;
    }
    gg2:;
    for(int i=poss;i<=n;i++){
        if(a[i]==-1){
            //cout<<i<<endl;
            if(a[i-1]==1||a[i+1]==1){
                if(od>0){
                    a[i]=1;
                    od--;
                }
                else{
                    ev--;
                    a[i]=0;
                }
            }
            else{
                if(ev>0){
                    a[i]=0;
                    ev--;
                }
                else{
                    od--;
                    a[i]=1;
                }
            }
        }
    }
    int cnt=0;
    //cout<<a[1]<<' ';
    for(int i=2;i<=n;i++){
        //cout<<a[i]<<' ';
        if(a[i]!=a[i-1])cnt++;
    }
    cout<<cnt<<endl;
    //system("pause");
    return 0;
}