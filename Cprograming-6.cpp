//구조체
#include<stdio.h>
typedef struct rectangle
{            //구조체 정의
	double pos1;            //구조체 멤버
	double pos2; 

}rectangle;             
double area(rectangle dot1, rectangle dot2){

	double length1, length2;
	if(dot1.pos1-dot2.pos1>0){
		length1=(dot1.pos1-dot2.pos1);
	}
	else{
		length1=-(dot1.pos1-dot2.pos1);
	}

	if(dot1.pos2-dot2.pos2>0){
		length2=(dot1.pos2-dot2.pos2);
	}
	else{
		length2=-(dot1.pos2-dot2.pos2);
	}

	return length1*length2;

}



int main(){
	rectangle dot1, dot2;  //구조체 변수 선언
		printf("좌측 상단 점의 좌표 :");
		scanf("%lf %lf",&dot1.pos1,&dot1.pos2);
		printf("우측 하단 점의 좌표 :");
		scanf("%lf %lf",&dot2.pos1,&dot2.pos2);
	
    double rectanglearea=area(dot1, dot2);
	printf("%g", rectanglearea);


	return 0;


}