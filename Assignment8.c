#include <stdio.h>
#include <string.h>

void swap(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(){
    int motor1,motor2;
    printf("Enter speeds of motor1 & motor2 (in rad/s): ");
    scanf("%d %d", &motor1,&motor2);
    int *p1 = &motor1;
    int *p2 = &motor2;
    printf("Values before swapping:\n");
    printf("----------------------------------");
    printf("\nSpeed of Motor1: %d,\nAddress: %p",*p1,(void*)p1);
    printf("\nSpeed of Motor2: %d,\nAddress: %p\n",*p2,(void*)p2);
    swap(p1,p2);

    printf("Values after swapping:\n");
    printf("----------------------------------");
    printf("\nSpeed of Motor1: %d,\nAddress: %p",*p1,(void*)p1);
    printf("\nSpeed of Motor2: %d,\nAddress: %p\n",*p2,(void*)p2);

    return 0;
}