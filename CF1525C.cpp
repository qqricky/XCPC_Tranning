#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=3e5+10;
using namespace std;
int ans[N];
struct point
{
    int x;
    char ch;
    int num;
}a[N];
bool cmp(point tt,point ttt)
{
    return tt.x<ttt.x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        stack<int>odd;
        stack<int>even;
        int n,m;
        cin>>n>>m;
        memset(ans,0x3f,sizeof(int)*(n+1));
        for(int i=1;i<=n;i++){
            cin>>a[i].x;
            //b[i]=a[i];
        }
        for(int i=1;i<=n;i++){cin>>a[i].ch;a[i].num=i;}
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(a[i].ch=='R'){
                if(a[i].x&1)odd.push(i);
                else even.push(i);
            }
            else{
                if(a[i].x&1){
                    if(odd.size()){
                        int kk=odd.top();
                        odd.pop();
                        ans[a[kk].num]=ans[a[i].num]=(max(a[kk].x,a[i].x)-min(a[kk].x,a[i].x))/2;
                    }
                    else{
                        a[i].x=-a[i].x;
                        a[i].ch=='R';
                        odd.push(i);
                    }
                }
                else{
                    if(even.size()){
                        int kk=even.top();
                        even.pop();
                        ans[a[kk].num]=ans[a[i].num]=(max(a[kk].x,a[i].x)-min(a[kk].x,a[i].x))/2;
                    }
                    else{
                        a[i].x=-a[i].x;
                        a[i].ch=='R';
                        even.push(i);
                    }
                }
            }
        }
        for(int i=n;i>=1;i--){
            if(ans[a[i].num]==INF){
                //cout<<i<<"WWWWWWWWW"<<endl;
                if(a[i].ch=='R'){
                    a[i].x=2*m-a[i].x;
                    if(a[i].x&1){ 
                        odd.pop();
                        if(odd.size()){
                            int kk=odd.top();
                            odd.pop();
                            ans[a[kk].num]=ans[a[i].num]=(max(a[kk].x,a[i].x)-min(a[kk].x,a[i].x))/2;
                        }
                    }
                    else{
                        even.pop();
                        if(even.size()){
                            int kk=even.top();
                            even.pop();
                            ans[a[kk].num]=ans[a[i].num]=(max(a[kk].x,a[i].x)-min(a[kk].x,a[i].x))/2;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(ans[i]==INF)ans[i]=-1;
        }
        for(int i=1;i<n;i++)std::cout<<ans[i]<<' ';
        std::cout<<ans[n]<<endl;
    }
    //system("pause");
    return 0;
}