#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

#define XXX 1

// 练习extern：函数外定义变量 x_test2 和 y_test2
int x_test2;
int y_test2;
int addtwonum()
{
	// 函数内声明变量 x 和 y 为外部变量
	extern int x_test2;
	extern int y_test2;
	// 给外部变量（全局变量）x 和 y 赋值
	x_test2 = 4;
	y_test2 = 2;
	return x_test2 + y_test2;
}

#define LENGTH 10   
#define NEWLINE '\n'

double average(int num, ...)
{

	va_list valist;
	double sum = 0.0;
	int i;

	/* 为 num 个参数初始化 valist */
	va_start(valist, num);

	/* 访问所有赋给 valist 的参数 */
	for (i = 0; i < num; i++)
	{
		sum += va_arg(valist, int);
	}
	/* 清理为 valist 保留的内存 */
	va_end(valist);

	return sum / num;
}

float getAverage(int *arr, int size)
{
	int    i;
	double avg;
	double sum=0;

	for (i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	avg = sum / size;

	return avg;
}

/* 要生成和返回随机数的函数 */
int* getRandom()
{
	static int  r[10];//必须要static，不然局部变量传不出去
	int i;

	/* 设置种子 */
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; ++i)
	{
		r[i] = rand();
		printf("r[%d] = %d\n", i, r[i]);

	}

	return r;
}

enum DAY
{
	MON = 1, TUE, WED, THU, FRI, SAT, SUN
};
enum season 
{
	spring, summer = 3, autumn, winter
};

int max(int x, int y)
{
	return x > y ? x : y;
}

void populate_array(int* array, size_t arraySize, int (*getNextValue)(void))
{
	for (size_t i = 0; i < arraySize; i++)
		array[i] = getNextValue();
}

// 获取随机值
int getNextRandomValue(void)
{
	return rand();
}

struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
};
struct B;    //对结构体B进行不完整声明

//结构体A中包含指向结构体B的指针
struct A
{
	struct B* partner;
	//other members;
};

//结构体B中包含指向结构体A的指针，在A声明完后，B也随之进行声明
struct B
{
	struct A* partner;
	//other members;
};

void printBook(struct Books book)
{
	printf("Book title : %s\n", book.title);
	printf("Book author : %s\n", book.author);
	printf("Book subject : %s\n", book.subject);
	printf("Book book_id : %d\n", book.book_id);
}

union Data
{
	int i;
	float f;
	char  str[20];
} data;

struct bs {
	unsigned a : 4;
	unsigned : 4;    /* 空域 */
	unsigned b : 4;    /* 从下一单元开始存放 */
	unsigned c : 4;
}bs1;//a 占第一字节的 4 位，后 4 位填 0 表示不使用，b 从第二字节开始，占用 4 位，c 占用 4 位

typedef struct Files
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
} File;//用File表示struct Files



