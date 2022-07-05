
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

struct sjf
{
    int pid;
    int btime;
    int wtime;
    int ttime;
    int arrtime;
    int comptime;
} p[10];

void sort(struct sjf *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (p[j].arrtime > p[j + 1].arrtime)
            {
                struct sjf temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int i, n;
    int towtwtime = 0, totttime = 0;
    printf("\n ***fcfs scheduling***\n");
    printf("enter the no of process");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {   
        p[i].pid = i;
        printf("\nburst time of the process : ");
        scanf("%d", &p[i].btime);
        printf("\arrival time of the process : ");
        scanf("%d", &p[i].arrtime);
    }

    sort(p, n);

    p[0].wtime = 0;
    p[0].ttime = p[0].comptime = p[0].btime;
    totttime += p[0].ttime;



    for (i = 1; i < n; i++)
    {
        p[i].wtime = (p[i].arrtime - p[i - 1].comptime >= 0) ? 0 : (p[i - 1].comptime - p[i].arrtime);
        p[i].ttime = p[i].wtime + p[i].btime;
        p[i].comptime = p[i].arrtime + p[i].wtime + p[i].btime;
        totttime += p[i].ttime;
        towtwtime += p[i].wtime;
    }



    for (i = 0; i < n; i++)
    {
        printf("\nwaiting time for process %d : %d", p[i].pid, p[i].wtime);
        printf("\n turn around time for process %d : %d", p[i].pid, p[i].ttime);
        printf("\n");
    }

    printf("\ntotal waiting time :%d", towtwtime);
    printf("\naverage waiting time :%f", (float)towtwtime / n);
    printf("\ntotal turn around time :%d", totttime);
    printf("\naverage turn around time: :%f\n", (float)totttime / n);
}
