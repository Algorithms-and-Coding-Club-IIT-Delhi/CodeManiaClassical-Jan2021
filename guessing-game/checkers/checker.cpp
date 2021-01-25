#include "testlib.h"

const int LIMIT = 16;

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);

	int oufq = ouf.readInt(), pGuess = ouf.readInt();
	int ansq = ans.readInt(), jGuess = ans.readInt();

	if (ansq > LIMIT)
		quitf(_fail, "Limit is %d, but main solution have made %d queries", LIMIT, ansq);
	if (!jGuess)
		quitf(_fail, "Jury couldn't guess the number");

	if (oufq > LIMIT)
		quitf(_wa, "Limit is %d, but solution have made %d queries", LIMIT, oufq);
	if (!pGuess)
		quitf(_wa, "You lost to Bob :(");

	int n = inf.readInt();
	int m = inf.readInt();
	quitf(_ok, "You've won the game with %d guesses!", oufq);
}
