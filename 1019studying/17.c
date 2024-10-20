#include <stdio.h>
void hammer(){
static int durability = 3;
if (durability > 0){
durability--;
printf("Hammer!\n");
} else
printf("broken...\n");
}
int main(){
hammer();
hammer();
hammer();
hammer();
hammer();
return 0;
}
