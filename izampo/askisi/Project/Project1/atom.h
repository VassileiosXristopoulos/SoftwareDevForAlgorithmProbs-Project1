class atom{
private:
	int number;
	int hyd_num;
	atom **p;
public:
	
	atom(int,atom ***,int);
	~atom(); 
};