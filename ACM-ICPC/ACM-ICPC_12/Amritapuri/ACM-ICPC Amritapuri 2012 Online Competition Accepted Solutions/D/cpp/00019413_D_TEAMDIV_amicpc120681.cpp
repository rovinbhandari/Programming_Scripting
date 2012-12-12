#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

int n;
long long count1 = 1;
//int ak[20000];
struct list1{
	int n1;
	char ak;
	list1 *next;
}abc[20000];

bool label1( int i, char ak){
	list1 *t1 = abc[i].next;
	//int allSet = 0;
	char ak1;
	if( ak == 'k' )
		ak1 = 'a';
	else
		ak1 = 'k';
	while( t1 != NULL ){
		if( abc[t1->n1].ak == ak )
			return false;
		else
			if( abc[t1->n1].ak == 'x' ){
				if( ak=='k' )
					abc[t1->n1].ak = 'a';
				else
					abc[t1->n1].ak = 'k';
				bool b = label1( t1->n1, ak1 );
				if( b==false )
					return false;
				
			}
			
		t1 = t1->next;
		
	}
	/*t1 = abc[i].next;
	char ak1;
	if( ak == 'k' )
		ak1 = 'a';
	else
		ak1 = 'k';
	while( t1 != NULL ){
		bool b = label1( t1->n1, ak1 );
		if( b==false )
			return false;
		t1 = t1->next;
		
	}*/
	return true;
		
}

bool label( int i ){
	abc[i].ak = 'a';
	list1 *t1 = abc[i].next;
	while( t1 != NULL ){
		//printf("%dfuck\n", t1->n1);
		abc[t1->n1].ak = 'k';
		t1 = t1->next;
	}
	t1 = abc[i].next;
	while( t1 != NULL ){
		bool b = label1( t1->n1, 'k' );
		if( b==false )
			return false;
		t1 = t1->next;
	}
	return true;
}

void calc(){
	for( int i=0; i<n; i++ ){
		//printf("%d \n", i );//(abc[i].next)->n1);
		if( abc[i].ak == 'x' ){
			//printf("fuck");
			//printf("%d \n", i );//(abc[i].next)->n1);
			//if( abc[i].next == 0 )
				//printf("fuck");
			bool b = label( i );
			if( b==false ){
				printf("%d\n",0);
				return;
			}
			else 
				count1 = (count1*2)%1000000007;
			
		}
	}
	printf("%lld\n", count1);
	
	
}


int main(int argc, char **argv)
{
	int t;
	scanf("%d", &t);
	for( int i=0; i<t; i++ ){
		count1=1;
		scanf("%d", &n);
		
		for( int j=0; j<n; j++ ){
			abc[j].next = 0;
			abc[j].ak = 'x';
		}
		
		for( int j=0; j<n; j++ ){
			abc[j].n1 = j;
			int k;
			scanf("%d", &k);
			//cout<<k<<"fjnjfj"<<'\n';
			for( int i1=0; i1<k; i1++ ){
				//printf("fuck");
				int t1;
				scanf("%d", &t1);
				list1 *t2 = new list1;
				t2->n1 = t1;
				t2->next = abc[j].next;
				abc[j].next = t2;
				
				list1 *t3 = new list1;
				t3->n1 = j;
				t3->next = abc[t1].next;
				abc[t1].next = t3;
				
				// Insert
			} 
		}
		/*for( int i=0; i<n; i++ ){
			list1 *t1 = abc[i].next;
			while( t1 != NULL ){
				cout<<(t1->n1);
				t1 = t1->next;
			}
			cout<<'\n';
		}*/
		calc();
		char c;
		scanf("%c", &c);
    }
	return 0;
}

