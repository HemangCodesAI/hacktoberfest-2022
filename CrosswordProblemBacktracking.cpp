// A crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.

// Input format:
// The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
// The next line of input contains the word list, in which each word is separated by ';'. 

// Output format:
// Print the crossword grid, after placing the words of word list in '-' cells.  

// Constraints
// The number of words in the word list lie in the range of: [1,6]
// The length of words in the word list lie in the range: [1, 10]

// Input :
// +-++++++++
// +-++-+++++
// +-------++
// +-++-+++++
// +-++-+++++
// +-++-+++++
// ++++-+++++
// ++++-+++++
// ++++++++++
// ----------

// CALIFORNIA;NIGERIA;CANADA;TELAVIV

// Output :
// +C++++++++
// +A++T+++++
// +NIGERIA++
// +A++L+++++
// +D++A+++++
// +A++V+++++
// ++++I+++++
// ++++V+++++
// ++++++++++
// CALIFORNIA

#include <iostream>
using namespace std;

char crossword[10][10];

void resetVertical(int row, int col, bool state[], int size)
{
    int j = row;
    for(int i=0; i<size; i++)
    {
        if(state[i] == true)
        {
            crossword[j][col] = '-';
            state[i] = false;
        }
        j++;
    }
}
void setVertical(int row, int col, string name, bool state[])
{
    int j = row;
    for(int i=0; i<name.size(); i++)
    {
        if(crossword[j][col] == '-')
        {
            crossword[j][col] = name[i];
            state[i] = true;
        }
        else
        {
            state[i] = false;
        }
        j++;
    }
}
bool isValidVertical(int row, int col, string name)
{
    if(name.size() + row > 10)
    {
        return false;
    }
    
    int j = row;
    for(int i=0; i<name.size(); i++)
    {
        if(crossword[j][col] != '-' && crossword[j][col] != name[i])
        {
            return false;
        }
        j++;
    }
    return true;
}
void resetHorizontal(int row, int col, bool state[], int size)
{
    int j = col;
    for(int i=0; i<size; i++)
    {
        if(state[i] == true)
        {
            crossword[row][j] = '-';
            state[i] = false;
        }
        j++;
    }
}
void setHorizontal(int row, int col, string name, bool state[])
{
    int j = col;
    for(int i=0; i<name.size(); i++)
    {
        if(crossword[row][j] == '-')
        {
            crossword[row][j] = name[i];
            state[i] = true;
        }
        else
        {
            state[i] = false;
        }
        j++;
    }
}
bool isValidHorizontal(int row, int col, string name)
{
    if(name.size() + col > 10)
    {
        return false;
    }
    
    int j = col;
    for(int i=0; i<name.size(); i++)
    {
        if(crossword[row][j] != '-' && crossword[row][j] != name[i])
        {
            return false;
        }
        j++;
    }
    return true;
}
void solveCrossword(string names[], int l, int index)
{
    if(index == l)
    {
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                cout<<crossword[i][j];
            }
            cout<<endl;
        }
        return;
    }
    
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(crossword[i][j] == '-' || crossword[i][j] == names[index][0])
            {
                int size = names[index].size();
                bool state[size];
                
                if(isValidHorizontal(i, j, names[index]))
                {
                    setHorizontal(i, j, names[index], state);
                    solveCrossword(names, l, index + 1);
                    resetHorizontal(i, j, state, size);
                }
                
                if(isValidVertical(i, j, names[index]))
                {
                    setVertical(i, j, names[index], state);
                    solveCrossword(names, l, index + 1);
                    resetVertical(i, j, state, size);
                }
            }
        }
    }
}

int main()
{
    string str;
    for(int i=0; i<10; i++)
    {
        cin>>str;
        for(int j=0; j<10; j++)
        {
            crossword[i][j] = str[j];
        }
    }
    
    string name, word="", names[6];
    cin>>name;
    int l = 0;
    for(int i=0; i<name.length(); i++)
    {
        if(name[i] == ';')
        {
            names[l++] = word;
            word = "";
        }
        else
        {
            word += name[i];
        }
    }
    names[l++] = word;
    solveCrossword(names, l, 0);
}

