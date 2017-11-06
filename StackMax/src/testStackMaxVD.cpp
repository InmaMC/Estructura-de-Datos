#include <iostream>
#include <StackMaxVD.h>

using namespace std;

int main(){
	StackMaxVD my_stack;
	int i;
	for (i=10; i>=0; --i)
		my_stack.push(i);
	for (i=6; i<=18; i=i+2)
		my_stack.push(i);
	
	
	while(!my_stack.empty()){
		PairInt my_pair = my_stack.top();
		cout << my_pair.value << " Max: " << my_pair.max << endl;
		my_stack.pop();
	}
	
	return 0;
}
