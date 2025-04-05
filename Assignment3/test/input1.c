int main()
{
    char i;
    int p=0;
    int a=0;
    switch(i)
    {
        case 'a':
        {
            int a=0;
            p++;
            break;
        }
        case 'b':
        
        {
            switch(p)
            {
                case 1:
                {
                    int b=0;
                    a++;
                    break;
                }
                case 2:
                {
                    int c=0;
                    a--;
                    break;
                }
            }
        
            break;
        
        }
    }
    
    return 0;
}