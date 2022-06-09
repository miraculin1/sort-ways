#include <iostream>
void shellSort(int *nums, int numsSize, int *daltas, int daltasSize) {
  for (int i = 0; i < daltasSize; i++) {
    int dalta = daltas[i];

    for (int k = dalta; k < numsSize; k++) {
      int freshman = nums[k];
      int b = 0;
      for (b = k - dalta; b >= 0; b -= dalta) {
        if (nums[b] > freshman) {
          nums[b + dalta] = nums[b];
        } else {
          break;
        }
      }
      nums[b + dalta] = freshman;
    }
  }
}

int main() {
  int numsSize = 9;
  int daltasSize = 2;
  int daltas[]{3, 1};
  int nums[]{4, 5, 3, 1, 8, 2, 6, 9, 7};
  shellSort(nums, numsSize, daltas, daltasSize);

  for (int i = 0; i < numsSize; i++) {
    std::cout << nums[i];
  }
}
