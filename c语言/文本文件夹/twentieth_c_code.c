#include <stdio.h>
#include <stdlib.h>

// ����һ�����׵�ѧ������¼��ϵͳ
// ����������ƽ����
// ������grades[]�洢�������������飬count����Ԫ�ص�����
// ����ֵ������ƽ����
int caculate_average(int grades[], int count) {
  int sum = 0;
  //���ѧ������Ϊ0��ֱ�ӷ���0���������0�Ĵ���
  if (count == 0) {
    return 0;
  }
  //ѭ���ۼ����з���
  for (int i = 0; i < count; i++) {
    sum += grades[i];
  }
  //�����ܺͳ���������ƽ��ֵ
  return sum / count;
}

int main(){
  const char *filename = "student_grades.txt";
  FILE *student_grades_file;

  // --- ���� 1��д�����ݵ��ļ� ---
  printf("�������ļ� '%s' д��ѧ������...\n", filename);
  // ��д��ģʽ("w")���ļ������ʧ�ܣ����ӡ�����˳�
  student_grades_file = fopen(filename,"w");
  if(student_grades_file == NULL){
    perror("�ļ�д��ʱ��ʧ��!");
    return 1; // ���ط�0ֵ��ʾ�������
  }
  // ���ļ�д��5��ѧ���������ͷ���
  fprintf(student_grades_file, "Alice: 85\n");
  fprintf(student_grades_file, "Bob: 90\n");
  fprintf(student_grades_file, "Charlie: 78\n");
  fprintf(student_grades_file, "Diana: 92\n");
  fprintf(student_grades_file, "Ethan: 88\n");

  // ������ �ؼ���д����ɺ����ر��ļ����ѱ������
  fclose(student_grades_file);
  printf("ѧ�������ѳɹ�д���ļ� '%s'.\n", filename);

  // --- ���� 2�����ļ���ȡ���� ---
  printf("���ڴ��ļ� '%s' ��ȡѧ������...\n", filename);
  // �Զ�ȡģʽ("r")���ļ������ʧ�ܣ����ӡ�����˳�
  student_grades_file = fopen(filename, "r");
  if (student_grades_file == NULL) {
    perror("�ļ���ȡʱ��ʧ��!");
    return 1;
  }

  int grades[5];
  int student_count = 0;
  // ѭ����ȡ�ļ���ֱ���ļ�ĩβ���Զ���5��ѧ��
  // fscanf �᷵����ȷƥ��͸�ֵ������������������ÿ�η���1(ֻ��ȡһ������)
  while(student_count < 5 && fscanf(student_grades_file,"%*[^:]: %d\n", &grades[student_count]) == 1) {
    student_count++;
  }

  // ������ �ؼ�����ȡ��ɺ�ҲҪ�ر��ļ�
  fclose(student_grades_file);
  printf("�ѳɹ���ȡ %d ��ѧ���ķ���.\n", student_count);

  // --- ���� 3�����㲢��ʾƽ���� ---
  printf("�Ƿ�鿴ƽ���֣���1. ��  2. ��\n");
  int choice;
  // ��ȡ�û�����
  scanf("%d", &choice);

  if (choice == 1) {
    // ���ú�������ƽ����
    int average = caculate_average(grades, student_count);
    printf("ѧ��ƽ����: %d\n", average);
  }else {
    printf("���˳��鿴ƽ���ֹ��ܡ�\n");
  }
  return 0;
}