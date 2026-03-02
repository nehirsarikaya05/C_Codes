#include <stdio.h>
int main(void){
  puts("This program shows your bank account.");
  puts("Please press B to see your balance.");
  puts("Please press W to withdraw money.");
  puts("Please press D to deposit.");
  puts("Please press CTRL + D to exit.");
  int money = 12538;
  int demand;
  int w_amount;
  int d_amount;
  while ((demand = getchar()) != EOF){
    switch(demand){
      case 'B':
      case 'b':
        printf("Your balance -> %d\n", money);
        break;
      case 'W':
      case 'w':
        printf("Enter amount: ");
        scanf("%d",&w_amount);
        money -= w_amount;
        break;
      case 'D':
      case 'd':
        printf("Enter amount: ");
        scanf("%d", &d_amount);
        money += d_amount;
        break;
      case '\n':
      case '\t':
      case ' ':
        break;
      default:
        puts("Invalid request.");
        puts("Please press B to see your balance.");
        puts("Please press W to withdraw money.");
        puts("Please press D to deposit.");
        break;
    }
  }
}
