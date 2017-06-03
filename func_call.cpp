void func_cal(int * funcmain, int * arg1, int * arg2, int * newf, int n) {
	
	for (int i=0;i<(n*n);i++)
		{newf[i]=funcmain[arg1[i]*n+arg2[i]]}
}