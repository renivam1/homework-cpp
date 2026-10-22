#include <iostream>

int stoi(char* n, int len) {
    int res = 0;
    for(int i = 0; i < len; i++) {
        int digit = n[i] - '0';
        res = 10 * res + digit;
    }
    return res;
}

int main(int argc, char* argv[]) {
    if(argc != 2) return 1;
    std::cout.precision(6);
    char* tmp = argv[1];
    int len = 0;
    for(int i = 0; tmp[i] != '\0'; i++) len++;
    int n = stoi(tmp, len);
    double* a = new double[n];
    for(int i = 0; i < n; i++) std::cin >> a[i];
    double* b = new double[n];
    for(int i = 0; i < n; i++) std::cin >> b[i];
    double res = 0;
    for(int i = 0; i < n; i++) res += a[i] * b[i];
    std::cout << res << std::endl;
    delete[] a;
    delete[] b;
    return 0;
}
