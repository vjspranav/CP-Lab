#include<stdio.h>
void det(){
int det, n, i, j;
int m[3][3];
/* = {
    {2, 2, 4},
    {5, 4, 7},
    {6, 8, 9}
};*/
for(i=0; i<3; i++){
    for(j=0; j<3; j++){
	printf("Please enter the element of the row %d coloumn %d: ", i+1, j+1);
	scanf("%d", &m[i][j]);
    }
}
for(i=0; i<3; i++){
    for(j=0; j<3; j++){
	printf(" %d ", m[i][j]);
    }
    printf("\n");
}


det = (m[0][0]*((m[1][1]*m[2][2])-(m[1][2]*m[2][1])))-(m[0][1]*((m[1][0]*m[2][2])-(m[1][2]*m[2][0])))+(m[0][2]*((m[1][0]*m[2][1])-(m[1][1]*m[2][0])));
printf("Detereminent of entered matrix = %d\n", det);
}

int main(){
det();
}

