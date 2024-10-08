#include <stdio.h>

/* 当fahr= 0， 20 ... 300 时，分别
打印华氏温度与摄氏温度对照表 

使之能在转换表的顶部打印一个标题
*/
int main(){
	float fahr, celsius;
	int lower, upper, step;
	lower = 0; /*温度表的下限*/
	upper = 300;/*温度表的下限*/
	step  = 20;/*步长*/
	fahr = lower;
	printf("fahr celsius\n");
	while(fahr <= upper){
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f  %6.1f\n", fahr, celsius);
		fahr=fahr + step;
	}
	return 0;
}
