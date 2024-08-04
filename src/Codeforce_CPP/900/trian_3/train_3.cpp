#include <bits/stdc++.h>

int main () {
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
    int n;
    std::cin >> n;
    std::vector <int> mas(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> mas[i];
    }

    for (int i = 2; i <= n; i++) {
        if (mas[i - 2] < mas[i - 1]) {
            mas[i] += mas[i - 1];
        } else {
            mas[i] += mas[i - 2];
        }
    }
    std::cout << mas[n];
}