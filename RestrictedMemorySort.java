/*
This program is used for sorting numbers in a scenario where
the whole list cannot be brought into main memory for sorting
*/

import java.util.*;
import java.io.*;

class Element
{
    public int head;
    public ArrayList<Integer> list;

    public Element(int head, ArrayList<Integer> list)
    {
        this.head = head;
        this.list = list;
    }

    public void print() 
    {
        for (Integer x : this.list) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
}

public class RestrictedMemorySort
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(new File("numbers.txt"));
        //We maintain the sorted lists in a priority queue
        PriorityQueue<Element> disk = new PriorityQueue<Element>(100, new Comparator<Element>(){
            @Override
            public int compare(Element e1, Element e2)
            {
                return e1.head - e2.head;
            }
        });

        int count = 1;
        ArrayList<Integer> tempList = new ArrayList<Integer>();
        tempList.add(sc.nextInt());
        while(sc.hasNext()) {
            if (0 == count%10) {
                //Sort the current temporary list whose size depends on the size of the memory we have in hand.
                Collections.sort(tempList);
                // Add the list to the queue where the ordering is maintained by the head of the list.
                disk.add(new Element(tempList.get(0), tempList));
                tempList = new ArrayList<Integer>();
            }
            tempList.add(sc.nextInt());
            count++;
        }

        Collections.sort(tempList);
        // Add the remaining tempList to the queue.
        disk.add(new Element(tempList.get(0), tempList));

        while (0 < disk.size()) {
            Element e = disk.poll();
            System.out.print(e.head + " ");
            //e.print();
            if (0 < e.list.size()) {
                e.list.remove(0);
                if (0 < e.list.size()) {
                    e.head = e.list.get(0);
                    disk.add(e);
                }
            }
        }
    }
}