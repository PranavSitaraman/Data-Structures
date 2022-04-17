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
const long long SZ = 1 << 4;
int sum[2 * SZ] = { 0 };
int lazy[2 * SZ] = { 0 };
int query(int i, int l, int r, int a, int b)
{
	if (r < a || b < l) return 0;
	if (a <= l && r <= b) return sum[i];
	int m = (l + r) / 2;
	int ql = query(2 * i, l, m, a, b);
	int qr = query(2 * i + 1, m + 1, r, a, b);
	return ql + qr;
}
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
void push(int i, int l, int r)
{
	if (lazy[i] != 0) 
	{
		sum[i] += (r - l + 1) * lazy[i];
		if (l < r)
		{
			lazy[2 * i] += lazy[i];
			lazy[2 * i + 1] += lazy[i];
		}
		lazy[i] = 0;
	}
}
void pull(int i, int l, int r)
{
	int m = (l + r) / 2;
	push(2 * i, l, m);
	push(2 * i + 1, m + 1, r);
	sum[i] = sum[2 * i] + sum[2 * i + 1];
}
int query2(int i, int l, int r, int a, int b)
{
	push(i, l, r);
	if (r < a || b < l) return 0;
	if (a <= l && r <= b)
	{
		return sum[i];
	}
	int m = (l + r) / 2;
	int ql = query2(2 * i, l, m, a, b);
	int qr = query2(2 * i + 1, m + 1, r, a, b);
	return ql + qr;
}
void update2(int i, int l, int r, int a, int b, int k)
{
	if (r < a || b < l) return;
	if (a <= l && r <= b)
	{
		lazy[i] += k;
		return;
	}
	int m = (l + r) / 2;
	update2(2 * i, l, m, a, b, k);
	update2(2 * i + 1, m + 1, r, a, b, k);
	pull(i, l, r);
}
int main()
{
	printf("Enter the size of the tree: ");
	int a;
	scanf("%d", &a);
	printf("Enter the entries separated by spaces: ");
	for (int i = 0; i < a; i++)
	{
		int b;
		cin >> b;
		update(1, 1, SZ, i + 1, b);
	}
	cout << query(1, 1, SZ, 7, 15) << endl;
	update(1, 1, SZ, 15, 3);
	cout << query(1, 1, SZ, 7, 15);
}
