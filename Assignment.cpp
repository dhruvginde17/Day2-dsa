#include <iostream>
#include <stack>
using namespace std;

struct Q1Stack {
	stack<int> a;
	int maxele;

	void getMax()
	{
		if (a.empty())
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
		if (a.empty()) {
			cout << "Stack is empty\n";
			return;
		}

		int t = a.top();
		a.pop();

		if (t > maxele) {
			maxele = 2 * maxele - t;
		}
	}

	void push(int y)
	{
		if (a.empty()) {
			maxele = y;
			a.push(y);
			return;
		}

		if (y > maxele) {
			a.push(2 * y - maxele);
			maxele = y;
		}

		else{
			a.push(y);
		}
	}
};

int main()
{
	Q1Stack a;

	int n,i,choice, inp;
    cin>>n;

    for(i=0; i<n; i++)
    { 

        cin>>choice;
        if(choice==1){
            cin>>inp;
            a.push(inp);
        }
        else if(choice==2){
            a.pop();
        }
        else if(choice==3){
            a.getMax();
        }
        else{
            cout<<"Invalid choice!!";
        }
    }
	return 0;
}
