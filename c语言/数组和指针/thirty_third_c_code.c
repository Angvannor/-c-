#include <stdio.h>

// 选择排序函数
// arr[] : 待排序的数组
// n     : 数组长度
// cmp   : 比较函数指针（用于决定升序还是降序）
void selection_sort(int arr[], int n, int (*cmp)(int, int)) {
    for (int i = 0; i < n - 1; i++) {     // 外层循环：从第 i 个位置开始，找到剩余元素的最小/最大值
        int min_index = i;                // 假设当前位置 i 是最小(或最大)值下标
        for (int j = i + 1; j < n; j++) { // 内层循环：在未排序部分中寻找更小(或更大)的值
            if (cmp(arr[j], arr[min_index])) { // 如果 arr[j] 比 arr[min_index] 更符合排序规则
                min_index = j;                 // 更新最小(或最大)值的下标
            }
        }
        // 将找到的最小(或最大)值与当前位置交换
        int tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;
    }
}

// 升序比较函数：如果 a < b，返回真 (1)，表示 a 更小，应排在前面
int cmp_asc(int a, int b) { return a < b; }

// 降序比较函数：如果 a > b，返回真 (1)，表示 a 更大，应排在前面
int cmp_desc(int a, int b) { return a > b; }

int main() {
    int arr[] = {5, 2, 9, 1, 7};                  // 待排序数组
    int n = sizeof(arr) / sizeof(arr[0]);         // 计算数组长度

    printf("升序排序:\n");
    selection_sort(arr, n, cmp_asc);              // 使用升序比较函数排序
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("降序排序:\n");
    selection_sort(arr, n, cmp_desc);             // 使用降序比较函数排序
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
