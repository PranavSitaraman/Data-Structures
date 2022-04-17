#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cstdlib>
#include<ctype.h>
#include<math.h>
#include<cmath>
#include<time.h>
#include<ctime>
#include<string.h>
#include<string>
#include<limits.h>
#include<climits>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<complex>
using namespace std;
int main()
{
	int n;
	printf("Enter size of heap: ");
	scanf("%d", &n);
	int heap[20] = { 0 };
	printf("Enter heap in space separated integers: ");
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &heap[i]);
	}
	for (int run = 0; run < n; run++)
	{
		for (int loc = 1; loc <= n; loc++)
		{
			if (loc * 2 <= n && heap[loc] > heap[2 * loc])
			{
				int temp = heap[loc];
				heap[loc] = heap[2 * loc];
				heap[2 * loc] = temp;
			}
			else if (loc * 2 + 1 <= n && heap[loc] > heap[2 * loc + 1])
			{
				int temp = heap[loc];
				heap[loc] = heap[2 * loc + 1];
				heap[2 * loc + 1] = temp;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d, ", heap[i]);
	}
}
