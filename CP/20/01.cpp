#include <bits/stdc++.h>

using namespace std;

double height = 0,weight = 0;
	
	bool comment;
	bool weirdMethod;
	bool illegalInput;
	bool foundWeirdInput;

int main(int argc, char **argv) {
	for(int i = 1;i<argc;i++) {
		string str(argv[i]);
		
		if(str == "-m") {
			continue;
		}
		
		if(str == "-i") {
			weirdMethod = true;
			continue;
		}
		
		if(str == "-c") {
			comment = true;
			continue;
		}
		
		//parse
		char* p;
		strtol(str.c_str(),&p,10);
		if(!(*p)) {
			 height ? weight = stoi(str) : height = stoi(str);
			 continue;
		}
		
		size_t ft = str.find("ft"), in = str.find("in");
		if(ft != string::npos && in != string::npos) {
			 foundWeirdInput = true;
			 height = stoi(str.substr(0,ft)) * 30.48 + 2.54 * stoi(str.substr(ft+2,in-(ft+2)));
		   continue;
		}
		
		illegalInput = true;
		break;
	}
	
	if(illegalInput || (foundWeirdInput && !weirdMethod)) {
			cout << "Usage: quickbmi [-i or -m] [-c] height weight\n[-i]: Imperial, height in, e.g., 5ft9in, weight in lbs\n[-m]: Metric, height in cms, weight in kgs\n[-c]: provides comment\nheight and weight are positive integers.\n";
	
	} else {
		 if(weirdMethod) {
		 	  weight *= 0.45359;
		 }
		 double bmi = weight * 10000 / height / height;
		 printf("Your BMI is %.1f\n",bmi);
	   if(comment) {
	   	  cout << "Comment: "<< (bmi < 18.5 ? "Underweight\n" :
	   	  (bmi < 24 ? "Normal\n" :
	   	  (bmi < 27 ? "Overweight\n" :
	   	  (bmi < 30 ? "Mild obesity\n" :
	   	  (bmi < 35 ? "Moderate obesity\n" :
	   	  "Severe obesity\n")))));
	   }
	}
}

