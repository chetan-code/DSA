using System;
/// <summary>
/// Implementation of static fixed size stack
/// </summary>
public class Stack
{
    private const int MaxSize = 100;
    private int[] data;
    private int top;

    public Stack() {
        data = new int[MaxSize];
        top = -1;
    }

    public void Push(int value){
        if( top + 1 >= MaxSize ){
            System.Console.WriteLine("Stack overflow");
            return;
        }
        top++;
        data[top] = value;
    }

    public int Pop(){
        if(top == -1){
            System.Console.WriteLine("Stack underflow");
            return -1;            
        }
        int value = data[top];
        top--;
        return value;
    }

    public int Peek(){
        if( top == -1){
            System.Console.WriteLine("Stack is empty");
            return -1;
        }
        return data[top];
    }

    public void Print(){
        for(int i = 0; i <= top; i++){
            System.Console.WriteLine(data[i]);
        }
    }
}


public class MainWorld
{
    public static void Main(string[] args)
    {
        Stack stack  = new Stack();
        stack.Push(10);
        stack.Push(20);
        stack.Push(30);
        stack.Print();
        stack.Pop();
        stack.Print();
        System.Console.WriteLine(stack.Peek());

    }

}
