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
const int MAXN = 16;
int y[MAXN] = { 0 };
const long long SZ = 1 << 4;
int sum[2 * SZ] = { 0 };
int lazy[2 * SZ] = { 0 };
void update(int i, int l, int r, int p, int k)
{
	if (r < p || p < l) return;
	if (l == r)
	{
		sum[i] = k;
		return;
	}
	int m = (l + r) / 2;
	update(2 * i, l, m, p, k);
	update(2 * i + 1, m + 1, r, p, k);
	sum[i] = sum[2 * i] + sum[2 * i + 1];
}
void update3(int i, int x)
{
	for (; i < MAXN; i += (i & (-i))) y[i] += x;
}
int prefixSum(int i)
{
	int tot = 0;
	for (; i > 0; i -= (i & (-i))) tot += y[i];
	return tot;
}
int query3(int i, int j)
{
	return prefixSum(j) - prefixSum(i - 1);
}
int main()
{
	int tree[MAXN] = { 0 };
	printf("Enter the size of the tree: ");
	int a;
	scanf("%d", &a);
	printf("Enter the entries separated by spaces: ");
	for (int i = 0; i < a; i++)
	{
		int b;
		cin >> b;
		tree[i] = b;
		update(1, 1, SZ, i + 1, b);
	}
	for (int i = 0; i < MAXN; i++)
	{
		if (i % 2 == 0)
		{
			y[i] = sum[MAXN + i];
		}
		else
		{
			int a = MAXN + i;
			while (a % 2 != 0 && a != 1)
			{
				a = (a - 1) / 2;
			}
			y[i] = sum[a];
		}
	}
	for (int i = 0; i < MAXN; i++)
	{
		cout << y[i] << " ";
	}
	cout << endl << query3(7, 9) << endl;
	update3(15, 3);
	cout << query3(7, 9) << endl;
}
