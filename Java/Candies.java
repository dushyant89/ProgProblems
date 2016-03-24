/*
Alice is a kindergarden teacher. She wants to give some candies to the children in her class.  All the children sit in a line ( their positions are fixed), and each  of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to save money, so she needs to minimize the total number of candies given to the children.

Input Format

The first line of the input is an integer N, the number of children in Alice's class. Each of the following N lines contains an integer that indicates the rating of each child.

1 <= N <= 105
1 <= ratingi <= 105

Output Format

Output a single line containing the minimum number of candies Alice must buy.

Sample Input
3
1
2
2

Sample Output
4

Explanation

Here 1, 2, 2 is the rating. Note that when two children have equal rating, they are allowed to have different number of candies. Hence optimal distribution will be 1, 2, 1.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Candies {

    private static int [] score;
    private static int [] cost;

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        score = new int[n];
        cost = new int[n];
        int i = 0;
        while(sc.hasNextInt()) {
            cost[i] = 1;
            score[i++] = sc.nextInt();
        }
        boolean change = true;
        while(change) {
            change = false;
            for (i=0; i < n-1; i++) {
                // Always look to the right for the score
                if((score[i] < score[i+1]) && (cost[i] >= cost[i+1])) {
                    cost[i+1] += (cost[i] - cost[i+1]) + 1;
                    change = true;
                } else if ((score[i] > score[i+1]) && (cost[i] <= cost[i+1])) {
                    cost[i] += (cost[i+1] - cost[i]) + 1;
                    change = true;
                }
            }
        }
        int totalCost = 0;
        for(i=0; i<n; i++) {
            totalCost += cost[i];
        }
        System.out.println(totalCost);
    }
}