using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace resize
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[3] {1, 2, 3};
            
            OurArray our = new OurArray();
            our.Resize<int>(ref arr, 5);
            
            Console.WriteLine(String.Join(", ", arr));
        
            int item  = our.GetAt<int>(arr, 2, sizeof(int));
            Console.WriteLine(item);
            Console.WriteLine( arr[1] );

        }
    }

    class OurArray{
        public void Resize<T>( ref T[] source, int newSize)
        {
            if(newSize <= 0) return;
            if(source == null) return;
            if(source.Length == newSize) return;

            T[] newArray = new T[newSize];
            Buffer.BlockCopy(source, 0, newArray, 0, Buffer.ByteLength(source));

            source = newArray;

        }

        public T GetAt<T>(T[] source, int index, int SizeOf)
        {
            if(index < 0) return default(T);
            ref byte zeroAdrr = ref MemoryMarshal.GetArrayDataReference((Array)source);

            ref byte indexRef = ref Unsafe.Add( ref zeroAdrr, index * SizeOf);

            ref T item = ref Unsafe.As<byte, T>(ref indexRef);
            return item;
        }

    }
}
