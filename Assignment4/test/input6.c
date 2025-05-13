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
    return 0;
}