#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>



//int main()
//{
//	int arr[5];
//	int *p = arr;
//	int* arr[5];//指针数组
//	int (*p)[5] = &arr;//数组指针
//	return 0;
//}

//
//int main()
//{
//	int arr[3][4];
//	int(*pa)[4] = arr;//首元素的地址
//	int(*p)[3][4] = &arr;
//	return 0;
//}

//函数指针
//存放函数的指针
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
//    int(*p)(int, int) = Add;//p就是函数指针
//	int ret = (*p)(2, 3);//*可以省略
//	printf("%d\n", ret);
//	//Add(2,3)
//	//p(2,3)
//
//	void(*pa)(char*) = &test;//函数名本身就是地址
//	 
//	printf("%p\n", Add);
//	printf("%p\n", &Add);//这两种写法一摸一样，没有区别
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

//这是一个函数声明
//声明的函数是signal，signal有2个参数，第一个参数类型是int,第二个参数类型是一个函数指针，该函数指针指向的是函数参数是int
//返回类型是void
//signal函数的返回来类型是一个函数指针，该函数指向的是函数参数是int,返回类型是void
//void(*signal(void(int, void(*)(int)))(int);


//函数指针数组
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
//	//parr就是函数指针数组
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
//		printf("请选择：");
//		scanf("%d", &input);
//		printf("请输入两个操作数：");
//		scanf("%d %d", &x, &y);
//		ret = parr[input](x, y);
//		printf("%d\n", ret);
//	} while (input);
//	return 0;
//}


//int main()
//{
//	int(*parr[4])(int, int);
//	//pparr是指向函数指针数组的指针
//	int(*(*pparr)[4])(int, int) = &parr;
//	return 0;
//}


//回调函数
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

//qsort函数的使用
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
	//按年龄排序
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), com_age);
}


int main()
{
	//test1();
	test2();
	return 0;
}