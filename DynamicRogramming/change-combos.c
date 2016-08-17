#include <stdio.h>
#include <stdlib.h>

int numCombos(int );
int numWays(int amount, int * denoms, int index);
int makeChange(int num);
int numWaysMemoized(int amount, int * denoms, int index, int map[][4]);
int mcMemoized(int amount);
int numWaysMemoized(int amount, int * denoms, int index, int map[][4]);

int main(int argc, char ** argv){

  printf("Number of ways to represent %d cents is %d", atoi(argv[1]), mcMemoized(atoi(argv[1])));

  return 0;
}


// Nieve and completely incorrect because doesn't build from sub problems corectly
int numCombos(int num){
  if (num == 1)
    return 1;

  int ways = numCombos(num -1);

  if(num %5 == 0)
    ways++;
  if(num % 10 == 0)
    ways++;
  if(num % 25== 0)
    ways++;

  return ways;
}


// Recursive implementation using DP. Works but is redundant and innefficent.
int numWays(int amount, int * denoms, int index){
  if (index > 3) return 1;
  int denom = denoms[index];
  int ways = 0;

  for(int i = 0; i * denom < amount; i++){
    int amountLeft = amount - denom * i;
    ways += numWays(amountLeft, denoms, index + 1);
  }
  return ways;
}
int makeChange(int amount){
  int denoms[] = {1,5,10,25};
  return numWays(amount, denoms, 0);
}


// Memoize by storing previous computations in array.
int numWaysMemoized(int amount, int * denoms, int index, int map[][4]){
  if(index > 3) return 1;
  if(map[amount][index] > 0)
    return map[amount][index];

  int ways = 0;
  int denom = denoms[index];

  for(int i = 0; i * denom < amount; i++){
    int remaining = amount - i * denom;
    ways += numWaysMemoized(remaining, denoms, index + 1, map);
  }
  map[amount][index] = ways;
  return ways;
}

int mcMemoized(int amount){
  int map[2000][4] = {0};
  int denoms[] = {1, 5, 10, 25};

  return numWaysMemoized(amount, denoms, 0, map);
}