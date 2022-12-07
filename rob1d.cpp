#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
int v[100];
string can[100];
vector<int>ct1,ct2,t1,t2;
int pri=0;
int tot=0;
int calc(){
    int res=0;
    int num1=0;
    int num11=0;
    int num2=0;
    int num22=0;
    for(int j=0;j<t1.size();j++){
        num1+=((can[t1[j]][1]=='1'));
        num11+=(can[t1[j]][2]=='1');
    }
    for(int j=0;j<t2.size();j++){
        num2+=((can[t2[j]][1]=='1'));
        num22+=(can[t2[j]][2]=='1');
    }
    if(num1&&num2&&num11&&num22){
        res+=(1<<29);
    }
    num1=0;
    num2=0;
    for(int j=0;j<t1.size();j++){
        num1+=(can[t1[j]][2]=='1');
    }
    for(int j=0;j<t2.size();j++){
        num2+=(can[t2[j]][2]=='1');
    }
    if(num1&&num2){
        res+=(1<<28);
    }
    int num=0;
    for(int i=0;i<t1.size();i++){
        num+=v[t1[i]];
    }
    int dis=abs(num-(tot-num));
    int tmp=(100-dis);
    tmp<<=16;
    res+=tmp;
    if(num>(tot-num)){
        res+=(1<<14);
    }
    int val=0;
    int base=8000;
    for(int i=0;i<t1.size();i++){
        base=base/6;
        val=val+t1[i]*base;
    }
    res+=val;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=6;i++){
        cin>>v[i];
        tot+=v[i];
    }
    for(int i=1;i<=6;i++){
        cin>>can[i];
    }
    bool is=0;
    for(int i=0;i<(1<<6);i++){
        t1.clear();
        t2.clear();
        for(int j=0;j<6;j++){
            if(v[j+1]==0)continue;
            if((i>>j)&1){
                t1.push_back(j+1);
            }else{
                t2.push_back(j+1);
            }
        }
        bool flag=1;
        int num=0;
        for(int j=0;j<t1.size();j++){
            num+=can[t1[j]][0]-'0';
        }
        if(!num)flag=0;
        num=0;
        for(int j=0;j<t2.size();j++){
            num+=can[t2[j]][0]-'0';
        }
        if(!num)flag=0;
        if(!flag)continue;
        if(!is){
            is=1;
            ct1=t1;
            ct2=t2;
            pri=calc();
            continue;
        }
        int val=calc();
        if(val>pri){
            pri=val;
            ct1=t1;
            ct2=t2;
        }
    }
    if(!is)cout<<"GG";
    else{
        for(int i=0;i<ct1.size();i++){
            if(v[ct1[i]]){
                cout<<ct1[i];
            }
            if(i+1!=ct1.size())cout<<' ';
        }
        cout<<'\n';
        for(int i=0;i<ct2.size();i++){
            if(v[ct2[i]]){
                cout<<ct2[i];
            }
            if(i+1!=ct2.size())cout<<' ';
        }
    }
    cout.flush();
    // system("pause");
    return 0;
}