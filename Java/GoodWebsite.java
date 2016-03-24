import java.util.*;
import java.io.*;
import java.lang.Math;

public class GoodWebsite
{
    public static String [] getLinks(String link) {
        if ("homepage" == link) {
            String [] links = {"page1", "page2", "page3", "page5"};
            return links;
        } else if ("page2" == link) {
            String [] links = {"page1", "page3", "page4", "page5"};
            return links;
        } else if ("page3" == link) {
            String [] links = {"page1", "page6", "page7", "page5"};
            return links;
        } else if ("page4" == link) {
            String [] links = {"page6", "page7", "page8", "page9"};
            return links;
        } else if ("page5" == link) {
            String [] links = {"page6", "page2", "page8", "page9"};
            return links;
        }
        return null;
    }

    public static void main(String[] args) {
        HashMap<String, Integer> all_links_map = new HashMap<String, Integer>();
        all_links_map.put("homepage", 0);
        // Setting the initial capacity of the set to 20
        ArrayList<String> all_links_list = new ArrayList<String>(20);
        all_links_list.add("homepage");

        for (int i=0; i < all_links_list.size(); i++) {
            String parentLink = all_links_list.get(i);
            String [] links = getLinks(parentLink);
            int reach_index = all_links_map.get(parentLink);
            if (null != links) {
                for (String link : links) {
                    if (null == all_links_map.get(link)) {
                        all_links_map.put(link, reach_index+1);
                        all_links_list.add(link);
                    } else {
                        all_links_map.put(link, Math.max(all_links_map.get(link) + 1, reach_index + 1));
                    }
                }
            }
        }

        boolean check = false;
        for(Map.Entry<String, Integer> set : all_links_map.entrySet()) {
            System.out.println("Page : " + set.getKey() + " Value : " + set.getValue());
            if(5 <= set.getValue()) {
                System.out.println("Bad website");
                check = true;
                break;
            }
        }
        if (!check) {
            System.out.println("Good website");
        }
    }
}