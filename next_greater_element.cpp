#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<int> st;
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++)
    {
        int j = 1;
        while (!st.empty() && a[i] > st.top())
        {
            b[i - j] = a[i];
            st.pop();
            j++;
        }
            st.push(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            b[i] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout <<a[i]<<" "<< b[i] <<endl;
    }
}
