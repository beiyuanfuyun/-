#define _CRT_SECURE_NO_WARNINGS
//������Ϊһ���������ݽṹ��������������ָ������ͷ��㣬��Ԫ�ڵ㣬һ��ڵ㣬β�ڵ����
//ͷ���һ��������Ϊ0��β�ڵ��ָ����Ϊnull,��Ԫ�ڵ�Ϊ������Ч�������ͷһ���ڵ㣬һ��Ϊͷ������ĵ�һ���ڵ�
//������������ַ���������ģ����Բ���ʹ��+1ɶ�ģ����У�������
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
//������Ԫ�ص�����

//��ʼ��������
//ָ�뺯��
struct Node * init()
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	if (temp == NULL)
	{
		printf("�ڴ�����ʧ��\n");
		return NULL;
	}
	temp->data = 0;
	temp->next = NULL;
	printf("%#p\n", temp);
	return temp;//temp�Ŀռ䱻�ͷ��ˣ�����tempֵ�ﱣ�������뺯����ֵ��˭�����˸÷���ֵ�Ϳ��Ե����ڲ������������뺯��,����ַ����һ����
}


//Ԫ�صĲ���
//ͷ�巨   
//һ�����Ľڵ���ͷ�ڵ�ĺ��棬Ҳ����ͷ��㲻�䣬����buff��ָ�򲻱�
void insert(struct Node*list,int val)//val�����������ݣ�list����Ҫ����Ԫ�صĵ�ַ
{
	//1.�����½ڵ�
	//2.��ȥ���»���ָ��ȥ�Ҿɰ�
	//3.����ͷ��������»�

	//�����½ڵ�
	struct Node* New =(struct Node*)malloc(sizeof(struct Node));
	
	if (New != NULL)
	{
		New->data = val;
		//ԭ������Ԫ�ڵ�ĵ�ַΪ��  list->next��һ����������ʽ������һ������list�ṹ��������ݣ�����next����ָ���Ŀ�꣬���Ҳ����ָ��������׵�ַ��
	New->next = list->next;//list->next����������Ԫ�ڵ�ĵ�ַ,New->next�����ΪNew��ָ����
	//����ͷ����ָ��
	list->next = New;//����ǲ����һ����Ԫ�ڵ�Ҳ�ǿ��������õģ�����list-nextΪNULL��
	}
	else
    printf("�ڴ��ȡʧ��\n");
}

//������Ԫ�صĴ�ӡ

void list_print(struct Node*list)
{
	//ͷ�ڵ㻹�ǲ�Ҫ�Ҷ����ز���
	struct Node* p = list->next;//pָ����Ԫ�ڵ�
	while (p != NULL)
	{
		printf("%d->", p->data);
		//p++�Ǵ����
		//pָ����һ���ڵ�
		p = p->next;
	}
	printf("NULL\n\n");


}
//������Ԫ�ص�ɾ��
//1.Ŀ��ڵ��ǰ��һ���ڵ�Ϊǰ���ڵ㣬����һ��Ϊ��̽ڵ�,���Ŀ�Ľڵ���Ե�
//����ǰ���ڵ��next��ָ��Ϊ��̽ڵ㣬���ͷ�Ŀ�Ľڵ�
void ListDelete(struct Node*list,int val)
{
	//��Ҫ����������һ��Ϊp1һ��Ϊp2,p1ΪĿ�Ľڵ㣬p2Ϊǰ���ڵ�
	struct Node* p2 = list;//ָ��ͷ���
	struct Node* p1 = p2;//p1��p2�ĺ�̽ڵ�
	while (p2->next!=NULL)//ʲô����¿��Խ���ѭ��
	{
		if (p2->next->data == val)
		{
			p1 = p2->next;//p1ָ��Ŀ��ڵ�
			p2->next = p1->next;//p1�ĺ�̽ڵ�ĵ�ַ����ǰ���ڵ�
			free(p1);//�ͷ�Ҫ��ɾ���Ľڵ�
		}
		else
		{
			p2 = p2->next;
		}
	}
}

//������Ԫ�ص��޸�  ָ��ֵ�����޸�Ԫ��
void list_change(struct Node* list, int data)
{
	for (struct Node* temp = list->next; temp != NULL; temp = temp->next)
	{
		if (temp->data == val)//�ҵ�Ҫ���޸ĵ�Ԫ��
		{
			temp->data;
		}
	}
}

int main()
{
	struct Node* buff = NULL;
	buff = init();
	printf("%#p\n", buff);
	insert(buff, 1);
	insert(buff, 2);
	insert(buff, 3);
	insert(buff, 3);
	insert(buff, 4);
	insert(buff, 5);
	insert(buff, 6);
	insert(buff, 3);
	ListDelete(buff, 3);
	list_print(buff);
}