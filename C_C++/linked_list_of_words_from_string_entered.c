#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENUSERINPUT 1024

struct node
{
	char* word;
	struct node* next;
};

struct node* add_node(struct node*, char*);
void output(struct node*);

int main(void)
{
	char userinput[LENUSERINPUT];
	printf(" > ");
	fgets(userinput, LENUSERINPUT, stdin);

	struct node* head = NULL;
	struct node* pnode = NULL;
	char* token;
	char* str;
	int i;
	for(i = 0, str = userinput; ; i++, str = NULL)
	{
		token = strtok(str, " \t\n");
		if(token == NULL)
			break;

		pnode = add_node(pnode, token);
		if(!i)
			head = pnode;
	}
	output(head);
	return 0;
}

struct node* add_node(struct node* current, char* token)
{
	struct node* new = (struct node*) malloc(sizeof(struct node));
	new->word = (char*) malloc(strlen(token) + 1);
	strcpy(new->word, token);
	new->next = NULL;
	if(current)
		current->next = new;
	return new;
}

void output(struct node* head)
{
	struct node* i = head;
	while(i)
	{
		printf("\t%s\n", i->word);
		i = i->next;
	}
}

