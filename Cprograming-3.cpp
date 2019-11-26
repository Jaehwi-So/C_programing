#include<stdio.h>
//�迭�� ������ ��ȭ
//*************************************************************
//1�� �Լ�
//������ �迭           
void twomultiarray(){                                                 
	int array1[2][3]={1,2,3,4,5,6}; //������ �迭�� ����/�ʱ�ȭ [��][��]     
	int array2[2][2]={{1,2},{3,4}};   //������ �迭�� ����/�ʱ�ȭ, ��� �Ǵ� ������ 0���� �ʱ�ȭ�ȴ�.     
	int array3[][4]={1,2,3,4,5,6,7,8};  //2���� �迭���� ��(����)�� ������ �����ϴ�.(��(����)�� �˷��־��ٴ� ���� �Ͽ�)

	printf("\narray[2][3]�� ��°� �ش� �ּҰ� ���\n");
	int i=0;
	int j=0;
	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			printf("%d(%p)",array1[i][j],&array1[i][j]    );  //int�� �迭�̹Ƿ� �ּҰ����� ���̴� 4����Ʈ�� ���� �ȴ�. 


		}
		printf("\n");
     }
	for(i=0; i<6; i++){
		printf("%d  ", array1[i]);
	}
	

}
//*************************************************************
//2�� �Լ�
//������ �迭
void threemultiarray(){

	int array1[3][3][2]={{{50,70},{49,48},{72,36}},{{30,40},{29,46},{78,96}},{{54,49},{79,16},{58,76}}}; //������ �迭�� ����
	int i,j,k;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
				printf("%d�� %d�� �л� : ����%d ����%d    ",i+1,j+1,array1[i][j][0],array1[i][j][1]);
			
		}
		printf("\n");

	}
}
//3���� �迭�� �������� 2���� �迭�� ���ִ� ���·� �����ϴ� ���� ����. 


//*************************************************************
//3�� �Լ�
//���� ������
void doublepointer(){
	double num=3.14;
	double *ptr=&num;   //������ ���� ptr�� ����
	double **dptr=&ptr;  //���� ������ ���� dptr�� ����
	printf("ptr : %p \n", ptr);
	printf("*dptr : %p \n", *dptr);    //ptr==*dptr

	printf("*ptr = %f \n", *ptr);
	printf("**dptr : %f \n", **dptr);   //*ptr==**dptr

	double *ptr2=*dptr;
	*ptr2=10.99;
	printf("*ptr : %f \n", *ptr);
	printf("*ptr2 : %f \n", *ptr2);   
	printf("**dptr : %f \n", **dptr);     // dptr �� ptr �� num
	                                      //         ptr2 /

	double ***ddptr=&dptr;     //3�� ������ ���� ddptr�� ����
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
//4�� �Լ�
//�������� �����͸� �̿��� Call by Reference
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
Swap2(&pnum3,&pnum4);     //������ ���� pnum�� �ּҰ� ����
printf("%d %d \n",*pnum3,*pnum4);
printf("%d %d \n",pnum3,&pnum3);  //pnum3�� num3�� �ּҰ��� �ǹ�, &pnum3�� ������ ���� pnum3�� �ּҰ��� �ǹ�
}

