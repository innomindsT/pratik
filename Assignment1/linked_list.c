// to delete a node from reverse of singly linear linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node_t;

typedef struct list
{
	node_t *head; // head of the linked list
	int nodes_count;
}list_t;

// function declarations
void init_list(list_t *lptr);
node_t *create_node(int data);
int list_empty(list_t *lptr);
void delete_node(list_t *lptr , int pos);
void free_list(list_t *lptr);
void display_list(list_t *lptr);
int count_nodes(list_t *lptr);
void add_node(list_t *ptr, int data);
void  free_list(list_t *lptr);

int menu(void)
{
	int choice;
	printf("Select From Below Options...\n");
	printf("0.Exit\n");
	printf("1.Add Node\n");
	printf("2.Delete Node\n");
	printf("3.Display List\n");

	printf("Enter Choice:- ");
	scanf("%d",&choice);
	printf("\n");

	return choice;// return the user entered choice
}

enum menu_options
{
	EXIT , ADD , DELETE , DISPLAY 
};


int main(void)
{
	int pos;
	int data,choice;
	int count;
	list_t l1;//create a linked list
	init_list(&l1);//initialize the linked list

	while(1)
	{
		choice = menu();
		switch(choice)
		{
			case EXIT:
				free_list(&l1);
				exit(0);

			case ADD:
				printf("Enter Data :- ");
				scanf("%d",&data);
				add_node(&l1 , data);
				break;

			case DELETE:
				while(1)
				{
					printf("Enter Position To Delete:- ");
					scanf("%d",&pos);
					if(pos >= 1 && pos <= l1.nodes_count)
						break;
					printf("Invalid Position !!!\n");
				}
				count = count_nodes(&l1);
				printf("%d",count);
				int temp = count - pos;
				printf("%d",temp);
				int pos1 = temp + 1;
				printf("%d",pos1);
				printf("\n%d",pos1);
				delete_node(&l1,pos1);
				break;

			case DISPLAY:
				display_list(&l1);
				break;
		}
	}
	return 0;
}

void init_list(list_t *lptr)
{	
	lptr->head = NULL;
	lptr->nodes_count =0;
}

int list_empty(list_t *lptr)
{
	if(lptr->head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int count_nodes(list_t *lptr)
{
	int count =0 ;
	if( !list_empty(lptr)) // checking if list is empty
	{
		node_t *trav = lptr->head; // start traversing list from first node
		while(trav != NULL)       // traverse the list till last node
		{
			count++;           // increment the count
			trav = trav->next; // move pointer to next node
		}
	}
	return count;
}

node_t *create_node(int data)
{
	node_t *temp = (node_t *)malloc(sizeof(node_t));// dynamically allocated memory to list
	if(temp == NULL)
	{
		perror("malloc() Failed !!!\n");
		exit(1);
	}
	temp->data = data;// add data entered by user in the list
	temp->next = NULL;// indicated end of list

	return temp;
}

void add_node(list_t *lptr, int data)
{
	node_t *newnode = create_node(data);// create node dynamically 
	if( list_empty(lptr))// to check if list is empty
	{
		lptr->head = newnode ;//store address of newly node into head
		lptr->nodes_count++;
	}
	else
	{
		newnode->next = lptr->head;//store an address of current first node in next part of new created node
		newnode->next = lptr->head;
		lptr->head = newnode;//attach newly created node to the node
		lptr->nodes_count++;
	}
}

void delete_node(list_t *lptr , int pos)
{
	int i;
	node_t *temp = NULL;
	node_t *trav = lptr->head;
	while(i < pos -1 )
	{
		i++;
		trav = trav->next;
	}
	temp = trav->next;
	trav->next = trav->next->next;
	free(temp);
	temp = NULL;
	lptr->nodes_count--;
}

void display_list(list_t *lptr)
{
	if(!list_empty(lptr))
	{
		node_t *trav = lptr->head;
		printf("head -> ");
		while(trav != NULL)
		{
			printf(" %d -> ",trav->data);
			trav = trav->next;
		}
		printf(" null\n");
	}
	else
	{
		printf("List Is Empty!!!\n");
	}
}

void free_list(list_t *lptr)
{
	if(!list_empty(lptr))
	{
		if(lptr->head->next == NULL)
		{
			free(lptr->head);
			lptr->head = NULL;
			lptr->nodes_count = 0;
		}
		else
		{
			node_t *trav = lptr->head;// start traversal from first node
			while(trav->next->next != NULL)
			{
				trav = trav->next;
			}
			free(trav->next);//delete last node
			trav->next = NULL;
			lptr->nodes_count++;
		}
	}
	else
	{
		printf("List Is Empty!!!\n");
	}
}

