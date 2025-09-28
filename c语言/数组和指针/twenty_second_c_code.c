#include <stdio.h>
#include <string.h>

int main(){
  // 1.strlen()函数: 计算字符串长度(不包括终止符'\0')
  char str1[] = "Hello, World!";
  printf("字符串长度: %zu\n", strlen(str1));

  // 2.strcpy()函数: 字符串复制(会覆盖目标字符串)
  char str2[] = "Goodbye!";
  char dest[50];
  strcpy(dest, str2);
  printf("复制后的字符串: %s\n", dest);

  // 3.strcat()函数: 字符串连接(将源字符串追加到目标字符串末尾)
  char str3[100] = "Hello";
  strcat(str3, ", World!");
  printf("连接后的字符串: %s\n", str3);

  // 4.strcmp()函数: 字符串比较(按ASCII字典顺序比较两个字符串)
  int cmp = strcmp(str1, str2);
  if(cmp == 0){
    printf("字符串相等\n");
  }else if(cmp < 0){
    printf("str1 < str2\n");
  }else{
    printf("str1 > str2\n");
  }

  return 0;
} 