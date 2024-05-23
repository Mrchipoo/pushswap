 #include <stdio.h>
    void  ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

    int partition(int q[], int l, int r){
    int i,j;
    int p = q[l];
    i = l;
    j = r;
    while(i < j)
    {
        while(q[i] <= p)
            i++;
        while(q[j] > p)
            j--;
        if(i < j)
            ft_swap(&q[i],&q[j]);  
    }
    ft_swap(&q[l],&q[j]);
    return i;
}

    void quicksort(int *ptr, int low, int high)
    {
        if (low < high)
        {
            int p = partition(ptr, low, high);
            printf("%d\n", p);
            quicksort(ptr, low, p-1);
            quicksort(ptr, p+1, high);
        }
    }


    int main(){
        int i;
        int a[] = {3, 8, 2, 5, 1, 4, 7, 6};
        int len  = sizeof(a)/sizeof(a[0]);
        for ( i = 0; i < len; ++i)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        int *ptr = a;
        quicksort(ptr, 0, len-1);
        for (i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        return 0;
    }
