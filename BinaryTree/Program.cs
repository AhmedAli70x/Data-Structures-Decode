using System;
using metwally;

class Program
{
    public static void Main(string[] args)
    {
        // BinaryTree<char> tree = new BinaryTree<char>();
        // tree.Insert('A');
        // tree.Insert('B');
        // tree.Insert('C');
        // tree.Insert('D');
        // tree.Insert('E');
        // tree.Insert('F');
        // tree.Insert('G');
        // tree.Insert('H');
        // tree.Insert('I');
        // // tree.Print();

        // Console.WriteLine("Height: " + tree.Height());
        // tree.PreOrder();
        // tree.InOrder();
        // tree.PostOrder();
        BinaryTree<int> tree = new BinaryTree<int>();
        tree.BSInsert(1);
        tree.BSInsert(2);
        tree.BSInsert(3);
        tree.BSInsert(4);
        tree.BSInsert(5);
        tree.BSInsert(6);
        // tree.BSInsert(7);

        // Console.Write(tree.IsExist(10)) ;
 

        // Console.WriteLine("Height: " + tree.Height());
        // tree.PreOrder();
        
        // tree.PostOrder();

    //     tree.BsDelete(4);
    //     tree.PreOrder();

        // tree.BsDelete(5);
    //   tree.Print();
            tree.PreOrder();

      
            tree.Balance();
            tree.Print();

    }
}