void rotate(int a[], unsigned size, int shift)
{
    while((shift %= size)-- > 0) {
		unsigned i = 0;
		while(i < size){
        	int tmp = a[i];
            a[i] = a[i+1];
            a[++i] = tmp;
        }
    }
}
