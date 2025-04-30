int main() {
    int a = 5, b = 10, c = 15, d = 20;

    // Redundant calculation
    int x = a * 2;
    int y = a + a;

    // Constant folding
    int z = 4 * 5;
    float w = 30.0 / 5.0;

    // Strength reduction
    int u = d * 8; 

    // Dead code (if optimization is enabled)
    int unused = 100;

    // Combine multiple increments
    int counter = 0;
    counter = counter + 1;
    counter = counter + 1;
    counter = counter + 1;

    int temp = b;
    temp = temp;// Useless assignment

    if (1) {
        printf("This branch is always taken.\n");
    } else {
        printf("This branch is never taken.\n");
    }

    printf("Results: x=%d, y=%d, z=%d, w=%f, u=%d, counter=%d\n", x, y, z, w, u, counter);

    return 0;
}
