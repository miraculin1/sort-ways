#include <stdio.h>
#include <stdlib.h>

int *merge(int *nums1, int len1, int *nums2, int len2) {
  int *res = malloc(sizeof(int) * (len1 + len2));
  int rescount = 0;
  int l = 0, r = 0;
  while (l < len1 && r < len2) {
    if (nums1[l] < nums2[r]) {
      res[rescount++] = nums1[l];
      l++;
    } else {
      res[rescount++] = nums2[r];
      r++;
    }
  }
  if (l < len1) {
    while (l < len1) {
      res[rescount++] = nums1[l];
      l++;
    }
  } else {
    while (r < len2) {
      res[rescount++] = nums2[r];
      r++;
    }
  }

  return res;
}

// 将 l<->r 之间排序，返回一个需要 free 的排好序的数组
int *sort(int *nums, int l, int r) {
  if (r - l == 0) {
    // 基础情况
    int *res = malloc(sizeof(int));
    *res = nums[l];
    return res;
  }

  // 划分递归
  int mid = (l + r) / 2;
  int *p1 = sort(nums, l, mid);
  int *p2 = sort(nums, mid + 1, r);
  int *res = merge(p1, mid - l + 1, p2, r - mid);
  free(p1);
  free(p2);
  return res;
}

int *mergeSort(int *nums, int numsSize) { return sort(nums, 0, numsSize - 1); }

int main() {
  int data[] = {4, 3, 1, 2, 5, 9, 34};
  int size = 7;
  int *res = mergeSort(data, size);
  for (int i = 0; i < size; i++) {
    printf("%d ", res[i]);
  }
}
