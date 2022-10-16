#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

#define XXX 1

// ��ϰextern�������ⶨ����� x_test2 �� y_test2
int x_test2;
int y_test2;
int addtwonum()
{
	// �������������� x �� y Ϊ�ⲿ����
	extern int x_test2;
	extern int y_test2;
	// ���ⲿ������ȫ�ֱ�����x �� y ��ֵ
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

	/* Ϊ num ��������ʼ�� valist */
	va_start(valist, num);

	/* �������и��� valist �Ĳ��� */
	for (i = 0; i < num; i++)
	{
		sum += va_arg(valist, int);
	}
	/* ����Ϊ valist �������ڴ� */
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

/* Ҫ���ɺͷ���������ĺ��� */
int* getRandom()
{
	static int  r[10];//����Ҫstatic����Ȼ�ֲ�����������ȥ
	int i;

	/* �������� */
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

// ��ȡ���ֵ
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
struct B;    //�Խṹ��B���в���������

//�ṹ��A�а���ָ��ṹ��B��ָ��
struct A
{
	struct B* partner;
	//other members;
};

//�ṹ��B�а���ָ��ṹ��A��ָ�룬��A�������BҲ��֮��������
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
	unsigned : 4;    /* ���� */
	unsigned b : 4;    /* ����һ��Ԫ��ʼ��� */
	unsigned c : 4;
}bs1;//a ռ��һ�ֽڵ� 4 λ���� 4 λ�� 0 ��ʾ��ʹ�ã�b �ӵڶ��ֽڿ�ʼ��ռ�� 4 λ��c ռ�� 4 λ

typedef struct Files
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
} File;//��File��ʾstruct Files



