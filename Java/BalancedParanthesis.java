/* 
* This program checks if the input string given by the user
* contains a balanced set of paranthesis. https://en.wikipedia.org/wiki/External_sorting
*/

import java.util.*;
import java.io.*;

public class BalancedParanthesis
{
    public static boolean isBalanced (String input) {
        HashMap<Character,Integer> paranthesis_map = new  HashMap<Character,Integer>();
        HashMap<Character,Character> paranthesis_paranthesis = new  HashMap<Character,Character>();

        paranthesis_map.put('(',0);
        paranthesis_map.put('{',0);
        paranthesis_map.put('[',0);
        paranthesis_paranthesis.put(')','(');
        paranthesis_paranthesis.put('}','{');
        paranthesis_paranthesis.put(']','[');

        char [] chars = input.toCharArray();

        int val = 0;
        for(int i=0; i < chars.length; i++) {
            if ('(' == chars[i] || '{' == chars[i] || '[' == chars[i]) {
                val = paranthesis_map.get(chars[i]);
                paranthesis_map.put(chars[i], ++val);
            } else if (')' == chars[i] || '}' == chars[i] || ']' == chars[i]) {
                val = paranthesis_map.get(paranthesis_paranthesis.get(chars[i]));
                paranthesis_map.put(paranthesis_paranthesis.get(chars[i]), --val);
            }
        }

        if (paranthesis_map.get('(') == 0 && paranthesis_map.get('{')==0 && paranthesis_map.get('[')==0) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String []args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        sc.close();
        System.out.println(isBalanced(input));
    }
}
