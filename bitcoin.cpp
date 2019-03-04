#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void readInput(char const ** );


void readInput(char const *_argv[])
{
    int bitCoinValue = atoi(_argv[6]);
    int senderHashtableNumOfEntries = atoi(_argv[8]);
    int receiverHashtableNumOfEntries = atoi(_argv[10]);
    int bucketSize = atoi(_argv[12]);
    const char *_bitCoinBalancesFile = _argv[2], *_transactionsFile = _argv[4];
    //ifstream bitCoinBalancesFile, transactionsFile;
    /*bitCoinBalancesFile.open(_bitCoinBalancesFile);
    if (!bitCoinBalancesFile)
    {
        cerr << "Unable to open BitCoin Balances file";
        exit(1);
    }

    transactionsFile.open(_transactionsFile);
    if (!transactionsFile)
    {
        cerr << "Unable to open the Transactions file";
        exit(1);
    }*/
}

int main(int argc, char const *argv[])
{
    readInput(argv);

    //printf("%d\n", bitCoinValue);
    return 0;
}