#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qsort_cmp(const void *a, const void *b)
{
    return *(int *)a > *(int *)b;
}

int main()
{
    int case_num = 0;
    int marbles[10000];

    while (1) {
        int n, q;
        scanf("%d%d", &n, &q);
        if (n == 0 && q == 0)
            break;

        int i;
        
        for (i = 0; i < n; ++i)
            scanf("%d", &marbles[i]);

        qsort(marbles, n, sizeof (int), qsort_cmp);

        printf("CASE# %d:\n", ++case_num);

        while (q--) {
            int x;
            scanf("%d", &x);

            int i;
            for (i = 0; i < n; ++i) {
                if (marbles[i] == x)
                    break;
            }

            if (i == n)
                printf("%d not found\n", x);
            else
                printf("%d found at %d\n", x, i + 1);
        }
    }

    return 0;
}
