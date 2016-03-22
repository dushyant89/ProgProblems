/*
This program is used to find median in a list which changes
on every iteration i.e. elements can be added or removed from the list
*/

import java.util.*;
import java.io.*;

class MedianHeap
{
    public double median;
    PriorityQueue<Double> right_min_heap = new PriorityQueue<Double>(5);
    PriorityQueue<Double> left_max_heap = new PriorityQueue<Double>(5, new Comparator<Double>(){
        @Override
        public int compare(Double a1, Double a2) {
            return (a2 > a1) ? 1 : -1;
        }
    });
    public boolean even;
}

public class MovingMedian
{
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("mediansInput.txt"));
        int initialSize = sc.nextInt();
        ArrayList<Double> list = new ArrayList<Double>(initialSize);
        while(--initialSize >= 0) {
            list.add((double)sc.nextInt());
        }
        //Sorting the list.
        Collections.sort(list);

        // Initializing the heap now for storing the median.
        MedianHeap heap = new MedianHeap();
        int size = list.size();
        if (0 == size%2) {
            // If the list has even no. of elements
            heap.median = (list.get(size/2) + list.get(size/2 - 1))/2;
            // now making the right_min_heap
            for(int i=size/2; i < size; i++) {
                heap.right_min_heap.add(list.get(i));
            }
            // now making the left_max_heap
            for(int i=0; i <= size/2 -1; i++) {
                heap.left_max_heap.add(list.get(i));
            }
            heap.even = true;
        } else {
            heap.median = list.get(size/2);
            // now making the right_min_heap
            for(int i=size/2 + 1; i < size; i++) {
                heap.right_min_heap.add(list.get(i));
            }
            // now making the left_max_heap
            for(int i=0; i < size/2; i++) {
                heap.left_max_heap.add(list.get(i));
            }
            heap.even = false;
        }
/*        while(null != heap.left_max_heap.peek()) {
            System.out.print(heap.left_max_heap.poll() + " ");
        }
        System.out.println();
        while(null != heap.right_min_heap.peek()) {
            System.out.print(heap.right_min_heap.poll() + " ");
        }*/
        System.out.println("Initial Median : " + heap.median);
        while (sc.hasNextInt()) {
            double newElement = (double)sc.nextInt();
            if (heap.even) {
                if (newElement > heap.median) {
                    heap.right_min_heap.add(newElement);
                    heap.median = heap.right_min_heap.poll();
                } else {
                    heap.left_max_heap.add(newElement);
                    heap.median = heap.left_max_heap.poll();
                }
            } else {
                if (newElement > heap.median) {
                    heap.left_max_heap.add(heap.median);
                    heap.right_min_heap.add(newElement);
                    heap.median = (heap.right_min_heap.peek() + heap.median)/2;
                } else {
                    heap.right_min_heap.add(heap.median);
                    heap.left_max_heap.add(newElement);
                    heap.median = (heap.left_max_heap.peek() + heap.median)/2;
                }
            }
            System.out.println("Median now is : " + heap.median);
            heap.even = !heap.even;
        }
    }
}