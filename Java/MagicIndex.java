import java.util.*;
import java.io.*;

public class MagicIndex
{
    private static ArrayList<Integer> list = new ArrayList<Integer>();

    public static int findMagicIndex(int low, int high)
    {
        if (low <= high) {
            int mid = (low + high)/2;
            if (list.get(mid) > mid) {
                return findMagicIndex(low, mid-1);
            } else if (list.get(mid) < mid) {
                return findMagicIndex(mid +1 , high);
            } else if (list.get(mid) == mid){
                return mid;
            }
        }
        return -1;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        while(sc.hasNextInt()) {
            list.add(sc.nextInt());
        }

        System.out.println("Magic Index is : " + findMagicIndex(0, list.size()-1));

        sc.close();
    }
}