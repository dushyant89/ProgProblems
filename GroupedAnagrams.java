// This is the text editor interface.
// Anything you type or change here will be seen by the other person in real time.

import java.util.*;
import java.io.*;

public class GroupedAnagrams
{
    public static void main(String []args) throws Exception
    {
        HashMap<String, ArrayList<String>> anagrams = new HashMap<String, ArrayList<String>>();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        while(--n >= 0) {
            String input = br.readLine();

            char [] char_input = input.toCharArray();
            Arrays.sort(char_input);
            String sorted_input = new String(char_input);

            if (null == anagrams.get(sorted_input)) {
                ArrayList<String> list = new ArrayList<String>();
                list.add(input);
                anagrams.put(sorted_input, list);
            } else {
                anagrams.get(sorted_input).add(input);
            }
        }

        for (Map.Entry<String, ArrayList<String>> entry : anagrams.entrySet()) {
            ArrayList<String> list = entry.getValue();
            for (String temp : list) {
			    System.out.print(temp+" ");
		    }
		    System.out.println();
        }
    }
}