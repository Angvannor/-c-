#include <stdio.h>
#include <string.h>

// --- 结构体struct定义 ---
typedef struct{
  char name[50];
  int id;
  float score;
} Student;

// --- 全局变量（数据存储） ---
#define MAX_STUDENTS 100
Student students[MAX_STUDENTS];
int student_count = 0;

// --- 函数声明 ---
int add_student(char *name,int id,float score);
void list_all_students();
int delete_student(int id_to_delete);
int save_data();
int load_data();
void display_menu();

// --- 函数实现 ---

int add_student(char *name,int id,float score){
  if(student_count >= MAX_STUDENTS){
    printf("错误：学生记录已满，无法再添加新学生！\n");
    return -1;
  }

  // 数据赋值：使用 strcpy 复制字符串
  strcpy(students[student_count].name,name);
  students[student_count].id = id;
  students[student_count].score = score;

  student_count++;
  printf("成功添加学生：%s (ID: %d)\n",name,id);
  return 0;
}

void list_all_students(){
  printf("\n--- 学生列表 (%d 名学生) ---\n",student_count);
  if(student_count == 0){
    printf("目前没有学生记录。\n");
    return;
  }

  for(int i = 0;i < student_count;i++){
    printf("ID: %d | 姓名：%s | 分数： %.2f\n",students[i].id,students[i].name,students[i].score);
    return;
  }
  printf("-----------------------------------\n");
}

int delete_student(int id_to_delete){
  int found_index = -1;

  // 1.查找学生 ID
  for(int i = 0;i < student_count;i++){
    if(students[i].id == id_to_delete){
      found_index = i;
      break;
    }
  }

  if(found_index == -1){
    printf("错误：未找到 ID 为 %d 的学生记录。\n",id_to_delete);
    return -1;
  }

  // 2.数组移动（向前覆盖）
  for(int j =found_index;j < student_count - 1;j++){
    students[j] = students[j+1];
  }

  // 3.更新计时器
  student_count--;

  printf("成功删除 ID 为 %d 的学生记录。\n",id_to_delete);
  return 0;
}

int save_data(){
  FILE *fp = fopen("students.txt","w");
  if(fp == NULL){
    printf("错误:无法打开文件进行写入！\n");
    return -1;
  }

  for(int i = 0;i < student_count;i++){
    // 格式： 姓名，ID，分数 + 换行符
    fprintf(fp,"%s,%d,%.2f\n",students[i].name,students[i].id,students[i].score);
  }

  fclose(fp);
  printf("成功保存 %d 条学生记录到 students.txt。\n",student_count);
  return 0;
}

int load_data(){
  student_count = 0; // 重置计数器

  FILE *fp = fopen("student.txt","r");
  if(fp == NULL){
    //如果文件不存在，可以认为是程序第一次运行，不报错
    return 0;
  }

  Student temp_student;

  // 读取数据：%[^,] 读取到逗号，%d 读取整数，%f 读取浮点数
  while(fscanf(fp,"%[^,],%d,%f\n",temp_student.name,&temp_student.id,&temp_student.score)==3){
    // 结构体赋值
    students[student_count] = temp_student;
    student_count++;
  }

  fclose(fp);
  printf("成功加载 %d 条学生记录。\n",student_count);
  return 0;
}

void display_menu() {
    printf("\n--- 学生管理系统 ---\n");
    printf("1. 添加学生\n");
    printf("2. 查看所有学生\n");
    printf("3. 删除学生\n");
    printf("4. 保存并退出\n");
    printf("----------------------\n");
    printf("请选择操作 (1-4): ");
}

int main(){
  int choice;
  int id,id_to_delete;
  float score;
  char name[50];

  load_data();

  do{
    display_menu();
    if(scanf("%d",&choice) != 1){
      //处理输入错误
      while(getchar() != 1);
      choice = 0;
      continue;
    }

    switch (choice) {
            case 1:
                printf("输入姓名: ");
                scanf("%s", name);
                printf("输入ID: ");
                scanf("%d", &id);
                printf("输入分数: ");
                scanf("%f", &score);
                add_student(name, id, score);
                break;
            case 2:
                list_all_students();
                break;
            case 3:
                printf("输入要删除的ID: ");
                scanf("%d", &id_to_delete);
                delete_student(id_to_delete);
                break;
            case 4:
                save_data();
                printf("程序退出，数据已保存。\n");
                break;
            default:
                printf("无效选择，请重新输入。\n");
        }
    } while (choice != 4);

    return 0;
}
