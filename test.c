#include <immintrin.h>
#include <stdio.h>

void add_float_arrays(const float* a, const float* b, float* result, int size) {
    int i;
    for (i = 0; i < size; i += 8) {
        __m256 va = _mm256_loadu_ps(&a[i]);  // Load 8 floats from array a
        __m256 vb = _mm256_loadu_ps(&b[i]);  // Load 8 floats from array b
        __m256 vr = _mm256_add_ps(va, vb);   // Add the 8 floats
        _mm256_storeu_ps(&result[i], vr);    // Store the result into result array
    }
}

int main() {
    const int size = 16;
    float a[size], b[size], result[size];

    // Initialize arrays a and b with some values
    for (int i = 0; i < size; ++i) {
        a[i] = i * 1.0f;
        b[i] = i * 2.0f;
    }





    // Add arrays
    add_float_arrays(a, b, result, size);

    // Print result
    for (int i = 0; i < size; ++i) {
        printf("%f ", result[i]);
    }

    return 0;
}
