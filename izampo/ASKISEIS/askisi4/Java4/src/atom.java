/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Vassilis
 */
public class atom {

    protected atom[] array;
    final private String id;
    final private int counter;

    atom(String my_id, int my_counter) {
        id = my_id;
        counter = my_counter;
    }

    public void alcanium(atom[] arr, int position, int hydro_count, int size) {
        int count = 0;
        while ((arr[position].array[count] != null) && (count < 3)) {
            count++;
        }
        if (size == 1) {
            for (int i = 0; i < 4; i++) {
                arr[position].array[i] = new hydrogen(hydro_count);//new 
                hydro_count++;
                arr[position].array[i].array[0] = arr[position];
            }
        } else {
            arr[position].array[count] = arr[position + 1];
            arr[position + 1].array[0] = arr[position];
            for (int i = 0; i < 4; i++) {
                if (arr[position].array[i] == null) {
                    arr[position].array[i] = new hydrogen(hydro_count);//new
                    hydro_count++;
                    arr[position].array[i].array[0] = arr[position];
                }
            }
            for (int i = 0; i < 4; i++) {
                if (arr[position + 1].array[i] == null) {
                    arr[position + 1].array[i] = new hydrogen(hydro_count);//new
                    hydro_count++;
                    arr[position + 1].array[i].array[0] = arr[position + 1];
                }
            }
        }
    }

    public void alcenium(atom[] arr, int position, int start1, int hydro_count) {
        int count = 0;
        while ((arr[position].array[count] != null) && (count < 3)) {
            count++;
        }
        if (position == start1) { //diplos desmos
            arr[position].array[0] = arr[position + 1];
            arr[position].array[1] = arr[position + 1];
            arr[position + 1].array[0] = arr[position];
            arr[position + 1].array[1] = arr[position];
        } else {
            arr[position].array[count] = arr[position + 1];
            arr[position + 1].array[0] = arr[position];
        }
        for (int i = 0; i < 4; i++) {
            if (arr[position].array[i] == null) {
                arr[position].array[i] = new hydrogen(hydro_count);//new
                hydro_count++;
                arr[position].array[i].array[0] = arr[position];
            }
        }
        for (int i = 0; i < 4; i++) {
            if (arr[position + 1].array[i] == null) {
                arr[position + 1].array[i] = new hydrogen(hydro_count);//new
                hydro_count++;
                arr[position + 1].array[i].array[0] = arr[position + 1];
            }
        }
    }

    public void alcinium(atom[] arr, int position, int start1, int hydro_count) {
        int count = 0;
        while ((arr[position].array[count] != null) && (count < 3)) {
            count++;
        }
        if (position == start1) {
            arr[position].array[0] = arr[position + 1];
            arr[position].array[1] = arr[position + 1];
            arr[position].array[2] = arr[position + 1];
            arr[position + 1].array[0] = arr[position];
            arr[position + 1].array[1] = arr[position];
            arr[position + 1].array[2] = arr[position];
        } else {
            arr[position].array[count] = arr[position + 1];
            arr[position + 1].array[0] = arr[position];
        }
        for (int i = 0; i < 4; i++) {
            if (arr[position].array[i] == null) {
                arr[position].array[i] = new hydrogen(hydro_count);//new
                hydro_count++;
                arr[position].array[i].array[0] = arr[position];
            }
        }
        for (int i = 0; i < 4; i++) {
            if (arr[position + 1].array[i] == null) {
                arr[position + 1].array[i] = new hydrogen(hydro_count);//new
                hydro_count++;
                arr[position + 1].array[i].array[0] = arr[position + 1];
            }
        }
    }

    public void my_print(atom[] arr, int start, int w, int size) {
        if ((w != size) && (w != start)) {
            System.out.print(",");
        }
        System.out.print(arr[w].id + arr[w].counter + "(");
        if ((arr[w].array[0].counter == arr[w].array[2].counter) && (arr[w].array[0].id == arr[w].array[2].id)) {
            System.out.print("(triple)" + arr[w].array[0].id + arr[w].array[0].counter + "," + arr[w].array[3].id + arr[w].array[3].counter);
            System.out.print(")");
        } else if ((arr[w].array[0].counter == arr[w].array[1].counter) && (arr[w].array[0].id == arr[w].array[1].id)) {
            System.out.print("(double)" + arr[w].array[0].id + arr[w].array[0].counter + ",");
            System.out.print(arr[w].array[2].id + arr[w].array[2].counter + ", " + arr[w].array[3].id + arr[w].array[3].counter);
            System.out.print(")");
        } else {
            for (int i = 0; i < 4; i++) {
                System.out.print(arr[w].array[i].id + arr[w].array[i].counter);
                if (i != 3) {
                    System.out.print(",");
                }
            }
        }
        System.out.print(")");
    }
}
