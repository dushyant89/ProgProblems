import java.util.*;
import java.io.*;

public class NumberAsBits
{
    public static void main(String[] args)
    {
        byte [] data = new byte[2];
        int [] a = {1, 2, 4, 5, 4, 5, 2, 6, 8, 9, 7, 12, 13, 11, 10, 9};
        for (int i=0; i < a.length; i++) {
            /*
             a[i]/8 finds the location of the byte in the data array
             a[i]%8 finds the location of the bit inside the byte
            */
            data[a[i]/8] |= 1 << (a[i]%8);
        }

        for(int i = 0; i < data.length; i++) {
            for (int j = 0; j < 8; j++) {
                if (0 == (data[i] & (1 << j))) {
                    System.out.println(i*8 + j);
                }
            }
        }
    }
}