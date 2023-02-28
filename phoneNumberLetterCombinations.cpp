#include <iostream>
#include <vector>
using namespace std;

// Note that the ans array is passed by reference here
void solve(string phoneNumberString, string output, int index, vector<string> &ans, string letterMap[])
{
    //! this is a recursive function
    // base case. ie, if the index exceeds the length of the phoneNumberString;
    if (index >= phoneNumberString.length())
    {
        // push into the ans vector whatever we have till now in the output string
        ans.push_back(output);
        return;
    }

    // if not base case, get the current digit
    int number = phoneNumberString[index] - '0'; //? This line of code will get us the numeric value of the character. If it's a character of the number ofcourse. It works based on the ASCII values. You just substract the character '0' from the required character;

    // now, getting the corresponding letters under the number
    string lettersUnderNumber = letterMap[number];

    // for each letter in the available letters, repeat the same process
    for (int i = 0; i < lettersUnderNumber.length(); i++)
    {
        output.push_back(lettersUnderNumber[i]);
        // increment the index and recurse with the updated output string
        solve(phoneNumberString, output, index + 1, ans, letterMap);

        // once we call the same function for 'a', we don't need 'a' the next time. we need 'b' instead. So we clear out the last character that we pushed into the output string.
        output.pop_back();
    }
}

vector<string> getLetterCombinations(string phoneNumberString)
{
    vector<string> ans; // the final ans vector
    if (phoneNumberString.length() == 0)
    {
        return ans;
    }
    string output = ""; // the output string
    int index = 0;      // to keep track of the current digit in the phone number string

    // mapping the corresponding letters to the phone number
    string letterMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // the helper function
    solve(phoneNumberString, output, index, ans, letterMap);
    return ans;
}

int main()
{
    string phoneNumber;
    cout << "Enter the phone number string : ";
    cin >> phoneNumber;
    vector<string> answer;
    answer = getLetterCombinations(phoneNumber);
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    return 0;
}