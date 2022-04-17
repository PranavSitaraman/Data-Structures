#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include<string.h>
struct stack
{
	struct stack* prev;
	int data;
	struct stack* next;
} *top;
struct stack* stackcreate(int n)
{
	struct stack* nextnode, * tmp;
	top = (struct stack*)malloc(sizeof(struct stack));
	(*top).next = NULL;
	(*top).prev = NULL;
	tmp = top;
	for (int i = 1; i <= n; i++)
	{
		nextnode = (struct stack*)malloc(sizeof(struct stack));
		(*nextnode).data = i;
		(*nextnode).next = NULL;
		(*nextnode).next = tmp;
		(*tmp).prev = nextnode;
		tmp = nextnode;
	}
	return tmp;
}
void createstack()
{
	int n;
	printf("Enter length of stack: ");
	scanf("%d", &n);
	struct stack* tmp = stackcreate(n);
	printf("Stack contents:");
	while ((*tmp).next != NULL)
	{
		printf(" %d", (*tmp).data);
		tmp = (*tmp).next;
	}
}
void pop()
{
	int n;
	printf("Enter length of stack: ");
	scanf("%d", &n);
	struct stack* tmp = stackcreate(n);
	struct stack* end = tmp;
	end = (*end).next;
	printf("Value: %d", (*tmp).data);
	free(tmp);
	printf("\nStack contents:");
	while ((*end).next != NULL)
	{
		printf(" %d", (*end).data);
		end = (*end).next;
	}
}
void push()
{
	int k;
	printf("Enter length of stack: ");
	scanf("%d", &k);
	struct stack* tmp = stackcreate(k);
	struct stack* push = (struct stack*)malloc(sizeof(struct stack));
	int n;
	printf("Enter value to be pushed: ");
	scanf("%d", &n);
	(*push).data = n;
	(*tmp).prev = push;
	(*push).next = tmp;
	printf("Stack contents:");
	while ((*push).next != NULL)
	{
		printf(" %d", (*push).data);
		push = (*push).next;
	}
}
void stackempty()
{
	int n;
	printf("Enter length of stack: ");
	scanf("%d", &n);
	struct stack* tmp = stackcreate(n);
	if ((*tmp).next == NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		printf("Stack is not empty");
	}
}
struct queue
{
	struct queue* prev;
	int data;
	struct queue* next;
} *in;
struct queue* queuecreate(int n)
{
	struct queue* nextnode, * tmp;
	in = (struct queue*)malloc(sizeof(struct queue));
	(*in).next = NULL;
	(*in).prev = NULL;
	tmp = in;
	for (int i = 1; i <= n; i++)
	{
		nextnode = (struct queue*)malloc(sizeof(struct queue));
		(*nextnode).data = i;
		(*nextnode).next = NULL;
		(*nextnode).prev = tmp;
		(*tmp).next = nextnode;
		tmp = (*tmp).next;
	}
	return in;
}
void createqueue()
{
	int n;
	printf("Enter length of queue: ");
	scanf("%d", &n);
	struct queue* tmp = queuecreate(n);
	printf("Queue contents:");
	tmp = (*tmp).next;
	while (tmp != NULL)
	{
		printf(" %d", (*tmp).data);
		tmp = (*tmp).next;
	}
}
void enqueue()
{
	int k;
	printf("Enter length of queue: ");
	scanf("%d", &k);
	struct queue* tmp = queuecreate(k);
	struct queue* head = tmp;
	struct queue* push = (struct queue*)malloc(sizeof(struct queue));
	int n;
	printf("Enter value to be enqueued: ");
	scanf("%d", &n);
	while ((*tmp).next != NULL)
	{
		tmp = (*tmp).next;
	}
	(*tmp).next = push;
	(*push).prev = tmp;
	(*push).next = NULL;
	(*push).data = n;
	printf("Queue contents:");
	head = (*head).next;
	while (head != NULL)
	{
		printf(" %d", (*head).data);
		head = (*head).next;
	}
}
void dequeue()
{
	int k;
	printf("Enter length of queue: ");
	scanf("%d", &k);
	struct queue* tmp = queuecreate(k);
	struct queue* start = (*tmp).next;
	free(tmp);
	struct queue* head = (*start).next;
	free(start);
	(*head).prev = NULL;
	printf("Queue contents:");
	while (head != NULL)
	{
		printf(" %d", (*head).data);
		head = (*head).next;
	}
}
void queueempty()
{
	int n;
	printf("Enter length of queue: ");
	scanf("%d", &n);
	struct queue* tmp = queuecreate(n);
	if ((*tmp).next == NULL)
	{
		printf("Queue is empty");
	}
	else
	{
		printf("Queue is not empty");
	}
}
int main()
{
	char funcNames[][100] =
	{
		"Create Stack",
		"Pop",
		"Push",
		"Stack Empty",
		"Create Queue",
		"Enqueue",
		"Dequeue",
		"Queue Empty"
	};
	void (*funcs[])() =
	{
		createstack,
		pop,
		push,
		stackempty,
		createqueue,
		enqueue,
		dequeue,
		queueempty
	};
	int choice;
	int maxFuncs = sizeof(funcs) / sizeof(funcs)[0];
	for (int i = 0; i < maxFuncs; i++)
	{
		printf("%d: %s:\n", i + 1, funcNames[i]);
	}
	while (true)
	{
		printf("Enter selection: ");
		scanf("%d", &choice);
		getchar();
		if (choice > maxFuncs || choice <= 0)
		{
			break;
		}
		printf("%s : Output below\n", funcNames[choice - 1]);
		funcs[choice - 1]();
		printf("\n");
	}
}
