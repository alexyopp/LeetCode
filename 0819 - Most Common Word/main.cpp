//  Given a string "paragraph" and a string array of the banned words "banned", return the most frequent word that is
//  not banned.  It is guaranteed there is at least one word that is not banned, and that the answer is unique.
//
//  The words in paragraph are case-insensitive and the answer should be returned in lowercase.
//
//  Note that words can not contain punctuation symbols.
//  
//  Example 1:
//
//  Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
//  Output: "ball"
//
//  Explanation:
//  "hit" occurs 3 times, but it is a banned word.
//  "ball" occurs twice(and no other word does), so it is the most frequent non-banned word in the paragraph.
//  Note that words in the paragraph are not case sensitive, that punctuation is ignored(even if adjacent to words,
//  such as "ball,"), and that "hit" isn't the answer even though it occurs more because it is banned.
//
//  Example 2:
//
//  Input: paragraph = "a.", banned = []
//  Output: "a"
//
//  Constraints:
//
//  1 <= paragraph.length <= 1000
//  paragraph consists of English letters, space ' ', or one of the symbols : "!?',;.".
//  0 <= banned.length <= 100
//  1 <= banned[i].length <= 10
//  banned[i] consists of only lowercase English letters.

#include <iostream>
#include <string>
#include <vector>

#include "Solution1.h"

int main()
{
    std::string paragraph;
    std::vector<std::string> banned;

    // Case 1
    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    banned = { "hit" };
    std::cout << mostCommonWord(paragraph, banned) << std::endl;

    // Case 2
    paragraph = "a";
    banned = {};
    std::cout << mostCommonWord(paragraph, banned) << std::endl;

    // Case 3
    paragraph = "L, P! X! C; u! P? w! P. G, S? l? X? D. w? m? f? v, x? i. z; x' m! U' M! j? V; l. S! j? r, K. O? k? p? p, H! t! z' X! v. u; F, h; s? X? K. y, Y! L; q! y? j, o? D' y? F' Z; E? W; W' W! n! p' U. N; w? V' y! Q; J, o! T? g? o! N' M? X? w! V. w? o' k. W. y, k; o' m! r; i, n. k, w; U? S? t; O' g' z. V. N? z, W? j! m? W! h; t! V' T! Z? R' w, w? y? y; O' w; r? q. G, V. x? n, Y; Q. s? S. G. f, s! U? l. o! i. L; Z' X! u. y, Q. q; Q, D; V. m. q. s? Y, U; p? u! q? h? O. W' y? Z! x! r. E, R, r' X' V, b. z, x! Q; y, g' j; j. q; W; v' X! J' H? i' o? n, Y. X! x? h? u; T? l! o? z. K' z' s; L? p? V' r. L? Y; V! V' S. t? Z' T' Y. s? i? Y! G? r; Y; T! h! K; M. k. U; A! V? R? C' x! X. M; z' V! w. N. T? Y' w? n, Z, Z? Y' R; V' f; V' I; t? X? Z; l? R, Q! Z. R. R, O. S! w; p' T. u? U! n, V, M. p? Q, O? q' t. B, k. u. H' T; T? S; Y! S! i? q! K' z' S! v; L. x; q; W? m? y, Z! x. y. j? N' R' I? r? V! Z; s, O? s; V, I, e? U' w! T? T! u; U! e? w? z; t! C! z? U, p' p! r. x; U! Z; u! j; T! X! N' F? n! P' t, X. s; q'";
    banned = { "m", "i", "s", "w", "y", "d", "q", "l", "a", "p", "n", "t", "u", "b", "o", "e", "f", "g", "c", "x" };
    std::cout << mostCommonWord(paragraph, banned) << std::endl;
}
