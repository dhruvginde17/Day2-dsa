#include <iostream>
#include <stack>
using namespace std;

struct Q1Stack {
	stack<int> s;
	int maxele;

	void getMax()
	{
		if (s.empty())
		{
			cout << "Stack is empty\n";
		}

		else
		{
			cout <<maxele << "\n";
		}
	}

	void pop()
	{
		if (s.empty()) {
			cout << "Stack is empty\n";
			return;
		}

		int t = s.top();
		s.pop();

		// Max will change if the max element of the stack is being removed.
		if (t > maxele) {
			maxele = 2 * maxele - t;
		}
	}

	// Removes top element from MyStack
	void push(int x)
	{
		if (s.empty()) {
			maxele = x;
			s.push(x);
			return;
		}

		// If new number is less than maxele
		if (x > maxele) {
			s.push(2 * x - maxele);
			maxele = x;
		}

		else{
			s.push(x);
		}
	}
};


int main()
{
	Q1Stack s;

	int n,i,choice, inp;
    cin>>n;

    for(i=0; i<n; i++)
    { 

        cin>>choice;
        if(choice==1){
            cin>>inp;
            s.push(inp);
        }
        else if(choice==2){
            s.pop();
        }
        else if(choice==3){
            s.getMax();
        }
        else{
            cout<<"Invalid choice!!";
        }
    }
	return 0;
}
