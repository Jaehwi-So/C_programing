#include<stdio.h>
#include<math.h>
#include<Windows.h>

struct point           //구조체 point의 정의, 안에 xpos와 ypos변수가 들어있다. 
{	int xpos;          
	int ypos;
};

typedef struct position 
{
int xpos;
int ypos;
}Sposition;//struct position이라는 자료형에 새 이름 Sposition을 typedef로 부여
/*typedef struct
{
int xpos;
int ypos;
}Sposition;
다음의 형태로 구조체의 이름을 생략하는 것도 가능하다. 단 typedef struct pos1;과 같은 변수 선언은 불가능하다.
*/

//***********************************1번 함수***********************************************************
//구조체의 선언
void StructPoint(){

struct point pos1,pos2;     //구조체 point의 형태로 pos1, pos2 선언
double distance;
fputs("pos1의 좌표 :", stdout);      
scanf("%d %d", &pos1.xpos, &pos1.ypos);        
fputs("pos2의 좌표 :", stdout);     
scanf("%d %d", &pos2.xpos, &pos2.ypos);   
double result=sqrt((double)((pos1.xpos-pos2.xpos)*(pos1.xpos-pos2.xpos))+((pos1.ypos-pos2.ypos)*(pos1.ypos-pos2.ypos)));
//sqrt:제곱근
printf("두 점 사이의 거리는 %f입니다. \n", result);  //pos1의 x좌표와 y좌표
struct point pos3={1,2};   //구조체의 초기화 방법중 하나
printf("pos3 : %d %d  \n", pos3.xpos, pos3.ypos);
Sposition pos4={1,2}; // typedef타입 구조체 변수의 선언과 초기화
printf("pos4 : %d %d  \n", pos4.xpos, pos4.ypos);

}
//***********************************2번 함수***********************************************************
//구조체의 선언(멤버가 배열)
struct person         //구조체 person의 정의, 안에 배열이 구조체의 멤버로 들어있다.
{
	char name[20];
	char phone[20];
};

void StructArray(){
struct person man1, man2;  //구초제 person의 형태로 man1, man2 선언
puts("이름 입력 \n");
scanf("%s", man1.name);   //배열의 이름은 주소값이다.
puts("휴대폰번호 입력 \n");
scanf("%s", man1.phone);
printf("%s, %s \n", man1.name, man1.phone);

strcpy(man2.name, "소재휘");            //배열에 문자열을 저장한다.
strcpy(man2.phone,"010-7409-9910 ");
printf("%s, %s", man2.name, man2.phone);

}
//***********************************3번 함수***********************************************************
//구조체 배열의 선언
void StructArrayPos(){
	int i=0;
	struct point arr[3];       //arr[0]부터 arr[2]까지 4개의 구조체 선언
	for(i=0; i<3; i++){
		printf("점의 좌표 입력");
		scanf("%d %d",&arr[i].xpos,&arr[i].ypos);

	}
	for(i=0; i<3; i++){
		printf("%d번째 점의 좌표 : (%d,%d) \n",i+1, arr[i].xpos, arr[i].ypos);

	}
	struct person arr2[3]={
		{"소재휘","01074099910"},{"박지현","01056334761"},{"방신우","01063554633"}};
	//선언과 동시에 초기화
	for(i=0; i<3; i++){
		printf("%d번째 사람 : (%s,%s) \n",i+1, arr2[i].name, arr2[i].phone);

	}




}
//***********************************4번 함수***********************************************************
//구조체 포인터
/*
struct point           
{	int xpos;          
	int ypos;
};*/
struct circle
{
 char radious;
 struct point *center;
};
void StructPointer(){
	struct point pos1={1,2};
	struct point *ptr=&pos1;   //구조체의 포인터 선언. 포인터 변수 ptr이 pos1을 가리키게 된다.
	(*ptr).xpos=2;
	(*ptr).ypos+=1;
	printf("%d %d \n",pos1.xpos,pos1.ypos);
	printf("%d %d \n",(*ptr).xpos,(*ptr).ypos);
	printf("%d\n",ptr);

	ptr->xpos =3;   // ptr이 가리키는 구조체 변수의 멤버 xpos에 3 ,저장 포인터 할당은 ->
	ptr->ypos +=2;  // == (*ptr).ypos+=2
	printf("%d %d \n",pos1.xpos,pos1.ypos);
	
	//포인터 변수가 구조체의 멤버
	
	struct circle ring;    //radious와 구조체 center로 구성
	struct point cen;      //구조체 center의 x,y좌표
	printf("원의 반지름 입력 \n");
	scanf("%d",&ring.radious);  
	ring.center=&cen;      //구조체 내의 포인터 변수 ring.center에 구조체 cen의 주소값을 할당
	printf("원의 중심 좌표 입력 \n");
	scanf("%d %d",&cen.xpos, &cen.ypos); 
	printf("원의 반지름 : %d, 원의 중심 좌표 : (%d,%d)\n",ring.radious,ring.center->xpos,ring.center->ypos);
	printf("%p %p %p", &ring, &ring.radious, &ring.center); //구조체 변수의 주소값은 구조체 멤버의 첫번째 요소의 주소값과 동일하다.
	

}
//***********************************5번 함수***********************************************************
//함수로의 구조체 전달, 반환
//함수를 넘겨줄때에는 자료형 안썼고 넘겨받을때에는 자료형 썼다. 구조체도 마찬가지이다.
//int Function(int num){}
//Function(num)

