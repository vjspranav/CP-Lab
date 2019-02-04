#include<stdio.h>
void main(){
	int m=0, n=1, o, d;
	printf("Please enter the number of terms of The fibbonacci series you want to be printed\nEnter here: ");
    scanf("%d", &o);
    printf("%d  %d  ", m, n);
	for(d=0; d<o-2; d++){
	n = n + m;
	m = n - m;
	printf("%d  ", n);
	}
}
