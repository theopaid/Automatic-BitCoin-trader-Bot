#include <iostream>
#include <string>
#include <fstream>

using namespace std;



struct BitNode
{
    string BitCoinID;
    float percentage;
    BitNode *next;
};

class BitCoinIDsList
{
    private:
        BitNode *listHead;
        BitNode *listTail;

    public:
        BitCoinIDsList()
        {
            listHead = NULL;
            listTail = NULL;
        }

        void pushback(string _BitCoinID)
        {
            BitNode *temp = new BitNode;
            temp->BitCoinID = _BitCoinID;
            temp->percentage = 1.0;
            temp->next = NULL;
            if(listHead == NULL)
            {
                listHead = temp;
                listTail = temp;
                temp = NULL;
            }
            else
            {
                listTail->next = temp;
                listTail = temp;
            }
        }

        void changePCTofBC(string _BitCoinID, float newpct)
        {
            BitNode *current = listHead;
            while(current != NULL)
            {
                if(current->BitCoinID == _BitCoinID)
                {
                    current->percentage = newpct;
                    return;
                }
                current = current->next;
            }
        }

        ~BitCoinIDsList()
        {
            BitNode *current = listHead;
            BitNode *next;
            while(current != NULL)
            {
                next = current->next;
                delete current;
                current = next;
            }
        }
};

struct NodeForBalances
{
    string UserID;
    BitCoinIDsList *BitCoinsOfUser;
    NodeForBalances *next;
};

class WalletIDsList
{
    private:
        NodeForBalances *listHead;
        NodeForBalances *listTail;

    public:
        WalletIDsList()
        {
            listHead = NULL;
            listTail = NULL;
        }

        void pushback(string _UserID)
        {
            NodeForBalances *temp = new NodeForBalances();
            temp->UserID = _UserID;
            temp->BitCoinsOfUser = new BitCoinIDsList();
            temp->next = NULL;
            if(listHead == NULL)
            {
                listHead = temp;
                listTail = temp;
                temp = NULL;
            }
            else
            {
                listTail->next = temp;
                listTail = temp;
            }
        }

        ~WalletIDsList()
        {
            NodeForBalances *current = listHead;
            NodeForBalances *next;
            while(current != NULL)
            {
                next = current->next;
                delete current;
                current = next;
            }
        }
};



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