#include <stdio.h>
#include "minunit.h"

// gcc test_vector2_normalize.c -o test.exe

typedef double gdouble;

typedef struct {
    double x;
    double y;
} GimpVector2;

gdouble gimp_vector2_length(GimpVector2 *vector) {
    return sqrt(vector->x * vector->x + vector->y * vector->y);
}

GimpVector2 gimp_vector2_zero = {0.0, 0.0};

void gimp_vector2_normalize(GimpVector2 *vector) {
    gdouble len;

    len = gimp_vector2_length(vector);

    if (len != 0.0) {
        len = 1.0 / len;
        vector->x *= len;
        vector->y *= len;
    } else {
        *vector = gimp_vector2_zero;
    }
}

MU_TEST(test_gimp_vector2_normalize_non_zero) {
    GimpVector2 vector = {3.0, 4.0};
    gimp_vector2_normalize(&vector);
    mu_assert_double_eq(vector.x, 0.6);
    mu_assert_double_eq(vector.y, 0.8);
}

MU_TEST(test_gimp_vector2_normalize_zero) {
    GimpVector2 vector = {0.0, 0.0};
    gimp_vector2_normalize(&vector);
    mu_assert_double_eq(vector.x, 0.0);
    mu_assert_double_eq(vector.y, 0.0);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_gimp_vector2_normalize_non_zero);
    MU_RUN_TEST(test_gimp_vector2_normalize_zero);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
