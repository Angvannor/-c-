#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Ϊ�� exit()

// ��ʦ�ṹ�嶨��
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
  float payable_salary; // Ӧ������
  float telephone_bill;
  float water_and_electrity_bill;
  float rent;
  float income_tax;
  float health_fee;
  float provident_fund;
  float total_deduction; // �۳��ܶ�
  float actual_salary;   // ʵ������
} Teacher;

#define MAX_TEACHERS 100
Teacher teachers[MAX_TEACHERS];
int teacher_count = 0;

/* ����ԭ������ */
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


// �Ƴ��ַ���ĩβ�Ļ��з�
void trim_newline(char *s){
  size_t n = strlen(s);
  if(n > 0 && s[n-1] == '\n') s[n-1] = '\0';
}

// �������뻺����
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
    printf("���󣺽�ʦ��¼�������޷�������½�ʦ��\n");
    return -1;
  }

  // ���ID�Ƿ��Ѵ���
  for(int i = 0; i < teacher_count; i++){
    if(teachers[i].id == id){
      printf("����ID Ϊ %d �Ľ�ʦ�Ѵ��ڣ�\n", id);
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

  // �Զ����㹤��
  teachers[teacher_count].payable_salary = (basic_pay + allowance + living_allowance);
  teachers[teacher_count].total_deduction = (telephone_bill + water_and_electrity_bill + rent + income_tax + health_fee + provident_fund);
  teachers[teacher_count].actual_salary = teachers[teacher_count].payable_salary - teachers[teacher_count].total_deduction;

  teacher_count++;
  printf("�ɹ���ӽ�ʦ: %s (ID : %d)\n", name, id);
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
    printf("����δ�ҵ� ID Ϊ %d �Ľ�ʦ��\n", id);
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

  // ���¼��㹤��
  teachers[found_index].payable_salary = (basic_pay + allowance + living_allowance);
  teachers[found_index].total_deduction = (telephone_bill + water_and_electrity_bill + rent + income_tax + health_fee + provident_fund);
  teachers[found_index].actual_salary = teachers[found_index].payable_salary - teachers[found_index].total_deduction;

  printf("�ɹ��޸Ľ�ʦ��%s (ID : %d)\n", name, id);
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
    printf("����δ�ҵ� ID Ϊ %d �Ľ�ʦ��¼��\n", id_to_delete);
    return -1;
  }

  for(int j = found_index; j < teacher_count - 1; j++){
    teachers[j] = teachers[j+1];
  }

  teacher_count--;

  printf("�ɹ�ɾ�� ID Ϊ %d �Ľ�ʦ��¼��\n", id_to_delete);
  return 0;
}

void show_all_teachers(void){
  printf("\n--- ��ʦ�б� (%d ����ʦ) ---\n", teacher_count);
  if(teacher_count == 0){
    printf("Ŀǰû�н�ʦ��¼��\n");
    return;
  }

  printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
  printf("ID\t| ����\t\t| �Ա�\t| ��λ����\t\t| ��ͥסַ\t\t| ��ϵ�绰\t| ʵ������\n");
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
    printf("�����޷���ѯ�� ID Ϊ %d �Ľ�ʦ��\n", id_to_query);
    return;
  }
  
  printf("\n--- ��ѯ��� ---\n");
  printf("ID: %d\n", teachers[found_index].id);
  printf("����: %s\n", teachers[found_index].name);
  printf("�Ա�: %s\n", teachers[found_index].gender);
  printf("��λ����: %s\n", teachers[found_index].unit_name);
  printf("��ͥסַ: %s\n", teachers[found_index].address);
  printf("��ϵ�绰: %s\n", teachers[found_index].contact_number);
  printf("\n--- �������� ---\n");
  printf("Ӧ������: %.2f (����: %.2f, ����: %.2f, �����: %.2f)\n", 
        teachers[found_index].payable_salary, teachers[found_index].basic_pay, 
        teachers[found_index].allowance, teachers[found_index].living_allowance);
  printf("�۳��ܶ�: %.2f (�绰: %.2f, ˮ��: %.2f, ����: %.2f, ����˰: %.2f, ������: %.2f, ������: %.2f)\n", 
        teachers[found_index].total_deduction, teachers[found_index].telephone_bill, 
        teachers[found_index].water_and_electrity_bill, teachers[found_index].rent, 
        teachers[found_index].income_tax, teachers[found_index].health_fee, teachers[found_index].provident_fund);
  printf("ʵ������: %.2f\n", teachers[found_index].actual_salary);
  printf("----------------\n");
}


