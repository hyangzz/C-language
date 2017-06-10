#include<stdio.h>
#include<malloc.h>
#define Maxsize 30
typedef int ElemType;
//定义结构体
typedef struct SqList
{
	ElemType elem[Maxsize]; //存储线性表的数组
	int length;             //线性表当前长度
}SqList;

void Init_Sqlist(SqList *L) //初始化线性表
{
	L->length = 0; //初始化当前长度为0
}
int Insert_SqList(SqList *L, int i, ElemType e) //向表L的i位置插入数据e
{
	//判断插入位置是否合法
	if (L->length >= i - 1 && i > 0)//如果合法
	{
		int k;
		//依次向后挪位
		for (k = L->length; k >= i; k--)
		{
			L->elem[k] = L->elem[k - 1];
		}
		L->elem[k] = e; //将e插入L
		L->length++; //长度加1
		return 1;
	}
	else return 0;//已达最长长度，不能插入
}
int SqListDelete(SqList *L, int i,ElemType e)//删除线性表中第i个元素,并用e返回其值
{
	//判断第i位是否存在
	if (L->length >= i&&i > 0)
	{
		int k;
		for (k = i; k <= L->length;++k)
		{
			L->elem[i - 1] = L->elem[i];	
		}
		e = L->elem[i];
		L->length--;//长度减1
		return 1;
	}
	else return 0;//i值不合法
}
int Locate_SqList(SqList *L, ElemType n)//查询指定元素n的位置
{
	int i = 0;
	do{
		if (L->elem[i] == n)
			break;
		i++;
	} while (i < L->length);
//判断是否存在
	if (i < L->length)//存在
	{
		return i + 1;
	}
	else return 0;//存在
}
void Display_SqList(SqList L)//显示线性表中的元素
{
	int i;
	for (i = 0; i < L.length - 1; i++)
	{
		printf("%d ", L.elem[i]);
	}
	printf("%d\n", L.elem[i]);
}
int main()
{
	SqList L,La,Lb,Lc;
	Init_Sqlist(&L);
	printf("初始化....\n");
	printf("------------\n");
	printf("线性表如下：\n");
	Insert_SqList(&L, 1, 1);
	Insert_SqList(&L, 2, 2);
	Insert_SqList(&L, 3, 3);
	Insert_SqList(&L, 4, 4);
	Insert_SqList(&L, 5, 5);
	Display_SqList(L);
	printf("\n");
	printf("插入一个元素：\n");
	Insert_SqList(&L, 3, 21);
	Display_SqList(L);
	printf("\n");
	return 0;
}