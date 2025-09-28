#include <stdio.h>

// �Զ���strlen����
int my_strlen(const char *str){
  int length = 0;
  while(str[length] != '\0'){
    length++;
  }
  return length;
}


// �Զ���strcpy����
char* my_strcpy(char *dest,const char *src){
  int i = 0;
  while((dest[i] = src[i]) != '\0'){
    i++;
  }
  return dest;
}

// �Զ���strcat����
char* my_strcat(char *dest,const char *src){
  int i = 0,j = 0;
  while(dest[i] != '\0'){
    i++;
  }
  while((dest[i] = src[j]) != '\0'){
    i++;
    j++;
  }
  return dest;
}

// �Զ���strcmp����
int my_strcmp(const char *str1,const char *str2){
  int i = 0;
  int cmp = str1[i] - str2[i];
  while(cmp == 0 && str1[i] != '\0' && str2[i] != '\0'){
    i++;
    cmp = str1[i] - str2[i];
  }
  return cmp;
}

int main(){
  // 1.strlen()����: �����ַ�������(��������ֹ��'\0')
  char str1[] = "Hello, World!";
  printf("�ַ�������: %zu\n", my_strlen(str1));

  // 2.strcpy()����: �ַ�������(�Ḳ��Ŀ���ַ���)
  char str2[] = "Goodbye!";
  char dest[50];
  my_strcpy(dest, str2);
  printf("���ƺ���ַ���: %s\n", dest);

  // 3.strcat()����: �ַ�������(��Դ�ַ���׷�ӵ�Ŀ���ַ���ĩβ)
  char str3[100] = "Hello";
  my_strcat(str3, ", World!");
  printf("���Ӻ���ַ���: %s\n", str3);

  // 4.strcmp()����: �ַ����Ƚ�(��ASCII�ֵ�˳��Ƚ������ַ���)
  int cmp = my_strcmp(str1, str2);
  if(cmp == 0){
    printf("�ַ������\n");
  }else if(cmp < 0){
    printf("str1 < str2\n");
  }else{
    printf("str1 > str2\n");
  }

  return 0;
} 