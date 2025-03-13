#include <stdio.h>
#include "minunit.h"

// gcc test_vector3_inner_product.c -o test3.exe

typedef double gdouble;

typedef struct {
    double x;
    double y;
    double z;
} GimpVector3;

gdouble gimp_vector3_inner_product(const GimpVector3 *vector1, const GimpVector3 *vector2)
{
    return (vector1->x * vector2->x +
            vector1->y * vector2->y +
            vector1->z * vector2->z);
}

MU_TEST(test_gimp_vector3_inner_product) {
    GimpVector3 vector1 = {1.0, 2.0, 3.0};
    GimpVector3 vector2 = {4.0, 5.0, 6.0};

    gdouble result = gimp_vector3_inner_product(&vector1, &vector2);

    mu_assert_double_eq(result, 32.0);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_gimp_vector3_inner_product);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
