struct A{
    int a;
    int b;
};

int main() {
    struct A str;
    str.a = 7;
    str.b = 8;
    int a[3]={5,4,5};
    int c=a[0];
    printf("%d\n", c);
    int y = 50;
    int* p1 = &y;
    printf("Multi-level pointer value: %d\n", *p1);
    return 0;
}