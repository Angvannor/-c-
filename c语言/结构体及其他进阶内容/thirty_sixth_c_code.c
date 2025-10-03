#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char buffer[10];
  const char *src = "HelloWorld"; // 10个字符
  size_t dest_size = sizeof(buffer); // 10

  strncpy(buffer, src, dest_size - 1); // 复制 9 个字符
  buffer[dest_size - 1] = '\0';        // 手动添加 \0

  // buffer 现在是 "HelloWorl" + \0

  char log_msg[20]; // 缓冲区大小 20
  const char *user = "Admin";

  snprintf(log_msg, sizeof(log_msg), 
         "User: %s logged in at %d", 
         user, 
         166);

  // log_msg: "User: Admin logged" (如果完整消息超长，它会被安全截断并在末尾加 \0)

  char name_buffer[10];
  size_t input_len = strlen("JamesBond"); // 长度 9

  if (input_len < sizeof(name_buffer)) { // 9 < 10，安全
      // 可以安全地使用 strncpy/strcpy_s 等进行复制
      printf("输入安全。\n");
  } else {
      printf("输入过长，有溢出风险。\n");
  }

  return 0;
}