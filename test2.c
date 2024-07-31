#include <immintrin.h>
#include <stdio.h>

void add_float_arrays(const float* a, const float* b, float* result, int size) {
    int i;
    for (i = 0; i < size; i += 8) {
        __m256 va = _mm256_loadu_ps(&a[i]);
        __m256 vb = _mm256_loadu_ps(&b[i]);
        __m256 vr = _mm256_add_ps(va, vb);
        _mm256_storeu_ps(&result[i], vr);
    }
}

int main() {
    const int size = 16;
    float a[size], b[size], result[size];

    for (int i = 0; i < size; ++i) {
        a[i] = i * 1.0f;
        b[i] = i * 2.0f;
    }





    add_float_arrays(a, b, result, size);

    for (int i = 0; i < size; ++i) {
        printf("%f ", result[i]);
    }

    return 0;
}
