#include<stdio.h>

void main(){
	int m, l, k, j;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &m);
	m=m-1;
	int n[m];
	for(l=0; l<=m; l++){
		printf("Enter a number: ");
		scanf("%d", &n[l]);
	}
	for(l=0; l<=m; l++){
	printf("\nYour element %d is: %d", l+1, n[l]);
	printf("\nThe index of your element is: %d", l);
	printf("\nmemory address of your element is: %d\n", &n[l]);
	}
}



