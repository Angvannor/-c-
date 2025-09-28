#include <stdio.h>

int main(){
  printf("这是一个根据成绩的分级系统\n");
  int score;
  printf("请输入成绩: ");
  scanf("%d", &score);
  if(score < 0 || score > 100) {
    printf("输入错误，成绩应在0到100之间。\n");
  } else if(score >= 90) {
    printf("等级: A\n");
  } else if (score >= 80) {
    printf("等级: B\n");
  } else if (score >= 70) {
    printf("等级: C\n");
  } else if (score >= 60) {
    printf("等级: D\n");
  } else {
    printf("等级: E\n");
  }
  return 0;
}