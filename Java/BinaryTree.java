import java.util.*;
import java.io.*;
import java.lang.Math;

class Node
{
    private char value;
    private Node left;
    private Node right;

    public Node (char value, Node left, Node right)
    {
        this.value = value;
        this.left = left;
        this.right = right;
    }

    public char getValue()
    {
        return this.value;
    }

    public void setValue(char value)
    {
        this.value = value;
    }

    public Node getLeft()
    {
        return this.left;
    }

    public void setLeft(Node left)
    {
        this.left = left;
    }

    public Node getRight()
    {
        return this.right;
    }

    public void setRight(Node right)
    {
        this.right = right;
    }
}

public class BinaryTree
{
    public Node root;

    public Node getRoot()
    {
        return this.root;
    }

    public static void main(String[] args)
    {
        // Creating a binary tree here
        BinaryTree tree = new BinaryTree();;

        // Creating the input mechanism
        Scanner sc = new Scanner(System.in);

        Node node_h = new Node('H', null, null);
        Node node_d = new Node('D', node_h, null);
        Node node_e = new Node('E', null, null);
        Node node_b = new Node('B', node_d, node_e);
        Node node_f = new Node('F', null, null);
        Node node_g = new Node('G', null, null);
        Node node_c = new Node('C', node_f, node_g);
        Node node_a = new Node('A', node_b, node_c);

        tree.root = node_a;

        //Traverse the tree
        System.out.print("Traversal : ");
        tree.traverse(tree.root);
        System.out.println();

        //Calculate the height of the tree
        System.out.println("Height : " + tree.getHeight(tree.root));

        //Calculate the no. of leaf nodes
        System.out.println("No. of leaves : " + tree.getLeafCount(tree.root));

        // Check if the tree is balanced
        if (1 < tree.getBalanceFactor(tree.root)) {
            System.out.println("Tree is not balanced");
        } else {
            System.out.println("Tree is balanced");
        }

        // Lets swap the siblings
        tree.mirrorImage(tree.root);
        // Traverse the tree after swapping
        System.out.print("Traversal of mirror imageL: ");
        tree.traverse(tree.root);
        System.out.println();
    }

    public void traverse(Node node)
    {
        if (null != node) {
            traverse(node.getLeft());
            System.out.print(node.getValue()+"->");
            traverse(node.getRight());
        }
    }

    public int getHeight(Node node)
    {
        if (null != node.getLeft() && null != node.getRight()) {
            return 1 + Math.max(getHeight(node.getLeft()), getHeight(node.getRight()));
        } else if (null != node.getLeft()) {
            return 1 + getHeight(node.getLeft());
        } else if (null != node.getRight()) {
            return 1 + getHeight(node.getRight());
        }

        return 0;
    }

    public int getLeafCount(Node node)
    {
        if (null != node.getRight() && null != node.getLeft()) {
            return getLeafCount(node.getRight()) + getLeafCount(node.getLeft());
        } else if (null != node.getRight()) {
            return getLeafCount(node.getRight());
        } else if (null != node.getLeft()) {
            return getLeafCount(node.getLeft());
        }

        return 1;
    }

    public int getBalanceFactor(Node node)
    {
        int height_l = 0;
        int height_r = 0;

        if (null != node.getLeft()) {
            height_l = 1 + getBalanceFactor(node.getLeft());
        }
        if (null != node.getRight()) {
            height_r = 1 + getBalanceFactor(node.getRight());
        }

        return Math.abs(height_l - height_r);
    }

    public void mirrorImage(Node node)
    {
        if (null != node.getLeft() || null != node.getRight()) {
            if (null != node.getLeft()) {
                mirrorImage(node.getLeft());
            }
            if (null != node.getRight()) {
                mirrorImage(node.getRight());
            }
            // swap both the siblings
            Node temp = node.getRight();
            node.setRight(node.getLeft());
            node.setLeft(temp);
        }
    }
}