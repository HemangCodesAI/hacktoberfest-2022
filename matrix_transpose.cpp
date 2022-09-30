# include <iostream>
using namespace std;
int main()
{
    int i, j, n, m, a[10][10]; 
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> n >> m;
    cout << "Enter the elements of the  matrix: ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "The matrix is: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The transpose of the matrix is: " << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}