#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char buffer[10];
  const char *src = "HelloWorld"; // 10���ַ�
  size_t dest_size = sizeof(buffer); // 10

  strncpy(buffer, src, dest_size - 1); // ���� 9 ���ַ�
  buffer[dest_size - 1] = '\0';        // �ֶ���� \0

  // buffer ������ "HelloWorl" + \0

  char log_msg[20]; // ��������С 20
  const char *user = "Admin";

  snprintf(log_msg, sizeof(log_msg), 
         "User: %s logged in at %d", 
         user, 
         166);

  // log_msg: "User: Admin logged" (���������Ϣ���������ᱻ��ȫ�ضϲ���ĩβ�� \0)

  char name_buffer[10];
  size_t input_len = strlen("JamesBond"); // ���� 9

  if (input_len < sizeof(name_buffer)) { // 9 < 10����ȫ
      // ���԰�ȫ��ʹ�� strncpy/strcpy_s �Ƚ��и���
      printf("���밲ȫ��\n");
  } else {
      printf("�����������������ա�\n");
  }

  return 0;
}