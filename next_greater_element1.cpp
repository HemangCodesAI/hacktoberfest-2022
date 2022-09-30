// next greater element
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    //taking input of number of elements
    vector<int> a(n);
    //taking inputs of elements
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    stack<int> st;

    //vector b will store next greater element of corresponding element in array
    vector<int> b(n, 0);


    for (int i = 0; i < n; i++)
    {
        int j = 1;
        while (!st.empty() && a[i] > st.top())  //if stack is non-empty and stack top less than current element then assign that current element as next greater element of all the element which are in stack
        {
            b[i - j] = a[i];
            st.pop();
            j++;
        }
        //if current element is less that stack top then push current element to stack as it is less that other elements that are inside stack
            st.push(a[i]);
    }

    //checking if every element has next greater element or not

    //if they dont have next greater element the just assign it -1
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            b[i] = -1;
        }
    }

    //print element and its next greater elements
    for (int i = 0; i < n; i++)
    {
        cout <<a[i]<<" "<< b[i] <<endl;
    }
}
