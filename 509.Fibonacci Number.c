static int memo[31];

int fib(int N) {
    if(N < 2)    
        return N;
    if(!memo[N]) 
        return (memo[N] = fib(N - 1) + fib(N - 2));

    return memo[N];
}
