#include<bits/stdc++.h>
#pragma GCC optimise(2)
#define ll long long
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    stack<int>s;
    vector<int>v;
    int now=1;
    while (1)
    {
        if(s.size()){
            if(v.empty()||v[v.size()-1]>=s.top()){
                v.push_back(s.top());
                s.pop();
            }
            else{
                if(now>n){
                    for(int j=0;j<v.size()-1;j++){
                        cout<<v[j]<<' ';
                    }
                    cout<<v[v.size()-1]<<'\n';
                    v.clear();
                    continue;
                }
                if(v.empty()||a[now]<=v[v.size()-1]){
                    v.push_back(a[now]);
                    now++;
                }
                else{
                    if(s.size()>=m){
                        for(int j=0;j<v.size()-1;j++){
                        cout<<v[j]<<' ';
                    }
                    cout<<v[v.size()-1]<<'\n';
                        v.clear();
                        continue;
                    }
                    s.push(a[now]);
                    now++;
                }
            }
        }
        else{
            if(now>n)break;
            if(v.empty()||a[now]<=v[v.size()-1]){
                v.push_back(a[now]);
                now++;
            }
            else{
                if(s.size()>=m){
                    for(int j=0;j<v.size()-1;j++){
                        cout<<v[j]<<' ';
                    }
                    cout<<v[v.size()-1]<<'\n';
                    v.clear();
                    continue;
                }
                s.push(a[now]);
                now++;
            }
        }
        if(v.size()==k){
            //reverse(v.begin(),v.end());
            for(int j=0;j<v.size()-1;j++){
                        cout<<v[j]<<' ';
                    }
                    cout<<v[v.size()-1]<<'\n';
            v.clear();
        }
    }
    if(v.size()){
        //reverse(v.begin(),v.end());
        for(int j=0;j<v.size()-1;j++){
                        cout<<v[j]<<' ';
                    }
                    cout<<v[v.size()-1]<<'\n';
        v.clear();
    }
    cout.flush();
    //system("pause");
    return 0;
}