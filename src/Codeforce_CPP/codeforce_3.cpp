#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include <stdlib.h>
#include <unordered_map>
#include <fstream>
#include <functional>

int main () {
    int t;
    std::cin >> t;
    if (1 <= t <= 48) {
        while (t--) {
            int length;
            std::cin >> length;
            if (3 <= length <= 50) {
                int p = length * length;

                std::vector <int> array(p);
                for (int i = 0; i < length; i++) {
                    array[i] = i + 2;
                }

                for (int i = length - 1; i < array.size(); i++) {
                    array[i] = array[i % (length - 1)];
                }
                
                for (int i = length; i > 1; i--) {
                    if (i == length) {
                        std::cout << 1 << ' ';
                    }
                    std::cout << i << ' ';

                    if (i == 2) {
                        std::cout << std::endl;
                    }
                }

                for (int i = 0; i < length - 1; i++) {
                    for (int j = 0; j < length - 1; j++) {
                        std::cout << array[j + i] << ' ';
                        if (j == length - 2) {
                            std::cout << 1 << std::endl;
                        }
                    }
                }
            } else {
                break;
            }
        }
    } else {
        return 0;
    }

    return 0;
}