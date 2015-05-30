#include <iostream>
#include <map>
#include <vector>
#include <queue>

int main()
{
    using namespace std;

    int case_num = 0;

    while (true) {
        int t;
        cin >> t;
        if (t == 0)
            break;

        cout << "Scenario #" << ++case_num << endl;

        map<int, int> elem;

        for (int i = 0; i < t; ++i) {
            int l;
            cin >> l;

            while (l--) {
                int e;
                cin >> e;

                elem.insert(make_pair(e, i));
            }
        }
        cin.ignore();

        vector< pair<int, queue<int> > > q;

        while (cin.peek() != 'S') {
            if (cin.peek() == 'E') {
                cin.ignore(10, ' ');

                int e;
                cin >> e;

                auto team_num = elem.find(e);

                auto it = q.begin();
                for (; it != q.end(); ++it) {
                    if (it->first == team_num->second) {
                        it->second.push(e);
                        break;
                    }
                }

                if (it == q.end()) {
                    q.push_back(make_pair(team_num->second, queue<int>()));
                    q.back().second.push(e);
                }
            }
            else if (cin.peek() == 'D') {
                cout << q.front().second.front() << endl;

                if (q.front().second.size() == 1)
                    q.erase(q.begin());
                else
                    q.front().second.pop();
            }

            cin.ignore(10, '\n');
        }
        cin.ignore(10, '\n');

        cout << endl;
    }

    return 0;
}