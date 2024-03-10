#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#define PREFIX "Sully_"
#define COUNT 5
#define S "#include <sys/wait.h>%c#include <stdlib.h>%c#include <string.h>%c#include <unistd.h>%c#include <stdio.h>%c#define PREFIX %cSully_%c%c#define COUNT %d%c#define S %c%s%c%cchar *name_make(){int size=(COUNT / 10) + 1;char *buff = malloc(sizeof(char) * (9 + size));if (buff == 0) return 0;sprintf(buff, %c%cs%cd.c%c, PREFIX, COUNT);return buff;}%cvoid shift_right(char *str, int offset){int n = strlen(str);int last = n - 1;for (int k=0; k< n - offset; k++) str[last - k] = str[last - (k + offset)];}%cint main(){if (COUNT <= 0) return 0;char *name = name_make();if (name == 0) return 1;char *dup = strdup(name);FILE *fo= fopen(name, %cw%c);shift_right(name, 2);name[0] = '.';name[1] = '/';fprintf(fo, S, 10, 10, 10, 10, 10, 34, 34, 10, COUNT - 1, 10, 34, S, 34, 10, 34, 37, 37, 34, 10, 10, 34, 34, 34, 34, 34, 34, 10);fclose(fo);int pid = fork();if(pid == 0){char *a[]={%cgcc%c, dup, %c-o%c, name, NULL};if (execvp(a[0], a)) exit(0);}else{wait(NULL);char *a[]={name};if (execvp(a[0], a)) exit(0);}}%c"
char *name_make(){
int size=(COUNT / 10) + 1;
char *buff = malloc(sizeof(char) * (9 + size));
if (buff == 0) return 0;
sprintf(buff, "%s%d.c", PREFIX, COUNT);
return buff;
}
void shift_right(char *str, int offset){
int n = strlen(str);
int last = n - 1;
for (int k=0; k < n - offset; k++)
str[last - k] = str[last - (k + offset)];
}
int main(){
  if (COUNT<=0)return 0;
  char *name = name_make();
  if (name == 0) return 1;
  char *dup = strdup(name);
  FILE *fo= fopen(name, "w");
  shift_right(name, 2);
  name[0] = '.';
  name[1] = '/';
  fprintf(fo, S, 10, 10, 10, 10, 10, 34, 34, 10, COUNT - 1, 10, 34, S, 34, 10, 34, 37, 37, 34, 10, 10, 34, 34, 34, 34, 34, 34, 10);
  fclose(fo);
  int pid = fork();
  if (pid == 0){
    char *a[]={"gcc", dup, "-o", name, NULL};
    if (execvp(a[0], a)) exit(0);
  } else {
    wait(NULL);
    char *a[]={name};
    if (execvp(a[0], a)) exit(0);
  }
}
