#include<stdio.h>
#include<math.h>
#include<Windows.h>

//puts(str) : 자동개행 ,         fputs(str,stdout) 
//gets(str,sizeof(str)),        fgets(str,sizeof(str),stdin)
//putchar(ch),                  fputc(ch,stdout)
//getchar(),                    fgetc(stdin)
//fflush(stdout) : 출력버퍼를 비운다. : 데이터가 목적지로 이동하게 된다.
//fflush(stdin) : 입력버퍼를 비운다. C언어에서는 정의하지 않음. : 입력한 데이터를 컷시킨다.

//*******************************1번 함수**************************************88
//파일의 입출력 기본
int FILEfop(){
	/************스트림의 구분하는 기준*****************
	1. 읽기 위한 스트림? 쓰기 위한 스트림?

	      스트림의 성격          파일이 없으면?
	r     읽기 가능                에러
	w     쓰기 가능                생성
	a  덧붙여 쓰기가능(add stream)  생성
	r+   읽기/쓰기 가능             에러
	w+   읽기/쓰기 가능             생성
	a+ 읽기/덧붙여 쓰기가능         생성
	
	a는 덧붙여 쓰기, +는 읽기쓰기 전부가능
	rt : 텍스트 모드에서 읽기 가능 rb : 바이너리 모드에서 읽기 가능

	#개행의 표현방식.
	\n은 c언어에서 약속된 개행 표현방식
	Windows의 파일 내 개행 \r\n
	Mac의 파일 내 개행 \r
	Unix 계열의 파일 내 개행 \n

	2. 텍스트 모드와 바이너리 모드
	문자 데이터 : 사람이 인식할 수 있는 문자를 담고 있는 파일(텍스트 파일)의 데이터
	바이너리 데이터 : 그 이외에 컴퓨터가 인식하 수 있는 데이터를 담고 있는 파일(영상.음원)의 데이터

	#파일을 텍스트 모드로 개방                      #바이너리 모드로 개방
	개행의 변환이 자동으로 이루어진다.             개행의 변환이 이루어지지 않는다.
	형태의 변환 o                                 형태의 변화 x
	(ex : {\n <-> \r\n}  )
	*/



	//******************************파일 data.txt에 문자를 저장*********************************
	FILE *fp=fopen("data.txt","wt"); //fopen : 파일의 스트림 형성. 즉 파일의 개방을 의미한다.
	//*fp : 포인터는 스트림을 가리키는 지시자 역할
	//fopen : 파일의 스트림을 형성하는 함수. FILE 구조체 변수가 생성된다. FILE 구조체 변수에는 파일에 대한 정보가 담긴다.
	//("data.txt","wt) : 첫번째 인자는 스트림을 형성할 파일의 이름, 두번째 인자는 형성하고자 하는 스트림의 종류이다.
	//(wt : write stream, rt : read stream)

	//FILE *fp=fopen("C:\\Project\\data.txt","wt")와 같이 경로를 포함하여 파일 이름을 지정해도 된다.
	if(fp==NULL){
		puts("파일오픈 실패!");
		return -1; //비정상적인 종료를 의미하기 위해서 -1 반환
	}
	fputc('A', fp); //fputc('입력할 문자',포인터) : fp가 가리키는 파일에 A라는 문자를 putchar한다.
	fputc('B', fp);
	fclose(fp); //fclose(포인터) : 스트림을 해제하는 함수. 1.운영체제가 할당한 자원의 반환 2. 버퍼링되었던 데이터의 출력의 이유
	            //입력버퍼와 출력버퍼의 해제.

	//******************************파일 data.txt에 문자를 읽어들임*********************************
	FILE *fp2=fopen("data.txt","rt");  //fp2는 data.txt를 지시하고. rt(reading stream)의 스트림 형성으로 파일을 읽어들인다.
	int ch, i;
		if(fp2==NULL){
		puts("파일오픈 실패!");
		return -1; //비정상적인 종료를 의미하기 위해서 -1 반환
	}

	for(i=0; i<3; i++){
		ch=fgetc(fp2);  //배열 ch에 fp2에서 읽어들인 문자를 저장
		printf("%c \n",ch);

	}
	fclose(fp2);

	return 0;

}
//*******************************2번 함수****************************************
//파일의 입출력 함수

