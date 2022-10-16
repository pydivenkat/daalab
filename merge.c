#include <stdio.h>

#include <stdlib.h>

#include <math.h>

int count = 0;
void merge(int a[], int low, int mid, int high) {
  int i, j, k, c[1000];
  i = k = low;
  j = mid + 1;

  while (i <= mid && j <= high) {
    count++;
    if (a[i] < a[j])
      c[k++] = a[i++];
    else
      c[k++] = a[j++];
  }
  while (i <= mid) {
    count++;
    c[k++] = a[i++];
  }
  while (j <= high) {
    count++;
    c[k++] = a[j++];
  }
  for (i = low; i < k; i++) {

    a[i] = c[i];
  }
}
void mergesort(int a[], int low, int high) {

  if (low < high) {

    int mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}
void main() {
  int c1, c2, c3, arr[1000], n, i, a[1000], b[1000], c[1000], j;
  printf("Enter the size of array: ");
  scanf("%d", & n);
  printf("\nEnter the elements: \n");
  for (i = 0; i < n; i++) {
    scanf("%d", & arr[i]);
  }
  count = 0;
  mergesort(arr, 0, n - 1);
  printf("Array after sorting:\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\nThe count is %d\n", count);
  count = 0;
  printf("Total count:\n");
  printf("size\t ascending\t descending\t random\n");
  for (i = 5; i < 600; i = i * 2) {
    for (j = 0; j < i; j++) {
      a[j] = j;
      b[j] = i - j;
      c[j] = rand() % i;
    }
    count = 0;
    mergesort(a, 0, i - 1);
    c1 = count;
    count = 0;
    mergesort(b, 0, i - 1);
    c2 = count;
    count = 0;
    mergesort(c, 0, i - 1);
    c3 = count;

    printf("%d\t\t%d\t\t%d\t\t%d\n", i, c1, c2, c3);
  }
}
