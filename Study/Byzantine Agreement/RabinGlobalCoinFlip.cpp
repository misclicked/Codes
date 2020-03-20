//
// Created by misclicked on 3/17/20.
//

#include <bits/stdc++.h>

#define DECIDE      7
#define HIGH        6
#define LOW         5

#define TOTAL_NODES 9
#define BAD_NODES   1
#define ADVRATIO    1
#define BYZRATIO    8

#define DECIDED     1
#define UNDECIDED   0

#define HEAD        1
#define TAIL        0
using namespace std;

class GlobalCoin {
private:
    int coinValue;
public:
    int GetCoinValue() const {
        return coinValue;
    }

    void flipCoin() {
        coinValue = rand() % 2;
    }
};

class Node {
private:
    int maj;
    int tally;
    int vote;
    int isAdversary;
    int state;
    int decision;
public:
    Node(int isAdversary) {
        vote = rand() % 2;
        state = UNDECIDED;
        if (isAdversary)SetAdversary();
        else this->isAdversary = false;
    }

    int GetState() const {
        return state;
    }

    int GetDecision() const {
        return decision;
    }

    int GetVote() const {
        return vote;
    }

    bool IsAdversary() {
        return isAdversary == 1;
    }

    void SetAdversary() {
        isAdversary = true;
    }

    void RoundInput(const vector<int> &vec) {
        int countOfHead = 0;
        int countOfTail = 0;
        for (auto it:vec) {
            if (it == HEAD)countOfHead++;
            if (it == TAIL)countOfTail++;
        }
        if (countOfHead > countOfTail) {
            maj = HEAD;
            tally = countOfHead;
        } else {
            maj = TAIL;
            tally = countOfTail;
        }
    }

    void MakeDecision(const int &globalCoinState) {
        if (isAdversary) {
            vote = maj ^ 1;
            return;
        }
        if (tally * BYZRATIO >= DECIDE * TOTAL_NODES) {
            decision = maj;
            vote = maj;
            state = DECIDED;
        } else if (globalCoinState == HEAD && tally * BYZRATIO >= LOW * TOTAL_NODES
                   || globalCoinState == TAIL && tally * BYZRATIO >= HIGH * TOTAL_NODES) {
            vote = maj;
        } else {
            vote = 0;
        }
    }

};

int main() {
    srand(time(0));
    //make a GlobalCoin
    GlobalCoin gc;
    //make nodes
    vector<Node> Nodes;
    //bad nodes
    for (int i = 0; i < BAD_NODES; i++) {
        Nodes.push_back(Node(1));
    }
    //good nodes
    for (int i = BAD_NODES; i < TOTAL_NODES; i++) {
        Nodes.push_back(Node(0));
    }
    bool Alldecided = false;
    int round = 0;
    int voteOne;
    int voteZero;
    int cntDecisionMade;
    int decisionOne;
    int decisionZero;
    vector<int> roundVote;
    bool GoodVotedOne = false;
    bool GoodVotedZero = false;
    int finalDecision;
    while (!Alldecided) {
        cout << "Round:" << round++ << endl;
        //initial value
        roundVote.clear();
        voteOne = voteZero = 0;
        decisionOne = decisionZero = cntDecisionMade = 0;
        //flip Global Coin
        gc.flipCoin();
        //collect votes
        for (Node &it:Nodes) {
            if (it.GetVote()) {
                roundVote.push_back(1);
                voteOne++;
                if (!it.IsAdversary() && round == 1) {
                    GoodVotedOne = true;
                }
            } else {
                roundVote.push_back(0);
                voteZero++;
                if (!it.IsAdversary() && round == 1) {
                    GoodVotedZero = true;
                }
            }
        }
        //send votes
        for (Node &it:Nodes) {
            it.RoundInput(roundVote);
            it.MakeDecision(gc.GetCoinValue());
        }
        //print Info
        cout << "Voted One: " << voteOne << " Voted Zero: " << voteZero << endl;
        //collect decision
        for (Node &it:Nodes) {
            if (it.GetState() == DECIDED) {
                if (it.GetDecision()) {
                    decisionOne++;
                } else {
                    decisionZero++;
                }
                cntDecisionMade++;
            }
        }
        cout << cntDecisionMade << endl;
        cout << "Decide One: " << decisionOne << " Decide Zero: " << decisionZero << endl;
        //check all good decided
        Alldecided = cntDecisionMade >= (TOTAL_NODES - BAD_NODES);
        if (Alldecided) {
            if (decisionOne < decisionZero) {
                cout << "Final decision: 0\n";
                assert(GoodVotedZero);
            } else {
                cout << "Final decision: 1\n";
                assert(GoodVotedOne);
            }
            cout << "Used rounds: " << round << endl;
            cout << "Good nodes voted one at first round: " << GoodVotedOne << endl;
            cout << "Good nodes voted zero at first round: " << GoodVotedZero << endl;
        }
    }
}