#include <stdio.h>
#include <string.h>
#include <stdlib.h> // 为了 exit()

// 教师结构体定义
typedef struct{
  int id;
  char name[50];
  char gender[10];
  char unit_name[100];
  char address[100];
  char contact_number[12];
  float basic_pay;
  float allowance;
  float living_allowance;
  float payable_salary; // 应发工资
  float telephone_bill;
  float water_and_electrity_bill;
  float rent;
  float income_tax;
  float health_fee;
  float provident_fund;
  float total_deduction; // 扣除总额
  float actual_salary;   // 实发工资
} Teacher;

#define MAX_TEACHERS 100
Teacher teachers[MAX_TEACHERS];
int teacher_count = 0;

/* 函数原型声明 */
int add_teacher(int id,
  char *name,
  char *gender,
  char *unit_name,
  char *address,
  char *contact_number,
  float basic_pay,
  float allowance,
  float living_allowance,
  float telephone_bill,
  float water_and_electrity_bill,
  float rent,
  float income_tax,
  float health_fee,
  float provident_fund
);

int alter_teacher(int id,
  char *name,
  char *gender,
  char *unit_name,
  char *address,
  char *contact_number,
  float basic_pay,
  float allowance,
  float living_allowance,
  float telephone_bill,
  float water_and_electrity_bill,
  float rent,
  float income_tax,
  float health_fee,
  float provident_fund
);

int delete_teacher(int id_to_delete);
void show_all_teachers(void);
void query_teacher(int id_to_query);
void import_teacher(void);
int save_data(void);
void display_menu(void);
void trim_newline(char *s);
void clear_input_buffer(void);


// 移除字符串末尾的换行符
void trim_newline(char *s){
  size_t n = strlen(s);
  if(n > 0 && s[n-1] == '\n') s[n-1] = '\0';
}

// 清理输入缓冲区
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int add_teacher(int id,
  char *name,
  char *gender,
  char *unit_name,
  char *address,
  char *contact_number,
  float basic_pay,
  float allowance,
  float living_allowance,
  float telephone_bill,
  float water_and_electrity_bill,
  float rent,
  float income_tax,
  float health_fee,
  float provident_fund
)
{
  if(teacher_count >= MAX_TEACHERS){
    printf("错误：教师记录已满，无法再添加新教师！\n");
    return -1;
  }

  // 检查ID是否已存在
  for(int i = 0; i < teacher_count; i++){
    if(teachers[i].id == id){
      printf("错误：ID 为 %d 的教师已存在！\n", id);
      return -1;
    }
  }

  teachers[teacher_count].id = id;
  strncpy(teachers[teacher_count].name, name, sizeof(teachers[teacher_count].name)-1);
  teachers[teacher_count].name[sizeof(teachers[teacher_count].name)-1] = '\0';
  strncpy(teachers[teacher_count].gender, gender, sizeof(teachers[teacher_count].gender)-1);
  teachers[teacher_count].gender[sizeof(teachers[teacher_count].gender)-1] = '\0';
  strncpy(teachers[teacher_count].unit_name, unit_name, sizeof(teachers[teacher_count].unit_name)-1);
  teachers[teacher_count].unit_name[sizeof(teachers[teacher_count].unit_name)-1] = '\0';
  strncpy(teachers[teacher_count].address, address, sizeof(teachers[teacher_count].address)-1);
  teachers[teacher_count].address[sizeof(teachers[teacher_count].address)-1] = '\0';
  strncpy(teachers[teacher_count].contact_number, contact_number, sizeof(teachers[teacher_count].contact_number)-1);
  teachers[teacher_count].contact_number[sizeof(teachers[teacher_count].contact_number)-1] = '\0';

  teachers[teacher_count].basic_pay = basic_pay;
  teachers[teacher_count].allowance = allowance;
  teachers[teacher_count].living_allowance = living_allowance;
  teachers[teacher_count].telephone_bill = telephone_bill;
  teachers[teacher_count].water_and_electrity_bill = water_and_electrity_bill;
  teachers[teacher_count].rent = rent;
  teachers[teacher_count].income_tax = income_tax;
  teachers[teacher_count].health_fee = health_fee;
  teachers[teacher_count].provident_fund = provident_fund;

  // 自动计算工资
  teachers[teacher_count].payable_salary = (basic_pay + allowance + living_allowance);
  teachers[teacher_count].total_deduction = (telephone_bill + water_and_electrity_bill + rent + income_tax + health_fee + provident_fund);
  teachers[teacher_count].actual_salary = teachers[teacher_count].payable_salary - teachers[teacher_count].total_deduction;

  teacher_count++;
  printf("成功添加教师: %s (ID : %d)\n", name, id);
  return 0;
}

