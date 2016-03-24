// This is the text editor interface.
// Anything you type or change here will be seen by the other person in real time.

import java.util.*;
import java.io.*;

public class StringPermutations
{
    private static HashSet generatePermutations(String input)
    {
        HashSet<String> return_set = new HashSet<String>();
        if(input.length() > 0) {
            int len = input.length();
            HashSet<String> set = generatePermutations(input.substring(0, len-1));

            char suffix = input.charAt(len-1);

            if(set.size() > 0) {
                Iterator<String> iterator = set.iterator();
                while(iterator.hasNext()) {
                    StringBuilder str = new StringBuilder(iterator.next());
                    for(int i=0; i <= str.length(); i++) {
                        String add = str.insert(i, suffix).toString();
                        //System.out.println(add);
                        return_set.add(add);
                        str.deleteCharAt(i);
                    }
                }
            } else {
                return_set.add(input);
            }
        }

        return return_set;
    }

    public static void main(String []args) throws Exception
    {
        String input = "abcd";
        HashSet<String> set = generatePermutations(input);
        Iterator<String> iterator = set.iterator();
        while(iterator.hasNext()) {
            System.out.println(iterator.next());
        }
    }
}