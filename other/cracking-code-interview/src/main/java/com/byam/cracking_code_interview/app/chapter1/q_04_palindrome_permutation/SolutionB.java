package com.byam.cracking_code_interview.app.chapter1.q_04_palindrome_permutation;

public class SolutionB {
    public static void main (String[] args){
        String[] phrases = {"tact coa", "a ", "abbc", "  "};
        for (String p: phrases){
            System.out.println(p + ": " + isPalindromePermutation(p));
        }
    }

    private static boolean isPalindromePermutation(String phrase){
        int countOdd = 0;

        int[] countTable = new int[Character.getNumericValue('z') - Character.getNumericValue('a') + 1];
        for (int i = 0; i < phrase.length(); i++){
            int cNum = Character.getNumericValue(phrase.charAt(i)) - Character.getNumericValue('a');
            if (cNum > -1){
                countTable[cNum] ++;
                if (countTable[cNum] % 2 == 1){
                    countOdd ++;
                } else {
                    countOdd --;
                }
            }
        }

        return countOdd <= 1;
    }
}
