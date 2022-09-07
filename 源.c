//#define _CRT_SECURE_NO_WARNINGS
////单链表为一种线性数据结构，包括数据域与指针域，由头结点，首元节点，一般节点，尾节点组成
////头结点一般数据域为0，尾节点的指针域为null,首元节点为包含有效数据域的头一个节点，一般为头结点后面的第一个节点
////单链表的物理地址不是连续的，所以不能使用+1啥的，不行！！！！
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct Node
//{
//	int data;
//    N* next;
//}N;
////单链表元素的增加
//
////初始化单链表
////指针函数
//N* init()
//{
//	N* temp = (N*)malloc(sizeof(N));
//	if (temp == NULL)
//	{
//		printf("内存申请失败\n");
//		return NULL;
//	}
//	temp->data = 0;
//	temp->next = NULL;
//	printf("%#p", temp);
//	return temp;//temp的空间被释放了，但是temp值里保存着申请函数的值，谁接受了该返回值就可以调用内部函数进行申请函数
//}
//
//
//
////单链表元素的打印
//
////单链表元素的删除
//
////单链表元素的修改
//
//
//int main()
//{
//	N* buff = NULL;
//	buff = init();
//	printf("%#p", buff);
//}