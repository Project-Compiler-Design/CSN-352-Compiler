int glb;
int glb1 = 10;

int glb2;
struct foo
{
    int a;
    int b;
    struct foo *next;
};

int bar(int a, float b)
{
    int lcl = 10;
    while (b)
    {
        b--;
    }
    if (a == 0){
        return 0;
    }
        
    bar(++a, a + b + lcl); // what if I use a++;
}

int main()
{
    // int a=4;
    int a = 100, b[20], ret,glb;
    b[1]=5;
    static int hi;
    int arr[5] = {1,2,3,4,5};
    int i;
    for ( i = 0; i < a; i++)
    {
        int b = 0;
        b += i;
        if (b % 2 != b % 3)
            printf("%d\n", a + b);
        else if (b % 2 == 0)
        {
            switch (b)
            {
            case 100:
                printf("1\n");
                break;
            case 1000:
                printf("2\n");
            default:
                printf("2\n");
            }
        }
        // b[19] = i;
        ret = i;
    }
    int *c=b+2; // change to *
    c=b;
jump:
    struct foo newS[5];
    // printf(newS[3].b);
    // if (*(b+2) == 0){
    //     goto jump;
    // }
        // goto jump;
    bar(1, *b);
}