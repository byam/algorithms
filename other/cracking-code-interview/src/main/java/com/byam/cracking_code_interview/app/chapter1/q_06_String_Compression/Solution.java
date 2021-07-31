package com.byam.cracking_code_interview.app.chapter1.q_06_String_Compression;

/**
 * Time: O(n), Memory: O(1)
 */
public class Solution {

    private static String compressString(String word) {

        int compressSize = compressionSize(word);

        if (compressSize >= word.length())
            return word;

        char[] arr = new char[compressSize];

        int index = 0;
        int count = 1;
        char last = word.charAt(0);
        for (int i = 1; i < word.length(); i++){
            if (last == word.charAt(i))
                count ++;
            else {
                index = setChar(arr, index, last, count);
                last = word.charAt(i);
                count = 1;
            }
        }

        setChar(arr, index, last, count);

        return String.valueOf(arr);
    }

    private static int setChar(char[] arr, int index, char last, int count) {
        arr[index] = last;
        index ++;

        String strCount = String.valueOf(count);
        for (int i = 0; i < strCount.length(); i++){
            arr[index] = strCount.charAt(i);
            index ++;
        }

        return index;
    }

    private static int compressionSize(String word) {
        int size = 0;
        int count = 1;
        char last = word.charAt(0);
        for (int i = 1; i < word.length(); i++){
            if (last == word.charAt(i))
                count ++;
            else {
                size += 1 + String.valueOf(count).length();
                last = word.charAt(i);
                count = 1;
            }
        }

        size += 1 + String.valueOf(count).length();

        System.out.println(word + ": size = " + size);

        return size;
    }

    public static void main(String[] args){

        String[] words = {"aa", "aabcccccaaa", "aaaaaaaaaaaab"};

        for (String word: words){
            System.out.println(word + ": compress = " + compressString(word));
        }
    }
}
