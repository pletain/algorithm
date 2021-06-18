#include<stdio.h>
int data[10010], d[10010];
int main()
{
    int i, n, num, j, x, max, cor=0;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        max=0;
        scanf("%d %d", &data[i], &num);
        for(j=0; j<num; j++)
        {
            scanf("%d", &x);
            if(max<d[x]) max=d[x];
        }
        d[i]=data[i]+max;
        if(cor<d[i]) cor=d[i];
    }

    printf("%d", cor);
    return 0;
}

