class atom{
private:
	atom ** atom_array;
	atom **hydrogens;
	int number;
	char id[1];
	int counter;
	int found;
public:
	atom(int,int);
	~atom();
	void alcanium(atom**, int,int,int);
	void alcenium(atom**, int,int,int);
	void alcinium(atom**, int,int,int);
	void print(atom**,int,int,int);
};
