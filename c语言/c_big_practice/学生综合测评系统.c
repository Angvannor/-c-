#include <stdio.h>
#include <string.h>

typedef struct{
  int id;
  char name[50];
  char gender[10];
  char address[100];
  char contact_number[12];
  float chinese_score;
  float math_score;
  float english_score;
  float average_score;
  int rank;
  float daily_score;
  float comprehensive_score;
  int comprehensive_rank;
} Student;

#define MAX_STUDENTS 100
Student students[MAX_STUDENTS];
int student_count = 0;

/* prototypes */
int add_student(int id, char *name, char *gender, char *address, char *contact_number,
                float chinese_score, float math_score, float english_score, float daily_score);
int alter_student(int id, char *name, char *gender, char *address, char *contact_number,
                  float chinese_score, float math_score, float english_score, float daily_score);
int delete_student(int id_to_delete);
void query_student(int id_to_query);

float calculate_average_score(int index, float chinese_score, float math_score, float english_score);
void calculate_all_ranks(void);
float calculate_comprehensive_score(int index, float chinese_score, float math_score, float english_score, float daily_score);
void calculate_all_comprehensive_ranks(void);
int save_data(void);
void display_menu(void);

void trim_newline(char *s){
    size_t n = strlen(s);
    if(n > 0 && s[n-1] == '\n') s[n-1] = '\0';
}

int add_student(int id,char *name,char *gender,char *address,char *contact_number,float chinese_score,float math_score,float english_score,float daily_score){
  if(student_count >= MAX_STUDENTS){
    printf("错误：学生记录已满，无法再添加新学生！\n");
    return -1;
  }

  students[student_count].id = id;
  strncpy(students[student_count].name, name, sizeof(students[student_count].name)-1);
  students[student_count].name[sizeof(students[student_count].name)-1] = '\0';
  strncpy(students[student_count].gender, gender, sizeof(students[student_count].gender)-1);
  students[student_count].gender[sizeof(students[student_count].gender)-1] = '\0';
  strncpy(students[student_count].address, address, sizeof(students[student_count].address)-1);
  students[student_count].address[sizeof(students[student_count].address)-1] = '\0';
  strncpy(students[student_count].contact_number, contact_number, sizeof(students[student_count].contact_number)-1);
  students[student_count].contact_number[sizeof(students[student_count].contact_number)-1] = '\0';

  students[student_count].chinese_score = chinese_score;
  students[student_count].math_score = math_score;
  students[student_count].english_score = english_score;
  students[student_count].daily_score = daily_score;
  students[student_count].average_score = (chinese_score + math_score + english_score) / 3.0f;
  students[student_count].comprehensive_score = students[student_count].average_score * 0.8f + daily_score * 0.2f;

  student_count++;
  printf("成功添加学生：%s (ID : %d)\n", name, id);
  return 0;
}

int alter_student(int id, char *name, char *gender, char *address, char *contact_number, float chinese_score, float math_score, float english_score, float daily_score){
  int found_index = -1;
  for(int i = 0; i < student_count; i++){
    if(students[i].id == id){
      found_index = i;
      break;
    }
  }

  if(found_index == -1){
    printf("错误：未找到 ID 为 %d 的学生！\n", id);
    return -1;
  }

  strncpy(students[found_index].name, name, sizeof(students[found_index].name)-1);
  students[found_index].name[sizeof(students[found_index].name)-1] = '\0';
  strncpy(students[found_index].gender, gender, sizeof(students[found_index].gender)-1);
  students[found_index].gender[sizeof(students[found_index].gender)-1] = '\0';
  strncpy(students[found_index].address, address, sizeof(students[found_index].address)-1);
  students[found_index].address[sizeof(students[found_index].address)-1] = '\0';
  strncpy(students[found_index].contact_number, contact_number, sizeof(students[found_index].contact_number)-1);
  students[found_index].contact_number[sizeof(students[found_index].contact_number)-1] = '\0';

  students[found_index].chinese_score = chinese_score;
  students[found_index].math_score = math_score;
  students[found_index].english_score = english_score;
  students[found_index].daily_score = daily_score;

  students[found_index].average_score = (chinese_score + math_score + english_score) / 3.0f;
  students[found_index].comprehensive_score = students[found_index].average_score * 0.8f + daily_score * 0.2f;

  printf("成功修改学生：%s (ID : %d)\n", name, id);
  return 0;
}

