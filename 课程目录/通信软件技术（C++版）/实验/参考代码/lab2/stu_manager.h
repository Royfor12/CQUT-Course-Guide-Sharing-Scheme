#pragma once
#ifndef STU_MANAGER_H
#define STU_MANAGER_H

#define MAX_STUDENTS 1000
#define FILENAME "students.txt"

typedef struct {
    char id[20];           // 学号
    char name[50];         // 姓名
    char gender;           // 性别 (M/F)
    char major[50];        // 专业
    char class_name[20];   // 班级
    float math_score;      // 高数成绩
    float english_score;   // 英语成绩
    float political_score; // 思政成绩
    float total_score;     // 总成绩
} Student;

void stuManagerMain();

// 函数声明
void loadStudents();
void saveStudents();
void addStudent();
void deleteStudent();
void modifyStudent();
void searchStudent();
void displayAllStudents();
void sortStudents();
int findStudentIndex(const char* id);
void displayStudentDetails(Student s);
void clearInputBuffer();
void calculateTotalScore(Student *s);


#endif  // !STU_MANAGER_H