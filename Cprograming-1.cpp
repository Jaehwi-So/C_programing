#include<stdio.h>
#include<Windows.h>

//**함수, 연산자(산술, 논리, 비트 연산자), 자료형
//****************************************************************************************************************************
//#1번 함수
//1부터 n1까지 합연산 함수(입력값 출력값 존재 함수)
//재귀함수
int function(int n1){

		if(n1==0){
			return 0;
		}
		return n1+function(n1-1);
	
	
}

//****************************************************************************************************************************
//#2번 함수
// 안내문 출력 함수(입력값, 출력값 둘다 존재 X 함수)
void say()
{printf("\n작업을 골라주세요. \n");} 


//****************************************************************************************************************************
//#3번 함수
//별모양 그래프 함수(입력값 존재, 출력값 존재 X 함수)
//for문 이용, continue
void star(int n1, int exept, int how){
	int n4=n1;
	for(n1; n1>0; n1--){
			int n2=n1;
			int n3=n1;
		for(n2; n2>0; n2--){
        printf(" ");
		}
		if(n1%exept==0&&how==100){printf("%d의 배수\n", exept);
		continue;
		}
	    for(n3; n4-n3>=0; n3++){
		printf("*");
		}
		printf("(%d번째 수)\n",n1);
	}
}

//****************************************************************************************************************************
//#4번 함수
//숫자 비교 연산 함수(입력값 존재, 출력값 존재 함수)
//if문(조건문 이용), 반환값을 통해 main 함수에서 switch이용
//2중 조건문(조건문 안의 조건문)
//관계 연산자, 논리 연산자
//선위 증가, 후위 감소
int comp(int n1, int res){
	int nu1=0;
	printf("모든 비교를 원하시면 2를, 판별만을 원하시면 아무 숫자를 눌러주세요 : ");
	scanf("%d", &nu1);

	if(nu1==2){
		int zeroorone;
		if(n1>res){printf("비교값보다 작습니다\n");}            //관계 연산자            다르다 !=  같다== 대소관계< > <= >=
		if(n1>=res){printf("비교값보다 작거나 같습니다\n");}
		if(n1<res){printf("비교값보다 큽니다\n");}
		if(n1<=res){printf("비교값보다 크거나 같습니다\n");}
		if(n1==res){printf("비교값과 같습니다\n");}
		if(n1!=res){printf("비교값과 다릅니다\n");}           
		if(n1%2==0&&res%2==0){printf("둘 다 짝수입니다\n");}            //논리 연산자         AND &&       OR ||        NOT !
		if(n1%2==0||res%2==0){printf("둘 중 하나가 짝수입니다.\n");}
		zeroorone=((n1%2==0)&&(res%2==0));
		printf("%d=참이면 둘 다 짝수이거나 0입니다. \n",zeroorone);
		zeroorone=((n1%2==0)||(res%2==0));
		printf("%d=참이면 둘 중 하나가 짝수이거나 0입니다. \n",zeroorone);
		zeroorone=!res;
		printf("%d=참이면 당신의 숫자는 0입니다. \n",zeroorone);                  
		printf("원래 숫자 : %d\n", res);                           //선위 증가, 후위 감소 연산
		printf("후위 증가 res++ : %d\n", res++);
		printf("다음 문장 결과 : %d\n", res);
		printf("선위 감소 --res : %d\n", --res);
		printf("다음 문장 결과 : %d\n", res);
		return 3;
	}

	else{	
	if(n1>res){
		return 0;
	}
	else if(n1<res){
		return 1;
	}
	else{
		return 2;
	}

	}
}
//****************************************************************************************************************************
//#5번 함수
//2중 반복문을 이용한 10진법을 2진법으로 바꾸기
//비트 연산자
//자료형, 서식문자, 아스키코드, 문자열(포인터X)
void analyze(int num5){
	printf("%d를 2진수로 변환 : ",num5);                         //2진수 변환 반복문
    int ress=num5;
	int less=0;
	int wess=0;
	int zin2=0;
	int zin3=0;
	for(zin2=32; zin2>0; zin2--){
	int zin4=1;
	int zin5=1;
		for(zin3=zin2; zin3>1; zin3--){
			zin5=zin4*2;
			zin4=zin5;
		}
		
		
		wess=ress/zin5;
		printf("%d",wess);
		less=ress%zin5;
		ress=less;                                                                        //2진수 변환 반복문

	}
	printf("\n(음수로 전환하는 법은 음의 보수를 취하고 +1, 맨 처음 메모리는 부호를 결정하는 MSB)\n");  //비트 연산자
	int bit=0;
	int bit2=7;
	bit = num5 & bit2;
	printf("7의 2진수 표기는 00000111\n");                                                        //비트 연산자 암기
	printf("비트 연산자 AND (7 & %d) 의 결과는 %d\n", num5, bit);                                 // A&B  둘다 1이면 1로 반환                   
	bit = num5 | bit2;
	printf("비트 연산자 OR (7 | %d) 의 결과는 %d\n", num5, bit);                                  // A|B  둘중 하나가 1이면 1로 반환                                                        
	bit = num5 ^ bit2;
	printf("비트 연산자 XOR (7 ^ %d) 의 결과는 %d\n", num5, bit);                                 // A^B  서로 다를 때 1로 반환
	bit = ~num5;
	printf("비트 연산자 NOT (~%d) 의 결과는 %d\n", num5, bit);                                    // ~A   반전
	bit = num5;                                                                                 // 결과만 반환, A의 값은 변화 없음
	printf("비트 연산자 (>>%d) 의 결과는 %d\n", num5, bit>>2);                                   // A<<2 비트를 2칸 왼쪽으로 이동
	bit = num5;                                                                                 // 결과만 반환, A의 값은 변화 없음
	printf("비트 연산자 (<<%d) 의 결과는 %d\n", num5, bit<<2);

	printf("현재 숫자 자료형(int)의 크기 : %d \n", sizeof(num5));          //자료형        sizeof(A) : A의 자료형의 크기를 정수로 표현
	double num10 = 3.14;                                                 //정수 자료형 char(1) short(2) int(4) long(4) long long(8) 
	                                                                     //실수 자료형 float(4) double(8) long double(8+)
	printf ("%d(int) + %f(double)의 연산 결과(printf서식문자 %%d) : %d \n", num5, num10, num5+num10);  
	
	printf ("%d(int) + %f(double)의 연산 결과(printf서식문자 %%f) : %f \n", num5, num10, num5+num10);

	printf("16진수 정수로 출력 : %X \n", num5);             //*****서식 문자(printf)*******         ********서식 문자(scanf)******
	printf("8진수 정수로 출력 : %o \n", num5);              //%d(int, char, short) %ld(long)                %d(10진수)
	                                                       //%lld(long long) (10진수)            
	char word = '1';                                      //%o(8진수)  %X, %x(16진수)                  %o(8진수), %x(16진수)
	char word2 = 66;
	printf("아스키 코드 : %d \n", word);                  //%f(float,double) %Lf(long double)       %f,%e,%g(float) %lf(double)
	printf("값에 대응하는 문자 : %c \n", word2);          //%c(값에 대응하는 문자(char,short,int)          %Lf(long double)
	                                                     //%s(문자열)                                       %s(문자열)
	                                                                       
	
}