void import_teacher(void){
  FILE *fp = fopen("import.txt", "r");
  if(fp == NULL){
    printf("�����޷��� import.txt �ļ�����ȷ���ļ������ڳ���ͬĿ¼�¡�\n");
    return;
  }

  char line[512]; // �����������ڴ洢�ļ��е�ÿһ��
  int imported_count = 0;
  
  // ���ж�ȡ�ļ�
  while(fgets(line, sizeof(line), fp)){
      int id;
      char name[50], gender[10], unit_name[100], address[100], contact_number[12];
      float basic_pay, allowance, living_allowance, telephone_bill, water_electrity_bill, rent, income_tax, health_fee, provident_fund;

      // ʹ�� sscanf ���� CSV ��
      int result = sscanf(line, "%d,%49[^,],%9[^,],%99[^,],%99[^,],%11[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f",
          &id, name, gender, unit_name, address, contact_number, &basic_pay, &allowance,
          &living_allowance, &telephone_bill, &water_electrity_bill, &rent,
          &income_tax, &health_fee, &provident_fund);
      
      // ����ɹ�����������15���ֶ�
      if(result == 15){
        if(add_teacher(id, name, gender, unit_name, address, contact_number, 
                       basic_pay, allowance, living_allowance, telephone_bill, 
                       water_electrity_bill, rent, income_tax, health_fee, provident_fund) == 0){
          imported_count++;
        }
      } else {
        printf("���棺������ʽ����ȷ��һ�� -> %s", line);
      }
  }

  fclose(fp);
  printf("�ɹ��� import.txt ���� %d ����ʦ��¼��\n", imported_count);
}

int save_data(void){
  FILE *fp = fopen("teachers.txt", "w");
  if(fp == NULL){
    printf("�����޷����ļ�����д�룡\n");
    return -1;
  }

  // д��CSV��ͷ
  fprintf(fp, "ID,����,�Ա�,��λ����,��ͥסַ,��ϵ�绰,��������,����,�����,�绰��,ˮ���,����,����˰,������,������,Ӧ������,�۳��ܶ�,ʵ������\n");

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
  printf("�ɹ����� %d ����ʦ��¼�� teachers.txt��\n", teacher_count);
  return 0;
}

void display_menu(void){
  printf("\n--- ��ʦ���ʹ���ϵͳ ---\n");
  printf("1. ��ӽ�ʦ��Ϣ\n");
  printf("2. �޸Ľ�ʦ��Ϣ\n");
  printf("3. ɾ����ʦ��Ϣ\n");
  printf("4. ������н�ʦ��Ϣ\n");
  printf("5. ��ѯָ����ʦ��Ϣ\n");
  printf("6. ���ļ�������Ϣ\n");
  printf("7. ������Ϣ���ļ�\n");
  printf("0. �˳�ϵͳ\n");
  printf("------------------------\n");
  printf("��ѡ�����(0-7): ");
}


