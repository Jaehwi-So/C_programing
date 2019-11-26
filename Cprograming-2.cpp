#include<stdio.h>
//배열과 포인터
//**************************************************************************************************************************
//1번 함수
//배열의 선언과 초기화, 그리고 표현방법
void basic(void){
int arr[4]; //1번배열. 배열의 선언 (자료형 배열의 이름[배열의 크기];)

arr[0]=10; arr[1]=20; arr[2]=30; arr[3]=40;//배열의 변수 초기화
double arr2[]={100,200,300,400};//2번배열. 배열의 선언+초기화(이 때 배열의 크기 생략 가능)
double arr3[4]={3.14,3.15}; //3번배열. 모든 배열의 요소를 채워넣지 않아도 자동으로 0으로 초기화된다. 
//C언어에서는 배열의 크기를 설정 할 때 변수를 이용할 수 없다.


int arrnum1, arrnum2, arrnum3;
for(arrnum1=0;arrnum1<4;arrnum1++){   //배열의 요소는 반복문을 통해서 주로 표현한다.
	printf("%d ",arr[arrnum1]);
}
printf("\n");
for(arrnum2=0;arrnum2<4;arrnum2++){
	printf("%f ",arr2[arrnum2]);
}
printf("\n");
for(arrnum3=0;arrnum3<4;arrnum3++){
	printf("%f ",arr3[arrnum3]);
}
printf("\n");
printf("첫번째 배열의 크기는 %d \n",sizeof(arr));    //int형 배열의 크기
printf("두번째 배열의 크기는 %d",sizeof(arr2));      //double형 배열의 크기
}


