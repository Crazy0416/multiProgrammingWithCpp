#include <cstdio>
#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std;

int DoSomething(char c) {
	srand(c);
	int id = rand() % 10000;
	for (int i = 0; i < 10; i++) {
		this_thread::sleep_for(chrono::milliseconds(id));
		cout.put(c).flush();
	}
	return c;
}

int func1() {
	return DoSomething('.');
}

int func2() {
	return DoSomething('+');
}

int main() {
	cout << "starting func1() in background " << "and func2() in foreground : " << endl;

	future<int> result1(async(func1));
	int result2 = func2();

	int result = result1.get() + result2;

	cout << "\nresult of func1() + func2() : " << result << endl;
	system("pause");

	return 0;
}