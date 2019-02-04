#include<stdio.h>
void main(){
int n, m, a, i;
scanf("%d", &m);
for(a=m;a>=1;a=a/10){
n=m;
m=(m/10);
n=n-(m*10);
printf("%d", n);
}
}
