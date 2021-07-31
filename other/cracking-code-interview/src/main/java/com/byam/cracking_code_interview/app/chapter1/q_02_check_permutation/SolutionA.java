package com.byam.cracking_code_interview.app.chapter1.q_02_check_permutation;

/**
 * Sorting letters.
 * time: O(n log n), space: O(1)
 */
public class SolutionA {

    private static String sort(String str){
        char[] letters = str.toCharArray();
        java.util.Arrays.sort(letters);
        return new String(letters);
    }

    private static boolean isPermutation(String word1, String word2) {

        return word1.length() == word2.length() && sort(word1).equals(sort(word2));
    }

    public static void main(String[] args){
        String[][] pairs = {{"apple", "papel"}, {"carrot", "tarroc"}, {"hello", "llloh"}};

        for (String[] pair: pairs){
            String word1 = pair[0];
            String word2 = pair[1];

            boolean anagram = isPermutation(word1, word2);
            System.out.println(String.format("%s, %s: %s", word1, word2, anagram));
        }
    }
}
