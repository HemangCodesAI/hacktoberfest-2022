//it is made for a special case for finding 10.
//uncomment to take user input
#include <iostream>
using namespace std;
int linear_search(int arr[], int N, int x, int low, int high) {
  int i = low;
  for (; i < N; i++)
    if (arr[i] == x) {
      cout << x << " found at index " << i;
      return i;
    }
  cout << "not found";
  return -1;
}
int jump_search(int a[], int n, int search_key, int low, int high, int jump) {
  while (low <= high) {
    if (a[low] == search_key) {
      cout << search_key << " found at index " << low;
      return 0;
    } else if (a[low] < search_key) {
      low += jump;
    } else if (a[low] > search_key) {
      high = low - 1;
      low -= jump;
      linear_search(a, n, search_key, low, high);
      // return 0;
    } else {
      low += jump;
      cout << "@";
    }
  }
  if (low > n) {
    cout << search_key << " not found in the given array";
  }
  return 0;
}

int main() {
  int n{9};
  // cin >> n;
  int a[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
  // for (int i{}; i < n; i++) {
  //   cin >> a[i];
  // }
  int jump{2};
  int low{0};
  int high{8};
  int search_key{10};
  // cin >> low >> high >> search_key>>jump;
  jump_search(a, n, search_key, low, high, jump);
  return 0;
}
