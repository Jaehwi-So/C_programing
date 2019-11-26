#include<stdio.h>
//함수 포인터
void Function1(int n1, int n2){

	printf("%d + %d = %d \n", n1,n2,n1+n2);

}
void Function2(char *str){

	printf("%s \n", str);


}
int main(){
	int num1=10; 
	int num2=20;
	char *str="Jaehwi So";      //str포인터 선언, str 주소값 내에 문자열 할당
	Function1(num1,num2);

	void (*Pfunc)(int, int);    //함수 포인터 Pfunc의 선언
	//함수의 자료형(*(포인터 이름))(매개변수의 자료형)
	Pfunc=Function1; //함수의 이름은 주소값을 의미한다.
	Pfunc(num1,num2); //Pfunc와 Function에는 동일한 값이 저장된다. 변수냐 상수냐가 둘의 차이 Pfunc을 Function1처럼 사용할 수 있다.


	Function2(str); //포인터 변수 str에는 문자열의 첫글자인 H의 주소값이 저장되며 str이 가리키는 대상은 Hello World.
	//문자열이 메모리 공간에 저장->메모리의 주소값 반환 //printf함수는 문자열의 주소값을 전달받는 함수이다.
	void (*Pfunc2)(char*)=Function2;   //함수 포인터 Pfunc2의 선언. 매개변수는 포인터이므로 char*
	Pfunc2(str);
	

	//함수 포인터는 왜 쓰는지는 학자들의 의견이 분분하다고 하다.

	//*****************************************************************

	int num3=10;
	void *ptr;     //void형 포인터 변수의 선언, void형 포인터에는 어떠한 변수의 주소값이든 담을 수 있다.
	ptr=&num3;
	printf("%p \n", ptr);
	ptr=Function1;
	printf("%p \n", ptr);


	return 0;





}