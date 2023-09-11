/*
	Trinity of Neo - Segmentation Fault
	Using C programming language, create the following program without using any Loop(for, while, do-while), if/else or switch-case. 
	You are not allowed to use goto either. Your solution should be in 100 characters or less.
	
	Your output should generate 200 lines such that first 100 lines enlist the numbers from 1 to 100 (one number per line) 
	while the next 100 lines have the numbers from 100 to 1.
*/

#include<stdio.h>
int n=1;void a(){printf("%d\n",n<101?n:201-n);++n<201?a():n;}main(){a();}
