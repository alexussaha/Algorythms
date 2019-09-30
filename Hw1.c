//Усов Александр Александрович
#include <stdio.h>
#include <math.h>

//Задание 1
float IBM(float m, float h){
	float i;
	i = m/(h*h);
	return i;
}
//Задание 3
void swap(int* a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
//Задание 4
void solveTheQuad(){
	int a,b,c;
	float x1, x2, d;
	printf("\nax^2+bx+c=0\n");
	printf("a = ");
	scanf("%d",&a);
	printf("\nb = ");
	scanf("%d",&b);
	printf("\nc = ");
	scanf("%d",&c);
	d = b*b - 4*a*c;
	x1 = (-b+sqrt(d))/(2*a);
	x2 = (-b-sqrt(d))/(2*a);
	printf("x1 = %f, x2 = %f \n", x1, x2);
}
//Задание 6
void ageAdapt(){
	int age, v1, v2, i=0;
	 scanf("%d",&age);
	 v1 = age % 10;
     v2 = age % 100;
     if(v1 == 1 && v2 != 11) {
	 printf("%d god\n",age);i++;
	 }
    if(v1 >= 2 && v1 <= 4 && (v2 < 10 || v2 >= 20)) {
	printf("%d goda\n",age);
	i++;
	}
    if(i==0) {printf("%d let\n",age);}
}
//Задание 7
int isOneColor(int x1, int y1, int x2, int y2){
	if(x1 + y1 + x2 + y2 == 0) return 1;
	return 0;
}
//Задание 9
void quotientAndRemainder(){
	int a, b, i = 0;
	printf("\nVvedite delimoe:");
	scanf("%d",&a);
	printf("\nVvedite delitel:");
	scanf("%d",&b);
	while(a-b>=0){
		a -= b;
		i += 1;
	}
	printf("\nchatnoe = %d, ostatok = %d\n", i, a);
}
//Задание 10
int areTheOdd(int x){
	while(x>=0)
	{
		if((x % 10)%2!=0) return 1;
		x/=10;
	}
	return 0;
}
//Задание 14
void automorphicNums(){
	 int N = 1000000,i,d,s; 
int k, p; 
	printf("The programm finds automorphic numbers from 1 to 1000000\n");
	; 
		for(i=1;i<=N;i++){ 
			d=1;
			s=i*i; 
			k=log10(i)+1; 
			for(p=1;p<=k;p++){ 
				d=d*10;        
				} 
			if(s%d==i) {printf("%d - %d\n",i,s);} 
			} 
}


int main(){
	IBM(60, 1.95);
	int a = 5, b = 2;
	swap(&a,&b);
	printf("%d, %d",a,b);
    solveTheQuad();
	ageAdapt();
	printf("%d",isOneColor(2,1,3,2));
	quotientAndRemainder();
	printf("%d", areTheOdd(123));
	automorphicNums();
	return 0;
}