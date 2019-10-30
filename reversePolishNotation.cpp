//This is an implementation of a Reverse-Polish Notation Calculator using a stack data structure implemented with arrays
#include <iostream>
using namespace std;

int stack[20]; //holder of digits
int top = -1; //'top' value of the stack of digits
char input[40]; //character input for user input (double stack digits bc of spaces)
int temp1; //used for division and subtraction along with temp2
int temp2;
//functions
void push(int);
int pop();
void display();

int main() {
	//user input to a char array of digits and operators seperated by spaces
	cout << "Input a stream of Reverse-Polish Notation seperated by spaces:  ";
	cin.getline(input, 40);
	//If item in array is not a space, then it will either push the item if it's a value or perform the operation if operator
	for( int i=0; i<50; i++ ){
		if( isdigit(input[i]) ){
			push( input[i] - 48 );
		}
		else if( input[i] == '*' or input[i] == 'x'){
			push( pop() * pop() );
		}
		else if( input[i] == '/' ){
			temp1 = pop();
			temp2 = pop();
			push( temp2 / temp1 );
		}
		else if( input[i] == '+' ){
			push( pop() + pop() );
		}
		else if( input[i] == '-' ){
			temp1 = pop();
			temp2 = pop();
			push( temp2 - temp1 );
		}
		//display(); //display each iteration if necessary
	}
	
	cout << stack[0];
	return stack[0];
}
//pushes integer value into the stack as long as stack is not full
void push(int val) {
   if(top>19){
   	 cout<<"Stack is full"<<endl; 
   }
   else {
   	  top++;
      stack[top]=val;
   }
}
//removes and returns the top element of the stack unless stack is empty
int pop() {
   if(top<0){
      cout<<"Stack is empty"<<endl;
      throw "Underflow";
	}
   else {
   	  int t = stack[top];
      stack[top] = 0;
      top--;
      return t;
   }
}
//Displays all elements in stack seperated by commas if stack is non-empty
void display() {
   if(top>=0) {
      cout<<"Stack: ";
      for(int i=0; i<=top; i++)
         cout << stack[i] << ",";
         cout << endl;
   } 
   else{
   	cout<<"Stack is empty";
   }
}

