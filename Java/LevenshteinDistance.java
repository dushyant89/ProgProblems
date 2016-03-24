import java.io.*;

public class LevenshteinDistance {

    private static int minimum(int a, int b, int c) {
        return Math.min(Math.min(a, b), c);
    }

    public static int computeLevenshteinDistance(char [] lhs, char [] rhs) {
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

    public static void main(String[] args) throws Exception {
        String input_1 = "++++  + ";
        String input_2 = "++++  ++";
        System.out.println(
            computeLevenshteinDistance(
                input_1.toCharArray(),
                input_2.toCharArray()
            )
        );
    }
}