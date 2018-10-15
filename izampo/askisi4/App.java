/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Vassilis
 */
import java.util.Random;
public class App {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int size;
        for (int k = 0; k < 10; k++) {
            Random rand = new Random();
            int N=(rand.nextInt(20) + 1);
            //int N = 20 + (int) Math.random();
            atom[] my_array;
            my_array = new atom[N];
            for (int i = 0; i < N; i++) {
                my_array[i] = new carbon(i + 1);
            }
            int hydrogens = 1;
            int start = 0;
            while (start < N) {
                int found = 0;
                int v = (rand.nextInt(3) + 1);
                size = (rand.nextInt(N-start) + 1);
               // System.out.print(size);
                if (v == 1) {
                    if (size == 1) {
                        found = 1;
                        System.out.print("comp([");
                        for (int i = start; i < (start + size); i++) {
                            my_array[i].alcanium(my_array, i, hydrogens, size);
                        }
                    } else if (size > 1) {
                        found = 1;
                        System.out.print("comp([");
                        for (int i = start; i < (start + size - 1); i++) {
                            my_array[i].alcanium(my_array, i, hydrogens, size);
                        }
                    }
                    if (size > 0) {
                        found = 1;
                        for (int j = start; j < (start + size); j++) {
                            my_array[j].my_print(my_array, start, j, size);
                        }
                        System.out.println("])");
                    }
                    hydrogens += 2 * size + 2;
                } else if ((v == 2) && (size >= 2) && ((N - start) >= 2)) {
                    found = 1;
                    System.out.print("comp([");
                    for (int i = start; i < (start + size - 1); i++) {
                        my_array[i].alcenium(my_array, i, start, hydrogens);
                    }
                    for (int j = start; j < (start + size); j++) {
                        my_array[j].my_print(my_array, start, j, size);
                    }
                    System.out.println("])");
                    hydrogens += 2 * size;
                } else if ((v == 3) && (size >= 2) && ((N - start) >= 2)) {
                    found = 1;
                    System.out.print("comp([");
                    for (int i = start; i < (start + size - 1); i++) {
                        my_array[i].alcinium(my_array, i, start, hydrogens);
                    }
                    for (int j = start; j < (start + size); j++) {
                        my_array[j].my_print(my_array, start, j, size);

                    }
                    System.out.println("])");
                    hydrogens += size * 2 - 2;
                }
                if (found == 1) {
                    start += size;
                }
            }
        }
    }

}
