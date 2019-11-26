#include<stdio.h>
//배열과 포인터 심화
//*************************************************************
//1번 함수
//이차원 배열           
void twomultiarray(){                                                 
	int array1[2][3]={1,2,3,4,5,6}; //다차원 배열의 선언/초기화 [행][열]     
	int array2[2][2]={{1,2},{3,4}};   //다차원 배열의 선언/초기화, 비게 되는 공간은 0으로 초기화된다.     
	int array3[][4]={1,2,3,4,5,6,7,8};  //2차원 배열에서 행(세로)는 생략이 가능하다.(열(가로)를 알려주었다는 가정 하에)

	printf("\narray[2][3]의 출력과 해당 주소값 출력\n");
	int i=0;
	int j=0;
	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			printf("%d(%p)",array1[i][j],&array1[i][j]    );  //int형 배열이므로 주소값들의 차이는 4바이트가 나게 된다. 


		}
		printf("\n");
     }
	for(i=0; i<6; i++){
		printf("%d  ", array1[i]);
	}
	

}
//*************************************************************
//2번 함수
//삼차원 배열
void threemultiarray(){

	int array1[3][3][2]={{{50,70},{49,48},{72,36}},{{30,40},{29,46},{78,96}},{{54,49},{79,16},{58,76}}}; //삼차원 배열의 선언
	int i,j,k;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
				printf("%d반 %d번 학생 : 국어%d 영어%d    ",i+1,j+1,array1[i][j][0],array1[i][j][1]);
			
		}
		printf("\n");

	}
}
//3차원 배열은 여러개의 2차원 배열이 모여있는 형태로 이해하는 것이 좋다. 


//*************************************************************
//3번 함수
//다중 포인터
void doublepointer(){
	double num=3.14;
	double *ptr=&num;   //포인터 변수 ptr의 선언
	double **dptr=&ptr;  //더블 포인터 변수 dptr의 선언
	printf("ptr : %p \n", ptr);
	printf("*dptr : %p \n", *dptr);    //ptr==*dptr

	printf("*ptr = %f \n", *ptr);
	printf("**dptr : %f \n", **dptr);   //*ptr==**dptr

	double *ptr2=*dptr;
	*ptr2=10.99;
	printf("*ptr : %f \n", *ptr);
	printf("*ptr2 : %f \n", *ptr2);   
	printf("**dptr : %f \n", **dptr);     // dptr ㅡ ptr ㅡ num
	                                      //         ptr2 /

	double ***ddptr=&dptr;     //3중 포인터 변수 ddptr의 선언
	printf("&ddptr %p \n",ddptr);
	printf("&dptr ddptr %p %p\n",&dptr, ddptr);
	printf("***ddptr %f \n",***ddptr );
	printf("&ptr dptr %p %p\n",&ptr, dptr);
	printf("**dptr %f \n",**dptr);
	printf("&num ptr %p %p\n",&num, ptr);
	printf("*ptr %f \n",*ptr);
	//***ddptr==**dptr==*ptr=num

}
//*************************************************************
//4번 함수
//포인터의 포인터를 이용한 Call by Reference
void Swap(int *n1,int *n2){
	int num3=0;
	num3=*n1;
	*n1=*n2;
	*n2=num3;
}
void Swap2(int **n3, int **n4){
	int num5=0;
	num5=**n3;
	**n3=**n4;
	**n4=num5;

}
void doublecallbyreference(){
int num1=10;
int num2=20;
int *pnum=&num1;
int *pnum2=&num2;
printf("%d %d \n",num1,num2);
Swap(pnum,pnum2);
printf("%d %d \n",num1,num2);

int num3=30;
int num4=40;
int *pnum3=&num3;
int *pnum4=&num4;
printf("%d %d \n",*pnum3,*pnum4);
Swap2(&pnum3,&pnum4);     //포인터 변수 pnum의 주소값 전달
printf("%d %d \n",*pnum3,*pnum4);
printf("%d %d \n",pnum3,&pnum3);  //pnum3은 num3의 주소값을 의미, &pnum3은 포인터 변수 pnum3의 주소값을 의미
}

