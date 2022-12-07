#include <bits/stdc++.h>
using namespace std;
long long num[1002]={};
int main()
{
    num[0]=1;
    num[1]=4;
    num[2]=4;
    num[3]=12;
    for(int i=4;i<=1000;i++){
        int jie=(i+1)/2;
        int stage=2*jie+1;
        int suround=2*(stage-2)+2;
        if(i&1){
            num[i]=suround+num[i-4]+2*(2*(jie-1)+1-2)+2;
        }
        else num[i]=suround+num[i-4];

    }
    int n;
    cin>>n;
    cout<<num[n];
    return 0;
}