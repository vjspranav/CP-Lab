#include<stdio.h>
void main(){
int m, l, k, j, d=0;
printf("Enter the number of elements in the array: ");
scanf("%d", &m);
m = m-1;
int n[m];
	for(l=0; l<=m; l++){
		printf("Enter a number: ");
		scanf("%d", &n[l]);
	}
printf("Enter the element you want to find in the array: ");
scanf("%d", &j);
	for(k=0;k<=m;k++){
		if(j==n[k]){
			if(d==0){
				printf("[");
				for(l=0; l<=m; l++){
					if(j==n[l])
						printf(" *%d* ", n[l]);
					else
						printf(" %d ", n[l]);
					}
				printf("]\n");
				}
				d++;
				if(d==1)
					printf("Your element is in the array\nand it's position is: %d", k+1);
				else
					printf(", %d", k+1);
		}
	}
printf("\n");
if(d==0)
	printf("The element you've entered is not in the array");
}



