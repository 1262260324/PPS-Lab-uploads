#include <stdio.h>
#include <string.h>

#define THRESHOLD 50.0
#define LOG_FILE "navigation_log.txt"

typedef struct {
    int step;
    float distance;
    int x, y;
    char direction[10];
} NavRecord;

int countOccurrences(int x, int y) {
    FILE *fp = fopen(LOG_FILE, "r");
    if (!fp) return 0;

    NavRecord r;
    int cnt = 0;
    while (fscanf(fp, "%d %f %d %d %9s",
                  &r.step, &r.distance, &r.x, &r.y, r.direction) == 5) {
        if (r.x == x && r.y == y) {
            cnt++;
        }
    }

    fclose(fp);
    return cnt;
}

const char* alternativeDirection(const char *current) {
    if (strcmp(current, "Forward") == 0) return "Left";
    if (strcmp(current, "Left") == 0)    return "Right";
    if (strcmp(current, "Right") == 0)   return "Back";
    if (strcmp(current, "Back") == 0)    return "Forward";
    return "Forward";
}

void addRecord(NavRecord r) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (!fp) {
        printf("Error: Cannot open file!\n");
        return;
    }
    fprintf(fp, "%d %.2f %d %d %s\n", r.step, r.distance, r.x, r.y, r.direction);
    fclose(fp);
}

int main(void) {
    NavRecord r;
    int repeat;

    printf("--- Robot Navigation System ---\n");
    printf("Enter step number: ");
    scanf("%d", &r.step);

    printf("Enter distance (cm): ");
    scanf("%f", &r.distance);

    printf("Enter obstacle X (or -1 if none): ");
    scanf("%d", &r.x);

    printf("Enter obstacle Y (or -1 if none): ");
    scanf("%d", &r.y);

    printf("Enter direction (Forward/Left/Right/Back): ");
    scanf("%9s", r.direction);

    if (r.distance < THRESHOLD && r.x != -1 && r.y != -1) {
        repeat = countOccurrences(r.x, r.y);
        printf("Obstacle detected (distance = %.2f cm)\n", r.distance);
        if (repeat > 0) {
            printf("This obstacle was seen %d time(s) before.\n", repeat);
        }
        printf("Suggested alternative direction: %s\n",
               alternativeDirection(r.direction));
    }

    addRecord(r);
    return 0;
}
// step = 2
// dist = 25
// x = 10
// y = 20
// direction = Forward