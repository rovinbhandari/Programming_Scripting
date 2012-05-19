#include <stdio.h>

char *ar[] = {"Snakes", "on", "a", "Plane\n", NULL};

int main () {
char **i = ar;
while (*i) {
printf("%s ", *i);
i++;
}
}