int alter_teacher(int id,
  char *name,
  char *gender,
  char *unit_name,
  char *address,
  char *contact_number,
  float basic_pay,
  float allowance,
  float living_allowance,
  float telephone_bill,
  float water_and_electrity_bill,
  float rent,
  float income_tax,
  float health_fee,
  float provident_fund
)
{
  int found_index = -1;
  for(int i = 0; i < teacher_count; i++){
    if(teachers[i].id == id){
      found_index = i;
      break;
    }
  }

  if(found_index == -1){
    printf("错误：未找到 ID 为 %d 的教师！\n", id);
    return -1;
  }

  strncpy(teachers[found_index].name, name, sizeof(teachers[found_index].name)-1);
  teachers[found_index].name[sizeof(teachers[found_index].name)-1] = '\0';
  strncpy(teachers[found_index].gender, gender, sizeof(teachers[found_index].gender)-1);
  teachers[found_index].gender[sizeof(teachers[found_index].gender)-1] = '\0';
  strncpy(teachers[found_index].unit_name, unit_name, sizeof(teachers[found_index].unit_name)-1);
  teachers[found_index].unit_name[sizeof(teachers[found_index].unit_name)-1] = '\0';
  strncpy(teachers[found_index].address, address, sizeof(teachers[found_index].address)-1);
  teachers[found_index].address[sizeof(teachers[found_index].address)-1] = '\0';
  strncpy(teachers[found_index].contact_number, contact_number, sizeof(teachers[found_index].contact_number)-1);
  teachers[found_index].contact_number[sizeof(teachers[found_index].contact_number)-1] = '\0';

  teachers[found_index].basic_pay = basic_pay;
  teachers[found_index].allowance = allowance;
  teachers[found_index].living_allowance = living_allowance;
  teachers[found_index].telephone_bill = telephone_bill;
  teachers[found_index].water_and_electrity_bill = water_and_electrity_bill;
  teachers[found_index].rent = rent;
  teachers[found_index].income_tax = income_tax;
  teachers[found_index].health_fee = health_fee;
  teachers[found_index].provident_fund = provident_fund;

  // 重新计算工资
  teachers[found_index].payable_salary = (basic_pay + allowance + living_allowance);
  teachers[found_index].total_deduction = (telephone_bill + water_and_electrity_bill + rent + income_tax + health_fee + provident_fund);
  teachers[found_index].actual_salary = teachers[found_index].payable_salary - teachers[found_index].total_deduction;

  printf("成功修改教师：%s (ID : %d)\n", name, id);
  return 0;
}

int delete_teacher(int id_to_delete){
  int found_index = -1;

  for(int i = 0; i < teacher_count; i++){
    if(teachers[i].id == id_to_delete){
      found_index = i;
      break;
    }
  }

  if(found_index == -1){
    printf("错误：未找到 ID 为 %d 的教师记录。\n", id_to_delete);
    return -1;
  }

  for(int j = found_index; j < teacher_count - 1; j++){
    teachers[j] = teachers[j+1];
  }

  teacher_count--;

  printf("成功删除 ID 为 %d 的教师记录。\n", id_to_delete);
  return 0;
}

void show_all_teachers(void){
  printf("\n--- 教师列表 (%d 名教师) ---\n", teacher_count);
  if(teacher_count == 0){
    printf("目前没有教师记录。\n");
    return;
  }

  printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
  printf("ID\t| 姓名\t\t| 性别\t| 单位名称\t\t| 家庭住址\t\t| 联系电话\t| 实发工资\n");
  printf("--------------------------------------------------------------------------------------------------------------------------------------\n");

  for(int i = 0; i < teacher_count; i++){
    printf("%-d\t| %-12s\t| %-s\t| %-20s\t| %-20s\t| %-12s\t| %.2f\n",
          teachers[i].id, teachers[i].name, teachers[i].gender, teachers[i].unit_name, teachers[i].address, teachers[i].contact_number, teachers[i].actual_salary);
  }
  printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
}


