//파일 입출력
#include<stdio.h>

/*입력 스트림과 출력 스트림


            
			printf();  -----------출력버퍼 --------->  모니터
			                 출력 스트림

			scanf();   <----------입력버퍼 ----------  키보드
			                 입력 스트림


stdin : 표준 입력 스트림
stdout : 표준 출력 스트림
stderr : 표준 에러 스트림
*/


//1번 함수
//**********************문자 출력/문자 입력 함수****************************************
void getput(){

		printf("%d",printf("AAA"));
    //==3이 출력된다. printf의 반환값은 int형. 문자의 개수만큼 반환된다.
	/*int a='A';
	
    
	
	putchar(a);    //putchar, fputc : 문자 출력 함수
	fputc(a, stdout);
	getchar();     //getchar, fgetc : 문자 입력 함수
	fgetc(stdin); */


	int ch1,ch2;   
	ch1=getchar();
	ch2=fgetc(stdin);  //두번째 문자는 엔터키(아스키 코드 10인 \n으로 표현되는 문자)
	putchar(ch1);      
	fputc(ch2, stdout);


	//**********************EOF판단****************************************
	printf("\nEOF판단\n");
    int ch;              //int형으로 선언하는 이유 : 1. getchar와 fget함수의 반환형이 int형이기 때문이다. 
	                     //2. EOF는 int형 -1로 반환이되는데 char형의 경우 unsignedchar로 양의 정수로 반환될 수 있기 때문이다.
	while(1){                                  
		ch=getchar();    //해당 코드에서는 문자를 입력한 만큼 getchar함수가 호출되므로 하나의 문자만 입력하지 않아도 된다.
		if(ch==EOF){     //EOF : ctrl+z
			break;
		}
		putchar(ch);
	}        


}
//2번 함수
//**********************문자열 단위 입출력 함수****************************************
void strgetput(){
	
	printf("문자열 단위 입출력 함수\n");
	
	char *str="Simple String";
	puts(str) ;                 //문자열 단위 출력 함수 puts(str), fputs(str,stdout)
	printf("\n");
	puts(str) ;
	printf("\n");              //puts의 경우 자동으로 개행(\n)이 이루어지지만 fptus의 경우 그렇지 않다.
	fputs(str, stdout);
	printf("\n");
	fputs(str, stdout);
	
	char str2[8];
	gets(str2);
	puts(str2);
	fgets(str2,sizeof(str2),stdin);  //stdin으로부터 문자열을 입력받아서 배열 str에 저장하되 sizeof(str2)만큼의 길이만큼 저장
	fputs(str2,stdout);              //fgets함수는 엔터키(개행문자 \n)도 문자열의 일부로 받아들이고 \n을 만날 때까지 문자열을 읽어 들인다.

	printf("개행문자 확인\n");        //문자열은 6개의 문자+널문자로 배열의 크기 7을 만족시킨다.
	char str3[7];
	int i;                           //또한 공백문자도 문자열의 일부로 읽어들인다.

	for(i=0; i<3; i++){
		fgets(str3, sizeof(str3),stdin);
			printf("Read %d : %s\n", i+1,str3);



	}


}

//메인 함수
//*******************************************************************************
int main(){
	int num=0;
	printf("문자 단위 입출력 함수를 보시려면 1번을, 문자열 단위 입출력 함수를 보려면 2번을, 입력버퍼와 출력버퍼에 대해 보려면 3번을 눌러주세요");
    scanf("%d",&num);
	if(num==1){
		getput();



	}
	if(num==2){
		strgetput();



	}

	/* #include<string.h>
	strlen(str) = 문자열의 길이

	strcpy(str2, str1) // str1의 문자열을 str2에 저장
	strncpy(str2, str1, sizeof(str2)) // 범위를 고려한다. 단 sizeof(a)=5였을때 5개의 문자에 널문자가 없으면 엉뚱한 영역까지 복사한다.
	strcat(str1, str2) //str1의 뒤에 str2를 덧붙여라. str1뒤의 널문자가 덧붙임의 위치이다.
	strncat(str1, str2, 8)//str2의 문자열 중 최대 8개를 덧붙여라
	strcmp("ABCD","ABCDE") : 0이 반환되면 동일한 문자열, 0이 아닌 값이 반환되면 동일하지 않은 문자열

	#include<stdlib.h>
	atoi(str) : 문자열의 내용을 int형으로 반환
	atol(str) : long형으로 반환
	atof(str) : double형으로 반환
	















	/*
	char perID[7];
	char name[10];
	fputs("주민번호 앞 6자리 입력 : ",stdout);
	fgets(perID,sizeof(perID),stdin);
	fputs("이름입력 : ",stdout);
	ClearBuffer();
	fgets(name,sizeof(name),stdin);
	printf("주민번호 : %s\n",perID);
	printf("이름 : %s\n", name);*/



	return 0;

	



}









