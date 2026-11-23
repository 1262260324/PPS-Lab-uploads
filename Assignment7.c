#include <stdio.h>
#include <string.h>

struct Robot
{
    int id;
    char type[50];
    float payloadCapacity;
    float actualLoad;
    float operatingTime;
    float utilization;
};

int main(){
    struct Robot robots[100];
    int n, i;

    printf("Enter number of robots: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number if robots.\n");
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for Robot %d:\n", i + 1);

        printf("Robot ID: ");
        scanf("%d", &robots[i].id);

        printf("Robot Type: ");
        scanf(" %49[^\n]",robots[i].type);

        printf("Payload Capacity (kg): ");
        scanf("%f", &robots[i].payloadCapacity);

        printf("Actual Load (kg): ");
        scanf("%f", &robots[i].actualLoad);

        printf("Operating Time: ");
        scanf("%f", &robots[i].operatingTime);

        if (robots[i].payloadCapacity <= 0 )
        {
            printf("The payload capacity must be positive.\n");
            return 1;
        }
        robots[i].utilization = (robots[i].actualLoad/robots[i].payloadCapacity) * 100;
    }

    printf("\nList Report:\n");
    printf("%-8s %-20s %-12s %-12s %-12s %-12s %-20s\n", "ID","Type","Capacity","Load","Time(hrs)","Util(%)","Status");
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%-8d %-20s %-12.2f %-12.2f %-12.2f %-12.2f %-20s\n",
            robots[i].id,
            robots[i].type,
            robots[i].payloadCapacity,
            robots[i].actualLoad,
            robots[i].operatingTime,
            robots[i].utilization,
            (robots[i].actualLoad>robots[i].payloadCapacity?"Overloaded":"Within Limit"));
    }

    return 0;
}