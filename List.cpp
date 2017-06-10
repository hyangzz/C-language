#include<stdio.h>
#include<malloc.h>
#define Maxsize 30
typedef int ElemType;
//����ṹ��
typedef struct SqList
{
	ElemType elem[Maxsize]; //�洢���Ա������
	int length;             //���Ա�ǰ����
}SqList;

void Init_Sqlist(SqList *L) //��ʼ�����Ա�
{
	L->length = 0; //��ʼ����ǰ����Ϊ0
}
int Insert_SqList(SqList *L, int i, ElemType e) //���L��iλ�ò�������e
{
	//�жϲ���λ���Ƿ�Ϸ�
	if (L->length >= i - 1 && i > 0)//����Ϸ�
	{
		int k;
		//�������Ųλ
		for (k = L->length; k >= i; k--)
		{
			L->elem[k] = L->elem[k - 1];
		}
		L->elem[k] = e; //��e����L
		L->length++; //���ȼ�1
		return 1;
	}
	else return 0;//�Ѵ�����ȣ����ܲ���
}
int SqListDelete(SqList *L, int i,ElemType e)//ɾ�����Ա��е�i��Ԫ��,����e������ֵ
{
	//�жϵ�iλ�Ƿ����
	if (L->length >= i&&i > 0)
	{
		int k;
		for (k = i; k <= L->length;++k)
		{
			L->elem[i - 1] = L->elem[i];	
		}
		e = L->elem[i];
		L->length--;//���ȼ�1
		return 1;
	}
	else return 0;//iֵ���Ϸ�
}
int Locate_SqList(SqList *L, ElemType n)//��ѯָ��Ԫ��n��λ��
{
	int i = 0;
	do{
		if (L->elem[i] == n)
			break;
		i++;
	} while (i < L->length);
//�ж��Ƿ����
	if (i < L->length)//����
	{
		return i + 1;
	}
	else return 0;//����
}
void Display_SqList(SqList L)//��ʾ���Ա��е�Ԫ��
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
	printf("��ʼ��....\n");
	printf("------------\n");
	printf("���Ա����£�\n");
	Insert_SqList(&L, 1, 1);
	Insert_SqList(&L, 2, 2);
	Insert_SqList(&L, 3, 3);
	Insert_SqList(&L, 4, 4);
	Insert_SqList(&L, 5, 5);
	Display_SqList(L);
	printf("\n");
	printf("����һ��Ԫ�أ�\n");
	Insert_SqList(&L, 3, 21);
	Display_SqList(L);
	printf("\n");
	return 0;
}