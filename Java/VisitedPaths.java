import java.io.*;
import java.util.*;

class Node {
    private String value;
    private HashMap<String, Node> children = new HashMap<String, Node>();

    public String getValue()
    {
        return this.value;
    }

    public HashMap getChildren()
    {
        return this.children;
    }

    public void setValue(String value)
    {
        this.value = value;
    }
}

class Trie {
    private Node root;

    public Trie(Node node)
    {
        this.root = node;
    }

    public Node getRoot() {
        return this.root;
    }
}

public class VisitedPaths
{
    public static void main(String[] args)
    {
        Node root = new Node();
        root.setValue("/");
        Trie trie = new Trie(root);

        Scanner sc = new Scanner(System.in);
        System.out.println("How many paths you have in mind ?");
        int n =sc.nextInt();
        while(--n >= 0) {
            String path = sc.next();
            String [] path_elements = path.split("/");

            HashMap<String, Node> children = root.getChildren();

            for(int i=1; i < path_elements.length; i++) {
                Node node = new Node();
                if(null == children.get(path_elements[i])) {
                    node.setValue(path_elements[i]);
                    children.put(path_elements[i], node);
                } else {
                    node = children.get(path_elements[i]);
                    children = node.getChildren();
                }
                children = node.getChildren();
            }
        }
        System.out.println("Created the trie for the paths");
        displayVisitedPaths(root, "");
    }

    public static void displayVisitedPaths(Node node, String tab)
    {
        HashMap<String, Node> children = node.getChildren();
        if (0 < children.size()) {
            System.out.println(tab+node.getValue());
            tab += "\t";
            for(Map.Entry<String, Node> entry : children.entrySet()) {
                System.out.println(tab + "/" + entry.getKey());
                displayVisitedPaths(entry.getValue(), tab);
            }
        }
    }
}