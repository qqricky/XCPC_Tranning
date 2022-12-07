#include<bits/stdc++.h>
using namespace std;
#define long long long
bool cmp(int x,int y){
	return x<y;
}
int* sort_(int *a,int n){
	sort(a,a+n);
	int *b=(int*)malloc(sizeof(int)*(n-1));
	for(int i=0;i<n-1;i++)
		b[i]=a[i+1]-a[i];
	return b;
}

int maxFactor(int*b,int size){
	int maxEnd=10001,maxFactor=1;
	for(int i=0;i<size;i++)
		if (b[i]<maxEnd)
			maxEnd=b[i];
	for(int i=2;i<=maxEnd;i++){
		int flag=1;
		for(int j=0;j<size;j++){
			if(!(b[j]%i))
			{
				flag=0;
				break;
			}
		if(flag)
			maxFactor=i;	
		}
		
	}
	return maxFactor;
}
int main(void){
	int n;
	cin>>n;
	int *a=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int*b=sort_(a,n);  //排序后构造邻项差序列 
	int d=maxFactor(b,n-1); //找邻项差序列的最大公因子 ,即最大公差，这样使得原序列项数最少 
	int sumNum=1;
	for(int i=0;i<n-1;i++)
		sumNum+=b[i]/d;  //算出最大公差情形下的总项数 
    sumNum=max(sumNum,n);
	cout<<sumNum;
	free(a);
	free(b);
    //system("pause");
	return 0;
}