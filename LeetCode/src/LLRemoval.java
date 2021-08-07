public class LLRemoval {

    public static String printList(ListNode a) {
        StringBuilder s = new StringBuilder(a.val + " ---> ");
        ListNode n = a.next;
        while (n != null) {
            s.append(n.val).append(" ---> ");
            n = n.next;
        }
        return s.toString();
    }
    public static ListNode deleteDuplicates(ListNode a) {
        if (a == null) {
            return null;
        }

        ListNode cur = a;
        ListNode next = a.next;

        while (cur != null) {
            while (next != null && next.equals(cur)) {
                next = next.next;
            }

            // next is different or null at this point

            cur.next = next;
            cur = cur.next;

            if (next != null) {
                next = cur.next;
            }
        }

        return a;
    }

    public static void main(String[] args) {
        ListNode a = new ListNode(1);
        a.add(1);
        a.add(2);
        a.add(new int[]{2, 3, 3, 5, 5});

        System.out.println(printList(a));

        deleteDuplicates(a);

        System.out.println(printList(a));
    }
}
