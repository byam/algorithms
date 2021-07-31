package com.byam.cracking_code_interview.app.chapter1.q_03_urlify;

/**
 * time: O(n), space: O(1)
 */
public class Solution {

    // Assume string has sufficient free space at the end
    private static void replaceSpaces(char[] arr, int length){

        int space = 0;
        for (int i = 0; i < length; i++){
            if (arr[i] == ' ') {
                space++;
            }
        }


        int index = length + space * 2; // ' ' -> '%20'

        for (int i = length - 1; i >= 0; i--){

            if (arr[i] == ' '){
                arr[index - 1] = '0';
                arr[index - 2] = '2';
                arr[index - 3] = '%';
                index = index - 3;
            } else {
                arr[index - 1] = arr[i];
                index--;
            }
        }

    }

    private static int findLastCharacter(char[] arr){
        for (int i = arr.length - 1; i >= 0; i--){
            if (arr[i] != ' ')
                return i + 1;
        }

        return -1;
    }

    public static void main(String[] args) {
        String str = "Mr John Smith    ";
        char[] arr = str.toCharArray();
        int trueLength = findLastCharacter(arr);

        replaceSpaces(arr, trueLength);

        System.out.println(str);
        System.out.println(new String(arr));
    }
}
