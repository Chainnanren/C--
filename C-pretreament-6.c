//�����ж���
/*���C�ı������ṩ��һ���������������������ж�����š���������������̡����磺�����Ǹ���ͬһ
��Դ�ļ�Ҫ�������ͬ��һ������Ĳ�ͬ�汾��ʱ����������е��ô������ٶ�ĳ������������һ��ĳ��
���ȵ����飬��������ڴ����ޣ�������Ҫһ����С�����飬������һ�������ڴ��д��������Ҫһ������
�ܹ���д��*/

//��������
//�ڱ���һ�������ʱ���������Ҫ��һ����䣨һ����䣩������߷����Ǻܷ���ġ���Ϊ��������������ָ��
#include<stdio.h>
#define DEBUG
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	for (i = 0; i < 10; i++) {
		arr[i] = 0;
#ifdef DEBUG
		printf("%d\n", arr[i]);
#endif
	}
	return 0;
}


//��������ָ��

/* #if �������ʽ (���磺0,1��1-1)
	//....
	#endif*/
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	for (i = 0; i < 10; i++) {
		arr[i] = 0;
#if 1
	printf("%d\n", arr[i]);
#endif
	}
	return 0;
}

/*�����֧����������
	#if
	#elif
	#else
	#endif*/
int main() {
#if 1==1
	printf("haha\n");
#elif 2==1
	printf("hehe\n");
#else
	printf("�ٺ�");
#endif
}

/*�ж��Ƿ񱻶���*/
int main() {
#if defined(DEUBG)//������
	printf("hehe\n");
#endif


#if !defined(DEUBG)//û����
	printf("hehe\n");
#endif

/*#ifdef DEBUG
	printf("hehe\n");
#endif*/

/*#ifndef DEBUG    -    û����
printf("hehe\n");
#endif*/
	return 0;
}

/*Ƕ��ָ��*/
#if defined(QS_UNIX)
	#ifdef OPTION1
		n1();
	#endif
	#ifdef OPTION2
		n2;
	#endif
#elif defined(QS_UNIX)
	#ifdef OPTION2
		n2();
	#endif
#endif


//�ļ�����
/*�����滻��ʽ�ܼ򵥣�Ԥ��������ɾ������ָ����ð����ļ��������滻������һ��Դ�ļ�������
10�Σ��Ǿ�ʵ�ʱ�����10��*/

/*ͷ�ļ�����
	1.�����ļ�����
	#include "filename"
	���Ҳ��ԣ�����Դ�ļ�����Ŀ¼�²��ң������ͷ�ļ�δ�ҵ���������������ҿ⺯��ͷ�ļ�һ���ڱ�
	׼λ�ò���ͷ�ļ�������Ҳ�������ʾ����ʧ�ܡ�

	2.���ļ�����
	#include<filename.h>
	����ͷ�ļ�ֱ��ȥ��׼·����ȥ���ң�����Ҳ�������ʾ����ʧ��*/
	

//����ͷ�ļ����������
//����һ��
#ifndef __TEST_H__
#define __TEST_H__
		int Add(int x, int y);
#endif

//��������
#pragma once
		int Add(int x, int y);

/*Ԥ����׶����õ���ָ�� - Ԥ����ָ��
  1.��������ָ��
  2.#include
  3.#define
  ...*/