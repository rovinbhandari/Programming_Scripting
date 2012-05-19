#include<iostream>
#include<fstream>
#include"../include/slist.h"
using namespace std;

int main()
{
        char *c,*q;
        slist l;
        ofstream fout("file.txt");
        cout<<"Enter the elements in the file ($ to exit):"<<endl;
        c=new char[10];
        cin>>c;
        while(c[0]!='$')
        {
                fout<<c<<" ";
                cin>>c;
        }
        fout.close();
        ifstream fin("file.txt");
        do
        {
                q=new char[10];
                fin>>q;
                l.ins(q);
                l.disp();
        }while(fin);
        fin.close();
        cout<<"Enter the word to be deleted ";
        c=new char[10];
        cin>>c;
        l.del(c);
        l.disp();
        return 0;
}

