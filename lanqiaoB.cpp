#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int val=2*n-2;
    for(int l=1,r=n;l<=r;l++,r--,val-=2){
        a[l]=a[r]=val;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    //cout.flush();
    //system("pause");
    return 0;
}