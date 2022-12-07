#include <iostream>
#include <algorithm> 
#include <cstring> 
#include<vector>
using namespace std;
const int N=1e5+10;
vector<int>a[N];
vector<int>b[N];
int main()
{
	int x,y;cin>>x>>y;
    for(int i=0;i<=x;i++){
        a[i].resize(y+2);
        b[i].resize(y+2);
    }
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
		{
			cin>>a[i][j];
			b[i][j] =b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];			
		}
	int q;cin>>q;
	while(q--)
	{
		int x1,x2,y1,y2;
		cin >>x1>>y1>>x2>>y2;
		cout <<(b[x2][y2]+b[x1-1][y1-1]-b[x1-1][y2]-b[x2][y1-1])<<endl;
	}
	return 0;
}