//int Function(struct numpoint num){}
//int main(){
//struct numpoint num1;
//Function(num1)}

typedef struct numpoint
{
	int xpos;
	int ypos;
} Numpoint;

double StructPlus(Numpoint num3, Numpoint num4){
	return sqrt((double)((num3.xpos-num4.xpos)*(num3.xpos-num4.xpos))+((num3.ypos-num4.ypos)*(num3.ypos-num4.ypos)));
}
//Numpoint형태의 num1과 num2의 인자를 Numpoint형태의 num3과 num4로 전달받아 연산 후 double형태로 값을 반환한다.

struct numpoint StructGet(){
	Numpoint cen;
	printf("현재 위치좌표 입력");
	scanf("%d %d",&cen.xpos,&cen.ypos);
	return cen;
}

void Swap(Numpoint (*pos1)){
	int num= pos1->xpos;
	pos1->xpos=pos1->ypos;
	pos1->ypos=num;
}

//Numpoint의 구조체형에 좌표를 입력받아 struct numpoint형태로 구조체 변수 cen을 반환한다.

void StructFunction(){
	Numpoint num1=StructGet(); //위치좌표를 받아주는 함수의 반환값을 구조체변수 num1에 저장 
	Numpoint num2=StructGet(); //입력x 출력o 함수
	printf("%f",StructPlus(num1, num2)); //구조체 변수 num1과 num2를 인자로 전달한다.

//포인터+함수, Call by Reference
	Swap(&num1);
	printf("\nSwap : %d %d",num1.xpos,num1.ypos);


}
//***********************************6번 함수***********************************************************
//중첩 구조체
typedef struct circlepos
{int radious;
 struct point position; //구조체의 멤버로 구조체가 들어갈 수 있다.
}circlepos;

circlepos GetCirclePos(){
	circlepos CC;
	printf("좌표 입력");
	scanf("%d %d",&CC.position.xpos,&CC.position.ypos);
	printf("반지름 입력");
	scanf("%d",&CC.radious);
	return CC; //Circlepos 구조체 변수 CC를 반환한다.

}
void ShowCirclePos(circlepos pos){
	printf("\n좌표 : (%d,%d), 반지름 : %d",pos.position.xpos,pos.position.ypos,pos.radious); //pos변수의 멤버 position의 멤버 xpos
}
void SwapCirclePos(circlepos (*pos)){ //구조체 변수 pos[i]의 주소값을 인자로 전달받는다.
	int num=0;
	num=pos->position.xpos;
	pos->position.xpos=pos->position.ypos; //==(*pos).position.xpos
	pos->position.ypos=num;                //pos의 주소값에 할당된 값을 변화시킨다. 
	//pos가 가리키는 변수의 멤버 position의 멤버 ypos의 값 변화

}
void DoubleStruct(){
	int i=0;
	circlepos pos[3];
	for(i=0; i<3; i++){
		pos[i]=GetCirclePos(); //구조체 배열 pos[i]마다 좌표와 반지름을 할당해주는 함수. 
	}
	for(i=0; i<3; i++){
		ShowCirclePos(pos[i]); //함수를 호출하여 pos[i]에 할당된 값을 출력한다.
	}
	for(i=0; i<3; i++){
		SwapCirclePos(&pos[i]); //함수를 호출하여 pos[i]의 주소값을 인자로 전달, pos[i]에 멤버 position의 멤버 x,y를 바꾼다
	}
	for(i=0; i<3; i++){
		ShowCirclePos(pos[i]); //함수를 호출하여 pos[i]에 할당된 값을 출력한다.
	}
	circlepos Cone={1,{2,3}}; //중첩 구조체의 초기화
	printf("\n%d %d %d",Cone.position.xpos,Cone.position.ypos,Cone.radious);
}

