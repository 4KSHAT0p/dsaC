#include <bits/stdc++.h>
using namespace std;

int gtb(int n)
{
    int ans = 0;
    bool prev = false;
    int i;
    for (i = 31; i >= 0; i--)
    {
        if (n & (1 << i))
        {
            cout << "first set bit found at " << i << endl;
            prev = true;
            ans += pow(2, i);
            break;
        }
    }
    i--;
    while (i >= 0)
    {
        bool k = n & (1 << i);
        cout << k <<" "<<i<< " "
             << prev << endl;
        if (k ^ prev)
        {
            cout<<"adding"<<endl;
            ans += pow(2, i);
        }
        prev ^= k;
        i--;
    }

    return ans;
}
int main()
{

    cout << gtb(11);

    return 0;
}