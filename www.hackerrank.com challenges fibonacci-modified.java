import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


public class Solution {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    BigInteger firstTerm = BigInteger.valueOf(in.nextInt());
    BigInteger secondTerm = BigInteger.valueOf(in.nextInt());
    int term = in.nextInt();

    for(int i = 2; i < term; i++) {
      BigInteger tempTerm = firstTerm.add(secondTerm.multiply(secondTerm));
      firstTerm = secondTerm;
      secondTerm = tempTerm;
    }

    System.out.printf("%s", secondTerm.toString());
  }
}
