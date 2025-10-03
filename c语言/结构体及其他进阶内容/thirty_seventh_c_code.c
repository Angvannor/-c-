#include <stdio.h>
#include <stdlib.h>

// 1. 定义结构体
typedef struct {
    int id;
    float score;
} Student;

int main() {
    // ========== 写入部分 ==========
    FILE *fp = fopen("data.bin", "wb");
    if (fp == NULL) {
        perror("打开文件失败");
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

    // 先写入数量
    fwrite(&student_count, sizeof(int), 1, fp);
    // 再写入数组
    fwrite(students, sizeof(Student), student_count, fp);

    fclose(fp); // 写入完毕

    // ========== 读取部分 ==========
    fp = fopen("data.bin", "rb");
    if (fp == NULL) {
        perror("打开文件失败");
        return 1;
    }

    int loaded_count;
    Student loaded_students[10]; // 存放读取结果

    // 先读数量
    fread(&loaded_count, sizeof(int), 1, fp);
    // 再读数组
    fread(loaded_students, sizeof(Student), loaded_count, fp);

    fclose(fp); // 读取完毕

    // 输出检查
    printf("读取到 %d 个学生:\n", loaded_count);
    for (int i = 0; i < loaded_count; i++) {
        printf("ID: %d, Score: %.1f\n", loaded_students[i].id, loaded_students[i].score);
    }

    return 0;
}
