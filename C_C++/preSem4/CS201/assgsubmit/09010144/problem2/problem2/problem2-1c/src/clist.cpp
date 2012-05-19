#include "../include/clist.cpp"

void clist::ins(char*c)
{
        cur=head;
        prev=NULL;
        ptr=new cnode;
        ptr->s=c;
        ptr->next=NULL;
        if(head==NULL)
        {
                head=ptr;
                ptr->next=head;
        }
        else {
        while(cur->next!=head && strcmp(c,cur->s)>0)
        {
                prev=cur;
                cur=cur->next;
        }
        if(strcmp(c,cur->s)==0)
                cout<<"no duplication allowed"<<endl;
        else
        {
        if(prev==NULL && cur==head && strcmp(c,cur->s)>0)
        {
                ptr->next=head;
                cur->next=ptr;
        }
        else if(prev==NULL && cur==head && strcmp(c,cur->s)<0)
        {
                ptr->next=head;
                head=ptr;
                cur->next=head;
        }
        else if(prev==NULL && cur->next!=head)
        {
                tmp=cur;
                while(tmp->next!=head)
                        tmp=tmp->next;
                ptr->next=head;
                head=ptr;
                tmp->next=head;
        }
        else if(prev!=NULL && cur->next==head && strcmp(c,cur->s)>0)
        {
                ptr->next=head;
                cur->next=ptr;
        }
        else
        {
                ptr->next=cur;
                prev->next=ptr;
        }
        }
        }
}
void clist::disp()
{
        if(head==NULL)
                cout<<"list is empty"<<endl;
        else
        {       cout<<"displaying the list"<<endl;
        cur=head;
        while(cur->next!=head)
        {
                cout<<cur->s<<" ";
                cur=cur->next;
        }
        cout<<cur->s<<" ";
        cout<<endl;
        }
}
void clist::del(char *c)
{
        prev=NULL;
        cur=head;
        while(cur->next!=head && strcmp(c,cur->s)>0)
        {
                prev=cur;
                cur=cur->next;
        }
        if(strcmp(cur->s,c)!=0)
                cout<<"no such element"<<endl;
        else
        {
                if(prev==NULL && cur->next==head)
                {
                        head=NULL;
                        delete cur;
                }
                else if(prev==NULL && cur->next!=head)
                {
                        tmp=cur->next;
                        while(tmp->next!=head)
                                tmp=tmp->next;
                        head=cur->next;
                        tmp->next=head;
                        cur->next=NULL;
                       delete cur;
                }
                else if(prev!=NULL && cur->next==head)
                {
                        prev->next=head;
                        cur->next=NULL;
                        delete cur;
                }
                else
                {
                        prev->next=cur->next;
                        cur->next==NULL;
                        delete cur;
                }
        }
}
