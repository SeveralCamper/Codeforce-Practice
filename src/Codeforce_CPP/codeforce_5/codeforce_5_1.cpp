#include <bits/stdc++.h>

#define INT_MIN_BORDER -2147483648

int main () {
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
    int n;
    std::cin >> n;
    std::string s;
    std::vector <int> mas(n,INT_MIN_BORDER);
    mas[0] = 0;
    std::cin >> s;
    for (int i = 1; i < n; i++) {
        if (s[i] != 'w') {
            if (i - 1 >= 0) {
                if (s[i - 1] != 'w') {
                    mas[i] = mas[i - 1] + (s[i] == '"');
                }
            }
            if (i - 3 >= 0) {
                if (s[i - 3] != 'w') {
                   mas[i] = std::max(mas[i-3] + (s[i] == '"'), mas[i]); 
                }
            } 
            if (i - 5 >= 0) {
                if (s[i - 5] != 'w') {
                    mas[i] = std::max(mas[i-5] + (s[i] == '"'), mas[i]);
                }
            }
        } 
    }
    if (mas[n - 1] >= 0)
    std::cout << mas[n - 1];
    else {
    std::cout << -1;
    }
}