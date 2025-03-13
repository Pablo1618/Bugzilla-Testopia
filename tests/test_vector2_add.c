#include <stdio.h>
#include "minunit.h"

// gcc test_vector2_add.c -o test2.exe

typedef struct {
    double x;
    double y;
} GimpVector2;

void gimp_vector2_add(GimpVector2 *result, const GimpVector2 *vector1, const GimpVector2 *vector2)
{
    result->x = vector1->x + vector2->x;
    result->y = vector1->y + vector2->y;
}

MU_TEST(test_gimp_vector2_add) {
    GimpVector2 vector1 = {1.0, 2.0};
    GimpVector2 vector2 = {3.0, 4.0};
    GimpVector2 result;

    gimp_vector2_add(&result, &vector1, &vector2);

    mu_assert_double_eq(result.x, 4.0);
    mu_assert_double_eq(result.y, 6.0);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_gimp_vector2_add);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
