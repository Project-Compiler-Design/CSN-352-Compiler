int main(){
    int i=0;
    int *ptr = &i;
    int **ptr2 = &ptr;
    **ptr2 = 10;
    printf("%d\n", **ptr2);
    return 0;
}