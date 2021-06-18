#include<stdio.h>
int data[5000000]={0}, primeNum[5000000], check[5000000], cnt=0, k=1;

void cieve_of_Eratosthenes(int n)
{
    int i, j;
    for(i=2; i<=n; i++)
    {
        data[i]=i;
    }
    for(i=2; i<=n; i++)
    {
       if(check[i]==0)
       {
           primeNum[k]=i;
           k++;
           for(j=i; j<=n; j+=i)
           {
               check[j]=1;
           }
       }
    }
}

void Plus_operator(int n)
{
    int i=1, j=1, sum=2;

            while(i<=j&& i<k && j<k)
            {
                if(sum==n) cnt++;
                if(sum>n)
                {
                    sum-=primeNum[i];
                    i++;
                }
                else sum+=primeNum[++j];

            }
}
int main()
{
    int n;
    scanf("%d", &n);
    cieve_of_Eratosthenes(n);
    Plus_operator(n);
    printf("%d", cnt);
    return 0;
}