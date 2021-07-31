package com.byam.cracking_code_interview.app.utills;

public class BitManipulation {
    public static void main(String[] args){

        int count = Integer.bitCount(17);
        System.out.println("Count: " + count);

        int highest = Integer.highestOneBit(17);
        System.out.println("Highest: " + highest);

        int number = 3; // 11 in binary
        int reverseNumber = Integer.reverse(number);
        String reserserString = Integer.toBinaryString(reverseNumber);
        System.out.println("Normal: " + Integer.toBinaryString(number));
        System.out.println("Reverse: " + reserserString);

        Integer byBytes = Integer.decode("0x12345678");
        System.out.println("normal: " + Integer.toHexString(byBytes));
        System.out.println("reverse: " + Integer.toHexString(Integer.reverseBytes(byBytes)));

        // Shifting bits
        int uint = Integer.parseUnsignedInt("3");
        Integer shitfLeft = Integer.rotateLeft(uint, 2);
        Integer shitfRight = Integer.rotateRight(uint, 2);
        System.out.println("Normal: " + Integer.toBinaryString(uint));
        System.out.println("Left shift 2: " + Integer.toBinaryString(shitfLeft));
        System.out.println("Right shift 2: " + Integer.toBinaryString(shitfRight));

        // Logical conjunction
        System.out.println("3 in bits: " + Integer.toBinaryString(3));
        System.out.println("11 in bits: " + Integer.toBinaryString(11));
        System.out.println("Logical Conjunction in 3 and 11: " + Integer.toBinaryString(3 & 11));

    }
}
