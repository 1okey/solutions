// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem

string catAndMouse(int x, int y, int z) {
    if (abs(x - z) == abs(y - z))
        return "Mouse C";
    
    return abs(x - z) < abs(y - z) ? "Cat A" : "Cat B";
}
