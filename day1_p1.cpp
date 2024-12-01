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
int main()
{
    string blank;    
    vi list1, list2;
    while (getline(cin, blank))
    {
        vector<string> temp;

        temp = process(blank);
        if(temp[0] =="#")
        break;
        // cout<<temp[0]<<endl;
        // cout<<temp[1]<<endl;
        // cout<<temp[2]<<endl;
        list1.push_back(stoi(temp[0]));
        list2.push_back(stoi(temp[1]));
    }
    // part1
    sort(all(list1));
    sort(all(list2));
    long long int result=0;
    for(int i=0; i<list1.size(); i++)
    {
        result+= abs(list1[i]-list2[i]);
    }
    cout<<result<<endl;
    // part2
    int r=0;
    map <int,int> mone;
    map <int,int> msecond;
    for( int x: list1)
    {
        if(mone.find(x)!= mone.end())
        {
            mone[x]++;
        }
        else
        {
            mone[x]=1;
        }
    }
    for( int x: list2)
    {
        if(msecond.find(x)!= msecond.end())
        {
            msecond[x]++;
        }
        else
        {
            msecond[x]=1;
        }
    }

    for(auto x: mone)
    {
        if(msecond.find(x.first)!= msecond.end())
        {
            r += x.first * x.second * msecond[x.first];
        }
    }
    cout<<r;





}
