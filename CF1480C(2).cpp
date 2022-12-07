#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10; 
using namespace std;
int a[12]={};
int ar[N]={};
int ask(int x)
{
    int tmp;
    if(!ar[x]){
        cout<<'?'<<' '<<x<<endl;
        cout.flush();
        cin>>tmp;
        ar[x]=tmp;
        return tmp;
    }
    else return ar[x];
}
int check(int mid)
{
    int x=ask(mid);
    int y=ask(mid+1);
    if(x>y)return 1;
    else return 0;
}
void op(int x)
{
    cout<<"! "<<x<<endl;
    cout.flush();
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    if(n<=100){
        for(int i=1;i<=n;i++){
            cout<<'?'<<' '<<i<<endl;
            cout.flush();
            cin>>a[i];
        }
        a[0]=N+1;
        a[n+1]=N+1;
        for(int i=1;i<=n;i++){
            if(a[i]<a[i-1]&&a[i]<a[i+1]){
                cout<<'!'<<' '<<i<<endl;
                cout.flush();
                return  0;
            }
        }
    }
    else{
        // int pos=0;
        // int tmp=0;
        // int minn=N;
        // for(int i=n/10;i<n;i+=n/10){
        //     tmp=ask(i);
        //     if(tmp<minn){
        //         pos=i;
        //         minn=tmp;
        //     }
        // }
        int x1,x2;
        x1=ask(1);
        x2=ask(2);
        if(x1<x2){
            op(1);
            return 0;
        }
        int x4=ask(n);
        int x3=ask(n-1);
        if(x3>x4){
            op(n);
            return 0;
        }
        int l=1,r=n,mid;
        while(r-l>2)
        {
            mid=(l+r)>>1;
            if(check(mid))l=mid;
            else r=mid+1;
        }
        op(l+1);
        // for(int i=1;i<=10;i++){
        //     int k=rand()%(n)+1;
        //     tmp=ask(k);
        //     if(tmp<minn){
        //          pos=k;
        //          minn=tmp;
        //     } 
        // }
        // pos=(1+n)>>1;
        // minn=ask(pos);
        // int r=ask(pos+1);
        // int l=ask(pos-1);
        // if(r>minn&&l>minn){
        //     cout<<'!'<<' '<<pos<<endl;
        //     cout.flush();
        //     return 0;
        // }
        // if(r<minn&&l<minn){
        //     if(pos<n-pos)goto paris;
        // }
        // if(r<minn){
        //     pos+=2;
        //     int val=ask(pos);
        //     while(val<r){
        //         r=val;
        //         pos++;
        //         val=ask(pos);
        //     }
        //     cout<<'!'<<' '<<pos-1<<endl;
        //     cout.flush();
        //     return 0;
        // }
        // paris: ;
        // if(l<minn){
        //     pos-=2;
        //     int val=ask(pos);
        //     while(val<l){
        //         l=val;
        //         pos--;
        //         val=ask(pos);
        //     }
        //     cout<<'!'<<' '<<pos+1<<endl;
        //     cout.flush();
        //     return 0;
        // }
    }
    //system("pause");
    return 0;
}