#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "Header1.h"
int compareNames(const void *a, const void *b) {
	return strcmp(((ChildInfo *)a)->name, ((ChildInfo *)b)->name);
}

// Функция для выделения памяти под массив детей
ChildInfo* allocateMemoryForChildren(int numChildren) {
	ChildInfo *children = (ChildInfo *)malloc(numChildren * sizeof(ChildInfo));
	if (children == NULL) {
		printf("Ошибка выделения памяти\n");
		exit(1);
	}
	return children;
}

// Функция для ввода информации о детях
void inputChildrenInfo(ChildInfo *children, int numChildren) {
	for (int i = 0; i < numChildren; i++) {
		printf("Введите фамилию ребенка %d: ", i + 1);
		fgets((*(children + i)).name, MAX_NAME_LENGTH, stdin);
		(*(children + i)).name[strcspn((*(children + i)).name, "\n")] = '\0'; // Удаление символа новой строки

		printf("Введите заболевание ребенка %s: ", (*(children + i)).name);
		fgets((*(children + i)).illness.disease, MAX_DISEASE_LENGTH, stdin);
		(*(children + i)).illness.disease[strcspn((*(children + i)).illness.disease, "\n")] = '\0';

		printf("Введите лечащего врача ребенка %s: ", (*(children + i)).name);
		fgets((*(children + i)).illness.hospitalInfo.doctor, MAX_DOCTOR_LENGTH, stdin);
		(*(children + i)).illness.hospitalInfo.doctor[strcspn((*(children + i)).illness.hospitalInfo.doctor, "\n")] = '\0';

		// Проверка на наличие больницы (если ребенок находился в больнице)
		if (strcmp((*(children + i)).illness.disease, "Грипп") == 0 || strcmp((*(children + i)).illness.disease, "Ангина") == 0) {
			printf("Введите номер больницы, в которой находился ребенок %s: ", (*(children + i)).name);
			fgets((*(children + i)).illness.hospitalInfo.hospital, MAX_HOSPITAL_LENGTH, stdin);
			(*(children + i)).illness.hospitalInfo.hospital[strcspn((*(children + i)).illness.hospitalInfo.hospital, "\n")] = '\0';
		}
	}
}

// Функция для копирования данных из одного массива в другой
void copyChildrenInfo(ChildInfo *src, ChildInfo *dest, int numChildren) {
	for (int i = 0; i < numChildren; i++) {
		strcpy(dest->name, src->name);
		strcpy(dest->illness.disease, src->illness.disease);
		strcpy(dest->illness.hospitalInfo.doctor, src->illness.hospitalInfo.doctor);
		strcpy(dest->illness.hospitalInfo.hospital, src->illness.hospitalInfo.hospital);

		src++;
		dest++;
	}
}

// Функция для вывода таблицы с информацией о детях
void printChildTable(ChildInfo *children, int numChildren) {
	printf("+-------------------+----------------------+----------------------+----------------------+\n");
	printf("|      Фамилия      |      Заболевание     |      Лечащий врач    |      Номер больницы  |\n");
	printf("+-------------------+----------------------+----------------------+----------------------+\n");

	for (int i = 0; i < numChildren; i++) {
		printf("| %-17s | %-20s | %-20s | %-20s |\n",
			(*(children + i)).name, (*(children + i)).illness.disease,
			(*(children + i)).illness.hospitalInfo.doctor, (*(children + i)).illness.hospitalInfo.hospital);
	}

	printf("+-------------------+----------------------+----------------------+----------------------+\n");
}

// Функция для поиска детей с определенным заболеванием
void searchByDisease(ChildInfo *children, int numChildren) {
	char searchDisease[MAX_DISEASE_LENGTH];
	printf("Введите название болезни: ");
	fgets(searchDisease, MAX_DISEASE_LENGTH, stdin);
	searchDisease[strcspn(searchDisease, "\n")] = '\0'; // Удаление символа новой строки

	printf("Дети с болезнью \"%s\":\n", searchDisease);
	printf("+-------------------+----------------------+----------------------+\n");
	printf("|      Фамилия      |      Лечащий врач    |      Номер больницы  |\n");
	printf("+-------------------+----------------------+----------------------+\n");

	for (int i = 0; i < numChildren; i++) {
		if (strcmp((*(children + i)).illness.disease, searchDisease) == 0) {
			printf("| %-17s | %-20s | %-20s |\n",
				(*(children + i)).name, (*(children + i)).illness.hospitalInfo.doctor, (*(children + i)).illness.hospitalInfo.hospital);
		}
	}

	printf("+-------------------+----------------------+----------------------+\n");
}
