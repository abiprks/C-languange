#include <iostream>

void Func(int arr[][10][10]){
	arr[5][5][5] = 100;
}

void FUnc2(int(*arr)[10][10])
{
	arr[5][5][5] = 423;
}

int main(void){
	int array[10][10][10];
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
				array[i][j][k] = i * 100 + j * 10 + k;

	int(*pArr)[10][10][10] = &array; //pArr �̶�� �����Ͱ� int������ [10][10][10] ¥���� �迭�� �ּҸ� ����Ű���� ��(&�� ����).

	//pArr[5][5][5] = 200; error

	(*pArr)[5][5][5] = 200;
	Func(array);
	
	int(*pArr2)[10][10] = array;// pARr2�̶�� �����Ͱ� int������ [10][10] ¥���� �迭�� ù���� ������ arr[0][10][10]�� ����Ŵ(�ּҸ� �������)

	pArr2[5][5][5] = 111;

	FUnc2(array);
	printf("%p \n%p\n", pArr, pArr2);
	printf("%d\n", (*pArr)[5][5][5]);
	getchar();
	return 0;
}