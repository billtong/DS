package billtong.algorithm.dynamic_programing;

import java.util.Arrays;

public class LongestCommonSubstring {
    private String a;
    private String b;
    private int table[][];
    private StringBuffer buffer;

    public LongestCommonSubstring(String str1, String str2) {
        this.a = "x"+str1;  //to match the index of table
        this.b = "y"+str2;  //to match the index of table
        int lengthA = a.length();
        int lengthB = b.length();
        table = new int[lengthA][lengthB];
        for (int i=0; i<a.length(); i++)
            table[i][0] = 0;
        for (int j=0; j<b.length(); j++)
            table[0][j]=0;
    }

    public String solve() {
        for (int i=1; i<a.length(); i++) {
            for (int j=1; j<b.length(); j++) {
                table[i][j] = a.charAt(i) == b.charAt(j) ? table[i-1][j-1] + 1 : Math.max(table[i-1][j], table[i][j-1]);
            }
        }
        buffer = new StringBuffer();
        buffer = getLCS(a.length()-1, b.length()-1);
        return String.valueOf(buffer.reverse());
    }

    private StringBuffer getLCS(int i, int j) {
        if (i==0 || j==0)
            return buffer;
        else if (a.charAt(i) == b.charAt(j)) {
            buffer.append(a.charAt(i));
            return getLCS(i-1, j-1);
        } else if (a.charAt(i-1) == b.charAt(j) || table[i - 1][j] >= table[i][j - 1]){
            return getLCS(i-1, j);
        } else {
            return getLCS(i, j-1);
        }
    }
}
