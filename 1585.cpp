#include <iostream>
#include <string>

int main()
{
    using namespace std;

    int case_num;
    cin >> case_num;

    while (case_num--) {
        string line;
        cin >> line;

        int ans = 0;
        int continuous = 0;

        for (auto ch : line) {
            if (ch == 'X') {
                continuous = 0;
                continue;
            }

            ++continuous;
            ans += continuous;
        }

        cout << ans << endl;
    }

    return 0;
}