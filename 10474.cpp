#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    using namespace std;

    int case_num = 0;

    while (true) {
        int n, q;
        cin >> n >> q;
        if (n == 0 && q == 0)
            break;

        vector<int> marbles(n);
        for (auto &i : marbles)
            cin >> i;

        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << ++case_num << ':' << endl;

        while (q--) {
            int x;
            cin >> x;

            auto found = find(marbles.begin(), marbles.end(), x);

            if (found == marbles.end())
                cout << x << " not found" << endl;
            else
                cout << x << " found at " << (found - marbles.begin() + 1) << endl;
        }
    }

    return 0;
}