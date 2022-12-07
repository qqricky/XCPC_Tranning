#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int a[N];
ll cnt=0;
int b[N];
void merge_sort(int l,int r)
{
    if(r-l > 0)
    {
        int mid = (l+r) / 2 ;
        int i = l;
        int p = l , q = mid+1;
        merge_sort(l , mid);
        merge_sort(mid+1 , r);
        while(p<=mid || q<=r)
        {
            if(q>r || (p<=mid && a[p]<=a[q]))
                b[i++] = a[p++];
            else
            {
                b[i++] = a[q++];
                cnt += mid -p +1;
            }
        }
        for(i = l ; i <= r; i++)
            a[i] = b[i];
    }
}
void merge(int l,int mid,int r)
{
    int i=l,j=mid+1;
    for(int k=l;k<=r;k++){
        if(j>r||i<=mid&&a[i]<=a[j]){
            b[k]=a[i++];
        }
        else{
            b[k]=a[j++];
            cnt+=mid-i+1;
        }
    }
    for(int k=l;k<=r;k++)a[k]=b[k];
}
void sot(int l,int r)
{
    if(l==r)return ;
    int mid=(l+r)>>1;
    sot(l,mid);
    sot(mid+1,r);
    merge(l,mid,r);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll x,y;
    while(cin>>n>>x>>y)
    {
        cnt=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        merge_sort(1,n);
        cout<<min(x,y)*cnt<<endl;
    }
    //out.flush();
    system("pause");
    return 0;
}