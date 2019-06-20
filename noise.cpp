#include <cmath>

const int sec_width = 5;
const int hash_table[256] = {200, 35, 82, 243, 87, 134, 68, 179, 7, 14, 85, 64, 55, 83, 46, 151, 214, 95, 161, 19, 112, 69, 194, 56, 204, 65, 79, 140, 241, 57, 203, 136, 119, 137, 187, 150, 28, 192, 228, 217, 73, 222, 178, 105, 0, 103, 202, 133, 110, 242, 235, 115, 164, 25, 183,248, 113, 195, 84, 163, 147, 61, 210, 197, 122, 201, 108, 21, 227, 173, 117, 246, 96, 182, 88, 66, 138, 238, 186, 148, 185, 31, 44, 181, 77, 234, 29, 152, 239, 158, 237, 100, 116, 26, 6, 2, 53, 193, 10, 30, 174, 229, 45, 71, 51, 253, 198, 153, 43, 128, 213, 13, 209, 212, 224, 189, 114, 93, 132, 165, 142, 76, 90, 143, 32, 9, 131, 127, 233, 157, 223, 11, 118, 8, 221, 231, 156,92, 252, 15, 199, 5, 50, 191, 107, 226, 39, 180, 251, 27, 219,1, 12, 139, 188, 240, 99, 244, 155, 41, 126, 109, 225, 145, 23, 250, 236, 121, 220, 169, 177, 62, 144, 168, 159, 190, 70, 120, 249, 232, 47, 42, 94, 149, 60, 36, 20, 78, 124, 4, 135, 91, 130, 97, 75, 154, 208, 48, 54, 215, 18, 146, 17, 167, 38, 34, 141, 171, 74, 33, 172, 104, 40, 175, 170, 52, 184, 207, 125, 176,218, 67, 245, 49, 101, 86, 80, 37, 98, 106, 211, 166, 89, 196,216, 58, 63, 230, 205, 81, 16, 123, 129, 24, 247, 22, 111, 72,206, 255, 254, 160, 162, 102, 3, 59};

double lerp(double x0, double x1, double t) {
    // Linear interpolation
    return x0 + t * (x1 - x0);
}

double fade(double x) {
    // Fade function
    return 6*std::pow(x, 5) - 15*std::pow(x, 4) + 10*std::pow(x, 3);
}

int inc(int n) {
    return (n + 1) % sec_width;
}

double gradient(int hash, double x, double y) {
    int h = hash & 15;
    double u = h < 8 ? x : y, v = h < 4 ? y : x;
    
    return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

double noise(double x, double y) {
    int permutations[512], xi, yi, aa, ab, ba, bb;
    double location_x, location_y, faded_x, faded_y, x0, x1, out;

    for (int i = 0; i < 512; ++i) {
        permutations[i] = hash_table[i % 256];
    }

    x = fmod(x, sec_width);
    y = fmod(y, sec_width);

    xi = (int)x & 255;
    yi = (int)y & 255;

    location_x = x - (int)x;
    location_y = y - (int)y;

    faded_x = fade(location_x);
    faded_y = fade(location_y);

    aa = permutations[permutations[xi] + yi];
    ab = permutations[permutations[xi] + inc(yi)];
    ba = permutations[permutations[inc(xi)] + yi];
    bb = permutations[permutations[inc(xi)] + inc(yi)];

    x0 = lerp(gradient(aa, location_x, location_y), gradient(ba, location_x - 1, location_y), faded_x);
    x1 = lerp(gradient(ab, location_x, location_y - 1), gradient(bb, location_x - 1, location_y - 1), faded_y);
    out = lerp(x0, x1, faded_y);

    return out;
}
