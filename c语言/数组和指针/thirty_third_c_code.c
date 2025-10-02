#include <stdio.h>

// ѡ��������
// arr[] : �����������
// n     : ���鳤��
// cmp   : �ȽϺ���ָ�루���ھ��������ǽ���
void selection_sort(int arr[], int n, int (*cmp)(int, int)) {
    for (int i = 0; i < n - 1; i++) {     // ���ѭ�����ӵ� i ��λ�ÿ�ʼ���ҵ�ʣ��Ԫ�ص���С/���ֵ
        int min_index = i;                // ���赱ǰλ�� i ����С(�����)ֵ�±�
        for (int j = i + 1; j < n; j++) { // �ڲ�ѭ������δ���򲿷���Ѱ�Ҹ�С(�����)��ֵ
            if (cmp(arr[j], arr[min_index])) { // ��� arr[j] �� arr[min_index] �������������
                min_index = j;                 // ������С(�����)ֵ���±�
            }
        }
        // ���ҵ�����С(�����)ֵ�뵱ǰλ�ý���
        int tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;
    }
}

// ����ȽϺ�������� a < b�������� (1)����ʾ a ��С��Ӧ����ǰ��
int cmp_asc(int a, int b) { return a < b; }

// ����ȽϺ�������� a > b�������� (1)����ʾ a ����Ӧ����ǰ��
int cmp_desc(int a, int b) { return a > b; }

int main() {
    int arr[] = {5, 2, 9, 1, 7};                  // ����������
    int n = sizeof(arr) / sizeof(arr[0]);         // �������鳤��

    printf("��������:\n");
    selection_sort(arr, n, cmp_asc);              // ʹ������ȽϺ�������
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("��������:\n");
    selection_sort(arr, n, cmp_desc);             // ʹ�ý���ȽϺ�������
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
