
int main(){
    int i=0;
    int *ptr = &i;
    i+=1;
    printf("%d\n", *ptr);
    int y = 50;
    {
        y--;
    }
    int* p1 = &y;
   
    printf("Single level pointer value: %d\n", *p1);
    return 0;
}