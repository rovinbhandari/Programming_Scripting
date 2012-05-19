#include<iostream>
#include<string>
using namespace std;

struct node
{
        char * c;
        struct node * next;
};

class slist
{
        struct node *head, *cur, *prev, *ptr;
        public:
                slist();
                void ins(char*);
                void del(char*);
                void disp();
};






