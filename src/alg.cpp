// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = len - 1; i >= 0 ; i--) {
        if (arr[i] <= value) {
            for (int j = i + 1; j < len; j++) {
                if (arr[i] + arr[j] == value) {
                    count++;
                }
            }
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int cur = 0;
  int mid = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i;
    int right = len;
    while (left < right - 1) {
      mid = (left + right) / 2;
      if (arr[i] + arr[mid] == value) {
        count++;
        cur = mid + 1;
        while (arr[i] + arr[cur] == value && cur < right) {
          count++;
          cur++;
        }
        cur = mid - 1;
        while (arr[i] + arr[cur] == value && cur > left) {
          count++;
          cur--;
        }
        break;
      }
      if (arr[i] + arr[mid] > value) {
        right = mid;
      } else {
        left = mid;
      }
    }
  }
  return count;
}