void query_teacher(int id_to_query){
  int found_index = -1;

  for(int i = 0; i < teacher_count; i++){
    if(teachers[i].id == id_to_query){
      found_index = i;
      break;
    }
  }

  if(found_index == -1){
    printf("错误：无法查询到 ID 为 %d 的教师！\n", id_to_query);
    return;
  }
  
  printf("\n--- 查询结果 ---\n");
  printf("ID: %d\n", teachers[found_index].id);
  printf("姓名: %s\n", teachers[found_index].name);
  printf("性别: %s\n", teachers[found_index].gender);
  printf("单位名称: %s\n", teachers[found_index].unit_name);
  printf("家庭住址: %s\n", teachers[found_index].address);
  printf("联系电话: %s\n", teachers[found_index].contact_number);
  printf("\n--- 工资详情 ---\n");
  printf("应发工资: %.2f (基本: %.2f, 津贴: %.2f, 生活补贴: %.2f)\n", 
        teachers[found_index].payable_salary, teachers[found_index].basic_pay, 
        teachers[found_index].allowance, teachers[found_index].living_allowance);
  printf("扣除总额: %.2f (电话: %.2f, 水电: %.2f, 房租: %.2f, 所得税: %.2f, 卫生费: %.2f, 公积金: %.2f)\n", 
        teachers[found_index].total_deduction, teachers[found_index].telephone_bill, 
        teachers[found_index].water_and_electrity_bill, teachers[found_index].rent, 
        teachers[found_index].income_tax, teachers[found_index].health_fee, teachers[found_index].provident_fund);
  printf("实发工资: %.2f\n", teachers[found_index].actual_salary);
  printf("----------------\n");
}


void import_teacher(void){
  FILE *fp = fopen("import.txt", "r");
  if(fp == NULL){
    printf("错误：无法打开 import.txt 文件！请确保文件存在于程序同目录下。\n");
    return;
  }

  char line[512]; // 缓冲区，用于存储文件中的每一行
  int imported_count = 0;
  
  // 逐行读取文件
  while(fgets(line, sizeof(line), fp)){
      int id;
      char name[50], gender[10], unit_name[100], address[100], contact_number[12];
      float basic_pay, allowance, living_allowance, telephone_bill, water_electrity_bill, rent, income_tax, health_fee, provident_fund;

      // 使用 sscanf 解析 CSV 行
      int result = sscanf(line, "%d,%49[^,],%9[^,],%99[^,],%99[^,],%11[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f",
          &id, name, gender, unit_name, address, contact_number, &basic_pay, &allowance,
          &living_allowance, &telephone_bill, &water_electrity_bill, &rent,
          &income_tax, &health_fee, &provident_fund);
      
      // 如果成功解析出所有15个字段
      if(result == 15){
        if(add_teacher(id, name, gender, unit_name, address, contact_number, 
                       basic_pay, allowance, living_allowance, telephone_bill, 
                       water_electrity_bill, rent, income_tax, health_fee, provident_fund) == 0){
          imported_count++;
        }
      } else {
        printf("警告：跳过格式不正确的一行 -> %s", line);
      }
  }

  fclose(fp);
  printf("成功从 import.txt 导入 %d 条教师记录。\n", imported_count);
}

int save_data(void){
  FILE *fp = fopen("teachers.txt", "w");
  if(fp == NULL){
    printf("错误：无法打开文件进行写入！\n");
    return -1;
  }

  // 写入CSV表头
  fprintf(fp, "ID,姓名,性别,单位名称,家庭住址,联系电话,基本工资,津贴,生活补贴,电话费,水电费,房租,所得税,卫生费,公积金,应发工资,扣除总额,实发工资\n");

  for(int i = 0; i < teacher_count; i++){
    fprintf(fp, "%d,%s,%s,%s,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n",
        teachers[i].id, teachers[i].name, teachers[i].gender, teachers[i].unit_name, 
        teachers[i].address, teachers[i].contact_number, teachers[i].basic_pay, 
        teachers[i].allowance, teachers[i].living_allowance, teachers[i].telephone_bill, 
        teachers[i].water_and_electrity_bill, teachers[i].rent, teachers[i].income_tax, 
        teachers[i].health_fee, teachers[i].provident_fund, teachers[i].payable_salary,
        teachers[i].total_deduction, teachers[i].actual_salary);
  }

  fclose(fp);
  printf("成功保存 %d 条教师记录到 teachers.txt。\n", teacher_count);
  return 0;
}

void display_menu(void){
  printf("\n--- 教师工资管理系统 ---\n");
  printf("1. 添加教师信息\n");
  printf("2. 修改教师信息\n");
  printf("3. 删除教师信息\n");
  printf("4. 浏览所有教师信息\n");
  printf("5. 查询指定教师信息\n");
  printf("6. 从文件导入信息\n");
  printf("7. 保存信息到文件\n");
  printf("0. 退出系统\n");
  printf("------------------------\n");
  printf("请选择操作(0-7): ");
}