/*
##FILE *fp=fopen("data.txt","wt")       //파일 스트림 형성
##fclose(fp);                           //파일 스트림 종료
##feof(fp)                              //더이상 읽어들일 문자가 없을 시(EOF를 만날 시) 0이 아닌 값을 반환한다.

##fputc('A', fp);                       //fputc('입력할 문자',포인터) fp가 가리키는 스트림(파일)에 A라는 문자를 putchar한다.
##ch=fgetc(fp2);                        //배열 ch에 fp2에서 읽어들인 문자를 저장

**문자 데이터의 입출력**
##fgets(string,sizeof(string),fp)       //fp의 문자열을 sizeof(string)만큼 읽어들여 string 배열에 저장
##fputs("문자열 \n",fp);                 //문자열을 fp가 가리키는 스트림에 저장

**바이너리 데이터의 입출력**
##fread((void*)buf, 1, sizeof(buf), binR)  //1의 크기의 데이터 sizeof(buf)개를 binR로부터 읽어들여서 배열 buf에 저장해라
##fwrite((void*)buf, 1, sizeof(buf), binW) //1크기의 데이터 sizeof(buf)개를 buf로부터 읽어서 binW에 저장하라.

##fprintf(fp, "%s %c %d",name,sex,age);         //스트림 fp에 해당 문자열을 printf(put)한다.
##fscanf(fp2, "%s %c %d", name2, &sex2, &age2); //파일 포인터, 파일에서 데이터를 입력 받을 형식, 입력 받을 변수 목록

**위치 지시자**
##fseek(fp, x, SEEK_X)           //파일 위치 지시자의 이동.
fp 스트림에서 x만큼(음수 : 역방향, 양수 : 정방향)으로 SEEK_X로부터 이동
	SEEK_END : 끝에서 시작
	SEEK_SET : 처음에서 시작
	SEEK_CUR : 현재 파일 위치 지시자에서 시작
##ftell(fp)                      //현재 파일 위치 지시자의 위치를 반환한다.


//해당 형식대로 순서대로 파일을 읽어들인다.
*/ 
int FILErw(){
	char str[30];
	int ch;
	FILE *fp=fopen("simple.txt","wt");
	if(fp==NULL){
		puts("파일오픈 실패");
		return -1;
	}
	fputc('A', fp);
	fputc('B', fp);
	fputs("공부하기 \n",fp); //문자열 출력. 개행문자 포함. 따라서 텍스트 모드로 파일을 개방해야 한다.
	fputs("싫다 \n",fp); 
	fclose(fp);

	FILE *fp2=fopen("simple.txt","rt");
	if(fp2==NULL){
		puts("파일오픈 실패");
		return -1;
	}
	ch=fgetc(fp2);         //데이터를 입력한 순서와 형태대로 읽어들이고 있다.
	printf("%c \n", ch);
	ch=fgetc(fp2);
	printf("%c \n", ch);

	fgets(str,sizeof(str),fp2);     //fgets함수는 \n(개행)을 만날 때까지 읽어 들인다. 따라서 문자열에 끝에는 반드시 \n이 있어야 한다.
	printf("%s", str);              //문자열이 파일에 저장될 때에는 널 문자는 저장되지 않는다. 따라서 개행을 기준으로 문자열의 끝을구분.
	fgets(str,sizeof(str),fp2);
	printf("%s \n", str);
	printf("개행 확인용^^\n");

	fclose(fp2);


	//*************feof 함수 기반의 파일복사***********************
	FILE *reading=fopen("simple.txt", "rt"); //simple파일을 읽어들이는 스트림
	FILE *writing=fopen("simplecopy.txt", "wt");//simplecopy파일을 만들어 출력하는 스트림
	int ch2;

	if(reading==NULL||writing==NULL){
		puts("파일오픈 실패!");
		return -1;
	}

	while((ch2=fgetc(reading))!=EOF){            //ch2에 reading스트림 파일의 문자를 저장  EOF : 파일의 끝. ctrl+z
		fputc(ch2, writing);                     //ch2를 writing스트림 파일에 복사
	}

	if(feof(reading)!=0){                        //feof함수 : 더 이상 읽어들일 데이터가 존재하지 않으면 0이 아닌 값을 반환한다.
		puts("파일복사 완료");                    //파일의 끝을 확인해야 하는 경우에 유용하게 사용된다.
	}
	else
		puts("파일복사 실패");
	fclose(reading);
	fclose(writing);

	//문자열 단위 복사

	FILE *reading2=fopen("simplecopy.txt", "rt"); //simplecopy파일을 읽어들이는 스트림
	FILE *writing2=fopen("simplecopycopy.txt", "wt");//simplecopycopy파일을 만들어 출력하는 스트림
	char string[20];

	if(reading2==NULL||writing2==NULL){
		puts("파일오픈 실패!");
		return -1;
	}

	while(fgets(string,sizeof(string),reading2)!=NULL){     //string에 reading스트림 파일의 문자열을 저장 
    //fgets함수는 파일에 끝에 도달하여 읽을 데이터가 없을 시 NULL을 반환한다.
		fputs(str,writing2);                                //ch2를 writing스트림 파일에 복사
	}

	if(feof(reading2)!=0){                        //feof함수 : 더 이상 읽어들일 데이터가 존재하지 않으면 0이 아닌 값을 반환한다.
		puts("파일복사 완료");                    //파일의 끝을 확인해야 하는 경우에 유용하게 사용된다.
	}
	else
		puts("파일복사 실패");
	fclose(reading2);
	fclose(writing2);
	
	
	
	return 0;
}
//*******************************3번 함수****************************************
//바이너리 파일의 입출력 함수
int FILEbd(){
	FILE *binO=fopen("src.bin","wb");
	FILE *binR=fopen("src.bin","rb");   //바이너리 모드로 파일을 개방하고 있다.
	FILE *binW=fopen("srccopy.bin","wb");
	char buf[20];
	int readCnt;
	fwrite((void*)buf,1,sizeof(buf),binO);

	if(binR==NULL||binW==NULL){
		puts("파일오픈 실패");
		return -1;
	}

	while(1){
		readCnt=fread((void*)buf, 1, sizeof(buf), binR);   //fread함수를 이용하여 파일로부터 데이터를 읽어들이고 있다.
		//####fread((void*)buf, 1, sizeof(buf), binR)
        //1의 크기의 데이터 sizeof(buf)개를 binR로부터 읽어들여서 배열 buf에 저장해라
		//void* : 확정되지 않은 자료형

		if(readCnt<sizeof(buf)){          //fread함수가 sizeof(buf)의 반환 값보다 작은 값을 반환했을 때 참이 된다.
			                              //오류가 발생하였거나 파일의 끝에 도달하여 sizeof(buf)만큼 읽어들이지 못함 둘중 하나

			if(feof(binR)!=0){                        //파일의 끝에 도달한 경우
				fwrite((void*)buf, 1, readCnt, binW);
				puts("파일복사 완료");
				break;
			}
			else{                            //오류가 발생한 경우
				puts("파일복사 실패");
				break;}

		}
		fwrite((void*)buf, 1, sizeof(buf), binW);     
		//####fwrite((void*)buf, 1, sizeof(buf), binW)
		//1크기의 데이터 sizeof(buf)개를 buf로부터 읽어서 binW에 저장하라.
	}

	fclose(binR);
	fclose(binW);
	return 0;
}
//*******************************4번 함수****************************************
//텍스트 데이터와 바이너리 데이터의 동시 입출력
typedef struct fren
{
char name[10];
char sex;
int age;
}MFriend;

