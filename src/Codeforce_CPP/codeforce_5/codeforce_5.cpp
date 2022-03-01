#include <bits/stdc++.h>

int main () {
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
    int n, error = 0, grass_count = 0;
    std::cin >> n;
    std::vector <char> mas(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> mas[i];
    }

    for (int i = 0; i < n; i++) {
        if (i != n-1 && error != 1) {
            if (mas[i+1] == '"') {
                grass_count++;
                continue;
            } else if (mas[i+3] == '"') {
                if (mas[i+2] == '"' && mas[i+1] == '.') {
                    grass_count++;
                    i += 1;
                    continue;
                }
                grass_count++;
                i += 2;
                continue;
            } else if (mas[i+5] == '"') {
                if (mas[i+4] == '"' && mas[i+3] == '.') {
                    grass_count++;
                    i += 3;
                    continue;
                }
                    grass_count++;
                    i += 4;
                    continue;
            } else if (mas[i+3] == '.') {
                i += 2;
                continue;
            } else if (mas[i+1] == '.') {
                continue;
            } else if (mas[i+5] == '.') {
                i += 4;
                continue;
            } else {
                error = 1;
                grass_count = -1;
                break;
            }   
        }
    } 
        
    std::cout << grass_count;
}