
package datatraining;

import java.util.Scanner;

public class DataTraining {

    public static void main(String[] args) {
        int choice = 0;
        Proccess islem = new Proccess();
        Scanner in = new Scanner(System.in);
        Node root = null;
        String quit = "y";
        while(!quit.equals("q")){
            System.out.println("\n");
            System.out.println("1 - Sayi Ekle..."); 
            System.out.println("2 - Inorder Traversal...");
            System.out.println("3 - Sectiginiz sayinin yuksekligi nedir...");
            System.out.println("4 - Silme islemi...");
            System.out.println("5 - Guncelleme islemi...");
            System.out.println("6 - Bitirmek ister misiniz?");
            choice = in.nextInt();
            switch (choice) {
                case 1: 
                    System.out.println("Girmek istediginiz sayi nedir ?");
                    choice = in.nextInt();
                    islem.root = islem.added(islem.root, choice);
                    islem.inOrderOnce(islem.root, choice);
                    break;
                case 2:
                    System.out.println("Sayilar..."); 
                    islem.inOrder(islem.root);
                    break;
                case 3:
                    islem.inOrder(islem.root);
                    System.out.println("Sayiyi giriniz");
                    choice = in.nextInt();
                    islem.findHeight(islem.root, choice, 1);
                    break;
                case 4:
                    islem.inOrder(islem.root);
                    System.out.println("Hangi sayiyi silmek istiyorsunuz.");
                    choice = in.nextInt();
                    boolean ok = islem.isnIt(root, choice);
                    if(ok == false)
                        islem.root = islem.delete(islem.root, choice);
                    else
                        System.out.println("Boyle bir numara maalesef yok!");
                    break;
                case 5:
                    islem.inOrder(islem.root);
                    System.out.println("Hangi sayiyi guncellemek istiyorsunuz ? ");
                    choice = in.nextInt();
                    boolean thatsOk = islem.isnIt(root, choice);
                    if(thatsOk == false){
                        System.out.println("Hangi sayi ile guncelleyeceksiniz.");
                        int newData = in.nextInt();
                        thatsOk = islem.isnIt(root, newData);
                        if(thatsOk == false)
                            islem.root = islem.update(islem.root, choice, newData);
                        else
                            System.out.println("Boyle bir numara zaten var");
                    } 
                    else
                        System.out.println("Boyle bir numara maalesef yok!");
                    break;
                case 6:
                    System.out.println("Hayir (c) - Evet (q)");
                    quit = in.next();
            }
        }
        System.out.println("Program sonlandirildi...");
    }
    
}
