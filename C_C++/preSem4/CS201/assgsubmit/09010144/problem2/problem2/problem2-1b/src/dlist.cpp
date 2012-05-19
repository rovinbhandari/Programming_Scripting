#include "../include/dlist.h"

void dlist::ins(char*c)
{
        cur=head;
        tmp=NULL;
        while(cur!=NULL && strcmp(c,cur->s)>0)
        {
                tmp=cur;
                cur=cur->next;
        }
        ptr=new dnode;
        ptr->s=c;
        ptr->next=NULL;
        ptr->prev=NULL;
        if(tmp==NULL)
        {
                ptr->next=head;
                if(head!=NULL)
                        head->prev=ptr;
        }
}
void dlist::disp()
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
void dlist::del(char*c)
{
        cur=head;
        tmp=NULL;
        while(cur!=NULL && strcmp(c,cur->s)!=0)
        {
                tmp=cur;
                cur=cur->next;
        }
        if(cur==NULL)
        {
                cout<<"No such element in the list"<<endl;
        }
        else
        {
                if(tmp==NULL)
                {
                        head=cur->next;
                        cur->next=NULL;
                        delete cur;
                }
                else
                {
                        tmp->next=cur->next;
                        cur->next=NULL;
                        tmp->next->prev=tmp;
                       delete cur;
                }
        cout<<"Element successfully deleted"<<endl;
        }
}
