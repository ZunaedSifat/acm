## Type 1
### Question
Alice and Bob are playing a game, where there are `n` stones in a basket. In a move, the player can take `2` or `5` stones. Alice gives her move first, then Bod gives this move and it goes on until someone is unable to give a move. The player who can't give a move loses the game. Both Alice and Bob plays optimally. Given `n`, you need to tell, who will win the game.

### Answer
we can easily solve this using a dp. If the current player can make a move to such a losing position, he/she wins, otherwise he/she loses. The DP array from index `0` is following: 
`LLWLLWWW....`

## Type 2
Misere Nim,
when all of them are 1 or 0
when at least one them is greater than 1

Note:
1. Palindrome in binary string
1. set intersection, the stl way
1. If you divide the pile for grundy in more than one group, you will have to xor them (think this recursively)