#include <stdio.h>
#include <string.h>

// --- struct Student ---
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

// --- global variables ---
#define MAX_STUDENTS 100
Student students[MAX_STUDENTS];
int student_count = 0;

// --- function announce ---

// --- 1.student information processing ---
int add_student(int id,char *name,char *gender,char *address,char *contact_number,float chinese_score,float math_score,float english_score,float daily_score);
int alter_student(int id,char *name,char *gender,char *address,char *contact_number,float chinese_score,float math_score,float english_score,float daily_score);
int delete_student(int id_to_delete);
void query_student(int id_to_query);

// --- 2.student data processing ---
float calculate_average_score(int id,float chinese_score,float math_score,float english_score);
void calculate_all_ranks();
float calculate_comprehensive_score(int id,float chinese_score,float math_score,float english_score,float daily_score);
void calculate_all_comprehensive_ranks();
int save_data();
void display_menu();

// --- function implementation ---
int add_student(int id,char *name,char *gender,char *address,char *contact_number,float chinese_score,float math_score,float english_score,float daily_score){
  if(student_count >= MAX_STUDENTS){
    printf("����ѧ����¼�������޷��������ѧ����\n");
    return -1;
  }

  // --- data assignment ---
  students[student_count].id = id;
  strcpy(students[student_count].name,name);
  strcpy(students[student_count].gender,gender);
  strcpy(students[student_count].address,address);
  strcpy(students[student_count].contact_number,contact_number);
  students[student_count].chinese_score = chinese_score;
  students[student_count].math_score = math_score;
  students[student_count].english_score = english_score;
  students[student_count].daily_score = daily_score;

  student_count++;
  printf("�ɹ����ѧ����%s (ID : %d)\n",name,id);
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
    printf("����δ�ҵ� ID Ϊ %d ��ѧ����\n", id);
    return -1;
  }

  strcpy(students[found_index].name, name);
  strcpy(students[found_index].gender, gender);
  strcpy(students[found_index].address, address);
  strcpy(students[found_index].contact_number, contact_number);
  students[found_index].chinese_score = chinese_score;
  students[found_index].math_score = math_score;
  students[found_index].english_score = english_score;
  students[found_index].daily_score = daily_score;

  printf("�ɹ��޸�ѧ����%s (ID : %d)\n", name, id);
  return 0;
}

int delete_student(int id_to_delete){
  int found_index = -1;

  // 1. search id
  for(int i = 0;i < student_count;i++){
    if(students[i].id == id_to_delete){
      found_index = i;
      break;
    }
  }

  if(found_index == -1){
    printf("���� δ�ҵ� ID Ϊ %d ��ѧ����¼��\n",id_to_delete);
    return -1;
  }

  // 2. array cover
  for(int j = found_index;j < student_count - 1;j++){
    students[j] = students[j+1];
  }

  // 3. update timer
  student_count--;

  printf("�ɹ�ɾ�� ID Ϊ %d ��ѧ����¼��\n",id_to_delete);
  return 0;
};

void query_student(int id_to_query){ 
  int found_index = -1;

  for(int i = 0; i < student_count; i++){
    if(students[i].id == id_to_query){
      found_index = i;
      break;
    }
  }

  if(found_index == -1){ 
    printf("���� �޷���ѯ�� ID Ϊ %d ��ѧ����\n", id_to_query);
    return;
  }

  printf("----------------------------------------------------------------------------------------------------------------------------\n");
  printf("ID: %d | ������%s | �Ա�%s | ��ͥסַ: %s | ��ϵ�绰: %s | ���ķ����� %.2f | ��ѧ������ %.2f | Ӣ������� %.2f | �ճ��ɼ�: %.2f\n",
         students[found_index].id, students[found_index].name, students[found_index].gender, students[found_index].address,
         students[found_index].contact_number, students[found_index].chinese_score, students[found_index].math_score,
         students[found_index].english_score, students[found_index].daily_score);
  printf("----------------------------------------------------------------------------------------------------------------------------\n");
}

float calculate_average_score(int id,float chinese_score,float math_score,float english_score){
    students[id].chinese_score = chinese_score;
    students[id].math_score = math_score;
    students[id].english_score = english_score;

    students[id].average_score = (chinese_score + math_score + english_score) / 3.0;
    return students[id].average_score;
}

