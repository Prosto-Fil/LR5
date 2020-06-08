#include "template.cpp"

int main()
{
	int* arr = new int[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i;
		cout << arr[i] << " ";
	}
	cout << endl;

	vector<int> a(arr, 5);
	cout << a[0] << endl;
	cout << a.at(0) << endl;
	cout << a.get_capacity() << endl;
	cout << a.get_size() << endl;
	a.erase(0);
	a.push_back(5);
	cout << a.front() << " " << a.back() << endl;
	a.print();
	a.insert(2, 8);
	cout << endl;
	cout << endl;
	a.resize(3);
	cout << endl;
	cout << endl;

	int* arr2 = new int[5];
	for (int i = 0; i < 5; i++)
	{
		arr2[i] = i + 5;
		cout << arr2[i] << " ";
	}
	cout << endl;

	vector<int> b(arr2, 5);

	b.print();
	cout << endl;

	a = b;

	cout << endl;

	a.print();

	vector<int> c(a);

	cout << endl;

	c.print();

	int* arr3 = new int[7];
	for (int i = 0; i < 7; i++)
	{
		arr3[i] = i + 10;
		cout << arr3[i] << " ";
	}
	cout << endl;

	vector<int> d(arr3, 7);

	cout << endl;
	cout << d.get_size() << endl;
	cout << d[5] << endl;

	int* arr4 = new int[7];
	for (int i = 0; i < 7; i++)
	{
		arr4[i] = i + 55;
		cout << arr4[i] << " ";
	}
	cout << endl;

	vector<int> vec(arr4, 7);
	cout << "vec: ";
	vec.print();
	cout << endl;

	cout << "a: ";
	a.print();
	cout << endl;

	a.swap(vec);

	cout << "vec: ";
	vec.print();
	cout << endl;

	cout << "a: ";
	a.print();
	cout << endl;

	a.clear();
	cout << a.get_size() << endl;

	bool check = a.empty();
	cout << check << endl;

	int* test = new int[7];
	test = vec.get_data();

	try
	{
		cout << d[555] << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

	try
	{
		cout << d.at(555) << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

	cout << "hi" << endl;

	NewInt* objPtr = new NewInt[4]{ 5, 6, 7, 8 };
	NewInt testint(55);

	vector<NewInt> testinvec(objPtr, 4);

	testinvec.print();

	cout << testinvec.get_size() << endl;
	cout << testinvec[2] << endl;

	testinvec.erase(0);
	testinvec.push_back(testint);
	testinvec.print();
	cout << endl;
	cout << endl;
	testinvec.resize(2);
	testinvec.print();

	vector<int> testtest(arr, 5);
	cout << "TEST:" << endl;

	testtest.print();

	testtest.pop_back();

	cout << "TEST:" << endl;

	testtest.print();

	testtest.push_back(9);

	cout << "TEST:" << endl;

	testtest.print();

	testtest.erase(1, 3);

	cout << "TEST erase:" << endl;

	testtest.print();

	return 0;
}