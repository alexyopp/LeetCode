//****************************************************************************************************************************/
/*  Given a string text, you want to use the characters of "text" to form as many instances of the word "balloon" as possible.
*   You can use each character in text at most once.  Return the maximum number of instances that can be formed.
*
*   Example 1:
*
*   Input: text = "nlaebolko"
*   Output: 1
*
*   Example 2:
*
*   Input: text = "loonbalxballpoon"
*   Output: 2
*
*   Example 3:
*
*  Input: text = "leetcode"
*  Output: 0
*
*  Constraints:
*
*  1 <= text.length <= 10^4
*  text consists of lower case English letters only.
*
*  Note: This question is the same as 2287: Rearrange Characters to Make Target String.
*/

#include <iostream>     //  for std::cout, std::endl
#include <string>       //  for std::string

#include "Helpers.h"

#include "Solution1.h"

int main()
{
    std::string text;
    int expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto maxNumberOfBalloonsCallable = [&solution](std::string text) { return solution.maxNumberOfBalloons(text); };

    // Case 1
    text = "nlaebolko";
    expectedOutput = 1;
    std::cout << "Case 1: " << (Helpers::RunTestCase(maxNumberOfBalloonsCallable, text, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    text = "loonbalxballpoon";
    expectedOutput = 2;
    std::cout << "Case 2: " << (Helpers::RunTestCase(maxNumberOfBalloonsCallable, text, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    text = "leetcode";
    expectedOutput = 0;
    std::cout << "Case 3: " << (Helpers::RunTestCase(maxNumberOfBalloonsCallable, text, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 4
    text = "balllllllllllloooooooooon";
    expectedOutput = 1;
    std::cout << "Case 4: " << (Helpers::RunTestCase(maxNumberOfBalloonsCallable, text, expectedOutput) ? "PASS" : "FAIL") << "\n";
}
