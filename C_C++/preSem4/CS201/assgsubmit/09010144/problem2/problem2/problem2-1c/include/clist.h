#include<iostream>
#include<string.h>
using namespace std;
struct cnode
{
        char* s;
        struct cnode *next;
};
class clist
{
        cnode *head,*cur,*prev,*ptr,*tmp;
        public:
        clist()
        {
        head=cur=prev=ptr=tmp=NULL;
        }
        void ins(char*);
        void del(char*);
        void disp();
};

