#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include <stdlib.h>
#include <unordered_map>
#include <fstream>
#include <functional>

int main () {
    int t, * res_array = NULL;
    std::cin >> t;
    if (1 <= t <= 720) {
        int iter = 1;
        bool flag = 1;
        while(t--) {
            int r = 0, g = 0, b = 0;
            flag = 1;
            std::string string;
            std::cin >> string;
            for (int i = 0; i < string.size(); i++) {
                if (i == 0 && (string[i] == 'R' || string[i] == 'G' || string[i] == 'B')) {
                    flag = 0;
                }

                if (string[i] == 'R' && r < 1 || string[i] == 'G' && g < 1 || string[i] == 'B' && b < 1) {
                    flag = 0;
                }

                if (string[i]=='r') r++;
                if (string[i]=='g') g++;
                if (string[i]=='b') b++;
                if (string[i]=='R') r--;
                if (string[i]=='G') g--;
                if (string[i]=='B') b--;
            }

            res_array = (int *)realloc(res_array, (iter + 1) * sizeof(int));
            res_array[iter] = flag;
            iter++;            
        }

        for (int i = 1; i < iter; i++) {
            if (res_array[i] == 1) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}