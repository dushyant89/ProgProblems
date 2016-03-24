import java.util.*;
import java.io.*;

class Node {
    public int value;
    public Node leftChild;
    public Node rightChild;
}

public class BST {
    public Node rootNode;

    public static void main(String []args) throws Exception {
        System.out.println("Lets create some binary search tree");
        Scanner sc = new Scanner(System.in);
        BST tree = new BST();
        while(sc.hasNextInt()) {
            Node newNode = new Node();
            newNode.value = sc.nextInt();

            if (newNode.value < 0) break;

            if (null == tree.rootNode) {
                tree.rootNode = newNode;
            }
            else {
                Node currentNode = tree.rootNode;
                Node parentNode = null;
                boolean leftChild = false;
                while(null != currentNode) {
                    parentNode = currentNode;
                    if(newNode.value > currentNode.value) {
                        currentNode = currentNode.rightChild;
                        leftChild = false;
                    } else {
                        currentNode = currentNode.leftChild;
                        leftChild = true;
                    }
                }
                if(leftChild) {
                    parentNode.leftChild = newNode;
                } else {
                    parentNode.rightChild = newNode;
                }
            }
        }
        tree.traverse(tree.rootNode);
        System.out.println();
        System.out.println("Lets do some deletion from BST, enter the value you want to delete");
        int value = sc.nextInt();
        if(tree.hasNode(value)) {
            tree.deleteNode(value);
        } else {
            System.out.println("Cannot delete as value doesn't exist in the BST");
        }
        tree.traverse(tree.rootNode);
    }

    public void deleteNode(int value) {
        Node currentNode = this.rootNode;
        while(currentNode.value != value) {
            if(currentNode.value < value) {
                currentNode = currentNode.rightChild;
            } else if(currentNode.value > value){
                currentNode = currentNode.leftChild;
            }
        }
        Node inorderSuccessor = findInorderSuccessor(currentNode);
        while(null != inorderSuccessor.rightChild) {
            currentNode.value = inorderSuccessor.value;
            currentNode = inorderSuccessor;
            inorderSuccessor = findInorderSuccessor(currentNode);
        }
        currentNode.value = inorderSuccessor.value;
    }

    public Node findInorderSuccessor(Node node) {
        Node currentNode = node.rightChild;
        while (null != currentNode.leftChild) {
            currentNode = currentNode.leftChild;
        }
        return currentNode;
    }

    public boolean hasNode(int value) {
        Node currentNode = this.rootNode;
        while(currentNode != null) {
            if(currentNode.value == value) {
                return true;
            } else if(currentNode.value < value) {
                currentNode = currentNode.rightChild;
            } else {
                currentNode = currentNode.leftChild;
            }
        }
        return false;
    }

    public void traverse(Node node) {
        if (null != node) {
            this.traverse(node.leftChild);
            System.out.print(node.value + " ");
            this.traverse(node.rightChild);
        }
    }
}