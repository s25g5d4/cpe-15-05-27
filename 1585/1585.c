#include <stdio.h>

int main()
{
    int case_num;
    scanf("%d%*c", &case_num);

    while (case_num--) {
        int ans = 0;
        int continuous = 0;
        
        int ch;
        ch = getchar();
        
        while (ch != '\n' && ch != EOF) {
            if (ch == 'X') {
                continuous = 0;
            }
            else if (ch == 'O') {
                ++continuous;
                ans += continuous;
            }
            
            ch = getchar();
        }

        printf("%d\n", ans);
    }

    return 0;
}
