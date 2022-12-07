#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10; 
using namespace std;
int a[12]={};
int ask(int x)
{
    int tmp;
    cout<<'?'<<' '<<x<<endl;
    cout.flush();
    cin>>tmp;
    return tmp;
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
    if(n<=10){
        for(int i=1;i<=n;i++){
            cout<<'?'<<' '<<i<<endl;
            cout.flush();
            cin>>a[i];
        }
        a[0]=N;
        a[n+1]=N;
        for(int i=1;i<=n;i++){
            if(a[i]<a[i-1]&&a[i]<a[i+1]){
                cout<<'!'<<' '<<i<<endl;
                cout.flush();
                return  0;
            }
        }
    }
    else{
        int pos=0;
        int tmp=0;
        int minn=N;
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
            cout<<'!'<<' '<<1<<endl;
            cout.flush();
            return 0;
        }
        x2=ask(n);
        x1=ask(n-1);
        if(x1>x2){
            cout<<'!'<<' '<<n<<endl;
            cout.flush();
            return 0;
        }
        for(int i=1;i<=10;i++){
            int k=rand()%(n)+1;
            tmp=ask(k);
            if(tmp<minn){
                 pos=k;
                 minn=tmp;
            } 
        }
        int r=ask(pos+1);
        int l=ask(pos-1);
        if(r>minn&&l>minn){
            cout<<'!'<<' '<<pos<<endl;
            cout.flush();
            return 0;
        }
        if(r<minn&&l<minn){
            if(pos<n-pos)goto paris;
        }
        if(r<minn){
            pos+=2;
            int val=ask(pos);
            while(val<r){
                r=val;
                pos++;
                val=ask(pos);
            }
            cout<<'!'<<' '<<pos-1<<endl;
            cout.flush();
            return 0;
        }
        paris: ;
        if(l<minn){
            pos-=2;
            int val=ask(pos);
            while(val<l){
                l=val;
                pos--;
                val=ask(pos);
            }
            cout<<'!'<<' '<<pos+1<<endl;
            cout.flush();
            return 0;
        }
    }
    //system("pause");
    return 0;
}