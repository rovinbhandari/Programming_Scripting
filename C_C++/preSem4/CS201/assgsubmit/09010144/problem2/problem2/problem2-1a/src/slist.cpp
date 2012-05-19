#include "../include/slist.h"

slist()
{
	head = cur = prev = ptr = NULL;
}

void slist::ins(char*c)
{
        cur=head;
        prev=NULL;
        while(cur!=NULL && strcmp(c,cur->s)>0)
        {
                prev=cur;
                cur=cur->next;
        }
        ptr=new node;
        ptr->s=c;
        ptr->next=NULL;
        if(prev==NULL)
        {
                ptr->next=head;
                head=ptr;
        }
        else
        {
                prev->next=ptr;
                ptr->next=cur;
        }
}
void slist::del(char*c)
{
        cur=head;
        prev=NULL;
        while(cur!=NULL && strcmp(c,cur->s)!=0)
        {
                prev=cur;
                cur=cur->next;
        }
        if(cur==NULL)
        {
                cout<<"No such element in the list"<<endl;
        }
        else
        {
                if(prev==NULL)
                {
                        head=cur->next;
                        cur->next=NULL;
                        delete cur;
                }
                else
                {
                        prev->next=cur->next;
                        cur->next=NULL;
                        delete cur;
                }
        cout<<"Element successfully deleted"<<endl;
        }
}
void slist::disp()
{
        cur=head;
        cout<<endl<<"displaying the list"<<endl;
        while(cur!=NULL)
        {
                cout<<cur->s<<" ";
                cur=cur->next;
        }
        cout<<endl;
}

