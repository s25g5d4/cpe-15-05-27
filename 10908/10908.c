#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int case_num;
    char grid[22][22];
    scanf("%d", &case_num);

    while (case_num--) {
        int m, n, q;
        scanf("%d%d%d%*c", &m, &n, &q);

        int i;
        for (i = 0; i < m; ++i)
            fgets(grid[i], 22, stdin);

        printf("%d %d %d\n", m, n, q);

        while (q--) {
            int r, c;
            scanf("%d%d", &r, &c);

            int i;
            char ch = grid[r][c];
            
            for (i = 1; r + i < m && r - i >= 0 && c + i < n && c - i >= 0; ++i) {
                int e;
                
                for (e = c - i; e < c + i; ++e) {
                    if (grid[r - i][e] != ch)
                        goto HELL;
                }
                
                for (e = r - i; e < r + i; ++e) {
                    if (grid[e][c + i] != ch)
                        goto HELL;
                }
                
                for (e = c + i; e > c - i; --e) {
                    if (grid[r + i][e] != ch)
                        goto HELL;
                }
                
                for (e = r + i; e > r - i; --e) {
                    if (grid[e][c - i] != ch)
                        goto HELL;
                }
            }

            HELL:
            printf("%d\n", i * 2 - 1);
        }
    }

    return 0;
}
