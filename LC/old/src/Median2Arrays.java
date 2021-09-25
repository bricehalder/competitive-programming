import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Median2Arrays {

    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int total = nums1.length + nums2.length;

        if (total % 2 == 1) {
            return findKth(nums1, 0, nums2, 0, (total / 2) + 1);
        } else {
            return (findKth(nums1, 0, nums2, 0, total / 2 + 1) + findKth(nums1, 0, nums2, 0, total / 2)) / 2.0;
        }
    }

    private static int findKth(int[] nums1, int start1, int[] nums2, int start2, int k) {
        if (start1 >= nums1.length) {
            return nums2[start2 + k - 1];
        }

        if (start2 >= nums2.length) {
            return nums1[start1 + k - 1];
        }

        if (k == 1) {
            return Math.min(nums1[start1], nums2[start2]);
        }

        int index1 = start1 + k / 2 - 1;
        int index2 = start2 + k / 2 - 1;

        int key1 = index1 < nums1.length ? nums1[index1] : Integer.MAX_VALUE;
        int key2 = index2 < nums2.length ? nums2[index2] : Integer.MAX_VALUE;

        if (key1 < key2) {
            return findKth(nums1, index1 + 1, nums2, start2, k - k / 2);
        } else {
            return findKth(nums1, start1, nums2, index2  + 1, k - k / 2);
        }
    }

    public static void main(String[] args) {
        Scanner in = null;
        try {
            in = new Scanner(new File("median2arrays.in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        int n = in.nextInt();
        int m = in.nextInt();

        int[] a = new int[n];
        int[] b = new int[m];

        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

        for (int i = 0; i < m; i++) {
            b[i] = in.nextInt();
        }

        System.out.println(Arrays.toString(a) + "\n" + Arrays.toString(b));
        System.out.println(findMedianSortedArrays(a, b));
    }
}
