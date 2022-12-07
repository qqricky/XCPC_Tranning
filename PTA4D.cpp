#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[10];
int num=1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int sum=0;
    for(int i=1;i<=6;i++){
        cin>>a[i];
    }
    int n;
    cin>>n;
    set<int>s[7];
    for(int i=1;i<=6;i++){
        s[i].insert(a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            for(int k=6;k>=1;k--){
                if(!s[j].count(k)){
                    a[j]=k;
                    s[j].insert(k);
                    break;
                }
            }
        }
    }
    for(int i=1;i<=5;i++){
        cout<<a[i]<<' ';
    }
    cout<<a[6];
    // if(n==1){
    //     for(int i=1;i<=6;i++){
    //         cout<<a[i]<<' ';
    //     }
    // }
    // else{
    //     if(n&1){
    //         //cout<<num*6+(6-num)*5;
    //         for(int i=1;i<=6;i++){
    //             if(a[i]!=6)cout<<6<<' ';
    //             else cout<<5<<' ';
    //         }
    //     }
    //     else{
    //         for(int i=1;i<=6;i++){
    //             if(a[i]!=6)cout<<5<<' ';
    //             else cout<<6<<' ';
    //         }
    //     }
    // }
    cout.flush();
    //system("pause");
    return 0;
}