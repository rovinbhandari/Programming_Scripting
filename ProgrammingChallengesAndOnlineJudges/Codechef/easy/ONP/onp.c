#include <stdio.h>

char str[401];
char stack[401];
int top;

void push(char);
char pop(void);

void toRPN(void)
{
	int i = 0;
	char c;
	while(c = str[i])
	{
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			putchar(c);
		else if(c == ')')
		{
			putchar(pop());
			pop();
		}
		else
			push(c);
		i++;
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", str);
		toRPN();
		putchar('\n');
	}
	return 0;
}

void push(char c)
{
	stack[top++] = c;
}

char pop(void)
{
	return stack[--top];
}

