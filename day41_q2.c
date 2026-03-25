#include <stdio.h>
#include <string.h>

int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};
    int i;
    
    for (i = 0; i < size; i++) {
        freq[tasks[i] - 'A']++;
    }

    int maxf = 0;
    for (i = 0; i < 26; i++) {
        if (freq[i] > maxf) {
            maxf = freq[i];
        }
    }

    int countmax = 0;
    for (i = 0; i < 26; i++) {
        if (freq[i] == maxf) {
            countmax++;
        }
    }

    int slots = (maxf - 1) * (n + 1) + countmax;

    if (slots > size) {
        return slots;
    } else {
        return size;
    }
}

int main() {
    int size, n, i;
    scanf("%d", &size);

    char tasks[size];
    for (i = 0; i < size; i++) {
        scanf(" %c", &tasks[i]);
    }

    scanf("%d", &n);

    printf("%d\n", leastInterval(tasks, size, n));

    return 0;
}
