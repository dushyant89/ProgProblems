import java.util.*;
import java.io.*;

class Node
{
    private char value;
    private boolean isVisited;

    public void setValue(char value)
    {
        this.value = value;
    }

    public char getValue()
    {
        return this.value;
    }

    public boolean isVisited()
    {
        return this.isVisited;
    }

    public void setIsVisited(boolean isVisited)
    {
        this.isVisited = isVisited;
    }
}

class AdjacencyList
{
    private ArrayList<Node> edges = new ArrayList<Node>();

    public ArrayList<Node> getEdges()
    {
        return this.edges;
    }
}

class Graph
{
    private HashMap<Node, AdjacencyList> graph = new HashMap<Node, AdjacencyList>();

    public HashMap<Node, AdjacencyList> getGraph()
    {
        return this.graph;
    }
}

public class BreadthFirstSearch
{
    public static void main(String[] args)
    {
        // Creating a graph
        Graph connections = new Graph();
        HashMap<Node, AdjacencyList> graph  = connections.getGraph();

        // Creating nodes
        Node node_a = new Node();
        node_a.setValue('A');

        Node node_b = new Node();
        node_b.setValue('B');

        Node node_c = new Node();
        node_c.setValue('C');

        Node node_d = new Node();
        node_d.setValue('D');

        Node node_e = new Node();
        node_e.setValue('E');

        // Creating Adjancency Lists
        AdjacencyList node_a_list = new AdjacencyList();
        AdjacencyList node_b_list = new AdjacencyList();
        AdjacencyList node_c_list = new AdjacencyList();
        AdjacencyList node_d_list = new AdjacencyList();
        AdjacencyList node_e_list = new AdjacencyList();

        // Adding nodes to the list
        node_a_list.getEdges().add(node_b);
        node_a_list.getEdges().add(node_c);

        node_b_list.getEdges().add(node_d);

        node_c_list.getEdges().add(node_d);
        node_c_list.getEdges().add(node_e);

        node_d_list.getEdges().add(node_a);

        node_e_list.getEdges().add(node_d);

        // Mapping the lists to the nodes
        graph.put(node_a, node_a_list);
        graph.put(node_b, node_b_list);
        graph.put(node_c, node_c_list);
        graph.put(node_d, node_d_list);
        graph.put(node_e, node_e_list);

        performSearch(graph, node_b);
    }

    public static void performSearch(HashMap<Node, AdjacencyList> graph, Node start)
    {
        LinkedList<Node> queue = new LinkedList<Node>();
        queue.add(start);

        while(queue.size() > 0) {
            Node node = queue.remove();
            if (!node.isVisited()) {
                System.out.print(node.getValue()+"->");
                node.setIsVisited(true);

                ArrayList<Node> edges = graph.get(node).getEdges();
                for (Node next : edges) {
                    queue.addLast(next);
                }
            }
        }
    }
}