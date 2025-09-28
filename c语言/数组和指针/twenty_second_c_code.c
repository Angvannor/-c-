#include <stdio.h>
#include <string.h>

int main(){
  // 1.strlen()����: �����ַ�������(��������ֹ��'\0')
  char str1[] = "Hello, World!";
  printf("�ַ�������: %zu\n", strlen(str1));

  // 2.strcpy()����: �ַ�������(�Ḳ��Ŀ���ַ���)
  char str2[] = "Goodbye!";
  char dest[50];
  strcpy(dest, str2);
  printf("���ƺ���ַ���: %s\n", dest);

  // 3.strcat()����: �ַ�������(��Դ�ַ���׷�ӵ�Ŀ���ַ���ĩβ)
  char str3[100] = "Hello";
  strcat(str3, ", World!");
  printf("���Ӻ���ַ���: %s\n", str3);

  // 4.strcmp()����: �ַ����Ƚ�(��ASCII�ֵ�˳��Ƚ������ַ���)
  int cmp = strcmp(str1, str2);
  if(cmp == 0){
    printf("�ַ������\n");
  }else if(cmp < 0){
    printf("str1 < str2\n");
  }else{
    printf("str1 > str2\n");
  }

  return 0;
} 