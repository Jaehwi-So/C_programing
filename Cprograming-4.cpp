#include<stdio.h>
//�Լ� ������
void Function1(int n1, int n2){

	printf("%d + %d = %d \n", n1,n2,n1+n2);

}
void Function2(char *str){

	printf("%s \n", str);


}
int main(){
	int num1=10; 
	int num2=20;
	char *str="Jaehwi So";      //str������ ����, str �ּҰ� ���� ���ڿ� �Ҵ�
	Function1(num1,num2);

	void (*Pfunc)(int, int);    //�Լ� ������ Pfunc�� ����
	//�Լ��� �ڷ���(*(������ �̸�))(�Ű������� �ڷ���)
	Pfunc=Function1; //�Լ��� �̸��� �ּҰ��� �ǹ��Ѵ�.
	Pfunc(num1,num2); //Pfunc�� Function���� ������ ���� ����ȴ�. ������ ����İ� ���� ���� Pfunc�� Function1ó�� ����� �� �ִ�.


	Function2(str); //������ ���� str���� ���ڿ��� ù������ H�� �ּҰ��� ����Ǹ� str�� ����Ű�� ����� Hello World.
	//���ڿ��� �޸� ������ ����->�޸��� �ּҰ� ��ȯ //printf�Լ��� ���ڿ��� �ּҰ��� ���޹޴� �Լ��̴�.
	void (*Pfunc2)(char*)=Function2;   //�Լ� ������ Pfunc2�� ����. �Ű������� �������̹Ƿ� char*
	Pfunc2(str);
	

	//�Լ� �����ʹ� �� �������� ���ڵ��� �ǰ��� �к��ϴٰ� �ϴ�.

	//*****************************************************************

	int num3=10;
	void *ptr;     //void�� ������ ������ ����, void�� �����Ϳ��� ��� ������ �ּҰ��̵� ���� �� �ִ�.
	ptr=&num3;
	printf("%p \n", ptr);
	ptr=Function1;
	printf("%p \n", ptr);


	return 0;





}