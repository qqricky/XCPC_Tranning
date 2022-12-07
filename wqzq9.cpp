// 可删除的点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int arr[n][2];
    for (int i=0; i < n; i++)
    {
        for (int j=0; j < 2; j++)
        {
            cin >> arr[i][j];

        }
    }
    int count = 0;
    for (int i=0; i < n; i++)
    {
        
        for(int j=0;j<n;j++)
        {
            if (arr[i][1] * arr[j][1] < 0)
                continue;
            else
            {
                if (j == i)
                    continue;
                else
                    {
                    	count = 1;
                        break;
					}
            }
        } 
        
    }
        if (count == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
} 