int FILEtextbin(){
	char name[10];
	char sex;
	int age;

	FILE *fp=fopen("friend.txt", "wt");
	int i;

	for(i=0; i<3; i++){
		printf("이름 성별 나이 순 입력");
		scanf("%s %c %d",name,&sex,&age);
		getchar();                       //scanf함수는 엔터키를 입력버퍼에 남겨두므로 이를 소멸시키기 위해서 getchar()호출
		fprintf(fp, "%s %c %d",name,sex,age);//fprintf함수 : fp스트림에 해당 문자열을 printf(put)한다.
	}

	fclose(fp);

	char name2[10];
	char sex2;
	int age2;

	FILE *fp2=fopen("friend.txt", "rt");   //텍스트 모드로 파일 개방
	int ret;
	for(i=0; i<3; i++){
		ret=fscanf(fp2, "%s %c %d", name2, &sex2, &age2); //fscanf(파일 포인터, 파일에서 데이터를 입력 받을 형식, 입력 받을 변수 목록)
		if(ret==EOF)                                      //EOF를 반환하게 되면 반복문 탈출!
			break;
		printf("%s %c %d \n",name2,sex2,age2);
	}
	fclose(fp2);


	//텍스트와 바이너리 데이터의 집합체인 구조체 변수의 입출력
	FILE *fp3;
	FILE *fp4;
	MFriend MyFriend1;
	MFriend MyFriend2;

	//file write
	fp3=fopen("FriendList.bin","wb");
	printf("이름, 성별, 나이 순 입력 : ");
	scanf("이걸 쓸거다 %s %c %d \n",MyFriend1.name,&MyFriend1.sex,&MyFriend1.age);
	fwrite((void*)&MyFriend1, 1, sizeof(MyFriend1) , fp3);   
//fread((void*)buf, 1, sizeof(buf), binR)  //1의 크기의 데이터 sizeof(buf)개를 binR로부터 읽어들여서 배열 buf에 저장해라
//fwrite((void*)buf, 1, sizeof(buf), binW) //1크기의 데이터 sizeof(buf)개를 buf로부터 읽어서 binW에 저장하라.
	fclose(fp3);

	//file read
	fp4=fopen("FriendList.bin","rb");
	fread((void*)&MyFriend2, 1, sizeof(MyFriend2), fp4);
	printf("이걸 복사했다 %s %c %d \n",MyFriend2.name, MyFriend2.sex, MyFriend2.age);
	fclose(fp4);



	return 0;
}