//****************************************************************************************************************************
//#메인함수
//함수 호출
int main(){
	int num=3;
	int result=0;
	int define=0;
	int compare=0;
	int point=0;
	printf("정수를 입력하세요(0~10 입력 권장) : ");             //printf
	scanf("%d",&num);                          //scanf
	result=function(num);                      //#1 숫자들의 합 구하는 함수 호출
	printf("1부터 %d까지의 합은 %d",num,result);//숫자들의 합 구하는 함수 출력
	say();                                     //#2 안내문 함수 호출
	printf("**********************************************************************\n");
	printf("숫자의 크기비교 : 0 \n별모양 그래프: 1 \n숫자 분석 :2 \n종료 : 나머지 숫자\n");//결정
	scanf("%d",&define);
	printf("**********************************************************************\n");
	//****************************************************************************************************************************
	//그래프 보이기
	if(define==1){
	printf("제외할 배수의 줄이 있다면 1번을, 아니라면 나머지 숫자를 눌러주세요 : ");
	scanf("%d",&compare);
	int point=compare==1?100:200;             //삼항 연산자 : 변수 compare의 값이 1이 참이면 point라는 변수에 100, 거짓이면 200으로 초기화
	if(point==100){printf("몇의 배수를 제외할건가요? : ");//if 조건문 이용
	scanf("%d", &compare);
	}
	else{}
	printf("별모양 그래프입니다 \n");
	star(result, compare, point);              //#3
	return 0;}
	//****************************************************************************************************************************
	//숫자 판별
	else if(define==0)
	{printf("비교할 숫자를 입력하세요 : ");
	scanf("%d", &compare);
	comp(compare, result);                    //#4
	switch(comp(compare, result)){            //switch문 : switch(n)에서 n의 값이 case x : 에서 x와 일치할 때 실행, 일종의 조건문
	case 0:
		printf("대상값보다 작습니다");
		break;                                //break : 조건 만족시 반복문 탈출
	case 1:
		printf("대상값보다 큽니다");
		break;
	case 2:
		printf("대상값과 같습니다");
		break;
	case 3 :
		printf("숫자의 모든 비교 분석을 했습니다.");
		break;
	return 0;
	}
	}

	//****************************************************************************************************************************
	//숫자 분석
	else if(define==2){
		printf("숫자 분석을 시작합니다\n");
		analyze(result);                     //#5
	}

	//****************************************************************************************************************************
	//종료
	
	else
	{printf("종료하셨습니다");
	return 0;}//나머지 버튼. 종료

}