/*Call by Reference에서 두 함수의 차이점
1번째 함수는 pnum1이 num1의 주소값을 저장하고 pnum2가 num2의 주소값을 저장하는데 해당 주소값의 메모리상에 저장된 값을 swap한 것이다.(num1과 num2를 swap)
즉 n1과 n2에 저장된 값은 바뀌지만 pnum1과 pnum2와는 별개의 변수이므로 여전히 pnum1은 num1의 주소값을 저장, pnum2는 num2의 주소값을 저장한다.

2번째 함수는 pnum3과 pnum4의 주소값 자체를 swap하였다. 포인터의 주소값을 전달하여 pnum3과 pnum4의 주소값을 swap하였다.
즉 n3과 n4에 저장된 값이 바뀌면 pnum3과 pnum4의 swap도 이루어지게 된다.

*/
//*************************************************************
//5번 함수
//포인터 배열
void pointerarray(){
	int num1=10, num2=20, num3=30;
	int *pnum1=&num1;
	int *pnum2=&num2;
	int *pnum3=&num3;
	int *arr[]={pnum1,pnum2,pnum3};//포인터 배열의 선언, arr은 포인터를 담는 더블 포인터형
	printf("%d %d %d \n",pnum1,pnum2,pnum3);
	printf("%p %p %p \n",pnum1,pnum2,pnum3);  //포인터 변수로 이루어진 포인터 배열의 주소값
	printf("%d %d %d \n",*pnum1,*pnum2,*pnum3);
	printf("%d %d %d \n",*arr[0],*arr[1],*arr[2]);
	printf("%d %d %d \n",arr[0],arr[1],arr[2]);
    printf("%d %d \n",arr, &arr[0]);
	
	int **dptr=arr;     //배열의 이름은 포인터이다. 포인터 배열이었으므로 더블 포인터형이므로 형이 일치한다.
	printf("%d %d %d \n",*dptr[0],*dptr[1],*dptr[2]); 
	//포인터 변수도 배열의 이름처럼 사용이 가능하다. =*dptr[0]=*arr[0]
	printf("%d \n",sizeof(dptr));
	// int *ptr=arr[]   (==*ptr=arr[0])
	//ptr[0]=arr[0]
	//int *arr2[];               **                *                       0
	//int **ptr2=arr2[]         ptr2              ptr[0]                  *ptr[0]
	//*ptr2[0]=*arr2[0]         arr2            - arr2[0] -               *arr2[0]
	//                          배열의 이름  배열의 요소인 포인터   배열의 요소인 포인터가 가리키는 메모리
	//배열 포인터와 포인터 배열의 혼동 주의

	double num10=3.14;
	double *ptr5=&num10;
	printf("%d %d", sizeof(&num10), sizeof(ptr5));
}
/*******************************다중 포인터의 의의*************************

포인터는 함수 내에서 함수 외부에 선언된 변수에 접근하는 방법을 제시해준다.

*/
//*************************************************************
//6번 함수
//다차원 배열과 포인터의 관계
void relation(){
	int array[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	printf("%d \n", array);
	printf("%d \n", array[0]);
	printf("%d \n\n", &array[0][0]);
	printf("%d \n", array[1]);
	printf("%d \n\n", &array[1][0]);
	printf("%d \n", array[2]);
	printf("%d \n\n", &array[2][0]);
	printf("%d \n", sizeof(array));
	printf("%d \n", sizeof(array[0]));
	printf("%d \n\n", sizeof(array[0][0]));
	//array는 배열의 첫번째 요소를 가리키면서 배열의 전체를 의미한다.
	//array[0]은 1행의 첫번째 요소를 가리키면서 1행을 의미한다.
	//array[1]은 2행의 첫번째 요소를 가리키면서 1행을 의미한다.
	//array[0][0]은 첫번째 요소를 가리키면서 1행 1열을 의미한다.
	printf("%p \n", array);
	printf("%p \n", array+1); //주소값이 12가 증가했다. 즉 3행이므로 int형*3만큼 증가하여 [0][0]->[1][0]이 되었다.
	                          //2차원 배열에서의 증감연산은 가로의 길이에 따라서 달라진다.
	                          //즉 2차원 배열의 포인터형을 결정짓기 어려운 이유가 된다.

	//위 배열의 포인터 변수를 선언하려면 2가지를 고려 
	//1.가리키는 대상이 int형 변수이다. 2. sizeof(int)x3만큼의 크기단위로 증감한다.

	//*************배열의 포인터**********************
	int (*ptr)[3]; //포인터 변수의 선언. 자료형(*포인터이름)[가로의길이]
	ptr=array; //== ptr=&array[0];
	int i, j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%d   ",ptr[i][j]);   //2차원 배열의 포인터를 활용하여 배열 출력

		}
		printf("\n");
	}

	//***혼동주의***
	//int *Word[3]    ->포인터 배열  [배열 선언]
	//int (*Word)[3]  ->배열(의) 포인터 [포인터 선언]
	


}
//*************************************************************
//7번 함수
//2차원 배열을 함수의 인자로 전달하기
void Function1(int (*ptr)[4]){    //배열의 주소값의 메모리에 접근.(2차원 배열의 포인터)
	int i,j;
	for(i=0; i<2; i++){
		for(j=0; j<4; j++){
			printf("%d ", ptr[i][j]);  
		}
		printf("\n");
	}


}
void givearray(){
	int array[2][4]={1,2,3,4,5,6,7,8};
	Function1(array);   //배열의 주소값 전달
	printf("\n");
	//2차원 배열에서도 arr[i]와 *(arr+i)는 같다.
	int array2[3]={1,2,3};
	printf("array2[1] %d \n",array2[1]);
	printf("*array2+1 %d \n",*array2+1);
	printf("array[1][2] %d \n",array[1][2]);
	printf("(*(array+1))[2] %d \n",(*(array+1))[2]); //array+1은 행이 1 증가한다. array[1]을 *(array+1)로 치환
	printf("(*array[1]+2) %d \n",(*array[1]+2));   //array[1][2]에서 array[1]을 A로 치환하면 A[2] ->*(A+2)->*(array[1]+2)
	printf("*(*array+1)+2 %d \n",*(*(array+1)+2)); //위의 식에서 array[1]을 *(array+1)로 치환









}

//***********************메인 함수******************************
int main(){
	int num=0;
	printf("2차원 배열에 대해 보려면 1번을, 3차원 배열에 대해 보려면 2번을, 다중 포인터에 대해 보려면 3번을, 포인터의 포인터를 이용한 Call by Reference에 대해 보시려면 4번을,\n 포인터 배열에 대해 보시려면 5번을, 다차원 배열과 포인터의 관계에 대해 보려면 6번을, 2차원 배열을 함수의 인자로 전달하는 방법을 보려면 7번을 눌러주세요.");
	scanf("%d",&num);
	if(num==1){
		twomultiarray();

	}
	else if(num==2){
		threemultiarray();

	}
	else if(num==3){
		doublepointer();

	}
	else if(num==4){
		doublecallbyreference();

	}
	else if(num==5){
		pointerarray();

	}
	else if(num==6){
		relation();

	}
	else if(num==7){
		givearray();

	}

	return 0;
}