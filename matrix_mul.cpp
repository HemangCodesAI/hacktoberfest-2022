#include <iostream>
using namespace std;
int main()
{
    int i, j, n1, m1, a[10][10],n2,m2,b[10][10],n3,m3,c[10][10],k;
    cout << "Enter the number of rows and columns of the first matrix: ";
    cin >> n1 >> m1;
    cout << "Enter the elements of the first matrix: ";
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> n2 >> m2;
    cout << "Enter the elements of the second matrix: ";
    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < m2; j++)
        {
            cin >> b[i][j];
        }
    }
    if (m1 == n2)
    {
        n3 = n1;
        m3 = m2;
        for (i = 0; i < n3; i++)
        {
            for (j = 0; j < m3; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < m1; k++)
                {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }
        cout << "The product of the two matrices is: " << endl;
        for (i = 0; i < n3; i++)
        {
            for (j = 0; j < m3; j++)
            {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "The matrices cannot be multiplied";
    }
    return 0;    
}