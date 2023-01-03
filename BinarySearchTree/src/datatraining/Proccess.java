
package datatraining;

public class Proccess {
    Node root;
    public Proccess() {
        root = null;
    }
    
    public Node newNode(int key){
        root = new Node(key);
        inOrderOnce(root, key);
        return root;
    } 
    
    
    public boolean isnIt(Node root,int key){
        if(root != null && root.data != key){
            if(root.data < key){
                isnIt(root.right, key);
            }
            else if(root.data > key){
                isnIt(root.left, key);
            }
        }
        else if(root != null){
            return true;
        }
        return false;
    }
    
    
    public Node update(Node root, int key, int newNumber){
        if(root.data == key){
            if(root.right != null && root.left == null){
                if(root.right.data > newNumber){
                    System.out.println("Numara degistirildi, ihlalde bulunmadi.");
                    root.data = newNumber;
                }
                else{
                    System.out.println("Numara ihlalde bulundu.");
                }
            }
            else if(root.left != null && root.right == null){
                if(root.left.data < newNumber){
                    System.out.println("Numara degistirildi, ihlalde bulunmadi.");
                    root.data = newNumber;
                }
                else{
                    System.out.println("Numara ihlalde bulundu.");
                }
            }
            else if(root.left != null && root.right != null){
                if(root.left.data < newNumber && root.right.data > newNumber){
                    System.out.println("Numara degistirildi, ihlalde bulunmadi.");
                    root.data = newNumber;
                }
                else{
                    System.out.println("Numara ihlalde bulundu.");
                }
            }
            else{
                System.out.println("Numara degistirildi, ihlalde bulunmadi.");
                    root.data = newNumber;
            }
        }
        else if(root.data < key){
            if(root.data < newNumber)
                update(root.right, key, newNumber);
            else
                System.out.println("Numara ihlalde bulundu.");
        }
        else if(root.data > key){
            if(root.data > newNumber)
                update(root.left, key, newNumber);
            else
                System.out.println("Numara ihlalde bulundu.");
        }
        return root;
    }
    
    
    public Node delete(Node root, int key){
        if(root == null){
            return null;
        }
        Node iter1, iter2;
        if(root.data == key){
            if(root.left == root.right){
                root = null;
                return null;
            }
            else if(root.left == null){
                iter1 = root.right;
                return iter1;
            }
            else if(root.right == null){
                iter1 = root.left;
                return iter1;
            }
            else{
                iter1 = iter2 = root.right;
                while(iter1.left != null){
                    iter1 = iter1.left;
                }
                iter1.left = root.left;
                return iter2; 
            }
        }
        else{
            if(root.data < key){
                root.right = delete(root.right, key);
            }
            else{
                root.left = delete(root.left, key);
            }
        }
        return root;
    }
    
    
    public Node added(Node root, int key){
       if(root != null && key != root.data){
           if(key < root.data)
               root.left = added(root.left, key);
           else
               root.right = added(root.right, key);
       }
       else if(root != null){
           System.out.println("Aynı numara var!!!(Ekleme yapılamaz...)");
       }
       else
           root = newNode(key);
       return root;
    }
    
    
    public int findHeight(Node root, int key, int height){
        if(root != null){
            if(root.data == key)
            System.out.println("Bu sayinin yuksekligi = " + height);
            else if(root.data < key)
                findHeight(root.right, key, height + 1);
            else
                findHeight(root.left, key, height + 1);
        }
        else{
            System.out.println("Maalesef boyle bir eleman yok");
        }
        return height;
    }
    
    
    public Node inOrderOnce(Node root, int key){
        if(root.data > key){
            if(root.left != null){
                if(root.left.left != null && root.left.left.data == key){
                    System.out.println("Eklenen dugumun ebeveyn ve kardesleri");
                    inOrder(root.left);
                }
                else if(root.left.right != null && root.left.right.data == key){
                    System.out.println("Eklenen dugumun ebeveyn ve kardesleri");
                    inOrder(root.left);
                }
                else if(root.left.data == key){
                    System.out.println("Eklenen dugumun ebeveyn ve kardesleri");
                    inOrder(root);
                }
                else{
                    inOrderOnce(root.left, key);
                }
            }
            else{
                inOrderOnce(root.left, key);
            }
        }
        else if(root.data < key){
            if(root.right != null){
                if(root.right.left != null && root.right.left.data == key){
                System.out.println("Eklenen dugumun ebeveyn ve kardesleri");
                inOrder(root.right);
                }
                else if(root.right.right != null && root.right.right.data == key){
                    System.out.println("Eklenen dugumun ebeveyn ve kardesleri");
                    inOrder(root.right);
                }
                else if(root.right.data == key){
                    System.out.println("Eklenen dugumun ebeveyn ve kardesleri");
                    inOrder(root);
                }
                else{
                    inOrderOnce(root.right, key);
                }
            }
            else{
                inOrder(root);
            }
        }
        else{
            System.out.println("Eklenen dugumun ebeveyn ve kardesleri");
            inOrder(root);
        }
        return root;
    }
    
    public void inOrder2(Node root, int x){
        if(x < 1){
            if(root != null){
                inOrder2(root.left, x - 1);
                System.out.println(root.data + " ");
                inOrder2(root.right, x - 1);
            }
        }
    }
    
    public void inOrder(Node root){
        if(root != null){
            inOrder(root.left);
            System.out.print(root.data + " ");
            inOrder(root.right);
        }
    }
    
}
