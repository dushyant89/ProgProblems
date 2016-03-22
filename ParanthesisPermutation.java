import java.util.*;

public class ParanthesisPermutation
{
    public static void main(String[] args) {
        ArrayList<ArrayList<String>> main_list = new ArrayList<ArrayList<String>>();
        // No. of inner lists should be equal to n-1 before reaching the case for n
        int n = 4;

        // Adding the list for the base case
        ArrayList<String> list_1 = new ArrayList<String>();
        list_1.add("()");

        main_list.add(list_1);

        for(int i=1; i < n; i++) {
            ArrayList<String> base_list = main_list.get(i-1);
            ArrayList<String> new_list = new ArrayList<String>();
            boolean once = true;
            for(String str : base_list) {
                if (once) {
                    // Attach at the front of the component
                    new_list.add("()" + str);
                    once = false;
                }
                //Search for first ( and add after that
                int start = 0;
                int index = str.indexOf("(", start);
                while (-1 != index) {
                    new_list.add(str.substring(0, index+1) + "()" + str.substring(index+1));
                    start = index + 1;
                    index = str.indexOf("(", start);
                }
            }
            main_list.add(new_list);
        }
        for (ArrayList<String> list : main_list) {
            for(String str : list) {
                System.out.println(str);
            }
            System.out.println();
        }
    }
}