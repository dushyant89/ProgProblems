/*
Given an unlimited stream of characters, that can only be read one character at a time,
using a specific function (e.g. getChar()), and a list of patterns (e.g. "cat", "dog", "man"),
write an algorithm to find all the occurrences of the patterns in the stream.
*/

import java.util.*;
import java.io.*;

class Node {
    public char value;
    public HashMap<Character, Node> children = new HashMap<Character, Node>();
    public boolean isWord;
}

class Trie {
    public Node root;
}

public class FindPattern
{
    public static void main (String[] args) throws Exception
    {
        Scanner sc = new Scanner(new File("randomStrings.txt"));
        int no_of_patterns = 6;
        Trie trie = new Trie();
        Node root = new Node();
        trie.root = root;
        for(int i=0; i < no_of_patterns; i++) {
            String pattern = sc.next();
            Node currentNode = root;
            for(int j=0; j < pattern.length(); j++) {
                if (null == currentNode.children.get(pattern.charAt(j))) {
                    Node newNode = new Node();
                    newNode.value = pattern.charAt(j);
                    currentNode.children.put(pattern.charAt(j), newNode);
                    currentNode = newNode;
                } else {
                    currentNode = currentNode.children.get(pattern.charAt(j));
                }
            }
            currentNode.isWord = true;
        }

        char [] input = sc.next().toCharArray();
        Node currentNode = root;
        String str = "";
        for(int i=0; i < input.length; i++) {
            if (null != currentNode.children.get(input[i])) {
                Node child = currentNode.children.get(input[i]);
                int j = i;
                while(null != child) {
                    str += input[j++];
                    if (child.isWord) {
                        System.out.println(str);
                        break;
                    }
                    if (j < input.length) {
                        child = child.children.get(input[j]);
                    } else {
                        break;
                    }
                }
            }
            str = "";
        }
    }
}