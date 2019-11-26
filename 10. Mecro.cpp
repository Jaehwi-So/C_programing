//매크로
#include<stdio.h>
#include<stdlib.h>
//*****************************매크로 정의*************************************
/*
1.선행 처리 전(main 함수 컴파일 전)에 행해진다.
2.자료형을 별도로 정의하지 않아도 된다.
*/

//1번함수 매크로
#define NAME "홍길동"
#define PRIN_ADRESS   puts("경기도 용인시 삽니다\n");
#define PRINT_MODE    printf("안녕하세요\n");
#define SQUARE(X) X*X           //매크로의 인자전달
#define MSQUARE(X) ((X)*(X))

#define PI = 3.14
#define PRODUCT(X,Y)    ((X)*(Y))
#define CIRCLE_AREA(R)  (PRODUCT(R,R)*3.14)

//2번함수 매크로
#define TrueM 0
#define EACH_NUM 24


//매개변수의 치환
#define STRING_JOB(A,B)    "내 이름은 "#A","#B" 이죠"
#define STNUM(Y,S,P) Y##S##P


//*******************************1번 함수**************************************
//선행처리 매크로 + 부록 매개변수의 치환
int UseMecro(){
	PRINT_MODE;                      
	printf("저는 %s입니다\n", NAME);    
	PRIN_ADRESS;               
	//#define SQUARE(X) (X*X)
	printf("%d\n",SQUARE(5));           //SQUARE  5x5=25
	printf("%d\n",SQUARE(5+3));         //SQUARE  5+3x5+3=19로 출력. 따라서 괄호를 잘 넣어주자.
	printf("%d\n",SQUARE((5+3)));       //SQUARE  (5+3)x(5+3)=64로 출력
	printf("%d\n",120/SQUARE(2));       //SQUARE  120/2*2=120 나눗셈이 먼저 진행되기 때문. 괄호 중요

	//#define SQUARE(X) ((X)*(X))        //모범 선행 처리 매크로 선언
	printf("%d\n",(120/(MSQUARE(2))));    //모범 인자 전달
	//매크로의 몸체부분을 구성하는 X와 같은 전달인자 하나하나에 괄호를 치고, 전체를 한번 더 괄호로 묶어주는 습관 들이기.
	
	//#define CIRCLE_AREA(R)  (PRODUCT(R,R)*3.14)
	printf("%g \n",CIRCLE_AREA(3));      //매크로 안의 매크로 호출


	//**부록** 매개변수 치환. 시험확률 낮음
    //#연산자 : 치환 연산자.
	//#define STRING_JOB(A,B)    "내 이름은 "#A","#B" 이죠"
    //#define STNUM(Y,S,P) Y##S##P                   //## : 결합 연산자
	printf("%s \n", STRING_JOB(코난, 탐정));
	printf("%s \n", STNUM(123, 456, 789));  


	return 0;
}
//*******************************1번 함수**************************************
//조건부 컴파일을 위한 매크로
//매크로의 조건검사.    #if와 #endif는 세트.
int IfMecro(){
	int num1=20;
	int num2=10;

//#define TrueM 0
#if TrueM     //TrueM이 0이 아니면 참이다.
	printf("ADD는 참\n");
#endif

#ifdef TrueM  //매크로 TrueM이 정의되어있다면
	printf("TrueM매크로는 정의되어있다.\n");
#endif

#ifndef FalseM  //매크로 FalseM이 정의되어 있지 않다면
	printf("FalseM매크로는 정의되어 있지않다.\n");
#endif

#if EACH_NUM<20
	printf("현재 매크로 상수는 20보다 작다");
#elif EACH_NUM>80
	printf("현재 매크로 상수는 80보다 크다");
#else 
	printf("현재 매크로 상수는 20<= EACH_NUM <=80 이다.");
#endif



	return 0;
}

//***********************************메인 함수***********************************************************

int main(){



printf("선행처리기 매크로에 대해 보려면 1번을, 조건부 컴파일에 대해 보려면 2번을 눌러주세요.\n");
int num=0;  
scanf("%d",&num);
if(num==1){
	UseMecro();
}
if(num==2){
	IfMecro();
}


scanf("%d",&num);
return 0;

}