#include <stdio.h>

// 自定义的字符串分割函数
// 功能类似 strtok，每次调用返回一个用 delim 分隔的子串
char *my_strtok(char *str, char delim){
  static char *p;   // 静态指针，保存上一次分割的位置
                    // 之所以用 static，是为了在多次调用函数时，仍然记住上次的位置

  // 如果传入的 str 不是 NULL，就说明是第一次调用，初始化 p
  if(str != NULL) 
    p = str;

  // 如果 p 为空，或者已经到达字符串末尾，则返回 NULL
  if(p == NULL || *p == '\0') 
    return NULL;

  // 保存当前分割的起始位置
  char *start = p;

  // 往后遍历，直到遇到分隔符或者字符串结束符
  while(*p != '\0' && *p != delim){
    p++;
  }

  // 如果遇到了分隔符，就把它改成 '\0'，形成一个独立的子串
  // 并且让 p 指向下一个字符，方便下次调用继续切分
  if(*p == delim){
    *p = '\0';  // 截断字符串
    p++;        // 移动到下一个子串的起点
  } else {
    // 否则说明到达了字符串结尾，下次调用直接返回 NULL
    p = NULL;
  }

  // 返回当前分割得到的子串
  return start;
}

int main(){
  // 原始字符串
  char str[] = "Hello,World,This,is,a,test";

  // 第一次调用，传入原始字符串和分隔符
  char *token = my_strtok(str, ',');

  // 循环调用，直到返回 NULL
  while(token != NULL){
    printf("%s\n", token);   // 打印每个子串
    token = my_strtok(NULL, ','); // 后续调用传 NULL，继续从上次保存的位置开始
  }

  return 0;
}
