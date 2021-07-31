package com.byam.cracking_code_interview.app.chapter1.q_02_check_permutation;


/**
 * Counting letters.
 * time: O(n), space: O(1)
 */
public class SolutionB {

    private static boolean isPermutation(String word1, String word2) {

        if (word1.length() != word2.length())
            return false;

        // assume ASCII
        int[] lettes = new int[256];

        for (int i = 0; i < word1.length(); i++){
            int val = word1.charAt(i);
            lettes[val]++;
        }

        for (int i = 0; i < word2.length(); i++){
            int val = word2.charAt(i);
            lettes[val]--;

            if(lettes[val] < 0)
                return false;
        }

        return true;
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
