#include <stdio.h>
#include <string.h>

// 1. 定义 Student 结构体
typedef struct {
    int id;
    char name[50];
    float score;
} Student;

// 2. 结构体数组：存储学生数据
#define MAX_STUDENTS 3
Student students[MAX_STUDENTS];
int student_count = 0;

// 填充学生数据（演示如何操作结构体数组）
void setup_data() {
    // 使用 . 运算符访问结构体数组的成员
    students[0].id = 101;
    strcpy(students[0].name, "张三");
    students[0].score = 85.5;

    students[1].id = 102;
    strcpy(students[1].name, "李四");
    students[1].score = 92.0;
    
    students[2].id = 103;
    strcpy(students[2].name, "王五");
    students[2].score = 78.8;

    student_count = MAX_STUDENTS;
}

// 3. 按 ID 查找学生：返回结构体指针，使用 -> 运算符
Student* find_student_by_id(int id) {
    for (int i = 0; i < student_count; i++) {
        // 获取数组元素（一个结构体）的地址，赋给指针 s_ptr
        Student* s_ptr = &students[i]; 
        
        // *** 重点：使用 -> 运算符访问指针指向的结构体成员 ***
        // s_ptr->id 等价于 (*s_ptr).id
        if (s_ptr->id == id) { 
            return s_ptr; // 返回指向该结构体的指针
        }
    }
    return NULL; // 未找到
}

int main() {
    setup_data();
    printf("--- 数据初始化完成 ---\n");

    printf("\n--- 查找学生 (ID: 102) ---\n");
    Student* found = find_student_by_id(102);
    
    if (found != NULL) {
        // 通过指针和 -> 运算符打印成员信息
        printf("找到学生 (指针访问): ID: %d, 姓名: %s, 分数: %.2f\n", 
               found->id, found->name, found->score);
               
        // 通过指针修改数据（证明指针直接指向了原数组元素）
        printf("--- 通过指针将李四的分数改为 100.0 ---\n");
        found->score = 100.0;
        
        printf("修改后的分数 (通过指针访问): %.2f\n", found->score);
    } else {
        printf("未找到目标 ID 的学生。\n");
    }

    printf("\n--- 验证原数组数据已被修改 ---\n");
    // 直接访问原数组元素，可以看到分数已变为 100.0
    printf("数组 students[1] 的分数: %.2f\n", students[1].score);

    return 0;
}