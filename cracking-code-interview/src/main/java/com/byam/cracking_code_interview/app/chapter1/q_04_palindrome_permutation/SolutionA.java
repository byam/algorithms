package com.byam.cracking_code_interview.app.chapter1.q_04_palindrome_permutation;

/**
 * Time: O(n)
 */
public class SolutionA {

    public static void main (String[] args){
        String[] phrases = {"tact coa", "a ", "abbc", "  "};
        for (String p: phrases){
            System.out.println(p + ": " + isPalindromePermutation(p));
        }
    }

    private static boolean isPalindromePermutation(String phrase){
        int[] countTable = createLetterCountTable(phrase);
        return isOneOddLetter(countTable);
    }

    private static int[] createLetterCountTable(String phrase){
        int aNum = Character.getNumericValue('a');
        int zNum = Character.getNumericValue('z');
        int size = zNum - aNum + 1;
        int[] table = new int[size];

        for (int i = 0; i < phrase.length(); i++){
            int charNum = Character.getNumericValue(phrase.charAt(i));

            if (charNum >= aNum && charNum <= zNum)
                table[charNum - aNum] ++;
        }

        return table;
    }

    private static boolean isOneOddLetter(int[] table){
        boolean flag = true;

        for (int count : table){
            if (count % 2 == 1){
                if (!flag)
                    return false;
                flag = false;
            }
        }

        return true;
    }
}
