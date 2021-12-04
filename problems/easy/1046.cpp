// greedy, priority queue

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pile(stones.begin(), stones.end());
    while (pile.size() > 1) {
        int leftRock = pile.top();
        pile.pop();
        int rightRock = pile.top();
        pile.pop();
        leftRock -= rightRock;
        if (leftRock) {
            pile.push(leftRock);
        }
    }
    if (pile.size() == 0) return 0;
    else return pile.top();
}
