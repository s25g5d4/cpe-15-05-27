#include <iostream>
#include <vector>
#include <string>

int main()
{
    using namespace std;

    int case_num;
    cin >> case_num;

    while (case_num--) {
        int m, n, q;
        cin >> m >> n >> q;
        cin.ignore();

        vector< vector<char> > grid(m);
        for (auto &i : grid) {
            string line;
            getline(cin, line);

            i = vector<char>(line.begin(), line.end());
        }

        cout << m << ' ' << n << ' ' << q << endl;

        while (q--) {
            int r, c;
            cin >> r >> c;

            int i;
            char ch = grid[r][c];
            for (i = 1; r + i < m && r - i >= 0 && c + i < n && c - i >= 0; ++i) {
                for (int e = c - i; e < c + i; ++e) {
                    if (grid[r - i][e] != ch)
                        goto HELL;
                }
                for (int e = r - i; e < r + i; ++e) {
                    if (grid[e][c + i] != ch)
                        goto HELL;
                }
                for (int e = c + i; e > c - i; --e) {
                    if (grid[r + i][e] != ch)
                        goto HELL;
                }
                for (int e = r + i; e > r - i; --e) {
                    if (grid[e][c - i] != ch)
                        goto HELL;
                }
            }

            HELL:
            cout << i * 2 - 1 << endl;
        }
    }

    return 0;
}