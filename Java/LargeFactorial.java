// This is the text editor interface.
// Anything you type or change here will be seen by the other person in real time.

import java.util.*;
import java.io.*;

public class LargeFactorial
{
    public static void main(String []args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int [] a  = new int [500];
        int high = 0;
        a[0] = 2;
        for (int i = 3; i<=n; i++) {
            int k = 0;
            int x = 0;
            int carry = 0;
            while (k <= high) {
                x = a[k] * i + carry;
                carry = x/10;
                a[k++] = x%10;
            }
            high = k;
            while (0 != carry) {
                a[high++] = carry%10;
                carry = carry/10;
            }
        }

        for (int i=high-1; i >=0; i--) {
            System.out.print(a[i]);
        }
    }
}