#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Header.h"
#define MAX_NAME_LENGTH 50
#define MAX_DISEASE_LENGTH 20
#define MAX_HOSPITAL_LENGTH 50
#define MAX_DOCTOR_LENGTH 50
int main() {
	setlocale(LC_ALL, "rus"); // ��������� ������� �����������
	int numChildren;
	printf("������� ���������� ����� � ������� ����: ");
	scanf("%d", &numChildren);
	getchar(); // ������� ������
	// ��������� ������ ��� ������ �����
	ChildInfo *children = allocateMemoryForChildren(numChildren);
	// ���� ���������� � �����
	inputChildrenInfo(children, numChildren);
	// ���������� ����� �� ��������
	qsort(children, numChildren, sizeof(ChildInfo), compareNames);
	// ����� ���������� � ����� � ���� �������
	printChildTable(children, numChildren);
	// ����� ������� ��� ������ ����� � ������������ ������������
	searchByDisease(children, numChildren);
	// ������������ ���������� ������
	free(children);
	return 0;
}