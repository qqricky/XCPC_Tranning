#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=5e5+10; 
using namespace std;
int a1[N];
int a[N];
int b[N];
int f[N][2];
int liss(int a[],int n)
{
    vector<int>ans;
    for(int i=0;i<=n-1;i++)a[i]-=(i+1);
        ans.push_back(a[0]);
        for(int i=1;i<=n-2;i++){
            if(a[i]>=ans[ans.size()-1])ans.push_back(a[i]);
            else{
                int k=upper_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[k]=a[i];
            }
        }
        ans.push_back(a[n-1]);
    return ans.size();
}
int lis(int a[],int n)
{
    vector<int>ans;
    for(int i=1;i<=n;i++)a[i]-=i;
        ans.push_back(a[1]);
        for(int i=2;i<=n-1;i++){
            if(a[i]>a[n])continue;
            if(a[i]>=ans[ans.size()-1])ans.push_back(a[i]);
            else{
                int k=upper_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                if(k==0)continue;
                ans[k]=a[i];
            }
        }
        ans.push_back(a[n]);
        a[1]++;
    a[n]+=n;
    return ans.size();
}
int lis1(int a[],int n)
{
    if(n==1)return 1;
    vector<int>ans;
    for(int i=1;i<=n;i++)a[i]-=i;
    int pos=1;
        while(a[pos]>a[n]&&pos<=n){
            pos++;
        }
        if(pos==n)return 1;
        ans.push_back(a[pos]);
        for(int i=pos+1;i<=n-1;i++){
            if(a[i]>a[n])continue;
            if(a[i]>=ans[ans.size()-1])ans.push_back(a[i]);
            else{
                int k=upper_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[k]=a[i];
            }
        }
        ans.push_back(a[n]);
        a[1]++;
    a[n]+=n;
    return ans.size();
}
int lis2(int a[],int n)
{
    if(n==1)return 1;
    vector<int>ans;
    for(int i=1;i<=n;i++)a[i]-=i;
        ans.push_back(a[1]);
        for(int i=2;i<=n;i++){
            if(a[i]>=ans[ans.size()-1])ans.push_back(a[i]);
            else{
                int k=upper_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                if(k==0)continue;
                ans[k]=a[i];
            }
        }
    a[1]++;
    a[n]+=n;
    return ans.size();
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=k;i++)cin>>b[i];
        if(k==0){
            a[0]=-INF;
            a[n+1]=INF;
            cout<<n-liss(a,n+2)+2;
            cout.flush();
            system("pause");
            return 0;
        }
    int cnt=0;
    int flag=1;
    for(int i=2;i<=k;i++){
        if((a[b[i]]-a[b[i-1]]-1)<(b[i]-b[i-1]-1)){
            flag=0;
            break;
        }
        int len=b[i]-b[i-1]+1;
        cnt+=len-lis(a+b[i-1]-1,len);
        //cout<<cnt<<endl;
    }
    cnt+=b[1]-lis1(a,b[1]);
    cnt+=n-b[k]+1-lis2(a+b[k]-1,n-b[k]+1);
    if(flag)
        cout<<cnt<<endl;
    else
        cout<<-1<<endl;
    //system("pause");
    return 0;
}