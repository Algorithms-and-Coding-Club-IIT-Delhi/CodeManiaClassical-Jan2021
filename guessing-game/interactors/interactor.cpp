#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	registerInteraction(argc, argv);

	int k = inf.readInt();
	int n = inf.readInt();
	cout << n << endl
		 << flush;
	int queries = 0;
	bool guessed = false;
	while (queries < 16 && !guessed)
	{
		++queries;
		int g = ouf.readInt(1, n);
		if (g < k)
		{
			k = k - (k - g) / 2;
			cout << "lesser" << endl
				 << flush;
		}
		else if (g > k)
		{
			k = k + (g - k) / 2;
			cout << "greater" << endl
				 << flush;
		}
		else
		{
			guessed = true;
			cout << "guessed" << endl
				 << flush;
			break;
		}
	}
	ouf.readEoln();
	ouf.readEof();
	tout << queries << ' ' << (guessed * 1) << endl;
	if (!guessed)
		quitf(_wa, "You lost to Bob :(");
	quitf(_ok, "You've won the game with %d guesses!", queries);
}
