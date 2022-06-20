// to implement stack

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct{
	int arr[SIZE];
	int top;// to point/store top of stack
}stack_t;

// functions declaration
void init_stack(stack_t *ps);
int stack_full(stack_t *ps);
int stack_empty(stack_t *ps);
void push_element(stack_t *ps, int element);
int peek_element(stack_t *ps);
void pop_element(stack_t *ps);
void printStack(stack_t *ps,int count);

int menu(void)
{
	int choice;
	printf("Select From Below Options\n");
	printf("0. Exit\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Peek\n");
	printf("4. Print Stack\n");

	printf("Enter Choice : ");
	scanf("%d",&choice);
	printf("\n");

	return choice;
}

enum menu_options {
	EXIT,PUSH,POP,PEEK,PRINT
};

int main(void)
{
	stack_t s;
	int element;
	int choice;
	int i,count=0;
	init_stack(&s);// initialise stack
	 
	while(1)
	{
		choice = menu();
		switch(choice)
		{
			case EXIT:
				exit(0);
				break;

			case PUSH:
				if(! stack_full(&s))// check is stack is full : if full exit
				{
					printf("Enter Element: ");
					scanf("%d",&element);
					push_element(&s,element);
					count++;
					printf("%d is pushed on stack...\n",element);
					printf("\n");
				}
				else
				{
					printf("Stack Overflow\n");
				}
				break;

			case POP:
				if(! stack_empty(&s))// check if stack empty : if empty we cannot pop
				{
					element = peek_element(&s);//get the top element to pop
					pop_element(&s);// use the pop function to pop
					count--;
					printf("%d popped from stack\n",element);
				}
				else
				{
					printf("Stack Underflow..\n");
				}
				break;

			case PEEK:
				if(! stack_empty(&s))//to check if stack is empty; if empty exit
				{
					element = peek_element(&s);
					printf("Top Element of Stack is %d\n",element);
				}
				else
				{
					printf("Stack Underflow..\n");
				}
				break;
			case PRINT:
				printStack(&s,count);
				printf("\n");
				break;
			}
			
		}
	return 0;
}
void printStack(stack_t *ps,int count)
{
	printf("Elements in stack are:- \n");
	for(int i=0 ;i< count;i++)
	{
		printf("%d ",ps->arr[i]);
	}
	printf("\n");
}

void init_stack(stack_t *ps)
{
	ps->top = -1;// initilise stack and point to top // top =-1 indicates empty stack
}
int stack_full(stack_t *ps)
{
	// to check if stack is full if top == size -1 then this indicates stack is full
	return(ps->top == SIZE-1);
}
int stack_empty(stack_t *ps)
{
	// to check if stack is empty if top == -1 (like in init) then stack is empty
	return (ps->top == -1);
}
void push_element(stack_t *ps , int element)
{
	// to push we need to increment vakue of top by 1 and the pish element
	ps->top++;
	ps->arr[ps->top] = element;
}
int peek_element(stack_t *ps)
{
	// return the value at top position 
	return(ps->arr[ps->top]);
}
void pop_element(stack_t *ps)
{
	// to pop element from stack we need to decrement top which means we will delete top element
	ps->top--;
}
	
					


