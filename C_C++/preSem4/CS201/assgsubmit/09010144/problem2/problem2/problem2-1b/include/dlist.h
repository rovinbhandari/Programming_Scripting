#include<iostream>
#include<string.h>
using namespace std;
struct dnode
{
        char *s;
        struct dnode *next;
        struct dnode *prev;
};
class dlist
{
        dnode *head,*ptr,*tmp,*cur;
        public:
                dlist()
                {
                        head=cur=tmp=ptr=NULL;
                }
                void ins(char*);
                void del(char*);
                void disp();
};

