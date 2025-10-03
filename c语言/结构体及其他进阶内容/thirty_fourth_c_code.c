#include <stdio.h>
#include <string.h>

// --- �ṹ��struct���� ---
typedef struct{
  char name[50];
  int id;
  float score;
} Student;

// --- ȫ�ֱ��������ݴ洢�� ---
#define MAX_STUDENTS 100
Student students[MAX_STUDENTS];
int student_count = 0;

// --- �������� ---
int add_student(char *name,int id,float score);
void list_all_students();
int delete_student(int id_to_delete);
int save_data();
int load_data();
void display_menu();

// --- ����ʵ�� ---

int add_student(char *name,int id,float score){
  if(student_count >= MAX_STUDENTS){
    printf("����ѧ����¼�������޷��������ѧ����\n");
    return -1;
  }

  // ���ݸ�ֵ��ʹ�� strcpy �����ַ���
  strcpy(students[student_count].name,name);
  students[student_count].id = id;
  students[student_count].score = score;

  student_count++;
  printf("�ɹ����ѧ����%s (ID: %d)\n",name,id);
  return 0;
}

void list_all_students(){
  printf("\n--- ѧ���б� (%d ��ѧ��) ---\n",student_count);
  if(student_count == 0){
    printf("Ŀǰû��ѧ����¼��\n");
    return;
  }

  for(int i = 0;i < student_count;i++){
    printf("ID: %d | ������%s | ������ %.2f\n",students[i].id,students[i].name,students[i].score);
    return;
  }
  printf("-----------------------------------\n");
}

int delete_student(int id_to_delete){
  int found_index = -1;

  // 1.����ѧ�� ID
  for(int i = 0;i < student_count;i++){
    if(students[i].id == id_to_delete){
      found_index = i;
      break;
    }
  }

  if(found_index == -1){
    printf("����δ�ҵ� ID Ϊ %d ��ѧ����¼��\n",id_to_delete);
    return -1;
  }

  // 2.�����ƶ�����ǰ���ǣ�
  for(int j =found_index;j < student_count - 1;j++){
    students[j] = students[j+1];
  }

  // 3.���¼�ʱ��
  student_count--;

  printf("�ɹ�ɾ�� ID Ϊ %d ��ѧ����¼��\n",id_to_delete);
  return 0;
}

int save_data(){
  FILE *fp = fopen("students.txt","w");
  if(fp == NULL){
    printf("����:�޷����ļ�����д�룡\n");
    return -1;
  }

  for(int i = 0;i < student_count;i++){
    // ��ʽ�� ������ID������ + ���з�
    fprintf(fp,"%s,%d,%.2f\n",students[i].name,students[i].id,students[i].score);
  }

  fclose(fp);
  printf("�ɹ����� %d ��ѧ����¼�� students.txt��\n",student_count);
  return 0;
}

int load_data(){
  student_count = 0; // ���ü�����

  FILE *fp = fopen("student.txt","r");
  if(fp == NULL){
    //����ļ������ڣ�������Ϊ�ǳ����һ�����У�������
    return 0;
  }

  Student temp_student;

  // ��ȡ���ݣ�%[^,] ��ȡ�����ţ�%d ��ȡ������%f ��ȡ������
  while(fscanf(fp,"%[^,],%d,%f\n",temp_student.name,&temp_student.id,&temp_student.score)==3){
    // �ṹ�帳ֵ
    students[student_count] = temp_student;
    student_count++;
  }

  fclose(fp);
  printf("�ɹ����� %d ��ѧ����¼��\n",student_count);
  return 0;
}

void display_menu() {
    printf("\n--- ѧ������ϵͳ ---\n");
    printf("1. ���ѧ��\n");
    printf("2. �鿴����ѧ��\n");
    printf("3. ɾ��ѧ��\n");
    printf("4. ���沢�˳�\n");
    printf("----------------------\n");
    printf("��ѡ����� (1-4): ");
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
      //�����������
      while(getchar() != 1);
      choice = 0;
      continue;
    }

    switch (choice) {
            case 1:
                printf("��������: ");
                scanf("%s", name);
                printf("����ID: ");
                scanf("%d", &id);
                printf("�������: ");
                scanf("%f", &score);
                add_student(name, id, score);
                break;
            case 2:
                list_all_students();
                break;
            case 3:
                printf("����Ҫɾ����ID: ");
                scanf("%d", &id_to_delete);
                delete_student(id_to_delete);
                break;
            case 4:
                save_data();
                printf("�����˳��������ѱ��档\n");
                break;
            default:
                printf("��Чѡ�����������롣\n");
        }
    } while (choice != 4);

    return 0;
}
