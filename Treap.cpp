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
struct point
{
	point* l, * r;
	int k, p;
	point(int k) : l(0), r(0), k(k), p(rand()) {}
};
void split(point* t, point*& l, point*& r, int k)
{
	if (t == NULL) l = r = NULL;
	else if (k <= t->k) split(t->l, l, t->l, k), r = t;
	else split(t->r, t->r, r, k), l = t;
}
void merge(point*& t, point* l, point* r)
{
	if (l == NULL || r == NULL) t = l ? l : r;
	else if (l->p > r->p) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
}
void insert(point*& t, int k)
{
	point* n = new point(k), * a;
	split(t, t, a, k);
	merge(t, t, n);
	merge(t, t, a);
}
int main()
{
	point* a = new point(3);
	insert(a, 4);
}
