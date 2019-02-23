#include "main.h"



int main(int argc, const char * argv[]) {
    
    try {
    
        /*
        Stack<double> stack;
        Stack<double> j;
        
        stack.push(1.1);
        
        stack.push(2.2);
        
        stack.push(3.3);
        
        //cout << "top: " << stack.top() << endl;
        
        
        stack.printInternal();
        
        
        j=stack;
        
        //cout << "j stack " << endl;
        
        j.printInternal();
        
        cout << "stack size: " << stack.size() << endl;
        cout << "j size: " << j.size() << endl;
        
        cout << "s stack " << endl;
        Stack<double> s(stack);
        
        s.printInternal();
        
        
        stack.pop();
        cout << stack.size() << endl;
        //j.clear();
        //s.clear();
        
        //cout << stack.size() << endl;
        
        stack.printInternal();
        //j.printInternal();
        //s.printInternal();
     
        
        */
        
        
        Deque<double> deque;
        
        
        deque.insertBack(0);
        
        deque.insertBack(2.2);
        
        deque.insertFront(3.3);
        
        deque.printInternal();
        
        cout << "size: " << deque.size() << endl;
        
        cout << deque.front() << endl;
        cout << deque.back() << endl;
        
        deque.removeFront();
        deque.removeBack();
        deque.removeFront();
        

        
        
        cout << "size: " << deque.size() << endl;
        
      

        

        /*
        Deque<double> k(deque);
        
        
        cout << k.front() << endl;
        cout << k.back() << endl;
        
        cout << "k size: " << k.size() << endl;


        
        
       cout << "k size: " << k.size() << endl;
         
         */
         
        
        
        /*
        cout << "size: " << deque.size() << endl;
        deque.removeBack();
        deque.removeFront();
        deque.removeFront();
        
    
         
         */
        
        /*
        deque.removeBack();
        
        
        deque.removeBack();
       
        deque.removeBack();
         
        
        
        
        //deque.removeFront();
        

        
        deque.printInternal();
        
        
        deque.removeBack();
        deque.removeBack();
        deque.removeBack();
        
        cout << "size: " << deque.size() << endl;
        
        deque.insertFront(1.1);
        
        deque.insertFront(2.2);
        
        deque.insertFront(3.3);
        
        cout << "size: " << deque.size() << endl;
        
        deque.printInternal();
        
        deque.removeFront();
        deque.removeFront();
        deque.removeFront();
        
        
        
        
        //deque.removeFront();
        
        //deque.printInternal();
        
       cout << "size: " << deque.size() << endl;
         
         */

        
        
    }
    
    catch (NoSuchObject &nso0)
    {
        cout << "caught no_such_object in function main()\n";
        cout << nso0.what() << endl;
    }
    
    catch (bad_alloc& ba) {
        cout << "There is no memory available." << endl;

    }
    
    catch (...) {
        
        cout << "unknown exception caught in main" << endl;
        
    }

    return 0;
}
