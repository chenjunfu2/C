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
	QUEUE* hpQueue = NULL;//ͷ�ڵ�ָ��
	QUEUE* cpQueue = NULL;//β�ڵ�ָ��
	//int numQueue;//�������
}NODE;


//��β�����һ��
inline ERR Add_CpQueue(NODE& node, int list_x, int list_y, int list_n)
{
	ERR error;

	QUEUE* npQueue = NULL;
	try {
		npQueue = new (QUEUE);
	}
	catch (bad_alloc&) {
		no_good(error, new_failed, Add_CpQueue_F);
		return error;
	}

	npQueue->uQueue = node.cpQueue;
	npQueue->nQueue = NULL;

	npQueue->list_x = list_x;
	npQueue->list_y = list_y;
	npQueue->list_n = list_n;

	if (node.hpQueue == NULL)
		node.hpQueue = npQueue;

	node.cpQueue = npQueue;

	return error;
}

//��β��ɾ��һ��
inline ERR Del_CpQueue(NODE& node, int& list_x, int& list_y, int& list_n)
{
	ERR error;

	if (node.cpQueue == NULL)
	{
		no_good(error, cpQueue_Null, Del_CpQueue_F);
		return error;
	}
		
	list_x = node.cpQueue->list_x;
	list_y = node.cpQueue->list_y;
	list_n = node.cpQueue->list_n;

	QUEUE* delQueue = node.cpQueue;
	node.cpQueue = node.cpQueue->uQueue;
	try {
		delete delQueue;
	}
	catch (...) {
		no_good(error, delete_failed, Del_CpQueue_F);
		return error;
	}

	delQueue = NULL;
	if (node.cpQueue == NULL)
		node.hpQueue = NULL;

	return error;
}

//�鿴β��һ��
inline ERR See_CpQueue(const NODE& node, int& list_x, int& list_y, int& list_n)
{
	ERR error;

	if (node.cpQueue == NULL)
	{
		no_good(error, cpQueue_Null, Find_CpQueue_F);
		return error;
	}

	list_x = node.cpQueue->list_x;
	list_y = node.cpQueue->list_y;
	list_n = node.cpQueue->list_n;

	return error;
}

//ɾ������
inline ERR Del_AllQueue(NODE& node)
{
	ERR error;
	if (node.hpQueue == NULL)
		return error;

	QUEUE* delQueue = node.hpQueue;

	while (delQueue != NULL)
	{
		node.hpQueue = node.hpQueue->nQueue;
		try {
			delete delQueue;
		}
		catch (...) {
			no_good(error, delete_failed, Del_AllQueue_F);
			return error;
		}
		delQueue = node.hpQueue;
	}

	node.cpQueue = node.hpQueue = NULL;

	return error;
}


//������ȡ������
inline ERR See_All(NODE& node, bool(&fSee_P)(int&, int&, int&))
{
	ERR error;
	if (node.hpQueue == NULL)
	{
		no_good(error, hpQueue_Null, See_All_F);
		return error;
	}

	QUEUE* seeQueue = node.hpQueue;

	while (seeQueue != NULL)
	{
		if (fSee_P(seeQueue->list_x, seeQueue->list_y, seeQueue->list_n))
			seeQueue = seeQueue->nQueue;
		else
			break;
	}

	return error;
}

//������ӣ�����
inline ERR Add_All(NODE& node, bool(&fAdd_P)(int&, int&, int&))
{
	ERR error;
	if (node.hpQueue != NULL)
	{
		no_good(error, hpQueue_Have, Add_All_F);
		return error;
	}

	int list_x(0), list_y(0), list_n(0);

	while (fAdd_P(list_x, list_y, list_n))
	{
		if ((error = Add_CpQueue(node, list_x, list_y, list_n)).no_good)
			break;
	}

	return error;
}

//��nodeOβ���ڵ��ƶ���nodeIβ���ڵ�
inline ERR Move_CpQueue_To_CpQueue(NODE& nodeI, NODE& nodeO)
{
	ERR error;
	
	if (nodeO.cpQueue == NULL)
	{
		no_good(error, cpQueue_Null, Move_CpQ_To_CpQ_F);
		return error;
	}

	//ɾ��
	QUEUE* MovQueue = nodeO.cpQueue;
	nodeO.cpQueue = nodeO.cpQueue->uQueue;
	if (nodeO.cpQueue == NULL)
		nodeO.hpQueue = NULL;


	//���
	MovQueue->uQueue = nodeI.cpQueue;
	MovQueue->nQueue = NULL;

	if (nodeI.hpQueue == NULL)
		nodeI.hpQueue = MovQueue;

	nodeI.cpQueue = MovQueue;

	return error;


	/*
	if (nodeO.cpQueue == NULL)
		return error;

	QUEUE* QueSave = nodeO.cpQueue;

	nodeO.cpQueue->nQueue = NULL;
	nodeO.cpQueue = nodeO.cpQueue->uQueue;
	if (nodeO.cpQueue == NULL)
		nodeO.hpQueue = NULL;

	QueSave->uQueue = nodeI.cpQueue;
	nodeI.cpQueue = QueSave;
	if (nodeI.cpQueue != NULL)
		nodeI.cpQueue->nQueue = QueSave;
	if (nodeI.hpQueue == NULL)
		nodeI.hpQueue = QueSave;*/
	//nodeI.cpQueue = QueSave;
}

#endif