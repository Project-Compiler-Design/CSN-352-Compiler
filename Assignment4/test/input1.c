
int main() {
    float a = 1.0;
    float *b = &a;
    float **c = &b;
    **c = 2.0;
    printf("%f\n", c);
    return 0;

}



