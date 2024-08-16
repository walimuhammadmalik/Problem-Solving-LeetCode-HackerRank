import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    public static String abbreviation(String a, String b) {
        int n = a.length();
        int m = b.length();

        // DP table initialization
        boolean[][] dp = new boolean[n + 1][m + 1];
        dp[0][0] = true; // Both strings are empty

        // Handle cases where b is an empty string
        for (int i = 1; i <= n; i++) {
            if (Character.isLowerCase(a.charAt(i - 1))) {
                dp[i][0] = dp[i - 1][0];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char charA = a.charAt(i - 1);
                char charB = b.charAt(j - 1);

                // Check if we can match the current character
                if (Character.toUpperCase(charA) == charB) {
                    dp[i][j] = dp[i - 1][j - 1] || (Character.isLowerCase(charA) && dp[i - 1][j]);
                } else if (Character.isLowerCase(charA)) {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Return the final result
        return dp[n][m] ? "YES" : "NO";
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, q).forEach(qItr -> {
            try {
                String a = bufferedReader.readLine();

                String b = bufferedReader.readLine();

                String result = Result.abbreviation(a, b);

                bufferedWriter.write(result);
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