int delete_student(int id_to_delete){
  int found_index = -1;

  for(int i = 0;i < student_count;i++){
    if(students[i].id == id_to_delete){
      found_index = i;
      break;
    }
  }

  if(found_index == -1){
    printf("错误： 未找到 ID 为 %d 的学生记录。\n",id_to_delete);
    return -1;
  }

  for(int j = found_index;j < student_count - 1;j++){
    students[j] = students[j+1];
  }

  student_count--;

  printf("成功删除 ID 为 %d 的学生记录。\n",id_to_delete);
  return 0;
}

void query_student(int id_to_query){
  int found_index = -1;

  for(int i = 0; i < student_count; i++){
    if(students[i].id == id_to_query){
      found_index = i;
      break;
    }
  }

  if(found_index == -1){
    printf("错误： 无法查询到 ID 为 %d 的学生！\n", id_to_query);
    return;
  }

  printf("----------------------------------------------------------------------------------------------------------------------------\n");
  printf("ID: %d | 姓名：%s | 性别：%s | 家庭住址: %s | 联系电话: %s | 语文分数： %.2f | 数学分数： %.2f | 英语分数： %.2f | 日常成绩: %.2f\n",
         students[found_index].id, students[found_index].name, students[found_index].gender, students[found_index].address,
         students[found_index].contact_number, students[found_index].chinese_score, students[found_index].math_score,
         students[found_index].english_score, students[found_index].daily_score);
  printf("平均分：%.2f | 排名：%d | 综合分：%.2f | 综合排名：%d\n",
         students[found_index].average_score, students[found_index].rank,
         students[found_index].comprehensive_score, students[found_index].comprehensive_rank);
  printf("----------------------------------------------------------------------------------------------------------------------------\n");
}

/* index = students 数组下标（0..student_count-1） */
float calculate_average_score(int index,float chinese_score,float math_score,float english_score){
    if(index < 0 || index >= student_count){
        printf("calculate_average_score: index 越界 %d\n", index);
        return -1.0f;
    }
    students[index].chinese_score = chinese_score;
    students[index].math_score = math_score;
    students[index].english_score = english_score;

    students[index].average_score = (chinese_score + math_score + english_score) / 3.0f;
    return students[index].average_score;
}

void calculate_all_ranks(){
    for(int i = 0; i < student_count; i++){
        students[i].average_score = (students[i].chinese_score + students[i].math_score + students[i].english_score) / 3.0f;
    }

    for(int i = 0; i < student_count; i++){
        int rank = 1;
        for(int j = 0; j < student_count; j++){
            if(students[j].average_score > students[i].average_score){
                rank++;
            }
        }
        students[i].rank = rank;
    }
}

/* index = students 数组下标（0..student_count-1） */
float calculate_comprehensive_score(int index,float chinese_score,float math_score,float english_score,float daily_score){
    if(index < 0 || index >= student_count){
        printf("calculate_comprehensive_score: index 越界 %d\n", index);
        return -1.0f;
    }
    students[index].chinese_score = chinese_score;
    students[index].math_score = math_score;
    students[index].english_score = english_score;
    students[index].daily_score = daily_score;

    students[index].comprehensive_score = ( (chinese_score + math_score + english_score) / 3.0f ) * 0.8f + daily_score * 0.2f;
    return students[index].comprehensive_score;
}

void calculate_all_comprehensive_ranks(){
    for(int i = 0; i < student_count; i++){
        students[i].comprehensive_score = (students[i].chinese_score + students[i].math_score + students[i].english_score) / 3.0f * 0.8f + students[i].daily_score * 0.2f;
    }

    for(int i = 0; i < student_count; i++){
        int comprehensive_rank = 1;
        for(int j = 0; j < student_count; j++){
            if(students[j].comprehensive_score > students[i].comprehensive_score){
                comprehensive_rank++;
            }
        }
        students[i].comprehensive_rank = comprehensive_rank;
    }
}

int save_data(){
  calculate_all_ranks();
  calculate_all_comprehensive_ranks();

  FILE *fp = fopen("students.txt","w");
  if(fp == NULL){
    printf("错误:无法打开文件进行写入！\n");
    return -1;
  }

  fprintf(fp, "ID,姓名,平均分,排名,综合分,综合排名\n");

  for(int i = 0; i < student_count; i++){
    fprintf(fp,"%d,%s,%.2f,%d,%.2f,%d\n",
            students[i].id,
            students[i].name,
            students[i].average_score,
            students[i].rank,
            students[i].comprehensive_score,
            students[i].comprehensive_rank);
  }

  fclose(fp);
  printf("成功保存 %d 条学生记录到 students.txt。\n",student_count);
  return 0;
}

