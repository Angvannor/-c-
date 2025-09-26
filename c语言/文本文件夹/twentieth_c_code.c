#include <stdio.h>
#include <stdlib.h>

// 这是一个简易的学生分数录入系统
// 函数：计算平均分
// 参数：grades[]存储分数的整型数组，count数组元素的数量
// 返回值：整数平均分
int caculate_average(int grades[], int count) {
  int sum = 0;
  //如果学生人数为0，直接返回0，避免除以0的错误
  if (count == 0) {
    return 0;
  }
  //循环累加所有分数
  for (int i = 0; i < count; i++) {
    sum += grades[i];
  }
  //返回总和除以人数的平均值
  return sum / count;
}

int main(){
  const char *filename = "student_grades.txt";
  FILE *student_grades_file;

  // --- 步骤 1：写入数据到文件 ---
  printf("正在向文件 '%s' 写入学生分数...\n", filename);
  // 以写入模式("w")打开文件，如果失败，则打印错误并退出
  student_grades_file = fopen(filename,"w");
  if(student_grades_file == NULL){
    perror("文件写入时打开失败!");
    return 1; // 返回非0值表示程序出错
  }
  // 向文件写入5名学生的姓名和分数
  fprintf(student_grades_file, "Alice: 85\n");
  fprintf(student_grades_file, "Bob: 90\n");
  fprintf(student_grades_file, "Charlie: 78\n");
  fprintf(student_grades_file, "Diana: 92\n");
  fprintf(student_grades_file, "Ethan: 88\n");

  // ！！！ 关键：写入完成后必须关闭文件，已保存更改
  fclose(student_grades_file);
  printf("学生分数已成功写入文件 '%s'.\n", filename);

  // --- 步骤 2：从文件读取数据 ---
  printf("正在从文件 '%s' 读取学生分数...\n", filename);
  // 以读取模式("r")打开文件，如果失败，则打印错误并退出
  student_grades_file = fopen(filename, "r");
  if (student_grades_file == NULL) {
    perror("文件读取时打开失败!");
    return 1;
  }

  int grades[5];
  int student_count = 0;
  // 循环读取文件，直到文件末尾或以读满5个学生
  // fscanf 会返回正确匹配和赋值的项数。我们期望它每次返回1(只读取一个整数)
  while(student_count < 5 && fscanf(student_grades_file,"%*[^:]: %d\n", &grades[student_count]) == 1) {
    student_count++;
  }

  // ！！！ 关键：读取完成后也要关闭文件
  fclose(student_grades_file);
  printf("已成功读取 %d 名学生的分数.\n", student_count);

  // --- 步骤 3：计算并显示平均分 ---
  printf("是否查看平均分？：1. 是  2. 否\n");
  int choice;
  // 获取用户输入
  scanf("%d", &choice);

  if (choice == 1) {
    // 调用函数计算平均分
    int average = caculate_average(grades, student_count);
    printf("学生平均分: %d\n", average);
  }else {
    printf("已退出查看平均分功能。\n");
  }
  return 0;
}