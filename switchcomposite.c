#include<stdio.h>
void main(){
int m, i, a, d=0;
printf("Pleae enter a number to find whether its prime or composite: ");
scanf("%d", &i);
printf("1. Enter 1 to find out whether a number is composite or prime\n2. Enter 
2 to find out whether the number is even or odd\nPlease enter an option: " );
scanf("%d", &m);
switch(m){
case 1:
  for(a=1; a<=i; a++){
  if(i%a==0){
    d++;
  }
 }
    if(d>2)
    printf("\nThe number is composite\n");
    else
    printf("\nThe number is prime\n");
    break;

case 2:
  if(i%a==0){
    printf("The Number you've entered is even" );
  }else{
    printf("The Number you've entered is odd\n" );
  }
break;
default: printf("You've entered a wrong option\nPlease try again\n");
}
}
