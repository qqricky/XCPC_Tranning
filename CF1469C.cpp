#include <bits/stdc++.h>
#include <queue>
using namespace std;
struct men
{
    men(long long num,long long kane):num(num),kane(kane){};
    long long num,kane;
};
bool operator <( men x, men y){
        if(x.kane==y.kane)return x.num>y.num;
        else return x.kane<y.kane;
}
priority_queue<men>q;
int v[500002]={};
queue<long long> qu;
int main()
{
    ios_base::sync_with_stdio(false);
    int Q;
    cin>>Q;
    long long tot=0;
    for(int i=1;i<=Q;i++)
    {
        int demo;
        cin>>demo;
        if(demo==1){
            long long okane=0;
            cin>>okane;
            q.push(men(++tot,okane));
            qu.push(tot);
        }
        else if(demo==2){
            int k=qu.front();
            qu.pop();
            while(v[k]){
                k=qu.front();
                qu.pop();
            }
            v[k]=1;
            cout<<k<<' ';
        }
        else{
            men ke=q.top();
            q.pop();
            while(v[ke.num]){
                ke=q.top();
                q.pop();
            }
            v[ke.num]=1;
            cout<<ke.num<<' ';
        }
    }
    //system("pause");
    return 0;
}