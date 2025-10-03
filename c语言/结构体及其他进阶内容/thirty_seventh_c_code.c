#include <stdio.h>
#include <stdlib.h>

// 1. ����ṹ��
typedef struct {
    int id;
    float score;
} Student;

int main() {
    // ========== д�벿�� ==========
    FILE *fp = fopen("data.bin", "wb");
    if (fp == NULL) {
        perror("���ļ�ʧ��");
        return 1;
    }

    Student students[5] = {
        {1, 95.5},
        {2, 88.0},
        {3, 76.5},
        {4, 92.0},
        {5, 60.5}
    };
    int student_count = 5;

    // ��д������
    fwrite(&student_count, sizeof(int), 1, fp);
    // ��д������
    fwrite(students, sizeof(Student), student_count, fp);

    fclose(fp); // д�����

    // ========== ��ȡ���� ==========
    fp = fopen("data.bin", "rb");
    if (fp == NULL) {
        perror("���ļ�ʧ��");
        return 1;
    }

    int loaded_count;
    Student loaded_students[10]; // ��Ŷ�ȡ���

    // �ȶ�����
    fread(&loaded_count, sizeof(int), 1, fp);
    // �ٶ�����
    fread(loaded_students, sizeof(Student), loaded_count, fp);

    fclose(fp); // ��ȡ���

    // ������
    printf("��ȡ�� %d ��ѧ��:\n", loaded_count);
    for (int i = 0; i < loaded_count; i++) {
        printf("ID: %d, Score: %.1f\n", loaded_students[i].id, loaded_students[i].score);
    }

    return 0;
}
