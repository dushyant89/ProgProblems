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
                int editDistance = computeLevenshteinDistance(
                        Arrays.copyOfRange(this.haystack, m, m + this.needle.length),
                        this.needle
                    );
                if (3 > editDistance) {
                    result.add(m);
                }

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
    private int minimum(int a, int b, int c) {
        return Math.min(Math.min(a, b), c);
    }

    public static computeLevenshteinDistance(char [] lhs, char [] rhs)
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

    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new FileReader("SlimeTorpedo.blf"));
        char [][] torpedo = new char[11][9];

        String input;
        int row = 0;
        while (null != (input = br.readLine())) {
            torpedo[row++] = input.toCharArray();
        }
        br.close();

        br = new BufferedReader(new FileReader("TestData.blf"));
        row = 0; input = "";
        char [][] testData = new char[100][100];
        while (null != (input = br.readLine())) {
            testData[row++] = input.toCharArray();
        }
        br.close();

        KMP kmp = new KMP();
        for (int i = 0; i <= (testData.length - torpedo.length); i++) {
            kmp.setHaystack(testData[i]);
            // Start from the top. If the top row matches then
            // only check the rows below.
            kmp.setNeedle(torpedo[0]);

            ArrayList<Integer> result = kmp.findNeedle(0);
            // If there was an instance of one match.
            if (0 < result.size()) {
                // Iterate over the indices matched for the top row.
                for (int j = 0; j < result.size(); j++) {
                    int k;
                    // Check for the subsequent rows down.
                    for (k = 1; k < torpedo.length; k++) {
                        kmp.setNeedle(torpedo[k]);
                        kmp.setHaystack(testData[i+k]);
                        // If there is a mismatch in any of
                        // middle rows then break.
                        if (0 == kmp.findNeedle(result.get(j)).size()) {
                            break;
                        }
                    }
                    // If all the rows matched, means object found.
                    if (k == torpedo.length) {
                        System.out.println((i + 1) + " " + (1 + result.get(j)));
                    }
                }
            }
        }
    }
}
