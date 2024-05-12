// Online C# Editor for free
// Write, Edit and Run your C# code using C# Online Compiler

using System;
 

public class MyCode
{   public class Dictionary<Tkey, Tvalue> where Tkey:class{
    
    keyValuePair[] entries;
    int initialSize;
    int entriesCount;
    
    public Dictionary(){
        this.initialSize = 3 ;
        this.entries = new keyValuePair[this.initialSize];
    }
    
    public void ResizeOrNot(){
        
        if (this.entriesCount < this.entries.Length -1 )
        {
            return;
        }
        
        int newSize = this.entries.Length + this.initialSize;
        Console.WriteLine("[Resize ] from " + this.entries.Length + " to " + newSize);
 
        keyValuePair[] newArray = new keyValuePair[newSize];
        Array.Copy(this.entries, newArray, this.entries.Length);
        this.entries = newArray;
        
    }
    
    public int Size(){
        return this.entriesCount;
    }
    
    public void Set(Tkey key, Tvalue value){
        
        for(int i = 0 ; i<this.entries.Length; i++){
            if(this.entries[i] != null && this.entries[i].Key == key){
                this.entries[i].Value = value;
                return;
            }
        }
        this.ResizeOrNot();
        keyValuePair newPair = new keyValuePair(key, value);
        this.entries[this.entriesCount] = newPair;
        this.entriesCount ++;
    }
    
    public Tvalue Get(Tkey key){
        for(int i = 0 ; i<this.entries.Length; i++){
             if(this.entries[i] != null && this.entries[i].Key == key){
                return this.entries[i].Value ;
            }
        }
        return default(Tvalue);
        
    }
     
    public Boolean Remove(Tkey key){
        for(int i = 0 ; i<this.entries.Length; i++){
             if(this.entries[i] != null && this.entries[i].Key == key){
                this.entries[i] = this.entries[this.entriesCount-1];
                this.entries[this.entriesCount-1] = null;
                this.entriesCount --;
                return true;
            }
        }
        
        return false;
    }
    
    public void Print(){
        Console.WriteLine("----------");
        Console.WriteLine("[size] " + this.Size());
        
        for(int i = 0; i<this.entries.Length; i++){
             if(this.entries[i] != null){
                 Console.WriteLine(this.entries[i].Key +":"+ this.entries[i].Value);
             }
        }
        Console.WriteLine("----------");
    }
    
    class keyValuePair{
        
        Tkey _key;
        Tvalue _value;
        
        public Tkey Key{
            get{return _key;}
        }
        
        public Tvalue Value{
            get {return _value;}
            set {_value = value;}
        }
        
        public keyValuePair(Tkey key, Tvalue val){
            
            _key = key;
            _value = val;
            
        }
    }
       
       
   }
  
  
  public static void Main(string[] args)
    {
        Dictionary< string, string> dic = new Dictionary<string, string>();
        dic.Print();
        
         dic.Set("Sinar", "sinar@gmail.com");
        dic.Set("Elvis", "elvis@gmail.com");
        dic.Print();
        
        dic.Set("Tane", "tane@gmail.com");
        dic.Set("Gerti", "gerti@gmail.com");
        dic.Set("Arist", "arist@gmail.com");
        dic.Print();
        
        // dic.Set("rArist", "rarist@gmail.com");
        // dic.Set("tArist", "tarist@gmail.com");
        // dic.Set("yArist", "yarist@gmail.com");
        // dic.Print();
        
        
        Console.WriteLine(dic.Get("Tane"));
        Console.WriteLine(dic.Get("Sinar"));
        Console.WriteLine(dic.Get("Elviaaa"));
        
        
        dic.Remove("Sinar");
        dic.Remove("Elvis");
        dic.Remove("Tane");
        dic.Remove("Gerti");
        dic.Remove("Arist");
        dic.Print();
        dic.Set("Sinar", "sinar@gmail.com");
        dic.Print();
    }
}

 