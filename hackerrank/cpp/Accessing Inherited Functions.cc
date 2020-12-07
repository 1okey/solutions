// https://www.hackerrank.com/challenges/accessing-inherited-functions/problem

class D : public C, public B, public A
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {
            int cpy = new_val;
            while (cpy % 2 == 0) {
                A::func(val);
                cpy /= 2;
            }
             
            while (cpy % 3 == 0) {
                B::func(val);
                cpy /= 3;
            }
             
            while (cpy % 5 == 0) {
                C::func(val);
                cpy /= 5;
            }
		 }
		 void check(int);
};