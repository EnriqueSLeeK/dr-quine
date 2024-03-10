#include <stdio.h>
#define a "#include <stdio.h>%c#define a %c%s%c%c#define f m##a##i##n%c#define s() int f(){FILE *fo=fopen(%cGrace_kid.c%c,%cw%c);if (fo == 0) return 1;fprintf(fo, a, 10, 34, a, 34, 10, 10, 34, 34, 34, 34, 10, 10, 10, 10, 10, 10);fclose(fo);return 0;}%c%cs()%c/*%cComment%c*/%c"
#define s() int main(){FILE *fo=fopen("Grace_kid.c","w");if (fo == 0) return 1;fprintf(fo, a, 10, 34, a, 34, 10, 10, 34, 34, 34, 34, 10, 10, 10, 10, 10, 10);fclose(fo);return 0;}

s()
/*
Comment
*/
