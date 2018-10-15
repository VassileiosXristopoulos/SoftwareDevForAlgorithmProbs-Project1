/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Vassilis
 */
public class carbon extends atom {


    carbon(int i) {
        super("c", i);
        array=new atom[4];
        for(int j=0;j<4;j++){
            array[j]=null;
        }
    }


}
