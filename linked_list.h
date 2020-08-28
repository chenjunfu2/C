#pragma once

#ifndef LINKED_LIST
#define LINKED_LIST
#include "error.h"

//���ݽṹ��
typedef struct Queue {
	Queue* uQueue;//��һ�ڵ�
	int list_x;//�ƶ�����x
	int list_y;//�ƶ�����y
	int list_n;//�ƶ�����n
	Queue* nQueue;//��һ�ڵ�
}QUEUE;

//����ָ��ṹ��
typedef struct Node {
	QUEUE* hpQueue = nullptr;//ͷ�ڵ�ָ��
	QUEUE* cpQueue = nullptr;//β�ڵ�ָ��
	//int numQueue;//�������
}NODE;


//���һ��
inline ERR Add_CpQueue(NODE* node, int list_x, int list_y, int list_n)
{
	ERR error;

	QUEUE* npQueue = nullptr;
	try {
		npQueue = new (QUEUE);
	}
	catch (bad_alloc&) {
		no_good(error, new_failed);
		return error;
	}

	npQueue->uQueue = node->cpQueue;
	npQueue->nQueue = nullptr;

	npQueue->list_x = list_x;
	npQueue->list_y = list_y;
	npQueue->list_n = list_n;

	if (node->hpQueue == nullptr)
		node->hpQueue = npQueue;

	node->cpQueue = npQueue;

	return error;
}

//ɾ��һ��
inline ERR Del_CpQueue(NODE* node, int& list_x, int& list_y, int& list_n)
{
	ERR error;

	if (node->cpQueue == nullptr)
	{
		no_good(error, cpQueue_Null);
		return error;
	}
		
	list_x = node->cpQueue->list_x;
	list_y = node->cpQueue->list_y;
	list_n = node->cpQueue->list_n;

	QUEUE* delQueue = node->cpQueue;
	node->cpQueue = node->cpQueue->uQueue;
	try {
		delete delQueue;
	}
	catch (...) {
		no_good(error, delete_failed);
		return error;
	}

	delQueue = nullptr;
	if (node->cpQueue == nullptr)
		node->hpQueue = nullptr;

	return error;
}

//ɾ������
inline ERR Del_AllQueue(NODE* node)
{
	ERR error;
	if (node->hpQueue == nullptr)
		return error;

	QUEUE* delQueue = node->hpQueue;

	while (delQueue != nullptr)
	{
		node->hpQueue = node->hpQueue->nQueue;
		try {
			delete delQueue;
		}
		catch (...) {
			no_good(error, delete_failed);
			return error;
		}
		delQueue = node->hpQueue;
	}

	node->cpQueue = node->hpQueue = nullptr;

	return error;
}


#endif