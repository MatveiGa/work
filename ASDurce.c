#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "Header1.h"
int compareNames(const void *a, const void *b) {
	return strcmp(((ChildInfo *)a)->name, ((ChildInfo *)b)->name);
}

// ������� ��� ��������� ������ ��� ������ �����
ChildInfo* allocateMemoryForChildren(int numChildren) {
	ChildInfo *children = (ChildInfo *)malloc(numChildren * sizeof(ChildInfo));
	if (children == NULL) {
		printf("������ ��������� ������\n");
		exit(1);
	}
	return children;
}

// ������� ��� ����� ���������� � �����
void inputChildrenInfo(ChildInfo *children, int numChildren) {
	for (int i = 0; i < numChildren; i++) {
		printf("������� ������� ������� %d: ", i + 1);
		fgets((*(children + i)).name, MAX_NAME_LENGTH, stdin);
		(*(children + i)).name[strcspn((*(children + i)).name, "\n")] = '\0'; // �������� ������� ����� ������

		printf("������� ����������� ������� %s: ", (*(children + i)).name);
		fgets((*(children + i)).illness.disease, MAX_DISEASE_LENGTH, stdin);
		(*(children + i)).illness.disease[strcspn((*(children + i)).illness.disease, "\n")] = '\0';

		printf("������� �������� ����� ������� %s: ", (*(children + i)).name);
		fgets((*(children + i)).illness.hospitalInfo.doctor, MAX_DOCTOR_LENGTH, stdin);
		(*(children + i)).illness.hospitalInfo.doctor[strcspn((*(children + i)).illness.hospitalInfo.doctor, "\n")] = '\0';

		// �������� �� ������� �������� (���� ������� ��������� � ��������)
		if (strcmp((*(children + i)).illness.disease, "�����") == 0 || strcmp((*(children + i)).illness.disease, "������") == 0) {
			printf("������� ����� ��������, � ������� ��������� ������� %s: ", (*(children + i)).name);
			fgets((*(children + i)).illness.hospitalInfo.hospital, MAX_HOSPITAL_LENGTH, stdin);
			(*(children + i)).illness.hospitalInfo.hospital[strcspn((*(children + i)).illness.hospitalInfo.hospital, "\n")] = '\0';
		}
	}
}

// ������� ��� ����������� ������ �� ������ ������� � ������
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

// ������� ��� ������ ������� � ����������� � �����
void printChildTable(ChildInfo *children, int numChildren) {
	printf("+-------------------+----------------------+----------------------+----------------------+\n");
	printf("|      �������      |      �����������     |      ������� ����    |      ����� ��������  |\n");
	printf("+-------------------+----------------------+----------------------+----------------------+\n");

	for (int i = 0; i < numChildren; i++) {
		printf("| %-17s | %-20s | %-20s | %-20s |\n",
			(*(children + i)).name, (*(children + i)).illness.disease,
			(*(children + i)).illness.hospitalInfo.doctor, (*(children + i)).illness.hospitalInfo.hospital);
	}

	printf("+-------------------+----------------------+----------------------+----------------------+\n");
}

// ������� ��� ������ ����� � ������������ ������������
void searchByDisease(ChildInfo *children, int numChildren) {
	char searchDisease[MAX_DISEASE_LENGTH];
	printf("������� �������� �������: ");
	fgets(searchDisease, MAX_DISEASE_LENGTH, stdin);
	searchDisease[strcspn(searchDisease, "\n")] = '\0'; // �������� ������� ����� ������

	printf("���� � �������� \"%s\":\n", searchDisease);
	printf("+-------------------+----------------------+----------------------+\n");
	printf("|      �������      |      ������� ����    |      ����� ��������  |\n");
	printf("+-------------------+----------------------+----------------------+\n");

	for (int i = 0; i < numChildren; i++) {
		if (strcmp((*(children + i)).illness.disease, searchDisease) == 0) {
			printf("| %-17s | %-20s | %-20s |\n",
				(*(children + i)).name, (*(children + i)).illness.hospitalInfo.doctor, (*(children + i)).illness.hospitalInfo.hospital);
		}
	}

	printf("+-------------------+----------------------+----------------------+\n");
}
