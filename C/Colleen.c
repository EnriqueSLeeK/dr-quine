#include <stdio.h>
void nothing(){}
// Wow
int main(){// Nice!
  char *s="#include <stdio.h>%cvoid nothing(){}%c// Wow%cint main(){// Nice!%c%c%cchar *s=%c%s%c;%c%c%cprintf(s, 10, 10, 10, 10, 32, 32, 34, s, 34, 10, 32, 32, 10, 32, 32, 10, 10);%c%c%cnothing();%c}%c";
  printf(s, 10, 10, 10, 10, 32, 32, 34, s, 34, 10, 32, 32, 10, 32, 32, 10, 10);
  nothing();
}
