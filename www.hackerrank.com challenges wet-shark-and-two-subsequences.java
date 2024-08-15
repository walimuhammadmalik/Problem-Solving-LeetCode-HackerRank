import java.io.*;
import java.util.*;

public class Solution {
  private static InputReader in;
  private static PrintWriter out;
  public static int mod = 1000000007;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int M = in.nextInt();
    int R = in.nextInt();
    int S = in.nextInt();
    if ((R+S) % 2 != 0 || S >= R) {
      out.println("0");
      out.close();
      System.exit(0);
    }
    
    int P = (R+S)/2, Q = (R-S)/2;
    
    long[][] nways = new long[M+1][P+1];
    nways[0][0] = 1;
    for (int i = 1; i <= M; i++) {
      int x = in.nextInt();
      for (int j = M; j >= 1; j--) {
        for (int k = P; k >= x; k--) {
          nways[j][k] += nways[j-1][k-x];
          if (nways[j][k] >= mod) nways[j][k] -= mod;
        }
      }
    }
    
    long total = 0;
    for (int i = 0; i <= M; i++) {
      total = (total + nways[i][P] * nways[i][Q]) % mod;
    }
    out.println(total);
    out.close();
    System.exit(0);
    
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }


}
