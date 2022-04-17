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
struct impnode
{
	impnode * l, * r;
	int v, p, s, f;
	impnode(int v) : l(0), r(0), v(v), p(rand()), s(1), f(0) {}
};
int impsize(impnode * t)
{
	return t ? t->s : 0;
}
void imppush(impnode * t)
{
	if (t == NULL) return;
	if (t->f)
	{
		swap(t->l, t->r);
		if (t->l) t->l->f ^= 1;
		if (t->r) t->r->f ^= 1;
		t->f = 0;
	}
}
void imppull(impnode * t)
{
	if (t == NULL) return;
	t->s = impsize(t->l) + impsize(t->r) + 1;
}
void impsplit(impnode * t, impnode * &l, impnode * &r, int k)
{
	imppush(t);
	if (t == NULL) l = r = NULL;
	else if (k <= impsize(t->l)) impsplit(t->l, l, t->l, k), r = t;
	else impsplit(t->r, t->r, r, k - impsize(t->l) - 1), l = t;
	imppull(t);
}
void impmerge(impnode * &t, impnode * l, impnode * r)
{
	imppush(l), imppush(r);
	if (l == NULL || r == NULL) t = l ? l : r;
	else if (l->p > r->p) impmerge(l->r, l->r, r), t = l;
	else impmerge(r->l, l, r->l), t = r;
	imppull(t);
}
void impreverse(impnode * t, int l, int r)
{
	impnode * a, * b;
	impsplit(t, t, b, r + 1);
	impsplit(t, t, a, l);
	a->f ^= 1;
	impmerge(t, t, a);
	impmerge(t, t, b);
}
int main()
{
	impnode* a = new impnode(3), * b, * c;
	impsplit(a, b, c, 4);
}
