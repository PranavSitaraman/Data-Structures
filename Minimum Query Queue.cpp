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
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
struct set
{
	int value;
	int tempmin;
};
struct node
{
	node* prev;
	set data;
	node* next;
};
struct minstack
{
	node* head = NULL;
	node* tail = NULL;
	minstack()
	{
		head = (node*)calloc(1, sizeof(node));
		tail = (node*)calloc(1, sizeof(node));
		head->next = tail;
		tail->prev = head;
	};
	void enqueue(set a)
	{
		node* end = (node*)malloc(sizeof(node));
		node* second = tail->prev;
		tail->prev = end;
		end->next = tail;
		end->data.value = a.value;
		end->data.tempmin = a.tempmin;
		end->prev = second;
		second->next = end;
	};
	void push(int a)
	{
		node* begin = (node*)malloc(sizeof(node));
		node* second = head->next;
		head->next = begin;
		begin->prev = head;
		begin->data.value = a;
		if (second != tail)
		{
			begin->data.tempmin = MIN(second->data.tempmin, a);
		}
		else
		{
			begin->data.tempmin = a;
		}
		begin->next = second;
		second->prev = begin;
	};
	set pop(void)
	{
		set val = { (head->next)->data.value, (head->next)->data.tempmin };
		head->next = (head->next)->next;
		free((head->next)->prev);
		(head->next)->prev = head;
		return val;
	};
	bool empty()
	{
		if (head->next == tail && tail->prev == head)
		{
			return true;
		}
		return false;
	};
	~minstack()
	{
		node* point = head;
		point = point->next;
		while (point != tail)
		{
			free(point->prev);
			point = point->next;
		}
	}
};
struct mqq
{
	minstack first;
	minstack second;
	void add(int a)
	{
		first.push(a);
	}
	void remove()
	{
		if (second.empty() == true)
		{
			while (first.empty() == false)
			{
				second.enqueue(first.pop());
			}
		}
		second.pop();
		if (second.empty() == true)
		{
			while (first.empty() == false)
			{
				second.enqueue(first.pop());
			}
		}
	}
	int minimum()
	{
		if (second.empty() == false && first.empty() == false)
		{
			return MIN(first.head->next->data.tempmin, second.head->next->data.tempmin);
		}
		else if (second.empty() == true && first.empty() == false)
		{
			return first.head->next->data.tempmin;
		}
		else if (second.empty() == false && first.empty() == true)
		{
			return second.head->next->data.tempmin;
		}
		else
		{
			return NULL;
		}
	}
};
int main()
{
	mqq hello;
	hello.add(6);
	cout << hello.minimum() << endl;
	hello.add(5);
	cout << hello.minimum() << endl;
	hello.add(7);
	cout << hello.minimum() << endl;
	hello.remove();
	cout << hello.minimum() << endl;
	hello.remove();
	cout << hello.minimum() << endl;
	hello.add(4);
	cout << hello.minimum() << endl;
}