void calculate_all_ranks(){
    // 1. �ȼ�������ѧ����ƽ����
    for(int i = 0; i < student_count; i++){
        students[i].average_score = (students[i].chinese_score + students[i].math_score + students[i].english_score) / 3.0;
    }

    // 2. ��������
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

float calculate_comprehensive_score(int id,float chinese_score,float math_score,float english_score,float daily_score){
    students[id].chinese_score = chinese_score;
    students[id].math_score = math_score;
    students[id].english_score = english_score;
    students[id].daily_score = daily_score;

    students[id].comprehensive_score = (chinese_score + math_score + english_score) / 3.0 * 0.8 + daily_score * 0.2;
    return students[id].comprehensive_score;
}

void calculate_all_comprehensive_ranks(){
    // 1. �ȼ�������ѧ�����ۺϷ�
    for(int i = 0; i < student_count; i++){
        students[i].comprehensive_score = (students[i].chinese_score + students[i].math_score + students[i].english_score) / 3.0 * 0.8 + students[i].daily_score * 0.2;
    }

    // 2. �����ۺ�����
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
  // �ڱ���ǰ��ȷ�����з����������������µ�
  calculate_all_ranks();
  calculate_all_comprehensive_ranks();

  FILE *fp = fopen("students.txt","w");
  if(fp == NULL){
    printf("����:�޷����ļ�����д�룡\n");
    return -1;
  }
  
  // д�������
  fprintf(fp, "ID,����,ƽ����,����,�ۺϷ�,�ۺ�����\n");

  for(int i = 0; i < student_count; i++){
    // ��ʽ��ID,����,ƽ����,����,�ۺϷ�,�ۺ�����
    fprintf(fp,"%d,%s,%.2f,%d,%.2f,%d\n",
            students[i].id,
            students[i].name,
            students[i].average_score,
            students[i].rank,
            students[i].comprehensive_score,
            students[i].comprehensive_rank);
  }

  fclose(fp);
  printf("�ɹ����� %d ��ѧ����¼�� students.txt��\n",student_count);
  return 0;
}

void display_menu() {
    printf("\n--- ѧ���ۺϲ���ϵͳ ---\n");
    printf("1. ���ѧ����Ϣ\n");
    printf("2. �޸�ѧ����Ϣ\n");
    printf("3. ɾ��ѧ����Ϣ\n");
    printf("4. ��ѯѧ����Ϣ\n");
    printf("5. ���沢�˳�\n");
    printf("----------------------\n");
    printf("��ѡ����� (1-5): ");
}

int main(){
  int choice;
  int id,id_to_delete;
  char name[50];
  char gender[10];
  char address[100];
  char contact_number[12];
  float chinese_score;
  float math_score;
  float english_score;
  float daily_score;

  do{
    display_menu();
    if(scanf("%d",&choice) != 1){
      //�����������
      while(getchar() != 1);
      choice = 0;
      continue;
    }

    switch (choice) {
            case 1:
                printf("����ID��");
                scanf("%d",&id);
                printf("����������");
                scanf("%s",&name);
                printf("�����Ա�");
                scanf("%s",&gender);
                printf("�����ͥסַ��");
                scanf("%s",&address);
                printf("������ϵ�绰��");
                scanf("%s",&contact_number);
                printf("�������ĳɼ���");
                scanf("%f",&chinese_score);
                printf("������ѧ�ɼ���");
                scanf("%f",&math_score);
                printf("����Ӣ��ɼ���");
                scanf("%f",&english_score);
                printf("�����ճ��ɼ���");
                scanf("%f",&daily_score);
                add_student(id, name, gender, address, contact_number, chinese_score, math_score, english_score, daily_score);
                break;
            case 2:
                int chosen_id;
                printf("Ҫ�޸ĵ�ѧ��ID:");
                scanf("%d",&chosen_id);
                printf("����������");
                scanf("%s",&name);
                printf("�����Ա�");
                scanf("%s",&gender);
                printf("�����ͥסַ��");
                scanf("%s",&address);
                printf("������ϵ�绰��");
                scanf("%s",&contact_number);
                printf("�������ĳɼ���");
                scanf("%f",&chinese_score);
                printf("������ѧ�ɼ���");
                scanf("%f",&math_score);
                printf("����Ӣ��ɼ���");
                scanf("%f",&english_score);
                printf("�����ճ��ɼ���");
                scanf("%f",&daily_score);
                alter_student(chosen_id,name,gender,address,contact_number,chinese_score,math_score,english_score,daily_score);
                break;
            case 3:
                printf("����Ҫɾ����ID: ");
                scanf("%d", &id_to_delete);
                delete_student(id_to_delete);
                break;
            case 4:
                int chosen_id;
                printf("������Ҫ��ѯ��ѧ��ID��");
                scanf("%d",&chosen_id);
                query_student(chosen_id);
                break;
            case 5:
                save_data();
                printf("�����˳��������ѱ��档\n");
                break;
            default:
                printf("��Чѡ�����������롣\n");
        }
    } while (choice != 5);

    return 0;
}