#pragma once
#define MAX_NAME_LENGTH 50
#define MAX_DISEASE_LENGTH 20
#define MAX_HOSPITAL_LENGTH 50
#define MAX_DOCTOR_LENGTH 50
#define _CRT_SECURE_NO_WARNINGS
#ifndef Header1_h
typedef union {
	struct {
		char hospital[MAX_HOSPITAL_LENGTH];
		char doctor[MAX_DOCTOR_LENGTH];
	} hospitalInfo;
	char disease[MAX_DISEASE_LENGTH];
} IllnessInfo;

// Структура для хранения информации о ребенке
typedef struct {
	char name[MAX_NAME_LENGTH];
	IllnessInfo illness;
} ChildInfo;
#endif