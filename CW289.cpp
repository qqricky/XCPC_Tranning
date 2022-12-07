#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e6+10; 
using namespace std;
int a[2*N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    deque<ll>q;
    deque<ll>num;
    q.push_back(a[1]-1);
    num.push_back(1);
    for(int i=2;i<=n/2;i++){
        while(!q.empty()&&a[i]-i>q.back()){q.pop_back();num.pop_back();}
        q.push_back(a[i]-i);
        num.push_back(i);
    }
    ll ans=0;
    int val;

    for(int i=n/2+1;i<=n+n/2;i++){
        while(i-num.front()>n/2){
            num.pop_front();
            q.pop_front();
        }
        while(!q.empty()&&a[i]-i>q.back()){q.pop_back();num.pop_back();}
        q.push_back(a[i]-i);
        num.push_back(i);
        ans=max(ans,a[i]+i+q.front());
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}