//**************************************************************************************************************************
//2번 함수
//문자열의 표현
void sentence(void){

	//************************배열을 이용한 문자열의 표현****************************************

	int arrnum,arrnum2;
	char arr[]={'S','M','U'};     //문자열이 아니다. 문자 배열이다.
	char arr2[]={'S','M','U','\0'};//뒤에 널(\0)이 있으므로 문자열이다.                      문자열의 끝에는 항상 null이 삽입되어 있다.
	printf("문자 배열 %s \n", arr);          //문자열의 끝을 모르므로 요상하게 출력된다.                문자열의 길이+1(null)=배열의 길이
	printf("문자열 %s \n", arr2);         //문자열 출력

	printf("문자 배열 요소 출력 ");
	for(arrnum=0;arrnum<4;arrnum++){    //문자 배열의 요소 출력, 마지막 칸이 ?이다.           %s : 문자열
	printf("%c ",arr[arrnum]);                                                    //       %c : 값에 해당하는 단일 문자                                              
}
	printf("\n문자열 요소 출력 ");
	for(arrnum2=0;arrnum2<4;arrnum2++){ //문자열의 요소 출력, 마지막 칸이 null이다.
	printf("%c ",arr2[arrnum2]);
}
    arr[3]=0;                           //문자 배열의 종지부를 찍어주는 null 입력, null "문자 \0"의 아스키 코드값은 0이므로 동일한 표현         
	printf("\nnull을 첨가한 문자 배열 %s \n", arr);  


	char arr3[50];                  //scanf를 이용한 문자열을 입력받아 출력
	printf("\n문자열 입력 : ");  
	scanf("%s",arr3);               //주의사항 : scanf에서 배열에는 &를 사용하지 않는다.
	printf("문자열 출력 : %s \n", arr3);  //scanf를 이용하여 문자열을 입력받는 데에는 한계가 있다. 
                                      //scanf의 데이터 구분 기준은 공백이다. 따라서 띄어쓰기를 한 문자열은 각각 개별의 문자열로 인식한다.

	char arr4[]="University Studant";
	for(arrnum2=0;arrnum2<19;arrnum2++){ //변수 형태의 문자열 선언. (배열을 기반으로 하는 문자열의 선언)
	printf("%c",arr4[arrnum2]);
    }
	printf("\n");
    printf("%s \n",arr4); //문자열의 출력
	printf("%c ",*(arr4));
	printf("%c \n",*(arr4+1));


	//************************포인터를 이용한 문자열의 표현****************************************
	char *ptr = "Computer Game";         //상수 형태의 문자열 선언. (포인터를 기반으로 하는 문자열의 선언)
	                                     //포인터 변수 ptr에는 문자열의 첫글자인 'C'의 주소값이 저장된다.
	printf("ptr : %s\n", ptr);           //문자열의 내용 변경이 불가능하다.
	printf("*ptr : %c\n", *ptr);
	printf("ptr[2] : %c", ptr[2]);       //printf함수는 문자열의 주소값을 전달받는 함수이다.
	

	


}
//**************************************************************************************************************************
//3번 함수
//포인터
void pointer(void){
	int num=10;
	int *pnum; //변수와 주소를 할당받을 포인터 변수의 자료형은 동일한 것이 바람직하다.
	pnum=&num; // &은 변수 num의 주소값을 반환한다. 포인터는 주소값을 할당 받아야 하므로 상수가 아닌 &변수로 초기화 한다.
	*pnum=20;  // *은 포인터가 가리키는 메모리 공간에 접근한다. == 포인터 변수가 가리키는 메모리 공간인 변수에 20을 저장해라.

	/*암기 : &는 주소값 반환. *은 값(포인터가 가리키는 메모리 공간에 있는 값)을 반환한다. pnum=포인터(주소) *pnum=포인터가 가리키는 주소에 할당된 값(변수)
	포인터 변수는 초기화 시켜야 한다. pnum을 초기화
	포인터의 자료형(double *pnum) : 8바이트로 읽어 들여서 이를 실수로 해석한다.
	변수와 포인터의 자료형이 일치하지 않는다면 오류 발생. 예를 들어 설명하면
	double형태의 변수를 int형의 포인터에 저장하게 되면 포인터는 변수를 4바이트로 읽어 들여서 정수로 해석한다.*/

	printf("num=%d\n", num);
	printf("&num=%d\n", &num);  //num의 주소값
	printf("pnum=%d\n", pnum);  //포인터 변수 pnum에 저장된 num의 주소값
	printf("&pnum=%d\n", &pnum); //포인터 변수 pnum의 주소값
	printf("*pnum=%d\n", *pnum); //포인터 변수 pnum에 저장된 num의 주소값 추적. *pnum==num


	int *pnum2=&num;             // int *(pnum=&num) 포인터에 주소값을 할당. *pnum에 할당하는 것이 아니다.
	printf("*pnum2=%d\n",*pnum2);

	//만약 포인터 변수를 먼저 선언해 두고 나중에 유효한 주소값을 채워 넣을 때에는
	//NULL로 초기화 해둔다. 이를 NULL 포인터라고 한다.

	int *pnum3;
	pnum3=NULL;   // pnum3=0;과 동일한 표현. NULL포인터이다. 아무곳도 가리키지 않는다!
	int num3=0;
	printf("********************************\n");
	printf("%d\n",pnum3);
	printf("pnum3은 현재 NULL 포인터입니다. 이에 할당할 값을 입력해주세요");
	scanf("%d",&num3);
	pnum3=&num3;
	printf("%d\n",*pnum3);


	






}
//**************************************************************************************************************************
//4번 함수
//2차원 배열
void study(void){                             //     열     열     열     열     열       
int Arr[5][5];                                //행 [0][0] [0][1] [0][2] [0][3] [0][4]
int i, j;                                     //행 [1][0]
                                              //행 [2][0]
for(i=0; i<5; i++){                           //행 [3][0]
	for(j=0; j<5; j++){                       //행 [4][0]
		if(i>=j){
			Arr[i][j]=i+1;                    //2차원 배열은 자료형 배열이름[][]
		}                                     //int Arr[3][3]={{1,2,3},{4,5,6}}
		else{
			Arr[i][j]=0;
		}
	}
}
for(i=0; i<5; i++){
	for(j=0; j<5; j++){
		printf("%d ",Arr[i][j]);
	}
	printf("\n");
}
printf("\n");
int Arr2[2][2]={{1,2},{3,4}};
for(i=0; i<2; i++){
	for(j=0; j<2; j++){
		printf("%d ",Arr2[i][j]);
	}
	printf("\n");
}
}
//**************************************************************************************************************************
//5번 함수
//배열과 포인터의 관계
void pointerandarray(){
	int arr[]={1,2,3};
	printf("배열의 이름 : %p \n", arr); //배열의 이름은 배열의 시작 주소 값을 의미한다. "상수 형태의 포인터" 즉 주소값의 변경을 할 수 없다.
	printf("배열의 첫번째 요소 : %p \n", &arr[0]);
	printf("배열의 두번째 요소 : %p \n", &arr[1]);
	printf("배열의 세번째 요소 : %p \n", &arr[2]);
	//int형 배열요소간 주소값의 차이는 4바이트라는 것을 알 수 있다.
	printf("*arr : %d\n", *arr);
	*arr+=100;
	printf("증가연산후 *arr : %d\n", *arr);

	//***포인터 변수는 배열의 이름처럼 활용 가능하다!***
	int arr2[]={10,20,30};
	int *pointer=&arr2[0]; //== int *pointer=arr2
	printf("%d %d\n", arr2[0], pointer[0]);     //배열처럼 포인터 변수에도 []사용가능. *안붙여도 할당값 나옴
	printf("%d %d\n", arr2[1], pointer[1]);     
	printf("%d %d\n", arr2[2], pointer[2]);    
	printf("%d %d\n", *arr2, *pointer);         //배열의 첫번째 요소.

	//***포인터 변수의 연산***
	int num=20;
	int *pnum=&num;
	printf("pnum=%d \n",pnum);
	printf("++pnum=%d \n",++pnum); //포인터의 연산특성 : int 타입이므로 4가 증가한다. n*sizeof(자료형)만큼 증가.
 
	int arr3[]={11,22,33,44,55};
    int *ptr=arr3;
	printf("*ptr *ptr+1 *(ptr+1) arr3[1] *(arr3+1) : %d %d %d %d %d \n",*ptr, *ptr+1, *(ptr+1), arr3[1], *(arr3+1)); 
	//arr[i]=*(arr+i)


}
//**************************************************************************************************************************
//6번 함수, 외부 함수
int ptfunction(int *zip){   //==int ptfunction(int zip[])

	printf("%d ", zip[0]); //배열의 포인터 할당값을 전달받았다.
	printf("%d ", zip[1]);
	printf("%d ", zip[2]);
	printf("%d ", zip[3]);
	return 0;


}
//****************************************
//6번 함수
//포인터 배열 : 포인터 변수로 이뤄진 배열
void pointerarray(){
int num1=1; int num2=2; int num3=3; int num4=4;
int *arr1[]={&num1,&num2,&num3,&num4}; //포인터 배열의 선언. 배열에는 주소값을 할당받음
printf("포인터 배열 %d %d %d %d \n", *arr1[0],arr1[1],*arr1[2],arr1[3]); //*arr[]는 주소에 할당된 값, arr[]은 주소값이 나온다.

//****문자열을 저장하는 포인터 배열****
char *strArr[3]={"Simple","String","Array"};
printf("문자열 배열 %s %s %s \n", strArr[0], strArr[1], strArr[2]); //큰따옴표에 묶여서 표현되는 문자열은 
//그 형태에 관계없이 메모리 공간에 저장되고, 주소값이 반환된다. 즉 문자열 저장 이후 다음과 같은 형태가 된다.
//char *strArr[3]={0x1004, 0x1048, 0x2012};
//즉, 문자열 자체가 주소값으로 저장되므로 *strArr[0]이 아닌 strArr[0]의 형태로 써야 문자열이 출력된다.




//******함수로 배열의 인자 전달하기******
int arrayay[4]={1,2,3,4};
printf("배열의 시작 주소값 %d \n", arrayay); //배열의 이름은 배열의 시작 주소값을 의미한다.
ptfunction(arrayay); //배열의 주소값을 다른 함수로 전달한다. //==ptfunction(&arrayay[0]);
int *arrptr=arrayay; 
ptfunction(arrptr); //포인터의 주소값을 다른 함수로 전달한다.
}


