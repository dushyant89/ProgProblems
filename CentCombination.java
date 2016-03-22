import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class CentCombination
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> prices = new ArrayList<Integer>();
        System.out.println("Enter the coins which we have");
        while (sc.hasNextInt()) {
            prices.add(sc.nextInt());
        }
        String c = sc.next();
        System.out.println("Enter the no. for which we need to find the combinations");
        int n = sc.nextInt();

        int [][] grid = new int[n+1][prices.size()];

        for (int i=1; i < grid.length; i++) {
            for (int j=0; j < grid[i].length; j++) {
                int delta = i - prices.get(j);
                if (0 == delta) {
                    grid[i][j] = 1 + (((j-1) >= 0) ? grid[i][j-1] : 0);
                } else if(0 < delta && 0 < grid[delta][j]) {
                    grid[i][j] = grid[delta][j] + (((j-1) >= 0) ? grid[i][j-1] : 0);
                } else {
                    grid[i][j] = (((j-1) >= 0) ? grid[i][j-1] : 0);
                }
                System.out.print("grid" + "[" + i + "]"  + "[" + j + "]" + "= " + grid[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println(grid[n][prices.size()-1]);
    }
}