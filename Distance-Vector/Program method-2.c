// Distance Vector Routing Algorithm

#include <stdio.h>
struct node
{
    unsigned dist[20];
    unsigned from[20];
} rt[10];
int main()
{
    int dmat[20][20];
    int n, i, j, k, count = 0;
    printf("\nEnter the number of nodes : ");
    scanf("%d", &n);
    printf("\nEnter the cost matrix :\n");
    for(int y=0;y<10;y++){
        int k;
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &dmat[i][j]);
            dmat[i][i] = 0;
            rt[i].dist[j] = dmat[i][j];
            rt[i].from[j] = j;
        }
    do
    {
        count = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                for (k = 0; k < n; k++)
                    if (rt[i].dist[j] > dmat[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
    } while (count != 0);
    for (i = 0; i < n; i++)
    {
        printf("\n\nState value for router %d is \n", i + 1);
        printf("\t\nDest	nexthop	   Distance");
        for (j = 0; j < n; j++)
        {
            if ((j + 1) != rt[i].from[j] + 1)

                printf("\t\n %d	  %d		%d", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
            else
                printf("\t\n %d	  -		%d", j + 1, rt[i].dist[j]);
        }
    }
    printf("\n\n");
}