//**************************************************************************************************************************
//7번 함수
//Call by Value Vs Call by Reference

//****Call by Value 호출함수 *****
void CallbyV(int num1, int num2){
	int num3=num1;
	num1=num2;
	num2=num3;
	printf("%d %d \n",num1,num2);
}
//****Call by Reference 호출함수 *****
void CallbyR(int *num3, int *num4){          //num3과 num4의 메모리 공간에 접근하여 값을 변경하였다.
	int num5=*num3;
	*num3=*num4;
	*num4=num5;
	printf("%d %d \n",*num3,*num4);
}
//********************Call by Value**************************
void CbV(){
	int num1=10;
	int num2=20;
	printf("Call by Value\n");
	printf("%d %d \n",num1,num2);
	CallbyV(num1,num2);
	printf("%d %d \n",num1,num2);

	//값을 전달하는 Call by Value에서는 호출한 함수 안에서의 매개변수들만을 변경할 뿐, main함수의 변수에는 영향을 미치지 않음을
	//알 수 있다. (지역변수 특성)


//*******************Call by Reference*************************
	int num3=10;
	int num4=20;
	int *ptr1=&num3;
	int *ptr2=&num4;
	printf("Call by Reference\n");
	printf("%d %d \n",num3,num4);
	printf("%d %d \n",&num3,&num4);
	CallbyR(&num3,&num4);        //주소값 전달
	printf("%d %d \n",num3,num4);
	printf("%d %d \n",&num3,&num4);
	CallbyR(ptr1,ptr2);          //포인터(주소값) 전달
	printf("%d %d \n",num3,num4);
	printf("%d %d \n",&num3,&num4);


	//주소값을 전달하는 Call by Reference에서는 주소값(전역변수 특성)에 할당된 값의 Swap이 이루어졌으므로 호출한 함수 안에서의 주소값 변경은 곧 
	//main 함수 안에서의 주소값 변경으로 이어진다.
	//변수의 주소값을 인자로 받아서 해당 변수에 직접 접근한다.

	/*****Scanf에 &를 붙이는 이유********
	scanf("%d", &num);
	&를 붙여 해당 변수의 주소값을 전달하여 변수 num에 값을 채워넣어야 하므로 &를 붙인다.
	문자열의 경우
	scanf("%s", str);로 쓰는데 배열은 배열이름 그 자체가 주소값을 의미하기 때문이다.



	*/
}

