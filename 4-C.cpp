//
// Created on 2023/10/2.
//
#include <cstdio>
#include <climits>

int myAtoi(char *s) {
    int sign = 1;
    int result = 0;
    int i = 0;
    while (s[i] == ' ') {
        i++;
    }
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9') {
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (s[i] - '0');
        i++;
    }

    return sign * result;
}

int main() {
    char s[201];
    scanf("%s", s);
    int result = myAtoi(s);
    printf("%d\n", result);
    return 0;
}
