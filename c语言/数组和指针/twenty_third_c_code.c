#include <stdio.h>

// 自定义strlen函数
int my_strlen(const char *str){
  int length = 0;
  while(str[length] != '\0'){
    length++;
  }
  return length;
}


// 自定义strcpy函数
char* my_strcpy(char *dest,const char *src){
  int i = 0;
  while((dest[i] = src[i]) != '\0'){
    i++;
  }
  return dest;
}

// 自定义strcat函数
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

// 自定义strcmp函数
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
  // 1.strlen()函数: 计算字符串长度(不包括终止符'\0')
  char str1[] = "Hello, World!";
  printf("字符串长度: %zu\n", my_strlen(str1));

  // 2.strcpy()函数: 字符串复制(会覆盖目标字符串)
  char str2[] = "Goodbye!";
  char dest[50];
  my_strcpy(dest, str2);
  printf("复制后的字符串: %s\n", dest);

  // 3.strcat()函数: 字符串连接(将源字符串追加到目标字符串末尾)
  char str3[100] = "Hello";
  my_strcat(str3, ", World!");
  printf("连接后的字符串: %s\n", str3);

  // 4.strcmp()函数: 字符串比较(按ASCII字典顺序比较两个字符串)
  int cmp = my_strcmp(str1, str2);
  if(cmp == 0){
    printf("字符串相等\n");
  }else if(cmp < 0){
    printf("str1 < str2\n");
  }else{
    printf("str1 > str2\n");
  }

  return 0;
} 