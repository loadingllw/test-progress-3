#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>



//int main()
//{
//	int arr[5];
//	int *p = arr;
//	int* arr[5];//ָ������
//	int (*p)[5] = &arr;//����ָ��
//	return 0;
//}

//
//int main()
//{
//	int arr[3][4];
//	int(*pa)[4] = arr;//��Ԫ�صĵ�ַ
//	int(*p)[3][4] = &arr;
//	return 0;
//}

//����ָ��
//��ź�����ָ��
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//
//void test(char* a)
//{
//
//}
//
//int main()
//{
//	printf("%p\n", &Add);
//    int(*p)(int, int) = Add;//p���Ǻ���ָ��
//	int ret = (*p)(2, 3);//*����ʡ��
//	printf("%d\n", ret);
//	//Add(2,3)
//	//p(2,3)
//
//	void(*pa)(char*) = &test;//������������ǵ�ַ
//	 
//	printf("%p\n", Add);
//	printf("%p\n", &Add);//������д��һ��һ����û������
//
//	return 0;
//}






//#include <assert.h>
//int my_strlen(char *arr)
//{
//	assert(arr != NULL);
//	int count = 0;
//	while (*arr)
//	{
//		arr++;
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	//int len = my_strlen(arr);
//	//printf("%d\n", len);
//
//
//	int(*p)(char*) = my_strlen;
//	int len = (p)("hello world");
//	printf("%d\n", len);
//
//	return 0;
//}

//����һ����������
//�����ĺ�����signal��signal��2����������һ������������int,�ڶ�������������һ������ָ�룬�ú���ָ��ָ����Ǻ���������int
//����������void
//signal�����ķ�����������һ������ָ�룬�ú���ָ����Ǻ���������int,����������void
//void(*signal(void(int, void(*)(int)))(int);


//����ָ������
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	int a = 10;
//	int b = 30;
//	int*arr[] = { &a, &b };
//	int(*p)(int, int) = Add;
//	int(*p1)(int, int) = Sub;
//
//	//parr���Ǻ���ָ������
//	int(*parr[2])(int, int) = { Add, Sub };
//	return 0;
//}

//void menu()
//{
//	printf("******1.Add      2.Sub  ******\n");
//	printf("******3.Mul      4.Div  ******\n");
//	printf("*******************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x*y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	int(*parr[])(int, int) = { 0, Add, Sub, Mul, Div };
//	do
//	{
//		menu();
//		printf("��ѡ��");
//		scanf("%d", &input);
//		printf("������������������");
//		scanf("%d %d", &x, &y);
//		ret = parr[input](x, y);
//		printf("%d\n", ret);
//	} while (input);
//	return 0;
//}


//int main()
//{
//	int(*parr[4])(int, int);
//	//pparr��ָ����ָ�������ָ��
//	int(*(*pparr)[4])(int, int) = &parr;
//	return 0;
//}


//�ص�����
//void test()
//{
//	printf("hello world\n");
//}
//void test2(void(*p)())
//{
//	p();
//}
//
//int main()
//{
//	test2(test);
//	return 0;
//}

void sort(int *arr, int sz)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

//int main()
//{
//	int arr[] = { 1, 22, 56, 87, 9, 44, 37, 86, 45 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	sort(arr, sz);
//	print(arr, sz);
//	return 0;
//}

//qsort������ʹ��
#include <stdlib.h>
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void test1()
{
    int arr[] = { 1, 22, 56, 87, 9, 44, 37, 86, 45 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]),cmp_int );
	print(arr, sz);
}


struct Stu
{
	char name[20];
	int age;
};

com_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1) ->age - ((struct Stu*)e2)->age;
}

void test2()
{
	struct Stu arr[] = { { "zhangsan", 20 }, { "lisi", 32 }, { "wangwu", 17 } };
	//����������
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), com_age);
}


int main()
{
	//test1();
	test2();
	return 0;
}