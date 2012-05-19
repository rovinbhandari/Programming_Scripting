/*

				PROGRAM TO :	1).INPUT THE VALUES OF a,b,c FOR THE EQUATION ax^2 + bx + c = 0
						2).DECIDE THE NATURE OF ITS ROOTS USING DISCRIMINANT
						3).PRINT THE ROOTS IF ANY

*/

#include<stdio.h>		//  imports the standard input/output header file into the program
#include<math.h>		//  imports the Mathematical functions header file into the program
int main()
{
 double a,b,c,Disc,root1,root2;	//  Disc is the Discriminant for the euation ax^2 + bx +c = 0
 printf("\n\tPlease enter the values(floating point) of a,b,c\n");   //  \n = NEW LINE character and \t = TAB character
 printf("\ta = ");
 scanf("%lf",&a);		//  %x specifies the datatype to scanf while &X creates a memory address for variable X
 printf("\tb = ");
 scanf("%lf",&b);
 printf("\tc = ");
 scanf("%lf",&c);
 printf("\tSum of roots = %lf\n",(0.0 - b) / a);
 printf("\tProduct of roots = %lf\n",c / a);
 Disc = (b * b) - (4.0 * a * c);
 if(Disc < 0.0)			//  if <boolean_expression> is true control is passed to "if{}" otherwise to "else{}"
 {
  printf("\n\t  IMAGINARY ROOTS\n");
  printf("\t1st root = (%lf) + i(%lf)\n",(0.0 - b) / (2.0 * a),(0.0 - sqrt(fabs(Disc))) / (2.0 * a));	//  fabs() returns the absolute value of the floating point number entered as its parameter
  printf("\t2nd root = (%lf) + i(%lf)\n",(0.0 - b) / (2.0 * a),(0.0 + sqrt(fabs(Disc))) / (2.0 * a));	//  fabs() returns the absolute value of the floating point number entered as its parameter
 }
 else
 {
  if(Disc == 0.0)		//  "=" is ASSIGNMENT_OPERATEROR while "==" is COMPARISON_OPERATOR
  {
   printf("\n\t  EQUAL ROOTS\n");
  }
  else
  {
   printf("\n\t  UNEQUAL ROOTS\n");
  }
  root1 = (0.0 - b - sqrt(Disc)) / (2.0 * a);				//  sqrt() is a function in math.h to return the square root of the parameter passed
  root2 = (0.0 - b + sqrt(Disc)) / (2.0 * a);				//  sqrt() is a function in math.h to return the square root of the parameter passed
  printf("\t1st root = %lf\n", root1);
  printf("\t2nd root = %lf\n", root2);
 }
}

