#include<stdio.h>

void main(){
	int a, b, c, n;
	printf("Number of rows you want: ");
	scanf("%d", &n);
	n=n*2;
	for (a=1; a<=n; a = a+2){
		for(c=(n-a)/2;c>=1;c--){
			printf(" ");
		}
		for(b=1; b<=a; b++){
		printf("*");
	    }
	printf("\n");
	}
}
