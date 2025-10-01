#include <stdio.h>

// �Զ�����ַ����ָ��
// �������� strtok��ÿ�ε��÷���һ���� delim �ָ����Ӵ�
char *my_strtok(char *str, char delim){
  static char *p;   // ��ָ̬�룬������һ�ηָ��λ��
                    // ֮������ static����Ϊ���ڶ�ε��ú���ʱ����Ȼ��ס�ϴε�λ��

  // �������� str ���� NULL����˵���ǵ�һ�ε��ã���ʼ�� p
  if(str != NULL) 
    p = str;

  // ��� p Ϊ�գ������Ѿ������ַ���ĩβ���򷵻� NULL
  if(p == NULL || *p == '\0') 
    return NULL;

  // ���浱ǰ�ָ����ʼλ��
  char *start = p;

  // ���������ֱ�������ָ��������ַ���������
  while(*p != '\0' && *p != delim){
    p++;
  }

  // ��������˷ָ������Ͱ����ĳ� '\0'���γ�һ���������Ӵ�
  // ������ p ָ����һ���ַ��������´ε��ü����з�
  if(*p == delim){
    *p = '\0';  // �ض��ַ���
    p++;        // �ƶ�����һ���Ӵ������
  } else {
    // ����˵���������ַ�����β���´ε���ֱ�ӷ��� NULL
    p = NULL;
  }

  // ���ص�ǰ�ָ�õ����Ӵ�
  return start;
}

int main(){
  // ԭʼ�ַ���
  char str[] = "Hello,World,This,is,a,test";

  // ��һ�ε��ã�����ԭʼ�ַ����ͷָ���
  char *token = my_strtok(str, ',');

  // ѭ�����ã�ֱ������ NULL
  while(token != NULL){
    printf("%s\n", token);   // ��ӡÿ���Ӵ�
    token = my_strtok(NULL, ','); // �������ô� NULL���������ϴα����λ�ÿ�ʼ
  }

  return 0;
}
