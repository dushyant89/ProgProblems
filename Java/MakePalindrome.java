/*
Given a string of lowercase letters, determine the index of the character whose removal will make the string a palindrome. 
If the string is already a palindrome, then print −1−1. There will always be a valid solution.

Input Format

The first line contains T (the number of test cases). 
The T subsequent lines of test cases each contain a single string to be checked.

Constraints 
1 ≤ T ≤ 20 
1 ≤ length of string ≤ 100005 
All characters are Latin lower case indexed.

Output Format

Print the zero-indexed position (integer) of a character whose deletion will result in a palindrome; if there is no such 
character (i.e.: the string is already a palindrome), print -1. Any correct answer will be accepted; e.g.: for a string such as 
bcbc, we can either remove b at index 00 or c at index 33—both answers are acceptable.

Sample Input
3
aaab
baa
aaa

Sample Output
3
0
-1

Explanation

Test Case 1(aaabaaab): Removing b at index 33 results in a palindrome, so we print 3.

Test Case 2(baabaa): Removing b at index 00 results in a palindrome, so we print 0.

Test Case 3(aaaaaa): This string is already a palindrome, so we print -1; however, 0, 1, and 2 are also all acceptable answers, 
as the string will still be a palindrome if any one of the characters at those indices are removed.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class MakePalindrome {

    public static boolean isPalindrome(String str) {
        int len = str.length();
        int half_len = len/2;
        len = len-1;
        for (int i=0; i < half_len; i++) {
            if (str.charAt(i) != str.charAt(len-i)) {
                return false;
            }
        }
        return true;
    }
    
    public static boolean isPalindrome(StringBuilder str) {
        int len = str.length();
        int half_len = len/2;
        len = len-1;
        for (int i=0; i < half_len; i++) {
            if (str.charAt(i) != str.charAt(len-i)) {
                return false;
            }
        }
        return true;
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(new File("palindromeInput.txt"));
        int testCases = sc.nextInt();
        long start = System.currentTimeMillis();
        String input;
        while (--testCases >= 0) {
            input = sc.next();
            if (isPalindrome(input)) {
                System.out.println(-1);
            } else {
                char prev = '@';
                int len = input.length();
                for (int i=0; i < len; i++) {
                    if (input.charAt(i) != prev) {
                        //System.out.println(i);
                        StringBuilder str = new StringBuilder(input);
                        if (isPalindrome(str.deleteCharAt(i))) {
                            System.out.println(i);
                            break;
                        }
                    }
                    prev = input.charAt(i);
                }
            }
        }
        long end = System.currentTimeMillis();
        System.out.println("Total time : " + (end - start)/1000 + " s");
    }
}