void display_menu() {
    printf("\n--- 学生综合测评系统 ---\n");
    printf("1. 添加学生信息\n");
    printf("2. 修改学生信息\n");
    printf("3. 删除学生信息\n");
    printf("4. 查询学生信息\n");
    printf("5. 保存并退出\n");
    printf("----------------------\n");
    printf("请选择操作 (1-5): ");
}

int main(){
  int choice = 0;
  int id = 0, id_to_delete = 0;
  char name[50];
  char gender[10];
  char address[100];
  char contact_number[12];
  float chinese_score = 0.0f;
  float math_score = 0.0f;
  float english_score = 0.0f;
  float daily_score = 0.0f;

  do{
    display_menu();
    if(scanf("%d",&choice) != 1){
      int ch;
      while((ch = getchar()) != '\n' && ch != EOF); // 清空行
      choice = 0;
      continue;
    }

    switch (choice) {
            case 1: {
                /* 添加学生 */
                printf("输入ID：");
                if(scanf("%d",&id) != 1){ int ch; while((ch=getchar())!='\n' && ch!=EOF); printf("ID 输入错误。\n"); break; }
                printf("输入姓名（单词，不含空格）：");
                scanf("%49s", name);
                printf("输入性别：");
                scanf("%9s", gender);
                /* 读取地址（允许空格）*/
                printf("输入家庭住址（可含空格，按回车结束）：");
                { int ch; while((ch=getchar())!='\n' && ch!=EOF); } /* 清掉上一行残余 \n */
                if(fgets(address, sizeof(address), stdin) == NULL) address[0] = '\0';
                trim_newline(address);
                printf("输入联系电话：");
                scanf("%11s", contact_number);
                printf("输入语文成绩：");
                scanf("%f",&chinese_score);
                printf("输入数学成绩：");
                scanf("%f",&math_score);
                printf("输入英语成绩：");
                scanf("%f",&english_score);
                printf("输入日常成绩：");
                scanf("%f",&daily_score);
                add_student(id, name, gender, address, contact_number, chinese_score, math_score, english_score, daily_score);
                break;
            }
            case 2: {
                /* 修改学生 */
                int chosen_id;
                printf("要修改的学生ID: ");
                if(scanf("%d",&chosen_id) != 1){ int ch; while((ch=getchar())!='\n' && ch!=EOF); printf("ID 输入错误。\n"); break; }
                printf("输入姓名（单词，不含空格）：");
                scanf("%49s", name);
                printf("输入性别：");
                scanf("%9s", gender);
                printf("输入家庭住址（可含空格，按回车结束）：");
                { int ch; while((ch=getchar())!='\n' && ch!=EOF); }
                if(fgets(address, sizeof(address), stdin) == NULL) address[0] = '\0';
                trim_newline(address);
                printf("输入联系电话：");
                scanf("%11s", contact_number);
                printf("输入语文成绩：");
                scanf("%f",&chinese_score);
                printf("输入数学成绩：");
                scanf("%f",&math_score);
                printf("输入英语成绩：");
                scanf("%f",&english_score);
                printf("输入日常成绩：");
                scanf("%f",&daily_score);
                alter_student(chosen_id, name, gender, address, contact_number, chinese_score, math_score, english_score, daily_score);
                break;
            }
            case 3: {
                printf("输入要删除的ID: ");
                if(scanf("%d", &id_to_delete) != 1){ int ch; while((ch=getchar())!='\n' && ch!=EOF); printf("ID 输入错误。\n"); break; }
                delete_student(id_to_delete);
                break;
            }
            case 4: {
                int query_id;
                printf("请输入要查询的学生ID：");
                if(scanf("%d",&query_id) != 1){ int ch; while((ch=getchar())!='\n' && ch!=EOF); printf("ID 输入错误。\n"); break; }
                query_student(query_id);
                break;
            }
            case 5:
                save_data();
                printf("程序退出，数据已保存。\n");
                break;
            default:
                printf("无效选择，请重新输入。\n");
        }
    } while (choice != 5);

    return 0;
}