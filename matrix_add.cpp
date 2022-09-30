# include <iostream>
using namespace std;
int main()
{
    int i, j, n, m, a[10][10], b[10][10], c[10][10];
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> n >> m;
    cout << "Enter the elements of the first matrix: ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Enter the elements of the second matrix: ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    cout << "The sum of the two matrices is: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
