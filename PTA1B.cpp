#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<int,int>mp;
    string str;
    cin>>str;
    vector<int>v;
    map<int,int>pos;
    for(int i=0;i<str.length();i++){
        int x=str[i]-'0';
        mp[x]++;
        if(mp[x]==1){
            v.push_back(x);
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++){
        pos[v[i]]=i;
    }
    cout<<"int[] arr = new int[]{";
    for(int i=0;i<v.size();i++){
        pos[v[i]]=i;
        if(i<v.size()-1){
            cout<<v[i]<<',';
        }
        else{
            cout<<v[i]<<"};"<<endl;
        }
    }
    cout<<"int[] index = new int[]{";
    for(int i=0;i<str.size()-1;i++){
        cout<<pos[str[i]-'0']<<',';
    }
    cout<<pos[str[str.size()-1]-'0']<<"};";
    //system("pause");
    return 0;
}