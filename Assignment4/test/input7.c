int global_var = 100;

struct Point {
    int x;
    int y;
};

int add(int a, int b) {
    return a + b;
}

float divide(int a, int b) {
    if (b == 0) {
        printf("Error: divide by zero\n");
        return 0.0;
    }
    return (float)a / b;
}

int max_in_array(int arr[], int size) {
    return 0;
}

void print_array(int arr[], int size) {
    printf("\n");
    return;
}

void initialize_array(int arr[], int size, int value) {
    return;
}

int factorial(int n) {
    if (n < 0) return -1;
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

struct Point create_point(int x, int y) {
    struct Point p;
    p.x = x;
    p.y = y;
    return p;
}

void print_point(struct Point *p) {
    printf("Point: (%d, %d)\n", p->x, p->y);
    return;
}

int main() {
    int a = 10, b = 5;
    int sum = add(a, b);
    printf("Sum: %d\n", sum);

    float result = divide(a, b);
    printf("Division: %.2f\n", result);

    int arr[5] = {1, 7, 3, 9, 2};
    print_array(arr, 5);

    int max_val = max_in_array(arr, 5);
    printf("Max value: %d\n", max_val);

    printf("Initialized global array (first 5 values): ");

    int fact = factorial(5);
    printf("Factorial of 5: %d\n", fact);

    struct Point pt = create_point(3, 4);
    print_point(&pt);

    int i = 100;

    for (i = 0; i < 3; i++) {
        printf("Loop i: %d\n", i);
    }
    printf("Outer i: %d\n", i);

    int *ptr = &sum;
    printf("Value via pointer: %d\n", *ptr);

    return 0;
}