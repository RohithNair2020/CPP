// DSA Series - Love Babbar - Lecture No. 39
#include <iostream>
#include <vector>
using namespace std;

void solve(string inputString, vector<string> &ans, int index)
{
    if (index == inputString.length())
    {
        ans.push_back(inputString); // if string end reached, push into the answer array and return
        return;
    }
    for (int i = index; i < inputString.length(); i++)
    {
        swap(inputString[index], inputString[i]); // swap the current letter with each after it
        solve(inputString, ans, index + 1);       // recursion takes place here

        // the backtracking part
        swap(inputString[index], inputString[i]); // swap the letters back into places
    }
}

vector<string> getPermutations(string inputString)
{
    vector<string> ans;         // the final output array
    solve(inputString, ans, 0); // the recursive function call
    return ans;
}

int main()
{
    string inputString;
    cout << "Enter the input string: ";
    cin >> inputString;
    vector<string> permutations;
    permutations = getPermutations(inputString);
    for (int i = 0; i < permutations.size(); i++)
    {
        cout << permutations[i] << " ";
    }
    return 0;
}