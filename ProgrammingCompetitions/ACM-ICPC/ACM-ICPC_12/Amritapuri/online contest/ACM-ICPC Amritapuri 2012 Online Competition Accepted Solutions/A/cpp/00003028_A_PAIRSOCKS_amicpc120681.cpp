#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;
int main(int argc, char **argv)
{
	int t;
	scanf("%d", &t);
	for( int i=0; i<t; i++ ){
		int count[4]={0};
		char socks[51];
		scanf("%s", socks);
		string sock = string(socks);
		for( int j=0; j<sock.length(); j++ ){
			if( sock[j]=='R' )
				count[0]++;
			if( sock[j]=='G' )
				count[1]++;
			if( sock[j]=='B' )
				count[2]++;
			if( sock[j]=='W' )
				count[3]++;
		}
		int yn=0;
		for( int j=0; j<4; j++ ){
			if( count[j]%2 != 0 ){
				yn=1;
				break;
			}
		}
		if( yn==1 )
			printf("NO\n");
		else
			printf("YES\n");
		
		
	}
	return 0;
}