/*Call by Reference���� �� �Լ��� ������
1��° �Լ��� pnum1�� num1�� �ּҰ��� �����ϰ� pnum2�� num2�� �ּҰ��� �����ϴµ� �ش� �ּҰ��� �޸𸮻� ����� ���� swap�� ���̴�.(num1�� num2�� swap)
�� n1�� n2�� ����� ���� �ٲ����� pnum1�� pnum2�ʹ� ������ �����̹Ƿ� ������ pnum1�� num1�� �ּҰ��� ����, pnum2�� num2�� �ּҰ��� �����Ѵ�.

2��° �Լ��� pnum3�� pnum4�� �ּҰ� ��ü�� swap�Ͽ���. �������� �ּҰ��� �����Ͽ� pnum3�� pnum4�� �ּҰ��� swap�Ͽ���.
�� n3�� n4�� ����� ���� �ٲ�� pnum3�� pnum4�� swap�� �̷������ �ȴ�.

*/
//*************************************************************
//5�� �Լ�
//������ �迭
void pointerarray(){
	int num1=10, num2=20, num3=30;
	int *pnum1=&num1;
	int *pnum2=&num2;
	int *pnum3=&num3;
	int *arr[]={pnum1,pnum2,pnum3};//������ �迭�� ����, arr�� �����͸� ��� ���� ��������
	printf("%d %d %d \n",pnum1,pnum2,pnum3);
	printf("%p %p %p \n",pnum1,pnum2,pnum3);  //������ ������ �̷���� ������ �迭�� �ּҰ�
	printf("%d %d %d \n",*pnum1,*pnum2,*pnum3);
	printf("%d %d %d \n",*arr[0],*arr[1],*arr[2]);
	printf("%d %d %d \n",arr[0],arr[1],arr[2]);
    printf("%d %d \n",arr, &arr[0]);
	
	int **dptr=arr;     //�迭�� �̸��� �������̴�. ������ �迭�̾����Ƿ� ���� ���������̹Ƿ� ���� ��ġ�Ѵ�.
	printf("%d %d %d \n",*dptr[0],*dptr[1],*dptr[2]); 
	//������ ������ �迭�� �̸�ó�� ����� �����ϴ�. =*dptr[0]=*arr[0]
	printf("%d \n",sizeof(dptr));
	// int *ptr=arr[]   (==*ptr=arr[0])
	//ptr[0]=arr[0]
	//int *arr2[];               **                *                       0
	//int **ptr2=arr2[]         ptr2              ptr[0]                  *ptr[0]
	//*ptr2[0]=*arr2[0]         arr2            - arr2[0] -               *arr2[0]
	//                          �迭�� �̸�  �迭�� ����� ������   �迭�� ����� �����Ͱ� ����Ű�� �޸�
	//�迭 �����Ϳ� ������ �迭�� ȥ�� ����

	double num10=3.14;
	double *ptr5=&num10;
	printf("%d %d", sizeof(&num10), sizeof(ptr5));
}
/*******************************���� �������� ����*************************

�����ʹ� �Լ� ������ �Լ� �ܺο� ����� ������ �����ϴ� ����� �������ش�.

*/
//*************************************************************
//6�� �Լ�
//������ �迭�� �������� ����
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
	//array�� �迭�� ù��° ��Ҹ� ����Ű�鼭 �迭�� ��ü�� �ǹ��Ѵ�.
	//array[0]�� 1���� ù��° ��Ҹ� ����Ű�鼭 1���� �ǹ��Ѵ�.
	//array[1]�� 2���� ù��° ��Ҹ� ����Ű�鼭 1���� �ǹ��Ѵ�.
	//array[0][0]�� ù��° ��Ҹ� ����Ű�鼭 1�� 1���� �ǹ��Ѵ�.
	printf("%p \n", array);
	printf("%p \n", array+1); //�ּҰ��� 12�� �����ߴ�. �� 3���̹Ƿ� int��*3��ŭ �����Ͽ� [0][0]->[1][0]�� �Ǿ���.
	                          //2���� �迭������ ���������� ������ ���̿� ���� �޶�����.
	                          //�� 2���� �迭�� ���������� �������� ����� ������ �ȴ�.

	//�� �迭�� ������ ������ �����Ϸ��� 2������ ��� 
	//1.����Ű�� ����� int�� �����̴�. 2. sizeof(int)x3��ŭ�� ũ������� �����Ѵ�.

	//*************�迭�� ������**********************
	int (*ptr)[3]; //������ ������ ����. �ڷ���(*�������̸�)[�����Ǳ���]
	ptr=array; //== ptr=&array[0];
	int i, j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%d   ",ptr[i][j]);   //2���� �迭�� �����͸� Ȱ���Ͽ� �迭 ���

		}
		printf("\n");
	}

	//***ȥ������***
	//int *Word[3]    ->������ �迭  [�迭 ����]
	//int (*Word)[3]  ->�迭(��) ������ [������ ����]
	


}
//*************************************************************
//7�� �Լ�
//2���� �迭�� �Լ��� ���ڷ� �����ϱ�
void Function1(int (*ptr)[4]){    //�迭�� �ּҰ��� �޸𸮿� ����.(2���� �迭�� ������)
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
	Function1(array);   //�迭�� �ּҰ� ����
	printf("\n");
	//2���� �迭������ arr[i]�� *(arr+i)�� ����.
	int array2[3]={1,2,3};
	printf("array2[1] %d \n",array2[1]);
	printf("*array2+1 %d \n",*array2+1);
	printf("array[1][2] %d \n",array[1][2]);
	printf("(*(array+1))[2] %d \n",(*(array+1))[2]); //array+1�� ���� 1 �����Ѵ�. array[1]�� *(array+1)�� ġȯ
	printf("(*array[1]+2) %d \n",(*array[1]+2));   //array[1][2]���� array[1]�� A�� ġȯ�ϸ� A[2] ->*(A+2)->*(array[1]+2)
	printf("*(*array+1)+2 %d \n",*(*(array+1)+2)); //���� �Ŀ��� array[1]�� *(array+1)�� ġȯ









}

//***********************���� �Լ�******************************
int main(){
	int num=0;
	printf("2���� �迭�� ���� ������ 1����, 3���� �迭�� ���� ������ 2����, ���� �����Ϳ� ���� ������ 3����, �������� �����͸� �̿��� Call by Reference�� ���� ���÷��� 4����,\n ������ �迭�� ���� ���÷��� 5����, ������ �迭�� �������� ���迡 ���� ������ 6����, 2���� �迭�� �Լ��� ���ڷ� �����ϴ� ����� ������ 7���� �����ּ���.");
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