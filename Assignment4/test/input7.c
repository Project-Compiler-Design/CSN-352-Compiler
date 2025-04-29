int main(){
    int i=0;
    int *ptr = &i;
    int **ptr2 = &ptr;
    **ptr2 = 10;
    printf("%d\n", i);
    return 0;
}