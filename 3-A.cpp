//
// Created on 2023/10/2.
//
#include <iostream>
#include <string>
using namespace std;
string below_20[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string Change(int num) {
    if (num == 0) return "Zero";
    string result = "";
    if (num >= 1e9) {
        result += Change(num / 1e9) + " Billion ";
        num %= (int)1e9;
    }
    if (num >= 1e6) {
        result += Change(num / 1e6) + " Million ";
        num %= (int)1e6;
    }
    if (num >= 1e3) {
        result += Change(num / 1e3) + " Thousand ";
        num %= (int)1e3;
    }
    if (num >= 100) {
        result += below_20[num / 100] + " Hundred ";
        num %= 100;
    }
    if (num >= 20) {
        result += tens[num / 10] + " ";
        num %= 10;
    }
    if (num > 0) {
        result += below_20[num] + " ";
    }
    // Remove trailing space
    if (result.back() == ' ') {
        result.pop_back();
    }
    return result;
}
int main() {
    int n;
    cin >> n;
    string result = Change(n);
    cout << result << endl;
    return 0;
}