#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(int argc, char *argv[]) {
	unordered_set<string> myset = 
	{"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
	cout<<"myset contains:";
	for (auto it = myset.begin(); it != myset.end(); it++) {
		cout<<" "<< *it;
	}
	cout<<endl;
	cout<<"myset's buckets contain:\n";
	for (unsigned i = 0; i < myset.bucket_count(); i++) {
		cout<<"bucket #"<<i<<" contains:";
		for (auto local_it = myset.begin(i); local_it != myset.end(i); local_it++) {
			cout<<" "<<*local_it;
		}
		cout<<endl;
	}
	return 0;
}
