/*
Oh!! Mankind is in trouble again. This time it's a deadly disease spreading at a rate never seen before. The need of the hour is to set up efficient virus detectors. You are the lead at Central Hospital and need to find a fast and reliable way to detect the 'foot-prints' of the virus DNA in that of the patient.

The DNA of the patient as well as of the virus consists of lower case letters. Since the data collected is raw, there may be some errors. You will need to find all substrings in the patient DNA that either exactly matches the virus DNA, or has at most one mismatch.

For example: "aa" and "aa" are matching, "ab" and "aa" are matching, while "ab" and "ba" are not.

Input Format 
The first line contains the number of test cases T. T test cases follow. 
Each case contains two strings P(Patient DNA) and V(Virus DNA) separated by space.

Output Format 
Output T lines, one corresponding to each test case. For each test case, output a space delimited list of starting indices (0 indexed) of substrings of P which are matching with V according to the condition mentioned above. The indices have to be in an increasing order. If there is no matching output No Match!.

Constraints 
1 <= T <= 10 
P and V contain at most 100000 characters each. 
All characters in P and V are lowercase letters.

Sample Input

3  
abbab ba
hello world
banana nan

Sample Output

1 2
No Match!
0 2

Explanation 
For the first case, the substrings of P starting at indices 1 and 2 are "bb" and "ba" and they are matching with the string V which is "ba". 
For the second case, there are no matching substrings so the output is a blank line.

*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class SaveHumanity {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int testCases = sc.nextInt();
        while(--testCases >= 0) {
            String patient = sc.next();
            String virus = sc.next();
            
            int effective_length = patient.length() - virus.length() + 1;
            ArrayList<Integer> results = new ArrayList<Integer>(effective_length);
            
            for (int i=0; i < effective_length; i++) {
                int mismatchCount = 0;
                int temp = i;
                int j;
                for (j=0; j < virus.length(); j++) {
                    if (patient.charAt(temp++) != virus.charAt(j)) {
                        mismatchCount++;
                    }
                    if (1 < mismatchCount) {
                        break;
                    }
                }
                if (j == virus.length()) {
                    results.add(i);
                }
            }
          
            if (0 < results.size()) {
                for(Integer entry : results) {
                    System.out.print(entry + " ");
                }
            } else {
                System.out.print("No Match!");
            }
            System.out.println();
        }
    }
}