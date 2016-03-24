import java.util.*;
import java.io.*;

class KMP
{
    private int [] table;

    private char [] needle;

    private char [] haystack;

    public void setTable(int [] table)
    {
        this.table = table;
    }

    public void setNeedle(char [] needle)
    {
        this.needle = needle;
    }

    public void setHaystack(char [] haystack)
    {
        this.haystack = haystack;
    }

    private void createTable()
    {
        this.table = new int[this.needle.length];
        this.table[0] = -1; this.table[1] = 0;

        int pos = 2;
        int cnd = 0;

        while (pos < this.needle.length) {
            if (this.needle[pos-1] == this.needle[cnd]){
                cnd = cnd + 1;
                this.table[pos] = cnd;
                pos = pos + 1;
            } else if(cnd > 0) {
                cnd = this.table[cnd];
            } else {
                this.table[pos] = 0;
                pos = pos + 1;
            }
        }
    }

    public ArrayList<Integer> findNeedle(int m)
    {
        createTable();
        int i = 0;
        ArrayList<Integer> result = new ArrayList<Integer>();
        while ((m + i) < this.haystack.length) {
            if (this.haystack[m+i] == this.needle[i]) {
                if (i == this.needle.length - 1) {
                    result.add(m);
                    m = m + i - this.table[i];
                    i = this.table[i];
                } else {
                    i = i + 1;
                }
            } else {
         /*       int editDistance = computeLevenshteinDistance(
                        Arrays.copyOfRange(this.haystack, m, m + this.needle.length),
                        this.needle
                    );
                if (3 > editDistance) {
                    result.add(m);
                }*/

                if (-1 < this.table[i]) {
                    m = m + i - this.table[i];
                    i = this.table[i];
                } else {
                    m = m + 1;
                    i = 0;
                }
            }
        }
        return result;
    }
}

public class FindTorpedo
{
    private static char [][] torpedo;
    private static char [][] testData;

    private static int minimum(int a, int b, int c) {
        return Math.min(Math.min(a, b), c);
    }

    private static int computeLevenshteinDistance(char [] lhs, char [] rhs)
    {
        int[][] distance = new int[lhs.length + 1][rhs.length + 1];

        for (int i = 0; i <= lhs.length; i++) {
            distance[i][0] = i;
        }

        for (int j = 1; j <= rhs.length; j++){
            distance[0][j] = j;
        }

        for (int i = 1; i <= lhs.length; i++) {
            for (int j = 1; j <= rhs.length; j++){
                distance[i][j] = minimum(
                        distance[i - 1][j] + 1,
                        distance[i][j - 1] + 1,
                        distance[i - 1][j - 1] + ((lhs[i - 1] == rhs[j - 1]) ? 0 : 1)
                    );
            }
        }

        return distance[lhs.length][rhs.length];
    }

    private static int findMatches(int testDataRow, int testDataCol)
    {
        int matches = 0;
        for (int i=0; i < torpedo.length; i++) {
            for (int j=0; j < torpedo[0].length; j++) {
                if (testData[testDataRow+i][testDataCol+j] == torpedo[i][j]) {
                    matches++;
                }
            }
        }
        return matches;
    }

    private static void printMatches(int testDataRow, int testDataCol)
    {
        for(int i=testDataRow; i < testDataRow+torpedo.length; i++) {
            for(int j=testDataCol; j < testDataCol+torpedo[0].length; j++) {
                System.out.print(testData[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new FileReader("SlimeTorpedo.blf"));
        torpedo = new char[11][9];

        String input;
        int row = 0;
        while (null != (input = br.readLine())) {
            torpedo[row++] = input.toCharArray();
        }
        br.close();

        br = new BufferedReader(new FileReader("TestData.blf"));
        row = 0; input = "";
        testData = new char[100][100];
        while (null != (input = br.readLine())) {
            testData[row++] = input.toCharArray();
        }
        br.close();
        for (int testDataRow = 0; testDataRow <= (testData.length - torpedo.length); testDataRow++) {
            for (int testDataCol = 0; testDataCol <= (testData[0].length - torpedo[0].length); testDataCol++) {
                int matches = findMatches(testDataRow, testDataCol);
                if (0.66 <= (float)matches/99) {
                    System.out.println(testDataRow + " " + testDataCol + " " + (float)matches/99);
                    printMatches(testDataRow, testDataCol);
                }
            }
        }
    }
}
