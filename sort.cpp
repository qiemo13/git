#include <stdio.h>
void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void selection_sort(int a[], int len)
{
    int i, j, temp;

    for (i = 0; i < len - 1; i++)
    {
        int min = i;                  // 记录最小值，第一个元素默认最小
        for (j = i + 1; j < len; j++)     // 访问未排序的元素
        {
            if (a[j] < a[min])    // 找到目前最小值
            {
                min = j;    // 记录最小值
            }
        }
        if (min != i)
        {
            temp = a[min];  // 交换两个变量
            a[min] = a[i];
            a[i] = temp;
        }
    }
}

void insertion_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 1; i < len; i++) {
        temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; j--)
            arr[j] = arr[j - 1];
        arr[j] = temp;
    }
}

int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int)sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n ");

    selection_sort(arr, len);
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n ");

    insertion_sort(arr, len);
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}
