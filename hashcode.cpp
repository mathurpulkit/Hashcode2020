#include<stdio.h>
#include<fstream>
#include<iostream>
#include<ctype.h>
#include<vector>
#include<math.h>
#define ifile "input/f_libraries_of_the_world.txt"
#define ofile "output/outf.txt"
#define iter 1
std::size_t maxsize = 100000;
static long int tdays,tdays_c,tbooks,tlibs,libcount=0;
struct books
{
	long int id;
	long int score;
};
struct books *book= new struct books[100000];
void swap(int* a, int* b)  // utility swap function
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
class library
    {
        public:
        int size, days,limit,less;
		long double finscore;
		int *bookid= new int[100000];
        void lscore()  //score function
        {
			finscore=0;
			if (tdays<=days)
				return;
			if (size>((tdays-days)*limit))
				less=(tdays-days)*limit;
			else
				less=size;
			int i;
        	for(i=0;i<less;i++)
        		finscore+=book[bookid[i]].score;
			finscore= finscore/days;
        }
    	void sort()  //sort function
		{
    		int i, j, temp;
    		for(i=0;i<size-1;i++)  //implements bubble sort
    		{
        		for(j=0;j<size-i-1;++j)
        		{
            		if(book[bookid[j]].score<book[bookid[j+1]].score)
            		{
                		swap(&bookid[j],&bookid[j+1]);     //swapping
            		}
        		}
    		}
		}
		void dupkill(){
			int i;
			for (i=0;i<less;i++){
				book[bookid[i]].score = 0;
			}
		}
};
library *lib = new library[maxsize];
int *libord= new int[maxsize];
void lsort(int a)  //sort library function
{
    	int i, j, temp=a;
    	for(i=a+1;i<tlibs-1;i++)
    	{
           	if(lib[libord[i]].finscore>=lib[libord[temp]].finscore)
			temp = i;
        }
	if(temp!=a)
		swap(&libord[a],&libord[temp]);
}
void lcount(){ //no of libs to output
	long long int i=0,dc=0; //dc is daycount
	while(dc<=tdays_c){
		dc+=lib[libord[i]].days;
		i++;
	}
	libcount= (i>tlibs)?tlibs:i; // prevents errors for file A
}
void input()  //input function
{
	int i,j;
	std::ifstream fin1;
	fin1.open(ifile);
	fin1 >> tbooks;
	fin1 >> tlibs;
	fin1 >> tdays;
	for(i = 0; i < tbooks; i++)
	{
	    book[i].id = i;
	    fin1 >> book[i].score;
	}
	for(i = 0; i < tlibs; i++)
	{
	       fin1 >> lib[i].size;
	       fin1 >> lib[i].days;
	       fin1 >> lib[i].limit;
	       for(j = 0; j < lib[i].size; j++)
	       {
	           fin1 >> lib[i].bookid[j];
	       }
	}
	fin1.close();
}
void output()  // output function
{
	int i,j;
    std::ofstream fout1;
    fout1.open(ofile);
    fout1<<libcount<<"\n";
    for(i=0;i<libcount;i++)
    {
        fout1<<libord[i]<<" "<<(lib[libord[i]].less);
        fout1<<"\n";
        for(j=0;j<lib[libord[i]].less;j++)
        {
            fout1<<lib[libord[i]].bookid[j]<<" ";
        }
	fout1<<"\n";
    }
    fout1.close();
}
int main(){
	input();
	int i,j;
	tdays_c =tdays;
	for(i=0;i<tlibs;i++){
		lib[i].sort();
		lib[i].lscore();
	}
	for(i=0;i<tlibs;i++) //initializes the array
		libord[i]=i;
	for(i=0;i<tlibs;i++){
		lsort(i);
		if(lib[libord[i]].finscore==0)
			break;
		lib[libord[i]].dupkill();
		tdays = tdays - lib[libord[i]].days;
		for(j=i+1;j<tlibs;j++){
			lib[libord[j]].sort();
			lib[libord[j]].lscore();
		}
		printf("Selected %d libraries out of %ld libraries\n",i+1,tlibs);
	}
	lcount();   // Counts the number of libraries to write to the file
	printf("output done\n");
	output();
	return 0;
}


