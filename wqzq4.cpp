#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n;
	cin>>n;
	int *arr=(int*)malloc(sizeof(int)*n);
    int tmp;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		cin>>tmp;
	}
	int po_times=0,ne_times=0;
	for(int i=0;i<n;i++)
		if(arr[i]>0) po_times++;
		else  ne_times++;
	if((po_times<=1)||(ne_times<=1))
	cout<<"Yes";
	else cout<<"No";
	free(arr);
    system("pause");
	return 0;
}