package com.byam.cracking_code_interview.app.chapter1.q_01_is_unique;

public class QuestionA {

    private static boolean isUnique(String str){
        if (str.length() > 128)
            return false;

        boolean charSet[] = new boolean[128];

        for (int i = 0; i < str.length(); i++){
            int val = str.charAt(i);

            if(charSet[val])
                return false;

            charSet[val] = true;
        }

        return true;
    }

    public static void main(String[] args){
        String[] words = {"hello", "world"};

        for (String word: words){
            System.out.println(word + ": " + isUnique(word));
        }
    }
}
