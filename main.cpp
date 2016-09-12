#include <iostream>
#include "network.h"
#include <time.h>

using std::cout;

int main()
{
	srand(time(NULL));

	Network n;
	n.SetDepth(2);
	n.SetNodeCountAtLevel(10,0);
	n.SetNodeCountAtLevel(3,1);
	//n.SetNodeCountAtLevel(1,2);
	n.SetNumOutputs(1);
	n.SetNumInputs(3);
	n.LinkNeurons();
	n.SetLearningRate(0.2);

	vector<float> expect(1);
	expect[0] = 0.03;
	vector<float> test(2);
	test[0] = 0.2;
	test[1] = 0.3;
	test[2] = 0.5;

	vector<float> expectb(1);
	expectb[0] = 0.1;
	vector<float> testb(2);
	testb[0] = 0.4;
	testb[1] = 0.5;
	testb[2] = 0.5;

	vector<float> expectc(1);
	expectc[0] = 0.32;
	vector<float> testc(2);
	testc[0] = 0.8;
	testc[1] = 0.8;
	testc[2] = 0.5;

	n.ResetNetwork(); //Randomize Weights
	n.PrintNetwork();
	
	

	cout << "Expected: " << expect[0] << " " << expectb[0] << " " << expectc[0] << "\n";
	
	
	vector<float> o = n.Query(test);
	float resA = o[0];
	cout << "Initial result: " << o[0] << "\n";
	o = n.Query(testb);
	cout << "Initial result: " << o[0] << "\n";
	o = n.Query(testc);
	cout << "Initial result: " << o[0] << "\n";

	int qwe = 1000000;
	
	vector<float> rexp(1);
	vector<float> rinp(3);
	cout << "Treinando... \n";
	while(qwe--)
	{
		rinp[0] = (rand() % 200) / 100.0;
		rinp[1] = (rand() % 200) / 100.0;
		rinp[3] = (rand() % 200) / 100.0;
		rexp[0] = rinp[0] * rinp[1] * rinp[2];
		n.Train(rinp, rexp);
	}
	o = n.Query(test);
	cout << "Trained Result: " << o[0] << "\n";
	o = n.Query(testb);
	cout << "Trained Result: " << o[0] << "\n";

	o = n.Query(testc);
	cout << "Trained Result: " << o[0] << "\n";
	system("pause");
	return 0;
}

