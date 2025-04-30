//basic.c
// #include <stdio.h>

int addx(int a, int b) {
    return a + b;
}

int factorial(int n) {
    if (n <= 1) return 1;
    else return n * factorial(n - 1);
}

// int array_sum(int arr[5], int size) {

// }

struct Point {
    int x;
    int y;
};

// float point_sum(struct Point *p) {
//     return p->x / p->y;
// }

int main() {
    int a = 5, b = 10;

    int result = addx(a, b);
    if (result != 15) {
        printf("Arithmetic test failed: %d\n", result);
        return 1;
    }

    int fact = factorial(5);
    if (fact != 120) {
        printf("Recursion test failed: %d\n", fact);
        return 1;
    }

    int arr[5] = {1, 2, 3, 4, 5};
    // int arr_sum = array_sum(arr, 5);
    int array_sum = 0;
    int i = 0;
    for (i = 0; i < 5; i++) {
        array_sum = array_sum + arr[i];
    }
    // return sum;
    if (array_sum != 15) {
        printf("Array sum test failed: %d\n", array_sum);
        return 1;
    }

    // struct Point p = {3, 4};
    // // int p_sum = point_sum(&p);
    // // if (p_sum != 7) {
    // //     printf("Struct test failed: %d\n", p_sum);
    // //     return 1;
    // // }

    int value = 0;
    if (a < b) {
        value = 1;
    } else {
        value = 2;
    }
    if (value != 1) {
        printf("Branching test failed: %d\n", value);
        return 1;
    }

    printf("All tests passed successfully!\n");
    return 0;
}