#include <iostream>

int stoi(char* n, int len) {
    int res = 0;
    for(int i = 0; i < len; i++) {
        int digit = n[i] - '0';
        res = 10 * res + digit; 
    }
    return res;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void reverse(int* arr, int begin, int end) {
    end--;
    while (begin < end) {
        swap(arr[begin], arr[end]);
        begin++;
        end--;
    }
}

int main(int argc, char* argv[]) {
    char* &tmp = argv[1];
    int len = 0;
    for(int i = 0; tmp[i] != '\0'; i++) {len++;}
    int n = stoi(tmp, len);
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {std::cin >> arr[i];}
    int k;
    std::cin >> k;
    int sign = k > 0 ? 1 : (k < 0 ? -1 : 0);
    k = k * sign % n;
    if(sign == 1) {
        reverse(arr, 0, n - k);
        reverse(arr, n - k, n);
        reverse(arr, 0, n);
    } else if(sign == -1) {
        reverse(arr, 0, k);
        reverse(arr, k, n);
        reverse(arr, 0, n);
    }
    for(int i = 0; i < n; i++) {std::cout << arr[i] << '\n';}
    for(int i = 0; i < n; i++) {std::cout << arr[i] << ' ';}
    std::cout << std::endl;
    delete[] arr;
    return 0;
}