/*
A solution requires that no two queens share the same row, column, or diagonal. 
The eight queens puzzle is an example of the more general n queens problem of placing
n non-attacking queens on an n×n chessboard, for which solutions exist for all natural
numbers n with the exception of n=2 and n=3.
*/

import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class NQueens
{
    private static ArrayList<int []> results = new ArrayList<int []>();
    private static int size;

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter the grid size");
        size = sc.nextInt();

        placeQueens(0, new int[size]);

        for (int [] a : results) {
            for (int i=0; i < size; i++) {
                System.out.println("[" + i + "][" + a[i] + "]");
            }
            System.out.println("*********************************");
        }
    }

    // We recurse over the rows and the previously used columns.
    // The result[i] = j means Queen is placed at [i][j] in a grid of size size*size.
    public static void placeQueens(int row, int [] result)
    {
        if (row == size) {
            results.add(result.clone());
        } else {
            // Looping over all the columns.
            for (int col = 0; col < size; col++) {
                if (validPos(row, col, result)) {
                    result[row] = col;
                    placeQueens(row + 1, result);
                }
            }
        }
    }

    public static boolean validPos(int newRow, int currentCol, int [] result)
    {
        for (int i = 0; i < newRow; i++) {
            // Check if the previously placed queen in some previous row is in the same column.
            // All previous rows are less than the new row
            if (result[i] == currentCol) {
                return false;
            }

            if ((newRow - i) == Math.abs(result[i] - currentCol)) {
                return false;
            }
        }
        return true;
    }
}