//구조체 변수를 대상으로는 대입 연산과 sizeof 연산 정도가 가능하다. 덧뺄셈 등은 함수로 사용자가 정의해주어야 한다.

//***********************************7번 함수***********************************************************
//공용체
//공용체의 의의는 하나의 메모리 공간을 둘 이상의 방식으로 접근이 가능하다는 것이다.
struct updownbite
{
	short upper;
	short lower;
};
union bite
{
	int num;
	char twobite[4];
	struct updownbite UDbite;
};
void Union(){
	union bite Ubox;
	struct updownbite Sbox;
	printf("정수 입력 : ");
	scanf("%d", &Ubox.num);
	printf("상위 2바이트 : %u \n", Ubox.UDbite.upper); 
	printf("하위 2바이트 : %u \n", Ubox.UDbite.lower);
	printf("상위 1바이트 아스키코드 : %c \n", Ubox.twobite[0]);
	printf("하위 1바이트 아스키코드 : %c \n", Ubox.twobite[3]);
	printf("%d %d \n",sizeof(Ubox), sizeof(Sbox));    //공용체는 가장 큰 바이트인 4바이트를 공유하고, 구조체는 short타입x2의 메모리 할당
	printf("%p %p %p \n",&Ubox.num,Ubox.twobite,&Ubox.UDbite); //공용체의 멤버들의 주소값은 동일하다.
	printf("%p %p \n",&Sbox.upper,&Sbox.lower); //구조체의 멤버들의 주소값의 차이는 short(2)였다.

	//공용체의 4바이트에서 공용체의 멤버에 따라서 1바이트, 2바이트, 4바이트를 골라서 접근이 가능했다.

}
//***********************************8번 함수***********************************************************
//열거형
typedef enum syllable //typedef 선언이 추가된 syllable이라는 이름의 열거형의 정의
{
	Do=1, Re=2, Mi=3, Fa=4, So=5, La=6, Ti=7
}Syllable;
void Sound(Syllable sy){
	switch(sy)
	{
	case Do :
		puts("도"); return;
	case Re :
		puts("레"); return;
	case Mi :
		puts("미"); return;
	case Fa :
		puts("파"); return;
	case So :
		puts("솔"); return;
	case La :
		puts("라"); return;
	case Ti :
		puts("시"); return;
	}
	puts("도");
}
int Enumerated(){
	Syllable tone;
	//for(tone=Do; tone<=Ti; tone+=Do);

	return 0;

	


}
//***********************************메인 함수***********************************************************
typedef int ANT;
int main(){

//puts(str) : 자동개행 , fputs(str,stdout) 
//gets(str,sizeof(str)), fgets(str,sizeof(str),stdin)
//putchar(ch), fputc(ch,stdout)
//getchar(), fgetc(stdin)

printf("구조체의 선언(점의 좌표)를 보려면 1번을, 구조체의 선언(배열)을 보려면 2번을, 구조체 배열 선언을 보려면 3번을 구조체 포인터를 보려면 4번을, 함수로의 구조체 변수 전달,반환을 보려면 5번을, 구조체 중첩 예제를 보려면 6번을 눌러주세요, 공용체에 대해 보려면 7번을, 열거형에 대해 보려면 눌러주세요. \n");
ANT num=0;  // typedef int ANT 선언으로 int라는 자료형의 또다른 이름 ANT 부여
scanf("%d",&num);
if(num==1){
	StructPoint();
}
if(num==2){
	StructArray();
}
if(num==3){
	StructArrayPos();
}
if(num==4){
	StructPointer();
}
if(num==5){
	StructFunction();
}
if(num==6){
	DoubleStruct();
}
if(num==7){
	Union();
}
if(num==8){
	Enumerated();
}



scanf("%d",&num);
return 0;





}