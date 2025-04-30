typedef int Integer;
int main() {
    Integer a = 3;
    Integer b = 10;
    Integer c;
    switch(a)
    {
        case 1:
            c = a + b;
            printf("c is %d\n", c);
            break;
        case 2:
            c = a - b;
            printf("c is%d\n", c);
            break;
        case 3:
            c = a * b;
            printf("c is%d\n", c);
            break;
        default:
            c = a / b;
            printf("c is %d\n", c);
    }
    int i=2;
    until(i<0)
    {
        printf("i is %d\n", i);
        i--;
    }
    return 0;
}