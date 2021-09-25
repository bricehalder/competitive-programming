import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;


class Closest {

    /*
     * Complete the 'closest' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts following parameters:
     *  1. STRING s
     *  2. INTEGER_ARRAY queries
     */

    public static List<Integer> closest(String s, List<Integer> queries) {
        // Pseudocode:

        // Iterate through s once, putting each character into a hashmap, keeping track
        // of each index of the character -> O(S)

        // for each query -> O(N)
        //  if query > |s|
        //      add -1 to return array
        //  else if character only has one index
        //      add -1 to return array
        //  else
        //      add closest index using iterative binary search -> O(lg S)
        // return closest array

        // Time: O(N lg S + S) where N = |queries| and S = |s|
        // Space: O(S)

        Map<Character, List<Integer>> charIdx = new HashMap<>();
        List<Integer> toReturn = new LinkedList<>(); // Want linked list here to avoid resizing

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (charIdx.get(c) == null) {
                charIdx.put(c, new ArrayList<Integer>()); // Want arraylist here for binary search
            }

            charIdx.get(c).add(i);
        }

        for (int query : queries) {
            List<Integer> charIdxList = charIdx.get(s.charAt(query));
            if (charIdxList == null || charIdxList.size() == 1) {
                // need to check charIdxList == null first so we don't get null ptr exception
                toReturn.add(-1);
            } else {
                toReturn.add(binarySearch(charIdxList, query)); // binary search, must be iterative to avoid stack overflow
            }
        }

        return toReturn;
    }

    /**
     * Uses stable iterative binary search to find closest index to queried index.
     * Assumes that query passed is guaranteed to exist in index list.
     * Needs to be stable to return lower of two equidistant indices.
     * Must be iterative in order to not run into a potential stack overflow error with recursion.
     *
     * @param idxList the list of indices to search
     * @param query   the index of the query
     * @return the closest index to the query
     */
    private static int binarySearch(List<Integer> idxList, int query) {
        int queryIdx = idxList.indexOf(query); // index of query in character's index list
        idxList.remove(queryIdx); // remove the query from the list

        if (idxList.size() == 1) {
            int toReturn = idxList.get(0);
            idxList.add(queryIdx, query);
            return toReturn;
        }

        int lo = 0;
        int hi = idxList.size() - 1;
        int mid;

        while (lo < hi) {
            mid = (hi - lo) / 2;

            if (Math.abs(query - idxList.get(mid)) == Math.abs(query - idxList.get(mid + 1))) {
                hi = mid - 1;
                continue;
            }

            if (query < idxList.get(mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // Check if hi is -1
        if (hi == -1) {
            int toReturn = idxList.get(0);
            idxList.add(queryIdx, query); // insert query back into index list
            return toReturn;
        }

        int closest;
        // lo >= hi at this point
        if (Math.abs(query - idxList.get(lo)) < Math.abs(query - idxList.get(hi))) {
            closest = idxList.get(lo);
        } else {
            closest = idxList.get(hi);
        }

        idxList.add(queryIdx, query); // insert query back into index list

        return closest;
    }

    public static void main(String[] args) {
        List<Integer> soln = closest("aaaa", Arrays.asList(0, 1, 2, 3));
        for (int i : soln) {
            System.out.println(i);
        }
    }
}