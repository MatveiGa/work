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
	setlocale(LC_ALL, "rus"); // Установка русской локализации
	int numChildren;
	printf("Введите количество детей в детском саду: ");
	scanf("%d", &numChildren);
	getchar(); // Очистка буфера
	// Выделение памяти под массив детей
	ChildInfo *children = allocateMemoryForChildren(numChildren);
	// Ввод информации о детях
	inputChildrenInfo(children, numChildren);
	// Сортировка детей по алфавиту
	qsort(children, numChildren, sizeof(ChildInfo), compareNames);
	// Вывод информации о детях в виде таблицы
	printChildTable(children, numChildren);
	// Вызов функции для поиска детей с определенным заболеванием
	searchByDisease(children, numChildren);
	// Освобождение выделенной памяти
	free(children);
	return 0;
}