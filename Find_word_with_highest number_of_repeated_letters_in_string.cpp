// Problem Statement: Write a program to find a word in a given string that has the highest number of repeated letters. If not found, return -1.

// Examples:

// Example 1:
// Input: string=”abcdefghij google microsoft”
// Output: google
// Explanation: In “google” g appears 2 times, o appears 2 times which is highest among all words

// Example 2:
// Input: string = “cameron blue”
// Output: -1
// Explanation: No word has more than 1 letter.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void HighestRepeatedLetters(string &str) {
        int len = str.length() ;

        int maximumword = 0 ;

        int curr_maximumword = 0  ;

        string result = ""  ;


        for (int left = 0; left < len;) {

            int right = left + 1 ;
            while (str[right] != ' ' && right < len) {
                right++ ;
            }

            int frequency[26] = {0}  ;
            curr_maximumword = 0  ;

            for (int index = left ; index < right ; index++) {
                frequency[str[index] - 'a']++  ;
            }
            for (int index = 0 ; index < 26 ; index++) {
                if (frequency[index] > 1) {
                    curr_maximumword ++  ;
                }
            }


            if (curr_maximumword > maximumword) {
                maximumword = curr_maximumword ;
                result = ""  ;
                for (int j = left ; j < right ; j++)
                    result += str[j] ;

            }

            left = right + 1  ;
        }

        if (result.empty()) {
            cout << "-1";
        }
        else {

            cout << "Word with highest number of repeated letters : " ;
            cout << result << "\n"  ;
        }
    }
};
int main() {

    string str = "abcdefg google microsoft"  ;
    Solution obj ;
    obj.HighestRepeatedLetters(str)  ;
    return 0 ;
}
