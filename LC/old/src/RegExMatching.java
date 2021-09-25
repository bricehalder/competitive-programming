public class RegExMatching {
    public static boolean isMatch(String s, String p) {
        int pPos = 0;
        int sPos = 0;
        char curChar;

        while (pPos < p.length()) {
            curChar = p.charAt(pPos);

            if (curChar == '*') {
                pPos++;
                continue;
            }

            if (pPos < p.length() - 1) {
                if (p.charAt(pPos + 1) == '*') {
                    if (curChar == '.') {
                        curChar = s.charAt(sPos);
                    }
                    while (sPos < s.length() && matches(s.charAt(sPos), curChar)) {
                        sPos++;
                    }
                    pPos += 2; // 1 for the character, 1 for the '*'
                    continue;
                }
            }

            /* check char at sPos matches char at pPos */
            if (!matches(curChar, s.charAt(sPos))) {
                return false;
            }

            pPos++;
            sPos++;
        }

        if (sPos < s.length()) {
            return false;
        }

        return true;
    }

    private static boolean matches(char sChar, char pChar) {
        if (pChar == '.') {
            return true;
        }

        return pChar == sChar;
    }

    public static void main(String[] args) {
        String s = "ab";
        String p = ".*c";

        System.out.println(isMatch(s, p));
        System.out.println("Expected: false");
    }
}
