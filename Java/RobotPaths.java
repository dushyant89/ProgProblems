import java.util.*;
import java.io.*;

public class RobotPaths
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Please enter the size of the grid");
        int [][] grid = new int[sc.nextInt()][sc.nextInt()];

        System.out.println("Please enter the destination limits");
        int x = sc.nextInt() - 1;
        int y = sc.nextInt() - 1;

        int i=0; int j=0;
        grid[0][0] = 1;

        for (i=0; i < grid.length; i++) {
            for (j=0; j < grid[i].length; j++) {
                if (0 <= (j-1)) {
                    grid[i][j] += grid[i][j-1];
                }
                if (0 <= (i-1)) {
                    grid[i][j] += grid[i-1][j];   
                }
                if (i == x && j == y) break;
            }
            if (j < grid[0].length) break;
        }
        
        System.out.println(grid[x][y]);

        for (i=0; i < grid.length; i++) {
            for (j=0; j < grid[i].length; j++) {
                System.out.print(grid[i][j]+ " ");
            }
            System.out.println();
        }
    }
}