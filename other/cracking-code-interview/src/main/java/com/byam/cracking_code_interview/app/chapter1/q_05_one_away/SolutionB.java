package com.byam.cracking_code_interview.app.chapter1.q_05_one_away;

import java.util.Arrays;

/**
 * Time: O(n)
 */
public class SolutionB {
    public static void main (String[] args) {
        String[][] words = {{"pale", "ple"}, {"pales", "pale"}, {"pale", "bale"}, {"pale", "bae"}, {"pale", "pa"}};
        for (String[] pair: words){
            System.out.println(Arrays.toString(pair) + ": " + isOneAway(pair[0], pair[1]));
        }
    }

    private static boolean isOneAway(String a, String b){

        if (Math.abs(a.length() - b.length()) > 1)
            return false;

        String s1 = a.length() > b.length() ? a : b;
        String s2 = a.length() > b.length() ? b : a;

        int i1 = 0;
        int i2 = 0;

        boolean foundDiff = false;

        while (i1 < s1.length() && i2 < s2.length()){
            if (s1.charAt(i1) != s2.charAt(i2)){
                if (foundDiff)
                    return false;
                foundDiff = true;
                if (s1.length() == s2.length()) {
                    i2++;
                }
            } else {
                i2 ++;
            }
            i1 ++;
        }

        return true;
    }
}
