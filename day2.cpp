#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
vector<string> process(string s)
{
    stringstream ss(s);
    vector<string> tokens;
    string token;
    while (ss >> token)
    {
        tokens.push_back(token);
    }
    return tokens;
}
bool check(vi &v)
{
    bool pos1 = true, pos2 = true, pos3 = true;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < v[i - 1])
            pos1 = false;
        if (v[i] > v[i - 1])
            pos2 = false;
        int diff = abs(v[i] - v[i - 1]);
        if (diff < 1 || diff > 3)
            pos3 = false;
    }
    return ((pos1 | pos2) & pos3);
}

int main()
{
    string s;
    ll ans = 0, ans2 = 0;
    while (getline(cin, s))
    {
        vector<string> parse = process(s);
        vi store;
        for (int i = 0; i < parse.size(); i++)
            store.push_back(stoi(parse[i]));
        if (check(store))
            ans++;
        for (int i = 0; i < store.size(); i++)
        {
            vi remove;
            for (int j = 0; j < store.size(); j++)
            {
                if (j != i)
                    remove.push_back(store[j]);
            }
            if (!check(store) && check(remove))
            {
                ans2++;
                i++;
            }
        }
    }
    cout << ans << "\n"
         << ans+ans2 << "\n";
    return 0;
}