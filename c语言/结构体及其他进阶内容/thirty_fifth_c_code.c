#include <stdio.h>
#include <string.h>

// 1. ���� Student �ṹ��
typedef struct {
    int id;
    char name[50];
    float score;
} Student;

// 2. �ṹ�����飺�洢ѧ������
#define MAX_STUDENTS 3
Student students[MAX_STUDENTS];
int student_count = 0;

// ���ѧ�����ݣ���ʾ��β����ṹ�����飩
void setup_data() {
    // ʹ�� . ��������ʽṹ������ĳ�Ա
    students[0].id = 101;
    strcpy(students[0].name, "����");
    students[0].score = 85.5;

    students[1].id = 102;
    strcpy(students[1].name, "����");
    students[1].score = 92.0;
    
    students[2].id = 103;
    strcpy(students[2].name, "����");
    students[2].score = 78.8;

    student_count = MAX_STUDENTS;
}

// 3. �� ID ����ѧ�������ؽṹ��ָ�룬ʹ�� -> �����
Student* find_student_by_id(int id) {
    for (int i = 0; i < student_count; i++) {
        // ��ȡ����Ԫ�أ�һ���ṹ�壩�ĵ�ַ������ָ�� s_ptr
        Student* s_ptr = &students[i]; 
        
        // *** �ص㣺ʹ�� -> ���������ָ��ָ��Ľṹ���Ա ***
        // s_ptr->id �ȼ��� (*s_ptr).id
        if (s_ptr->id == id) { 
            return s_ptr; // ����ָ��ýṹ���ָ��
        }
    }
    return NULL; // δ�ҵ�
}

int main() {
    setup_data();
    printf("--- ���ݳ�ʼ����� ---\n");

    printf("\n--- ����ѧ�� (ID: 102) ---\n");
    Student* found = find_student_by_id(102);
    
    if (found != NULL) {
        // ͨ��ָ��� -> �������ӡ��Ա��Ϣ
        printf("�ҵ�ѧ�� (ָ�����): ID: %d, ����: %s, ����: %.2f\n", 
               found->id, found->name, found->score);
               
        // ͨ��ָ���޸����ݣ�֤��ָ��ֱ��ָ����ԭ����Ԫ�أ�
        printf("--- ͨ��ָ�뽫���ĵķ�����Ϊ 100.0 ---\n");
        found->score = 100.0;
        
        printf("�޸ĺ�ķ��� (ͨ��ָ�����): %.2f\n", found->score);
    } else {
        printf("δ�ҵ�Ŀ�� ID ��ѧ����\n");
    }

    printf("\n--- ��֤ԭ���������ѱ��޸� ---\n");
    // ֱ�ӷ���ԭ����Ԫ�أ����Կ��������ѱ�Ϊ 100.0
    printf("���� students[1] �ķ���: %.2f\n", students[1].score);

    return 0;
}