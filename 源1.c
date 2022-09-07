#define _CRT_SECURE_NO_WARNINGS
//单链表为一种线性数据结构，包括数据域与指针域，由头结点，首元节点，一般节点，尾节点组成
//头结点一般数据域为0，尾节点的指针域为null,首元节点为包含有效数据域的头一个节点，一般为头结点后面的第一个节点
//单链表的物理地址不是连续的，所以不能使用+1啥的，不行！！！！
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
//单链表元素的增加

//初始化单链表
//指针函数
struct Node * init()
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	if (temp == NULL)
	{
		printf("内存申请失败\n");
		return NULL;
	}
	temp->data = 0;
	temp->next = NULL;
	printf("%#p\n", temp);
	return temp;//temp的空间被释放了，但是temp值里保存着申请函数的值，谁接受了该返回值就可以调用内部函数进行申请函数,但地址还是一样的
}


//元素的插入
//头插法   
//一般插入的节点在头节点的后面，也就是头结点不变，所以buff的指向不变
void insert(struct Node*list,int val)//val代表插入的数据，list接收要插入元素的地址
{
	//1.生成新节点
	//2.先去让新欢的指针去找旧爱
	//3.再让头结点链接新欢

	//生成新节点
	struct Node* New =(struct Node*)malloc(sizeof(struct Node));
	
	if (New != NULL)
	{
		New->data = val;
		//原来的首元节点的地址为：  list->next（一般这样的形式有两个一个代表list结构体里的数据，如若next有有指向的目标，则就也代表指向物体的首地址）
	New->next = list->next;//list->next这里代表旧首元节点的地址,New->next代表的为New的指针域
	//更新头结点的指针
	list->next = New;//如果是插入第一个首元节点也是可以这样用的，这样list-next为NULL的
	}
	else
    printf("内存获取失败\n");
}

//单链表元素的打印

void list_print(struct Node*list)
{
	//头节点还是不要乱动，回不来
	struct Node* p = list->next;//p指向首元节点
	while (p != NULL)
	{
		printf("%d->", p->data);
		//p++是错误的
		//p指向下一个节点
		p = p->next;
	}
	printf("NULL\n\n");


}
//单链表元素的删除
//1.目标节点的前面一个节点为前驱节点，后面一个为后继节点,相对目的节点而言的
//先让前驱节点的next的指向为后继节点，再释放目的节点
void ListDelete(struct Node*list,int val)
{
	//需要两个变量，一个为p1一个为p2,p1为目的节点，p2为前驱节点
	struct Node* p2 = list;//指向头结点
	struct Node* p1 = p2;//p1是p2的后继节点
	while (p2->next!=NULL)//什么情况下可以结束循环
	{
		if (p2->next->data == val)
		{
			p1 = p2->next;//p1指向目标节点
			p2->next = p1->next;//p1的后继节点的地址给向前驱节点
			free(p1);//释放要被删除的节点
		}
		else
		{
			p2 = p2->next;
		}
	}
}

//单链表元素的修改  指定值进行修改元素
void list_change(struct Node* list, int data)
{
	for (struct Node* temp = list->next; temp != NULL; temp = temp->next)
	{
		if (temp->data == val)//找到要被修改的元素
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