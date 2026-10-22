#include <iostream>

const int MAX = 100'005;

char integerX[MAX];
char fractX[MAX];
char integerY[MAX];
char fractY[MAX];

const char* ans[] = {"less", "equal", "greater"};

void separate(char* n, int& cntI, int& cntF, int& isPositive, char (&arrI)[MAX], char (&arrF)[MAX]) {
    int p = 0;
    if(n[0] == '-') {
        isPositive = 0;
        p++;
    } else {
        isPositive = 1;
        if(n[0] == '+') p++;
    }
    int i = 0;
    while(n[p] != '\0') {
        if(n[p] == '.') break;
        arrI[i++] = n[p++];
        cntI++;
    }
    i = 0;
    while(n[p] != '\0') {
        if(n[p] == '.') {
            p++;
            continue;
        }
        arrF[i++] = n[p++];
        cntF++;
    }
    if(cntF == 0) {
        cntF++;
        arrF[0] = '0';
    }
}

int main(int argc, char* argv[]) {
    if(argc != 3) return 1;
    char* x = argv[1];
    char* y = argv[2];
    int res = -1;
    int ix = 0, fx = 0, isXPositive = 0;
    separate(x, ix, fx, isXPositive, integerX, fractX);
    int iy = 0, fy = 0, isYPositive = 0;
    separate(y, iy, fy, isYPositive, integerY, fractY);
    if(isXPositive ^ isYPositive) {
        if(isYPositive) res = 0;
        else res = 2;
    } else {
        if(ix < iy) res = 0;
        else if(ix > iy) res = 2;
        else {
            for(int i = 0; i < ix; i++) {
                if(integerX[i] < integerY[i]) {
                    res = 0;
                    break;
                }
                if(integerX[i] > integerY[i]) {
                    res = 2;
                    break;
                }
            }
            if(res == -1) {
                int m;
                if(fx < fy) m = fx;
                else m = fy;
                for(int i = 0; i < m; i++) {
                    if(fractX[i] < fractY[i]) {
                        res = 0;
                        break;
                    }
                    if(fractX[i] > fractY[i]) {
                        res = 2;
                        break;
                    }
                }
                if(res == -1) {
                    if(fx != fy) res = m == fx ? 0 : 2;
                    else res = 1;
                }
            }
        }
        if(!isXPositive) {
            if(res == 0) res = 2;
            else if(res == 2) res = 0;
        }
    }
    std::cout << ans[res] << std::endl;
    return 0;
}
