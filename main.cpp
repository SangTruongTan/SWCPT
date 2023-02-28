#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

inline void add_each(char *pLower, char *pGreater, int iLowerLen,
                     int iGreaterLen);

char R[72 + 1];
int RTemp[36][72 + 1];
int main() {
    cout << "Hello world" << endl;
    char Buf1[] = "-110101";
    char Buf2[] = "101";
    int base = 2;
    int SignBuf1 = 1;
    int SignBuf2 = 1;
    char *pBuf1 = Buf1;
    char *pBuf2 = Buf2;
    memset(RTemp, '\0', 36 * (72 + 1)*sizeof(int));
    if (Buf1[0] == '-') {
        pBuf1 += 1;
        SignBuf1 = -1;
    }
    if (Buf2[0] == '-') {
        pBuf2 += 1;
        SignBuf2 = -1;
    }
    int Buf1Len = strlen(pBuf1);
    int Buf2Len = strlen(pBuf2);
    cout << "Hello2" << endl;
    if (Buf1Len > Buf2Len) {
        add_each(pBuf2, pBuf1, Buf2Len, Buf1Len);
    } else {
        add_each(pBuf1, pBuf2, Buf1Len, Buf2Len);
    }
}

inline void add_each(char *pLower, char *pGreater, int iLowerLen,
                     int iGreaterLen) {
    // Convert String to numerical
    for (int i = 0; i < iGreaterLen; i++) {
        if (i < iLowerLen) {
            pLower[i] =
                pLower[i] <= '9' ? pLower[i] - '0' : pLower[i] - 'A' + 10;
        }
        if (i < iGreaterLen) {
            pGreater[i] =
                pGreater[i] <= '9' ? pGreater[i] - '0' : pGreater[i] - 'A' + 10;
        }
    }
    for (int i = 0; i < iLowerLen; i++) {
        for (int j = 0; j < iGreaterLen + iLowerLen - 1; j++) {
            if (j > iGreaterLen + i - 1)
                continue;
            int val1 = (int)pLower[iLowerLen - i - 1] * pGreater[iGreaterLen - j - 1];
            RTemp[i][j + i] = val1;
        }
    }
    for (int i = 0; i < iLowerLen; i++) {
        for (int j = 0; j < iGreaterLen + iLowerLen - 1; j++) {
            cout << RTemp[i][j] << " ";
        }
        cout << endl;
    }
}