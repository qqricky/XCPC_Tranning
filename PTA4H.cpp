#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
struct node
{
    string st,ed;
}nd[N];
bool cmp(node a,node b){
    return a.st<b.st;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string last="00:00:00";
    for(int i=1;i<=n;i++){
        char ch;
        cin>>nd[i].st>>ch>>nd[i].ed;
    }
    sort(nd+1,nd+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(nd[i].st!=last){
            cout<<last<<" - "<<nd[i].st<<'\n';
        }
        last=nd[i].ed;
    }
    if(last!="23:59:59"){
        cout<<last<<" - "<<"23:59:59\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}