#include <stdio.h>

int main(){
  printf("����һ�����ݳɼ��ķּ�ϵͳ\n");
  int score;
  printf("������ɼ�: ");
  scanf("%d", &score);
  if(score < 0 || score > 100) {
    printf("������󣬳ɼ�Ӧ��0��100֮�䡣\n");
  } else if(score >= 90) {
    printf("�ȼ�: A\n");
  } else if (score >= 80) {
    printf("�ȼ�: B\n");
  } else if (score >= 70) {
    printf("�ȼ�: C\n");
  } else if (score >= 60) {
    printf("�ȼ�: D\n");
  } else {
    printf("�ȼ�: E\n");
  }
  return 0;
}