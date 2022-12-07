#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int a[N];
int n[5];
struct node
{
    int x1,y1;
    int x2,y2;
};
bool cmp(node a,node b){
    return a.x1<b.x1;
}
int dis(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
vector<node>ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c1,c2,r1,r2;
    cin>>c1>>c2>>r1>>r2;
    for(int i=1;i<=4;i++)cin>>n[i];
    int x,y,d1,d2;
    cin>>x>>y>>d1>>d2;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            for(int ii=1;ii<=5;ii++){
                for(int jj=1;jj<=5;jj++){
                    if(dis(i,j,ii,jj)!=d1||dis(ii,jj,x,y)!=d2){
                        continue;
                    }
                    int R2=r2+n[4];
                    int R1=r1-n[3];
                    int C1=c1;
                    int C2=c2;
                    if(i==R1||i==R2)continue;
                    if(j==C1||j==C2)continue;
                    C1+=n[1];
                    C2-=n[2];
                    if(ii==R1||ii==R2)continue;
                    if(jj==C1||jj==C2)continue;
                    ans.push_back((node){i,j,ii,jj});
                }
            }
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    for(auto nd:ans){
        cout<<nd.x1<<' '<<nd.y1<<' '<<nd.x2<<' '<<nd.y2<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}