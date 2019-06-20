#include <iostream>
#include <ctime>
#include "noise.h"

int main() {
    std::clock_t begin = clock();

    double arr[500][500];
    for (double y = 1; y <= 500; ++y) {
        for (double x = 1; x <= 500; ++x) {
            arr[(int)y - 1][(int)x - 1] = noise(x / 10, y / 10);
            std::cout << arr[(int)y - 1][(int)x - 1] << std::endl;
        }
    }
    std::clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    std::cout << elapsed_secs << std::endl;

    return 0;
}
