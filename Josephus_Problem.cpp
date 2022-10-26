// Problem Statement: There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of person n and a number k which indicates that k-1 persons are skipped and the kth person is killed in a circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive. 

// Examples:

// Example 1:
// Input: n = 5 and k = 2
// Output: The safe position is 3
// Explanation:  Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives. 

// Example 2:
// Input:  n = 7 and k = 3
// Output: The safe position is 4
// Explanation: The persons at positions 3, 6, 2, 7, 5, 1 are killed in order, and the person at position 4 survives. 

#include<bits/stdc++.h>
using namespace std;

void solve(vector < int > person, int k, int index, int & ans) { 
if (person.size() == 1) { //base case 
ans = person[0]; //if last element is left 
return; 
} 
index =(index + k) % person.size(); //finding the person to be killed 
person.erase(person.begin() + index); //to erase that person 
solve(person, k, index, ans); //recursive call
return; 
} 
int main() { 
int n = 7 , k = 3 ; 
vector < int > person; //to store the person numbering 
for (int i = 1; i <= n; i++) { 
person.push_back(i); 
} 
int ans = -1; //to store the safest place 
solve(person, k - 1, 0, ans); 
cout<<"The safe position is: "<<ans<<endl; 
} 
