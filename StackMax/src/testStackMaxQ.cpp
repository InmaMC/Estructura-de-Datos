#include <iostream>
#include <StackMaxQ.h>

using namespace std;

int main(){
	StackMaxQ my_stack;
	int i;
	for (i=10; i>=0; --i)
		my_stack.push(i);
	
	while(!my_stack.empty()){
		PairInt my_pair = my_stack.top();
		cout << " Value: "<< my_pair.value << " Max: " << my_pair.max << endl;
		my_stack.pop();
	}
	
	return 0;
}
