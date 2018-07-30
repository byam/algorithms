package com.byam.cracking_code_interview.app.chapter1.q_05_one_away;

import java.util.Arrays;

/**
 * Time: O(n)
 */
public class SolutionA {
    public static void main (String[] args) {
        String[][] words = {{"pale", "ple"}, {"pales", "pale"}, {"pale", "bale"}, {"pale", "bae"}, {"pale", "pa"}};
        for (String[] pair: words){
            System.out.println(Arrays.toString(pair) + ": " + isOneAway(pair[0], pair[1]));
        }
    }

    private static boolean isOneAway(String a, String b){
        if (a.length() == b.length())
            return isOneReplace(a, b);
        if (a.length() == b.length() + 1)
            return isOneInsertOrRemove(a, b);
        if (a.length() + 1 == b.length())
            return isOneInsertOrRemove(b, a);

        return false;
    }

    private static boolean isOneReplace(String a, String b){
        boolean flag = true;

        for (int i = 0; i < a.length(); i++){
            if (a.charAt(i) != b.charAt(i)) {
                if (! flag){
                    return false;
                }
                flag = false;
            }
        }

        return true;
    }

    private static boolean isOneInsertOrRemove(String a, String b){
        boolean flag = true;

        int ia = 0;
        int ib = 0;
        for (int i = 0; i < b.length(); i++){
            if (a.charAt(ia) != b.charAt(ib)){
                if (! flag){
                    return false;
                }
                flag = false;
                ia ++;
            } else {
                ia++;
                ib++;
            }
        }

        return true;
    }
}
