package array_basic;
import java.io.*;
class M{
 void method(){
  throw new IOException("device error");
 }
}


public class Array_1{
   public static void main(String args[]){
   
          M m=new M();
          m.method();

    

    System.out.println("normal flow...");
  }
}