//*******************************5번 함수****************************************
//파일 위치 지시자

int FILEpoint(){

	//파일 생성
	FILE *fp=fopen("mess1.txt","wt");
	fputs("123456789",fp);
	fclose(fp);

	//파일 개방
	fp=fopen("mess1.txt","rt");

	//fseek(fp, x, SEEK_X)
	//파일 위치 지시자의 이동.
	//fp 스트림에서 x만큼(음수 : 역방향, 양수 : 정방향)으로 SEEK_X로부터 이동
	//SEEK_END : 끝에서 시작
	//SEEK_SET : 처음에서 시작
	//SEEK_CUR : 현재 파일 위치 지시자에서 시작

	fseek(fp, -2, SEEK_END); //끝(EOF)로부터 -2(왼쪽)의 문자 8
	putchar(fgetc(fp));
	fseek(fp, 2, SEEK_SET);//시작(1)로부터 2(오른쪽)의 문자 3
	putchar(fgetc(fp));
	fseek(fp, 2, SEEK_CUR);//현재 파일 위치자가 가리키는 4에서 2(오른쪽)의 문자 6
	putchar(fgetc(fp));
	fseek(fp, -2, SEEK_END); //끝(EOF)로부터 -2(왼쪽)의 문자 8
	putchar(fgetc(fp));
	fclose(fp);
	printf("\n");

	//현재 파일 위치 지시자의 위치는?
	//ftell(fp) : 현재 파일 위치 지시자의 위치를 반환한다.

	fp=fopen("mess1.txt","rt");
	int i;
	long fpos;

	for(i=0; i<9; i++){
		putchar(getc(fp));
		fpos=ftell(fp);
		fseek(fp, -1, SEEK_END);
		putchar(getc(fp));
		fseek(fp, fpos, SEEK_SET);

	}

	fclose(fp);

	return 0;
}

//***********************************메인 함수***********************************************************

int main(){



printf("파일 입출력의 기본에 대해 보려면 1번을, 문자 데이터 파일 입출력 함수에 대해 보려면 2번을, 바이너리 데이터 파일 입출력 함수에 대해 보려면 3번을, 텍스트 데이터와 바이너리 데이터 동시 출력을 보려면 4번을, 파일 위치 지시자에 대해 보려면 5번을 눌러주세요. \n");
int num=0;  
scanf("%d",&num);
if(num==1){
	FILEfop();
}
if(num==2){
	FILErw();
}
if(num==3){
	FILEbd();
}
if(num==4){
	FILEtextbin();
}
if(num==5){
	FILEpoint();
}





scanf("%d",&num);
return 0;
}