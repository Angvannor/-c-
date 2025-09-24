#include <stdio.h>

int main(){
  printf("这是一个课表查询系统\n");
  int day;
  printf("请输入星期几(1-7): ");
  scanf("%d",&day);
  switch(day){
    case 1:printf("1-2节：无课\n3-4节：C语言程序设计\n5-6节：雅思英语\n7-8节：高等数学\n");
    break;
    case 2:printf("1-2节：雅思英语\n3-4节：体育\n5-6节：思想道德与法治\n7-8节：无课\n");
    break;
    case 3:printf("1-2节：高等数学\n3-4节：雅思英语\n5-6节：无课\n7-8节：无课\n");
    break;
    case 4:printf("1-2节：雅思英语\n3-4节：C语言程序设计\n5-6节：软件技术基础\n7-8节：无课\n");
    break;
    case 5:printf("1-2节：无课\n3-4节：无课\n5-6节：思想道德与法治\n7-8节：高等数学\n");
    break;
    case 6:printf("1-2节：无课\n3-4节：无课\n5-6节：无课\n7-8节：国家安全与军事理论\n");
    break;
    case 7:printf("1-2节：无课\n3-4节：无课\n5-6节：无课\n7-8节：国家安全与军事理论\n");
    break;
    default:printf("输入错误，请输入1到7之间的数字。\n");
  }

  return 0;
}