int main() 
{
	/* 基本语法 */
	printf("Hello,world! \n");
	printf("int 存储大小 : %lu \n", sizeof(int));
	printf("float 存储大小 : %lu \n", sizeof(float));
	printf("double 存储大小 : %lu \n", sizeof(double));
	
	/* C变量 */
	int i_test1;
	int j_test1;
	char x_test1 = 'x';
	
	printf("addtwonum结果为：%d", addtwonum());//extern练习函数

	/* C常量 */
	i_test1 = 85;    /* 十进制 */
	i_test1 = 0213;  /* 八进制 */
	i_test1 = 0x4b;  /* 十六进制 */
	i_test1 = 30;    /* 整数 */
	i_test1 = 30u;   /* 无符号整数 */
	i_test1 = 30l;   /* 长整数 */
	i_test1 = 30ul;  /* 无符号长整数 */
	j_test1 = 3.14159;
	j_test1 = 314159E-5L;

	printf("%c", NEWLINE);//练习 #define 预处理器定义常量
	const int WIDTH = 5; // 练习 const 定义常量
	printf("area:%d \n", (LENGTH * WIDTH));

	/* 运算符 */
	int a = 21;
	int b = 10;
	int c;

	c = a + b;
	printf("Line 1 - c 的值是 %d\n", c);
	c = a - b;
	printf("Line 2 - c 的值是 %d\n", c);
	c = a * b;
	printf("Line 3 - c 的值是 %d\n", c);
	c = a / b;
	printf("Line 4 - c 的值是 %d\n", c);
	c = a % b;
	printf("Line 5 - c 的值是 %d\n", c);
	c = a++;  // 赋值后再加 1 ，c 为 21，a 为 22
	printf("Line 6 - c 的值是 %d\n", c);
	c = a--;  // 赋值后再减 1 ，c 为 22 ，a 为 21
	printf("Line 7 - c 的值是 %d\n", c);

	a = 5; //00000101
	b = 20;//00010100
	printf("%d \n", a&b );
	printf("%d \n", a|b);
	printf("%d \n", a^b);
	printf("%d \n", ~a);
	printf("%d \n", a<<1);
	printf("%d \n", a>>2);
	
	/* 判断 */
	int num;
	printf("输入一个数字 : ");
	scanf_s("%d", &num);
	(num % 2 == 0) ? printf("偶数\n") : printf("奇数\n");

	char grade = 'B';
	switch (grade)
	{
	case 'A':
		printf("很棒！\n");
		break;
	case 'B':
	case 'C':
		printf("做得好\n");
		break;
	case 'D':
		printf("您通过了\n");
		break;
	case 'F':
		printf("最好再试一下\n");
		break;
	default:
		printf("无效的成绩\n");
	}
	printf("您的成绩是 %c\n", grade);

	/* 循环 */
	a = 10;
	while (a > 0) {
		printf("a=%d \n", a);
		a--;
	}
	for (a = 5; a > 0; a--) {
		printf("a=%d \n", a);
	}
	do
	{
		if (a == 15)
		{
			/* 跳过迭代 */
			a = a + 1;
			continue;//跳过此次迭代
		}
		printf("a 的值： %d\n", a);
		a++;

	} while (a < 20);

	/* 数组 */
	int n[5];
	int i, j;
	for (i = 0; i < 5; i++) {
		n[i] = i + 2;
	}
	for (j = 0; j < 5; j++)
	{
		printf("n[%d] = %d\n", j, n[j]);
	}

	int n2[3][3] = {
		{0,1,2},
		{3,4,5},
		{6,7,8}
	};
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("a[%d][%d] = %d\n", i, j, n2[i][j]);
		}
	}

	float Average =getAverage(n, 5);
	printf("%f", Average);


	int* p;
	p = getRandom();
	for (i = 0; i < 10; i++)
	{
		printf("*(p + %d) : %d\n", i, *(p + i));
	}


	/* 枚举 */
	enum DAY day1 = SAT;
	printf("day1是：%d \n", day1);
	enum day weekend;
	weekend = (enum day)1;  //类型转换
	printf("weekend:%d \n", weekend);

	/* 指针 */
	int* ptr_1 = NULL;
	printf("ptr_1地址：%p\n", ptr_1);

	int  var[3] = { 10, 100, 200 };
	int * ptr[3];//ptr[]存储的是指针

	for (i = 0; i < 3; i++)
	{
		ptr[i] = &var[i]; /* 赋值为整数的地址 */
	}//把var数组每个数的地址传给ptr，*ptr[i]=var[i]
	for (i = 0; i < 3; i++)
	{
		printf("Value of var[%d] = %d\n", i, *ptr[i]);
	}


	const char* names[] = {
				   "Zara Ali",
				   "Hina Ali",
				   "Nuha Ali",
				   "Sara Ali",
	};//"Zara Ali"本身是一个字符串，也即数组，所以names必须是二级指针

	for (i = 0; i < 4; i++)
	{
		printf("Value of names[%d] = %s\n", i, names[i]);
	}



	/* 函数指针 */
	int (*p_)(int, int) = &max;
	int d;
	printf("请输入三个数字:");
	scanf_s("%d %d %d", &a, &b, &c);
	d = p_(p_(a, b), c);//与直接调用函数等价，d = max(max(a, b), c)
	printf("最大的数字是: %d\n", d);

	int myarray[10];
	/* getNextRandomValue 不能加括号，否则无法编译，因为加上括号之后相当于传入此参数时传入了 int , 而不是函数指针*/
	populate_array(myarray, 10, getNextRandomValue);//回调函数
	for (int i = 0; i < 10; i++) {
		printf("%d ", myarray[i]);
	}
	printf("\n");


	/* C字符串 */
	char site1[6] = { 'a','b','c','d','e' };
	printf("site1:%s\n", site1);
	char site2[15] = "nicebuddy";
	char site3[14];
	int len;
	strcpy_s(site3, site2);
	len = strlen(site1);
	printf("strlen(site1) :  %d\n", len);

	/* 结构体 */
	struct Books book1,book2[20];
	strcpy_s(book1.title, "C_programming");
	strcpy_s(book1.author, "Nuha Ali");
	strcpy_s(book1.subject, "C Programming Tutorial");
	book1.book_id = 114514;
	printf("Book 1 title : %s\n", book1.title);
	printf("Book 1 author : %s\n", book1.author);
	printf("Book 1 subject : %s\n", book1.subject);
	printf("Book 1 book_id : %d\n", book1.book_id);

	printBook(book1);

	struct Books* struct_pointer;
	struct_pointer = &book1;
	printf("Book title : %s\n", struct_pointer->title);//结构体的指针就用->指向对应结构内部值


	/* 共用体 */
	union Data data1;
	data1.i = 10;
	strcpy_s(data1.str, "C programming");
	printf("data1.i : %d\n", data1.i);
	printf("data1.f : %f\n", data1.f);
	printf("data1.str : %s\n", data1.str);//共用体的 i 和 f 成员的值有损坏，因为最后赋给变量的值占用了内存位置

	data1.i = 10;
	printf("data.i : %d\n", data1.i);

	data1.f = 220.5;
	printf("data.f : %f\n", data1.f);

	strcpy_s(data1.str, "C Programming");
	printf("data.str : %s\n", data1.str);


	/* 位域 */
	printf("Sizeof( bs1 ) : %d\n", sizeof(bs1));

	/* typedef */
	File file;

	/* 宏 */
#if XXX
	printf("预处理宏");
#endif

	/* 可变参数 */
	printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2, 3, 4, 5));
	printf("Average of 5, 10, 15 = %f\n", average(3, 5, 10, 15));




}