int main() 
{
	/* �����﷨ */
	printf("Hello,world! \n");
	printf("int �洢��С : %lu \n", sizeof(int));
	printf("float �洢��С : %lu \n", sizeof(float));
	printf("double �洢��С : %lu \n", sizeof(double));
	
	/* C���� */
	int i_test1;
	int j_test1;
	char x_test1 = 'x';
	
	printf("addtwonum���Ϊ��%d", addtwonum());//extern��ϰ����

	/* C���� */
	i_test1 = 85;    /* ʮ���� */
	i_test1 = 0213;  /* �˽��� */
	i_test1 = 0x4b;  /* ʮ������ */
	i_test1 = 30;    /* ���� */
	i_test1 = 30u;   /* �޷������� */
	i_test1 = 30l;   /* ������ */
	i_test1 = 30ul;  /* �޷��ų����� */
	j_test1 = 3.14159;
	j_test1 = 314159E-5L;

	printf("%c", NEWLINE);//��ϰ #define Ԥ���������峣��
	const int WIDTH = 5; // ��ϰ const ���峣��
	printf("area:%d \n", (LENGTH * WIDTH));

	/* ����� */
	int a = 21;
	int b = 10;
	int c;

	c = a + b;
	printf("Line 1 - c ��ֵ�� %d\n", c);
	c = a - b;
	printf("Line 2 - c ��ֵ�� %d\n", c);
	c = a * b;
	printf("Line 3 - c ��ֵ�� %d\n", c);
	c = a / b;
	printf("Line 4 - c ��ֵ�� %d\n", c);
	c = a % b;
	printf("Line 5 - c ��ֵ�� %d\n", c);
	c = a++;  // ��ֵ���ټ� 1 ��c Ϊ 21��a Ϊ 22
	printf("Line 6 - c ��ֵ�� %d\n", c);
	c = a--;  // ��ֵ���ټ� 1 ��c Ϊ 22 ��a Ϊ 21
	printf("Line 7 - c ��ֵ�� %d\n", c);

	a = 5; //00000101
	b = 20;//00010100
	printf("%d \n", a&b );
	printf("%d \n", a|b);
	printf("%d \n", a^b);
	printf("%d \n", ~a);
	printf("%d \n", a<<1);
	printf("%d \n", a>>2);
	
	/* �ж� */
	int num;
	printf("����һ������ : ");
	scanf_s("%d", &num);
	(num % 2 == 0) ? printf("ż��\n") : printf("����\n");

	char grade = 'B';
	switch (grade)
	{
	case 'A':
		printf("�ܰ���\n");
		break;
	case 'B':
	case 'C':
		printf("���ú�\n");
		break;
	case 'D':
		printf("��ͨ����\n");
		break;
	case 'F':
		printf("�������һ��\n");
		break;
	default:
		printf("��Ч�ĳɼ�\n");
	}
	printf("���ĳɼ��� %c\n", grade);

	/* ѭ�� */
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
			/* �������� */
			a = a + 1;
			continue;//�����˴ε���
		}
		printf("a ��ֵ�� %d\n", a);
		a++;

	} while (a < 20);

	/* ���� */
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


	/* ö�� */
	enum DAY day1 = SAT;
	printf("day1�ǣ�%d \n", day1);
	enum day weekend;
	weekend = (enum day)1;  //����ת��
	printf("weekend:%d \n", weekend);

	/* ָ�� */
	int* ptr_1 = NULL;
	printf("ptr_1��ַ��%p\n", ptr_1);

	int  var[3] = { 10, 100, 200 };
	int * ptr[3];//ptr[]�洢����ָ��

	for (i = 0; i < 3; i++)
	{
		ptr[i] = &var[i]; /* ��ֵΪ�����ĵ�ַ */
	}//��var����ÿ�����ĵ�ַ����ptr��*ptr[i]=var[i]
	for (i = 0; i < 3; i++)
	{
		printf("Value of var[%d] = %d\n", i, *ptr[i]);
	}


	const char* names[] = {
				   "Zara Ali",
				   "Hina Ali",
				   "Nuha Ali",
				   "Sara Ali",
	};//"Zara Ali"������һ���ַ�����Ҳ�����飬����names�����Ƕ���ָ��

	for (i = 0; i < 4; i++)
	{
		printf("Value of names[%d] = %s\n", i, names[i]);
	}



	/* ����ָ�� */
	int (*p_)(int, int) = &max;
	int d;
	printf("��������������:");
	scanf_s("%d %d %d", &a, &b, &c);
	d = p_(p_(a, b), c);//��ֱ�ӵ��ú����ȼۣ�d = max(max(a, b), c)
	printf("����������: %d\n", d);

	int myarray[10];
	/* getNextRandomValue ���ܼ����ţ������޷����룬��Ϊ��������֮���൱�ڴ���˲���ʱ������ int , �����Ǻ���ָ��*/
	populate_array(myarray, 10, getNextRandomValue);//�ص�����
	for (int i = 0; i < 10; i++) {
		printf("%d ", myarray[i]);
	}
	printf("\n");


	/* C�ַ��� */
	char site1[6] = { 'a','b','c','d','e' };
	printf("site1:%s\n", site1);
	char site2[15] = "nicebuddy";
	char site3[14];
	int len;
	strcpy_s(site3, site2);
	len = strlen(site1);
	printf("strlen(site1) :  %d\n", len);

	/* �ṹ�� */
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
	printf("Book title : %s\n", struct_pointer->title);//�ṹ���ָ�����->ָ���Ӧ�ṹ�ڲ�ֵ


	/* ������ */
	union Data data1;
	data1.i = 10;
	strcpy_s(data1.str, "C programming");
	printf("data1.i : %d\n", data1.i);
	printf("data1.f : %f\n", data1.f);
	printf("data1.str : %s\n", data1.str);//������� i �� f ��Ա��ֵ���𻵣���Ϊ��󸳸�������ֵռ�����ڴ�λ��

	data1.i = 10;
	printf("data.i : %d\n", data1.i);

	data1.f = 220.5;
	printf("data.f : %f\n", data1.f);

	strcpy_s(data1.str, "C Programming");
	printf("data.str : %s\n", data1.str);


	/* λ�� */
	printf("Sizeof( bs1 ) : %d\n", sizeof(bs1));

	/* typedef */
	File file;

	/* �� */
#if XXX
	printf("Ԥ�����");
#endif

	/* �ɱ���� */
	printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2, 3, 4, 5));
	printf("Average of 5, 10, 15 = %f\n", average(3, 5, 10, 15));




}