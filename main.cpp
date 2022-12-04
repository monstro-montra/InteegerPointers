#include <iostream>
//Program: Create a C++ program that asks the user to enter three integer values as input.  Store the values into three different variables.
//For each variable, create an integer pointer to dynamic memory. Display the contents of the variables and pointers.  In your program, be sure
// to use the new operator and delete operators to management memory.
using namespace std;

struct intArray{ //declare structure called intArray (public by default)
    int arr[3];

    //struct methods
    static intArray getInputs() { //declare function for intArray structure
        intArray intArray_member{}; //declare a member of the structure to be able to access arr from intArray
        for (int i = 0; i < 3; i++){ //loop with i at starting value of 0 as long as i < arr.size, and add one at the end of each loop.
            cout << "Input integer #" << i << ":"; //ask user to input an integer
            cin >> intArray_member.arr[i]; //get user input and add it to arr for initialization.
        }
        return intArray_member;
    }

    static void getAddresses(){
        intArray intArray_member{};//declare a member of the structure to be able to access arr from intArray
        int * p_Input = new int[3]; //dynamically declare an array of int pointers. these will hold the addresses of another variable.
        for(int i = 0; i < 3; i++){ //loop until i < 3 is no longer true.
            p_Input[i] = intArray_member.arr[i]; //set p_Input[i] = to arr[i]
            cout << "Element " << i << " address: " << p_Input << endl; //print the address of arr[i], which p_Input[i] holds.
            p_Input += 1; //go to the next pointer.
        }
        delete [] p_Input; //delete the p_Input array to free memory.
    }

    static void printArray(int array[]){ //void function to print arr from intArray structure
        for (int i = 0; i < 3; i++){ // loop as long as i < arr.size. add 1 to i every iteration.
            cout << "Element " << i << ":" << array[i] << endl; //print the element at i.
        }
    }
};

int main() {
    intArray inputs = intArray::getInputs(); //declare member of intArray structure and initialize it with getInputs()
    intArray::printArray(inputs.arr); //call printArray function on inputs.arr
    intArray::getAddresses();
    system("pause>0");
    return 0;
}
