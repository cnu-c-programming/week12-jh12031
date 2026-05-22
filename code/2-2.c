#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[64];
    int score;
} Student;

int main(int argc, const char* argv[]) {
    FILE* fp = fopen("student.txt", "r");
    int count = 0;
    Student students[64];

    while (fscanf(fp, "%s %d", students[count].name, &students[count].score) != EOF) {
        count++;
    }

    int max = 0;
    float avg = 0;

    int sum = 0;

    for (int i = 0; i < count; i++) {
        if (students[i].score > max) {
            max = students[i].score;
        }
        sum += students[i].score;
    }
    if (count > 0) {
        avg = (float)sum / count;
    }

    printf("max: %d\n", max);
    printf("avg: %.2f\n", avg);

    fclose(fp);

    return 0;
}

