/*Q4 . Find The Winner Of Circular Game
There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. More formally, 
moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the
 1st friend.The rules of the game are as follows: Start at the 1st friend.
Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some
friends more than once.The last friend you counted leaves the circle and loses the game.If there is still more than one friend in the circle,
go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.Else, the last friend in the circle wins 
the game.Given the number of friends, n, and an integer k, return the winner of the game.
*/
#include <iostream>
#include <vector>
using namespace std;

int findTheWinner(int n, int k) {
    vector<int> friends;
    for (int i = 1; i <= n; i++) {
        friends.push_back(i);
    }
    
    int index = 0;
    while (friends.size() > 1) {

        index = (index + k - 1) % friends.size();

        friends.erase(friends.begin() + index);
    }
    
    // Return the last remaining friend
    return friends[0];
}

int main() {
    int n = 5, k = 2;
    cout << "Winner: " << findTheWinner(n, k) << endl;
    return 0;
}
