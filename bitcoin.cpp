#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void readInput(char const *_argv[])
{
    string _bitCoinBalancesFile, _transactionsFile;
    int bitCoinValue, senderHashtableNumOfEntries, receiverHashtableNumOfEntries, bucketSize;
    for(int i = 1; i < 12; i += 2) {
        if(!string(_argv[i]).compare("-a"))
            _bitCoinBalancesFile = _argv[i+1];
        else if(!string(_argv[i]).compare("-t"))
            _transactionsFile = _argv[i+1];
        else if(!string(_argv[i]).compare("-v"))
            bitCoinValue = atoi(_argv[i+1]);
        else if(!string(_argv[i]).compare("-h1"))
            senderHashtableNumOfEntries = atoi(_argv[i+1]);
        else if(!string(_argv[i]).compare("-h2"))
            receiverHashtableNumOfEntries = atoi(_argv[i+1]);
        else if(!string(_argv[i]).compare("-b"))
            bucketSize = atoi(_argv[i+1]);
    }
    ifstream bitCoinBalancesFile, transactionsFile;
    bitCoinBalancesFile.open(_bitCoinBalancesFile);
    if (!bitCoinBalancesFile)
    {
        cerr << "Unable to open BitCoin Balances file";
        exit(1);
    }
    string name;
    bitCoinBalancesFile >> name;
    cout << name << endl;
    transactionsFile.open(_transactionsFile);
    if (!transactionsFile)
    {
        cerr << "Unable to open the Transactions file";
        exit(1);
    }
}

int main(int argc, char const *argv[])
{
    readInput(argv);

    //printf("%d\n", bitCoinValue);
    return 0;
}