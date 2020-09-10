package Section3;

import java.util.Arrays;
import java.util.Random;
import java.util.concurrent.TimeUnit;

public class Prob01 {

    private static int MAX = 100000;
    private static long NANO = 1000000000;
    private static int[] dsel = new int[MAX];
    private static int[] rdsel = new int[MAX];
    private static int[]  dbub= new int[MAX];
    private static int[]  rdbub= new int[MAX];
    private static int[]  dins= new int[MAX];
    private static int[]  rdins= new int[MAX];
    private static int[]  dmrg= new int[MAX];
    private static int[]  drmrg= new int[MAX];
    private static int[]  dqik1= new int[MAX];
    private static int[]  rdqik1= new int[MAX];
    private static int[]  dqik2= new int[MAX];
    private static int[]  rdqik2= new int[MAX];
    private static int[]  dqik3= new int[MAX];
    private static int[]  rdqik3= new int[MAX];

    public static void main(String[] args) {
        String[] head = {"          ", "Random1000", "Reverse1000","Random10000", "Reverse10000","Random100000", "Reverse100000"};
        String[] type = {"", "selection", "bubble", "insertion", "quick1", "quick2", "quick3", "heap", "library"};
        int[][] table = new int[8][6];
        int[] size = {1000,10000,100000};
        long sel = 0, rsel = 0;
        long bub = 0, rbub = 0;

    //    for (int i=0; i<size.length;i++) {
           // int k = size[i] - 1;
        int k = 1000-1;
            for (int test = 0; test < 10; test++) {
                genrandon(1000);
                arrayClone();

                sel += selection(dsel);
                System.arraycopy(dsel, 0, rdsel, 0, dsel.length);
                arrayRvs(rdsel, k, 1000);
                rsel += selection(rdsel);

                bub += bubble(dbub);
                System.arraycopy(dbub, 0, rdbub, 0, dbub.length);
                arrayRvs(rdbub, k, 1000);
                rbub += bubble(rdbub);
            }
//        }
//        for (int i = 0; i < 7; i++)
//            System.out.print(head[i]+"  ");
//        for (int i=0; i<9; i++)
//            System.out.println(type[i]);


        System.out.println((sel/(NANO*10.0))+" "+sel);
        System.out.println(TimeUnit.NANOSECONDS.toMillis(rsel)/10000.0+" "+rsel);
        System.out.println(TimeUnit.NANOSECONDS.toMillis(bub)/10000.0+" "+bub);
        System.out.println(TimeUnit.NANOSECONDS.toMillis(rbub)/10000.0+" "+rbub);

    }

    private static void arrayClone() {
        System.arraycopy(dsel,0,dbub,0,dsel.length);
        System.arraycopy(dsel,0,dins,0,dsel.length);
        System.arraycopy(dsel,0,dmrg,0,dsel.length);
        System.arraycopy(dsel,0,dqik1,0,dsel.length);
        System.arraycopy(dsel,0,dqik2,0,dsel.length);
        System.arraycopy(dsel,0,dqik3,0,dsel.length);
    }

    private static void genrandon(int n) {
        Random r = new Random();
        for (int i = 0; i < n; i++)
            dsel[i] = r.nextInt(n) + 1;
    }

    private static void arrayRvs(int[] rdata, int k, int sz) {
        for (int i=0; i<sz/2; i++) {
            int tmp = rdata[i];
            rdata[i] = rdata[k];
            rdata[k--] = tmp;
        }
    }

    private static long bubble(int[] data) {
        long startTime = System.nanoTime();
        for (int i=data.length-1; i>0; i--) {
            for (int j=0; j<i; j++) {
                if (data[j]>data[j+1]) {
                    int tmp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = tmp;
                }
            }
        }
        long endTime = System.nanoTime();
        return endTime-startTime;
    }

    private static long selection(int[] data) {
        long startTime = System.nanoTime();
        for ( int i=data.length-1; i>0; i-- ) {
            int max = i;
            for ( int j=i-1; j>=0; j-- ) {
                if (data[j] > data[max]) max = j;
            }
            int tmp = data[i];
            data[i] = data[max];
            data[max] = tmp;
        }
        long endTime = System.nanoTime();
        return endTime-startTime;
    }
}