int main(){
  int choice = 0;
  
  // 临时变量用于接收用户输入
  int id = 0;
  char name[50], gender[10], unit_name[100], address[100], contact_number[12];
  float basic_pay, allowance, living_allowance, telephone_bill, water_electrity_bill, rent, income_tax, health_fee, provident_fund;

  do {
    display_menu();
    if(scanf("%d", &choice) != 1){
      printf("无效输入，请输入数字！\n");
      clear_input_buffer(); // 清理错误输入
      choice = -1; // 设置为无效选项，继续循环
      continue;
    }
    
    clear_input_buffer(); // 清理 scanf 留下的换行符

    switch (choice) {
      case 1: // 添加教师
        printf("请输入教师ID: ");
        scanf("%d", &id); clear_input_buffer();
        printf("请输入姓名: ");
        fgets(name, sizeof(name), stdin); trim_newline(name);
        printf("请输入性别: ");
        fgets(gender, sizeof(gender), stdin); trim_newline(gender);
        printf("请输入单位名称: ");
        fgets(unit_name, sizeof(unit_name), stdin); trim_newline(unit_name);
        printf("请输入家庭住址: ");
        fgets(address, sizeof(address), stdin); trim_newline(address);
        printf("请输入联系电话: ");
        fgets(contact_number, sizeof(contact_number), stdin); trim_newline(contact_number);
        printf("请输入基本工资: "); scanf("%f", &basic_pay);
        printf("请输入津贴: "); scanf("%f", &allowance);
        printf("请输入生活补贴: "); scanf("%f", &living_allowance);
        printf("请输入电话费: "); scanf("%f", &telephone_bill);
        printf("请输入水电费: "); scanf("%f", &water_electrity_bill);
        printf("请输入房租: "); scanf("%f", &rent);
        printf("请输入所得税: "); scanf("%f", &income_tax);
        printf("请输入卫生费: "); scanf("%f", &health_fee);
        printf("请输入公积金: "); scanf("%f", &provident_fund);
        clear_input_buffer();
        add_teacher(id, name, gender, unit_name, address, contact_number, basic_pay, allowance, living_allowance, telephone_bill, water_electrity_bill, rent, income_tax, health_fee, provident_fund);
        break;
      
      case 2: // 修改教师
        printf("请输入要修改的教师ID: ");
        scanf("%d", &id); clear_input_buffer();
        printf("--- 请输入新的信息 ---\n");
        printf("请输入新姓名: ");
        fgets(name, sizeof(name), stdin); trim_newline(name);
        printf("请输入新性别: ");
        fgets(gender, sizeof(gender), stdin); trim_newline(gender);
        printf("请输入新单位名称: ");
        fgets(unit_name, sizeof(unit_name), stdin); trim_newline(unit_name);
        printf("请输入新家庭住址: ");
        fgets(address, sizeof(address), stdin); trim_newline(address);
        printf("请输入新联系电话: ");
        fgets(contact_number, sizeof(contact_number), stdin); trim_newline(contact_number);
        printf("请输入新基本工资: "); scanf("%f", &basic_pay);
        printf("请输入新津贴: "); scanf("%f", &allowance);
        printf("请输入新生活补贴: "); scanf("%f", &living_allowance);
        printf("请输入新电话费: "); scanf("%f", &telephone_bill);
        printf("请输入新水电费: "); scanf("%f", &water_electrity_bill);
        printf("请输入新房租: "); scanf("%f", &rent);
        printf("请输入新所得税: "); scanf("%f", &income_tax);
        printf("请输入新卫生费: "); scanf("%f", &health_fee);
        printf("请输入新公积金: "); scanf("%f", &provident_fund);
        clear_input_buffer();
        alter_teacher(id, name, gender, unit_name, address, contact_number, basic_pay, allowance, living_allowance, telephone_bill, water_electrity_bill, rent, income_tax, health_fee, provident_fund);
        break;
      
      case 3: // 删除教师
        printf("请输入要删除的教师ID: ");
        scanf("%d", &id);
        clear_input_buffer();
        delete_teacher(id);
        break;

      case 4: // 浏览所有
        show_all_teachers();
        break;

      case 5: // 查询指定
        printf("请输入要查询的教师ID: ");
        scanf("%d", &id);
        clear_input_buffer();
        query_teacher(id);
        break;

      case 6: // 导入
        import_teacher();
        break;

      case 7: // 保存
        save_data();
        break;

      case 0: // 退出
        printf("感谢使用，系统已退出。\n");
        break;

      default:
        printf("无效选项，请输入 0-7 之间的数字！\n");
        break;
    }
  } while (choice != 0);

  return 0;
}