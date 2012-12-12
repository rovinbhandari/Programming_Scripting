#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct list{
	int a;
//	char s[50];
	struct list *next;
}list;
list * insert(int a,/*char *s,*/list *head){
	list *tmphead=NULL;
	list *node=malloc(sizeof(list));
	node->a=a;
//	strcpy(node->s,s);
	node->next=NULL;
	tmphead=head;
	if(head==NULL){
		head=node;
		return head;
	}
	else{
		while(tmphead->next!=NULL){
			tmphead=tmphead->next;
		}
		tmphead->next=node;
		return head;
	}
}
void print(list *head){
	while(head!=NULL){
		printf("%d\n",head->a);
		head=head->next;
	}
}
int main(){
//	list *head=NULL;
//	head=insert(4,head);
//	print(head);
	int t;
	scanf("%d",&t);
	int i;
	char c;
	scanf("%c",&c);
	for(i=0;i<t;i++){
		int r=0,w=0,b=0,g=0;
		scanf("%c",&c);
		while(c!='\n'){
			if(c=='R'){
				r++;
			}
			else if(c=='W'){
				w++;
			}
			else if(c=='G'){
				g++;
			}
			else if(c=='B'){
				b++;
			}
		scanf("%c",&c);

		}
		if(r%2==0 && w%2==0 && g%2==0 && b%2==0){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
