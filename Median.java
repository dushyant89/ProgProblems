import java.util.*;
import java.io.*;

public class Median 
{
    public static double calculateMedian(ArrayList<Integer> a)
    {
        int size = a.size();
        ArrayList<ArrayList<Integer>> lists = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> list = new ArrayList<Integer>();
        list.add(a.get(0));
        // Making groups of 5 elements each.
        int i;
        for (i=1; i < size; i++) {
            if (0 == i%5) {
                lists.add(list);
                list = new ArrayList<Integer>(5);
                System.out.println();
            }
            System.out.print(i + ":" + a.get(i) + " ");
            list.add(a.get(i));
        }
        lists.add(list);
        System.out.println();
        //Now sort each of the sub groups.
        ArrayList<Integer> newList = new ArrayList<Integer>();
        for (ArrayList<Integer> temp : lists) {
            Collections.sort(temp);
            // Getting the medians of the 5 element group.
            newList.add(temp.get(temp.size()/2));
            //System.out.print(temp.get(2) + " ");
        }
        System.out.println("Size:" + newList.size());
        if (newList.size() < 3) {
            if (1 == newList.size()) {
                return (double)newList.get(0);
            } else{
                return (double)(newList.get(0) + newList.get(1))/2;
            }
        }
        return calculateMedian(newList);
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> a = new ArrayList<Integer>();
        while (sc.hasNextInt()) {
            a.add(sc.nextInt());
        }

        System.out.println(calculateMedian(a));
    }
}