//**************************************************************************************************************************
//8번 함수(실험)
void science(){
	char array[]="university studant";
	printf("%s \n",array);
	printf("%c \n",*(array+9));
	printf("%c \n",*(array+10));
	printf("%c \n",*(array+11));

	char *array2[2][2]={"university","studant","so","jaehwi"};
	printf("%s, %s, %s, %s, \n",array2[0][0],array2[0][1],array2[1][0],array2[1][1]);






}

//**************************************************************************************************************************
//메인 함수


int main(){

	int number=0;
	printf("배열의 선언과 초기화, 표현방법을 보시려면 1번을, 문자열에 대해 알아보려면 2번을, \n포인터에 대해 알아보려면 3번을, 2차원 배열을 보려면 4번을, 포인터와 배열의 관계를 보려면 5번을, 포인터 배열에 대해 보려면 6번을, \nCall by Value VS Call by Reference를 보려면 7번을, 실험은 8번을 눌러주세요 \n");
	scanf("%d",&number);
	if(number==1){
		basic();
	}
	else if(number==2){
		sentence();
	}
	else if(number==3){
		pointer();
	}
	else if(number==4){
		study();
	}
	else if(number==5){
		pointerandarray();
	}
	else if(number==6){
		pointerarray();
	}
	else if(number==7){
		CbV();
	}
	else if(number==8){
		science();
	}
	return 0;



	
}
