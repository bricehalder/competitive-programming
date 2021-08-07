import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Cousins {

    public static class Node {

        Node(int i) {
            num = i;
            children = new ArrayList<>();
        }

        Node(int i, Node parent) {
            num = i;
            children = new ArrayList<>();
            this.parent = parent;
        }

        int num;
        List<Node> children;
        Node parent;

        void add(int i) {
            children.add(new Node(i, this));
        }

        void add(Node n) {
            children.add(n);
        }

        int getLast() {
            return children.get(children.size() - 1).num;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "num=" + num;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n, k;
        int count;

        Node kNode;

        while (true) {
            n = in.nextInt();
            k = in.nextInt();

            if (n == 0 && k == 0) {
                break;
            }

            count = 0;

            Node root = new Node(in.nextInt());
            Node cur = root;
            kNode = cur;

            if (cur.num == k) {
                kNode = cur;
            }

            int first = in.nextInt();
            count++;

            int next = first;

            while (!(next > first + 1)) {
                Node child = new Node(next, cur);
                cur.add(child);
                if (next == k) {
                    kNode = child;
                }
                first = next;
                next = in.nextInt();
                count++;
            }

            while (count < n) {
                cur = getNextChild(root);
                first = next;
                while (!(next > first + 1)) {
                    if (count >= n) {
                        break;
                    }
                    Node child = new Node(next, cur);
                    cur.add(child);
                    if (next == k) {
                        kNode = child;
                    }
                    first = next;
                    next = in.nextInt();
                    count++;
                }
            }

//            System.out.println(kNode);

            Node parent = kNode.parent;
            if (parent == null || parent.parent == null) {
                System.out.println(0);
                continue;
            }

            Node grandparent = parent.parent;

            int sum = 0;
            for (Node child : grandparent.children) {
                if (child == kNode.parent) {
                    continue;
                }
                sum += child.children.size();
            }

            System.out.println(sum);
        }
    }

    public static Node getNextChild(Node n) {
        if (n.children.size() == 0) {
            return n;
        }

        Queue<Node> queue = new LinkedList<>();

        ((LinkedList<Node>) queue).addAll(n.children);

        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            ((LinkedList<Node>) queue).addAll(cur.children);
            if (cur.children.size() == 0) {
                return cur;
            }
        }
        return null;
    }
}