int main(){
  int choice = 0;
  
  // ��ʱ�������ڽ����û�����
  int id = 0;
  char name[50], gender[10], unit_name[100], address[100], contact_number[12];
  float basic_pay, allowance, living_allowance, telephone_bill, water_electrity_bill, rent, income_tax, health_fee, provident_fund;

  do {
    display_menu();
    if(scanf("%d", &choice) != 1){
      printf("��Ч���룬���������֣�\n");
      clear_input_buffer(); // �����������
      choice = -1; // ����Ϊ��Чѡ�����ѭ��
      continue;
    }
    
    clear_input_buffer(); // ���� scanf ���µĻ��з�

    switch (choice) {
      case 1: // ��ӽ�ʦ
        printf("�������ʦID: ");
        scanf("%d", &id); clear_input_buffer();
        printf("����������: ");
        fgets(name, sizeof(name), stdin); trim_newline(name);
        printf("�������Ա�: ");
        fgets(gender, sizeof(gender), stdin); trim_newline(gender);
        printf("�����뵥λ����: ");
        fgets(unit_name, sizeof(unit_name), stdin); trim_newline(unit_name);
        printf("�������ͥסַ: ");
        fgets(address, sizeof(address), stdin); trim_newline(address);
        printf("��������ϵ�绰: ");
        fgets(contact_number, sizeof(contact_number), stdin); trim_newline(contact_number);
        printf("�������������: "); scanf("%f", &basic_pay);
        printf("���������: "); scanf("%f", &allowance);
        printf("�����������: "); scanf("%f", &living_allowance);
        printf("������绰��: "); scanf("%f", &telephone_bill);
        printf("������ˮ���: "); scanf("%f", &water_electrity_bill);
        printf("�����뷿��: "); scanf("%f", &rent);
        printf("����������˰: "); scanf("%f", &income_tax);
        printf("������������: "); scanf("%f", &health_fee);
        printf("�����빫����: "); scanf("%f", &provident_fund);
        clear_input_buffer();
        add_teacher(id, name, gender, unit_name, address, contact_number, basic_pay, allowance, living_allowance, telephone_bill, water_electrity_bill, rent, income_tax, health_fee, provident_fund);
        break;
      
      case 2: // �޸Ľ�ʦ
        printf("������Ҫ�޸ĵĽ�ʦID: ");
        scanf("%d", &id); clear_input_buffer();
        printf("--- �������µ���Ϣ ---\n");
        printf("������������: ");
        fgets(name, sizeof(name), stdin); trim_newline(name);
        printf("���������Ա�: ");
        fgets(gender, sizeof(gender), stdin); trim_newline(gender);
        printf("�������µ�λ����: ");
        fgets(unit_name, sizeof(unit_name), stdin); trim_newline(unit_name);
        printf("�������¼�ͥסַ: ");
        fgets(address, sizeof(address), stdin); trim_newline(address);
        printf("����������ϵ�绰: ");
        fgets(contact_number, sizeof(contact_number), stdin); trim_newline(contact_number);
        printf("�������»�������: "); scanf("%f", &basic_pay);
        printf("�������½���: "); scanf("%f", &allowance);
        printf("�������������: "); scanf("%f", &living_allowance);
        printf("�������µ绰��: "); scanf("%f", &telephone_bill);
        printf("��������ˮ���: "); scanf("%f", &water_electrity_bill);
        printf("�������·���: "); scanf("%f", &rent);
        printf("������������˰: "); scanf("%f", &income_tax);
        printf("��������������: "); scanf("%f", &health_fee);
        printf("�������¹�����: "); scanf("%f", &provident_fund);
        clear_input_buffer();
        alter_teacher(id, name, gender, unit_name, address, contact_number, basic_pay, allowance, living_allowance, telephone_bill, water_electrity_bill, rent, income_tax, health_fee, provident_fund);
        break;
      
      case 3: // ɾ����ʦ
        printf("������Ҫɾ���Ľ�ʦID: ");
        scanf("%d", &id);
        clear_input_buffer();
        delete_teacher(id);
        break;

      case 4: // �������
        show_all_teachers();
        break;

      case 5: // ��ѯָ��
        printf("������Ҫ��ѯ�Ľ�ʦID: ");
        scanf("%d", &id);
        clear_input_buffer();
        query_teacher(id);
        break;

      case 6: // ����
        import_teacher();
        break;

      case 7: // ����
        save_data();
        break;

      case 0: // �˳�
        printf("��лʹ�ã�ϵͳ���˳���\n");
        break;

      default:
        printf("��Чѡ������� 0-7 ֮������֣�\n");
        break;
    }
  } while (choice != 0);

  return 0;
}