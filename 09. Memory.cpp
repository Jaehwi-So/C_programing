#include<stdio.h>
#include<stdlib.h>


	/*메모리 구조
	코드 영역       :  코드가 저장되는 메모리
	데이터 영역     :  프로그렘 시작부터 종료 시까지 남아있음. 전역변수/static변수
	힙 영역         :  
	스택 영역       : 선언된 함수를 빠져나가면 소멸됨. 지역변수/매개변수
	*/

//*******************************1번 함수**************************************88
//힙 영역의 메모리 공간 할당과 해제
int HipMemory(){
	/*
	malloc함수
	##int *ptr = (int*)malloc(sizeof(int))
	1.malloc 함수호출로 할당된 메모리 공간은 직접 free함수의 호출을 통해서 해제하지 않으면 계속 남아있다.
	프로그래머가 관리하는 메모리 공간
	2.malloc함수는 주소값을 반환한다. 따라서 포인터를 이용하여 메모리에 접근해야 한다.
	3.malloc함수의 반환형은 void형이다. 따라서 void형으로 반환되는 주소 값을 적절히 형 변환을 시켜 메모리 공간에 접근한다.
	void *ptr = malloc(sizeof(int))
	==void *ptr = malloc(4)                 : 4바이트가 힙 영역에 저장. 포인터 ptr을 이용하여 해당 주소값에 접근 
	                                          4바이트라는 정보만 있으므로 형은 알 수 없다.

	-> int *ptr = (int*)malloc(sizeof(int)); : int로의 형 변환을 시켜서 할당된 메모리 공간에 접근한다.
	

	##free(ptr) : 힙 영역에 할당된 메모리를 해제시킨다.
	*/
	
	int *ptr1 = (int*)malloc(sizeof(int));        //int형 변수의 주소값은 int형 포인터이므로 형 변환하였다.
	int *ptr2 = (int*)malloc(sizeof(int)*7);      //1차원 배열의 주소값 역시 int형 포인터이다.
	int i;

	*ptr1=20;                                    //힙 영역에 할당된 변수에 접근하여 값을 저장한다.

	for(i=0; i<7; i++){                          //힙 영역에 할당된 배열에 접근하여 값을 저장한다.
		ptr2[i]=i+1;
	}

	printf("%d \n",*ptr1);
	for(i=0; i<7; i++){
		printf("%d ",ptr2[i]);
	}

	if(ptr1==NULL){
		printf("메모리 할당 실패");
	}//ptr1이 가리키는 주소값이 없는 경우 메모리 할당에 실패했음을 알 수 있다.

	free(ptr1);                                 //할당된 힙 영역의 메모리를 해제하고 있다.
	free(ptr2);
	

	/*
	##calloc함수 
	void *ptr = void *calloc(30,sizeof(int)) 
	1. melloc함수와 인자전달의 차이. sizeof(int)크기의 블록 30개를 할당해라.
	2. melloc함수는 메모리 공간 초기화 X, 쓰레기값으로 채워짐, calloc 함수는 메모리 공간의 모든 비트를 0으로 초기화

	##realloc 함수
	int *ptr=(int*)malloc(sizeof(int)*3); -> 길이가 3인 int형 배열 힙 메모리에 할당
	ptr=(int*)realloc(ptr, sizeof(ptr)*5); ->ptr에 할당된 메모리를 길이가 5인 int형 배열의 크기로 확장
	*/

	return 0;

}
//*******************************2번 함수**************************************88
//힙 영역의 메모리 활용
char * ReadUserName(void){                           //char 포인터형으로 반환
	char *name = (char*)malloc(sizeof(char)*30);     //문자열 저장을 위해서 힙 영역에 메모리 공간을 할당한다.
	printf("What's your name? ");
	gets(name);
	return name;

}
int HipUse(){
	char *name1;
	char *name2;

	name2=ReadUserName();
	printf("name2 : %s\n", name2);
	name1=ReadUserName();                           
	printf("name1 : %s\n", name1);
	name2=ReadUserName();
	printf("name2 : %s\n", name2);

	printf("again name1 : %s \n", name1);
	printf("again name2 : %s \n", name2);
	free(name1);
	free(name2);
	return 0;

}
//***********************************메인 함수***********************************************************

int main(){



printf("힙 영역의 메모리 공간 할당과 해제에 대해 보려면 1번을, 활용을 보려면 2번을 눌러주세요 눌러주세요\n");
int num=0;  
scanf("%d",&num);
if(num==1){
	HipMemory();
}
if(num==2){
	HipUse();
}


scanf("%d",&num);
return 0;





}