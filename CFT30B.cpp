#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
struct node
{
    int pos;
    int num;
};
vector<node>v[N];
int cha[N]={};
int pf[N]={};
int pm[N]={};
int sm[N]={};
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char ch;
        int val;
        cin>>ch>>val;
        if(ch=='s'){
            v[val].push_back(node{i,1});
        }
        else{
            v[val].push_back(node{i,-1});
        }
    }
    for(int i=1;i<=1e6;i++){
        if(v[i].size()<2)continue;
        pf[0]=v[i][0].num;
        pm[0]=pf[0];
        //cout<<pf[0]<<' ';
        for(int j=1;j<v[i].size();j++){
            pf[j]=pf[j-1]+v[i][j].num;
            pm[j]=min(pm[j-1],pf[j]);
            //cout<<pf[j]<<' ';
        }
        //cout<<endl;
        if(pf[v[i].size()-1]!=0){
            continue;
        }
        sm[v[i].size()-1]=pf[v[i].size()-1];
        for(int j=v[i].size()-2;j>=0;j--){
            sm[j]=min(sm[j+1],pf[j]);
        }
        for(int j=1;j<v[i].size();j++){
            if(pm[j-1]<=sm[j]&&v[i][j-1].num==-1&&v[i][j].num==1){
                cha[v[i][j-1].pos+1]++;
                cha[v[i][j].pos+1]--;
            }
        }
        if(sm[0]==0){
            cha[1]++;
            cha[v[i][0].pos+1]--;
            cha[v[i][v[i].size()-1].pos+1]++;
        }
    }
    int ma=0,pos=1;
    for(int i=1;i<=n;i++){
        cha[i]+=cha[i-1];
        if(cha[i]>ma){
            ma=cha[i];
            pos=i;
        }
    }
    cout<<pos<<' '<<ma;
    cout.flush();
    //system("pause");
    return 0;
}