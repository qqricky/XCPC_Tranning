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
    set<int>s;
    for(int i=1;i<=5;i++)s.insert(i);
    auto k=lower_bound(s.begin(),s.end(),3);
    //cout<<*k<<endl;
    multiset<int>ms;
    for(int i=1;i<=5;i++)ms.insert(i);
    ms.insert(1);
    ms.insert(2);
    int cnt=ms.erase(1);
    // cout<<cnt<<endl;
    // cout<<ms.size()<<endl;
    auto it=ms.equal_range(2);
    for(auto i=it.first;i!=it.second;i++){
        cout<<*i<<endl;
    }
    system("pause");
    return 0;
}