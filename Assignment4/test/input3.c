int main()
{
    int num, count, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // for loop terminates when count exceeds num
    for(count = 1; count <= num; count++)
    {
        sum &= count;
    }

    printf("Sum = %d", sum);

    return 0;
}