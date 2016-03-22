import java.util.*;
import java.io.*;

public class StairCase {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int [] a = new int[sc.nextInt() + 1];
        int [] steps = {1, 2, 3}; 
        a[0] = 1;
        // Looping over the stair cases , bottom up approach
        for(int i=1; i < a.length; i++) {
            for (int j = 0; j < steps.length; j++) {
                int delta = i - steps[j];
                if (0 <= delta) {
                    a[i] += a[delta];
                } else {
                    break;
                }
            }
            System.out.println("i:" + i + " a[i] : " + a[i]);    
        }
        System.out.println(a[a.length - 1]);
    }
}