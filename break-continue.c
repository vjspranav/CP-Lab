#include<stdio.h>
void breake(){
	int b, i, d=0;
	printf("Please enter a number\n");
	scanf("%d", &b);
	while(d<8){
		printf("Please enter another number\n");
		scanf("%d", &i);
		if(i<0)
		break;
		b = b+i;
		d++;
	}
	printf("The sum of all numbers(excluding negative is) is : %d", b);
}


void continuee(){
	int b, i, d=0;
	char a='y';
	printf("Please enter a number\n");
	scanf("%d", &b);
	while(d<8){
		printf("Please enter another number\n");
		scanf("%d", &i);
		if(i<0)
		continue;
		b = b+i;
		d++;
	}
	printf("The sum of all numbers(excluding negative(if any)) is: %d", b);
}

void main(){
printf("\nOUTPUT FOR BREAK\n");
	breake();
printf("\nOUTPUT FOR CONTINUE\n");
	continuee();
}
