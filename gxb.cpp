#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
struct node
{
    char ch;
    ll id,cd,fd;
}nd[N];
bool cmp(node a,node b){
    if(a.fd==b.fd){
        if(a.id==b.id){
            return a.ch<b.ch;
        }
        return a.id<b.id;
    }
    return a.fd<b.fd;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        nd[i].ch=(char)('A'+i-1);
        cin>>nd[i].id;
    }
    for(int i=1;i<=n;i++){
        cin>>nd[i].cd;
        nd[i].fd=nd[i].cd*nd[i].id;
    }
    sort(nd+1,nd+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout<<nd[i].ch;
        if(i!=n)cout<<' ';
    }
    cout.flush();
    // system("pause");
    return 0;
}