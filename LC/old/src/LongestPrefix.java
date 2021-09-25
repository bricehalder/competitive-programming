public class LongestPrefix {
    public static String longestCommonPrefix(String[] strs) {
        String prefix = "";
        int pos = 0;
        boolean inAll;

        if (strs.length == 0) {
            return prefix;
        }

        for (char c : strs[0].toCharArray()) {
            inAll = true;
            for (String word : strs) {
                if (word.equals(strs[0])) { continue; }
                if (pos >= word.length() || word.charAt(pos) != c) {
                    inAll = false;
                }
            }
            if (inAll) {
                prefix += strs[0].charAt(pos);
                pos++;
            }
        }
        return prefix;
    }

    public static void main(String[] args) {
        String[] input = new String[]{"ca", "a"};
        System.out.println(longestCommonPrefix(input));
    }
}
