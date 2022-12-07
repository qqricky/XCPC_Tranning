#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(void){
	int n;
	cin>>n;
	int (*map)[n]=(int(*)[n])malloc(sizeof(int)*n*n);
	int (*dist)[n]=(int(*)[n])malloc(sizeof(int)*n*n);
	memset(map,0,sizeof(int)*n*n);
	memset(dist,0x3f,sizeof(int)*n*n);
	for(int i=0;i<n-1;i++){             //输入 
		int v1,v2;
		cin>>v1>>v2;
		cin>>map[v1-1][v2-1];
		map[v2-1][v1-1]=dist[v1-1][v2-1]=dist[v2-1][v1-1]=map[v1-1][v2-1];
	}
	for(int k=0;k<n;k++){                          //Floyd算法 
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j])
					dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	for(int i=0;i<n;i++){            //到自己的距离设成0 
		dist[i][i]=0;
	}
	int max=0;
	for(int i=0;i<n*n;i++){         //找所有距离里最大的 
		if(max<*(dist[0]+i))
			max=*(dist[0]+i);
	}
	cout<<10*max+max*(max+1)/2;     //根据题目信息推出来的路费公式 
	return 0;
}