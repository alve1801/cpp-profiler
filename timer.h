#include <time.h> // for timer
#include <map> // for db
#include <string> // i hate this already

using namespace std;

struct Timer{
	map<string,float>entries;
	clock_t time;

	Timer(){reset();}

	void reset(){time=clock();}

	void disp(){
		float t=0;
		for(auto&[key,val]:entries)t+=val; // this could prolly be done better

		for(auto&[key,val]:entries) // i hate this
			printf("% 10s : % 10.3f (% 5.1f%%)\n",key.c_str(),val*1000/CLOCKS_PER_SEC,val*100/t);
		printf("     total : % 10.3f (100.0%%)\n",t*1000/CLOCKS_PER_SEC);
	}

	void operator[](string s){ // this goes AFTER the thing we timin'
		clock_t a=clock();
		entries[s]+=(float)(a-time);
		reset();
	}
};

Timer timer; // spares me from having to initialise it in the main file
