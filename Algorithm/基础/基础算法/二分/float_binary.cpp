bool check(double x) {/* ... */} //���x�Ƿ�����ĳ������

double bsearch_3(double l, double r) {
	for(int i = 0; i < 100; i++) {
		double mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	return l;
}
