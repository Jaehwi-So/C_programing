//메인함수로의 인자 전달
#include<stdio.h>

int main(int argc, char *argv[]){     //char *argv[]는 배열의 주소값을 인자로 전달받을 수 있는 매개변수의 선언이다.

	int i=0;
	printf("전달된 문자열의 수 : %d \n", argc);         //argc는 문자열의 개수를 전달받는다. 
	for(i=0; i<argc; i++){
		printf("%d번째 문자열 : %s \n", i+1, argv[i]);}
	return 0;
	int num1=0, num2=0;
	printf("몇번째 문자열의 몇번째 요소를 찾으시겠습니까?");
	scanf("%d %d",&num1,&num2);
	printf("\n%d번째 문자열의 %c번째 요소 : %c",num1,num2,*(argv[num1]+num2));

} 
