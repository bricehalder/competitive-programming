import java.util.Objects;

public class ListNode {
    int val;

    ListNode next;

    ListNode(int x) { val = x; next = null; }

    void add(int x) {
        if (next == null) {
            next = new ListNode(x);
            return;
        }

        ListNode n = next;
        while (n.next != null) {
            n = n.next;
        }
        n.next = new ListNode(x);
    }

    void add(int[] arr) {

        ListNode n = next;
        while (n.next != null) {
            n = n.next;
        }

        for (int i : arr) {
            n.next = new ListNode(i);
            n = n.next;
        }
    }

    @Override
    public String toString() {
        return "" + val;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ListNode listNode = (ListNode) o;
        return val == listNode.val;
    }

    @Override
    public int hashCode() {

        return Objects.hash(val);
    }
}
