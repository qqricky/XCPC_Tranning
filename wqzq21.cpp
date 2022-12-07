#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define m_inf 0x3f
using namespace std;

int data[110]={};
vector<int> opNum;

void getOpNum(int n){
    cout<<"sadsfjkl"<<n<<endl;
	opNum.clear();
	_for(i,1,101){
		if(data[i]>0){
			if(i%n==0||n%i==0)
			opNum.push_back(i);
		}
	}
}
//int path=1; 
int dfs(int n){ //我先拿走 n,第一次迭代是对手的回合 
	getOpNum(n);   
    for(int x:opNum){
        cout<<x<<' ';
        cout<<endl;
    }     //接招方式 
	if(opNum.empty()) return 0; //无招可走，输 
	int count=0;
	for(int x:opNum){   //遍历出招策略 
		data[x]--;
		if(!dfs(x)) {data[x]++;return 1;} //存在必胜出招策略 (即对手必败)
		else count++; 		//自己必败的走法 
		data[x]++;
	}
	if(count==opNum.size()) {  //无论自己怎么走，必败 
		return 0;
	}
    return 0;
}

int main(){
	memset(data,0,sizeof(int)*110);
	vector<int>startNum;
	int x;cin>>x;data[x]++;char ch=getchar();
	while(ch!='\n'){cin>>x;data[x]++;ch=getchar();}; 
	ch='0';
	while(ch!='\n'){cin>>x;startNum.push_back(x);ch=getchar();};
    //cout<<"asdjka"<<endl;
	for(int x:startNum){
        data[x]--;
		if(!dfs(x)){
			cout<<x;
            system("pause");
			return 0;
		}
        data[x]++;
    }

}
