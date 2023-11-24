//
// Created on 2023/11/18.
//
#include <iostream>
#include<string>
using namespace std;

void nextbulid(const char* pattern, int m, int *next) {
    int len = 0;
    next[0] = 0;

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            next[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = next[len - 1];
            } else {
                next[i] = 0;
                i++;
            }
        }
    }
}

void kmpSearch(const char* text, const char* pattern,int m,int n) {
    int flag=0;
    int *next;
    next = new int[m];
    for(int i=0;i<m;i++){
        next[i]=0;
    }
    nextbulid(pattern, m, next);

    int i = 0; // 索引text
    int j = 0; // 索引pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            // 找到匹配，输出位置
            cout << i - j << " ";
            flag=1;
            j = next[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }
    }
    if(flag==0)
    {
        cout<<-1;
    }
}

int main() {
    int len_s1, len_s2;
    cin >> len_s1 >> len_s2;

    char* s1 = new char[len_s1 + 1];
    char* s2 = new char[len_s2 + 1];

    cin >> s1 >> s2;

    kmpSearch(s1, s2,len_s2,len_s1);

    delete[] s1;
    delete[] s2;

    return 0;
}
