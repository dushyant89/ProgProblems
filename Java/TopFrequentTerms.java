import java.util.*;
import java.io.*;

class KeyComparator implements Comparator<Integer>
{
    @Override
    public int compare(Integer o1, Integer o2) {
        return o2 - o1;
    }
}

public class TopFrequentTerms
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(new File("words.txt"));
        HashMap<String, Integer> string_map = new HashMap<String, Integer>();
        // n is the length of the input
        // O(n) time for making the map
        while(sc.hasNext()) {
            String input = sc.next();
            int val;
            if (null == string_map.get(input)) {
                val = 1;
                string_map.put(input, 1);
            } else {
                val = string_map.get(input);
                string_map.put(input, ++val);
            }
        }

        TreeMap<Integer, ArrayList<String>> result_map = new TreeMap<Integer, ArrayList<String>>(new KeyComparator());
        //O(nlog(n)) for creating the whole TreeMap
        for(Map.Entry<String, Integer> entry : string_map.entrySet()) {
            ArrayList<String> list = result_map.get(entry.getValue());
            if (null == list){
                list = new ArrayList<String>();
                list.add(entry.getKey());
                result_map.put(entry.getValue(), list);
            } else {
                list.add(entry.getKey());
            }
        }

        for(Map.Entry<Integer, ArrayList<String>> entry : result_map.entrySet()) {
            System.out.print(entry.getKey() + ": ");
            for (String result : entry.getValue()) {
                System.out.print(result + " ");
            }
            System.out.println();
        }
    }
}