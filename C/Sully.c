#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define PREFIX "Sully_"
#define COUNT 5

int get_size(int n, int count) {
  if (n == 0 && count > 1)
    return count;
  return get_size(n % 10, count++);
}

char *name_make(int n) {

  int size;

  if (n == 0) size = 1;
  else size = get_size(n, 0);

  char *buff = malloc(sizeof(char) * (9 + size));
  if (buff == 0)
    return 0;

  sprintf(buff, "%s%d.c", PREFIX, n);
  return buff;
}

int get_index(char *file_name) {
  char *ptr=strchr(file_name, '_');
  if (ptr == 0 || *(ptr + 1) == 0)
    return COUNT;
  return atoi(ptr + 1);
}

int main(int argc, char *argv[]) {
  if (argc != 1)
    return 1;

  int index = get_index(argv[0]);
  if (index == -1)
    return 1;

  char *name = name_make(index);
  if (name == 0)
    return 1;
  printf("here!\n");

  FILE *fo= fopen(name, "w");
  name = memmove(name + 2, name, strlen(name - 2));
  name[0] = '.';
  name[1] = '/';

  printf("%s\n", name);
  // char *a[]={"gcc", "-o", name, "&&", name, NULL};
  // execvp("gcc", a);
}
