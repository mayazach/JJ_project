#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int main(){

	ifstream myfile;
	string line;
	int pos = 0;
	int count,i,j,num[2];
	string elem[2];
	string terminate="S";
	myfile.open("graph.txt");

/*gets input for graph from a text file*/
	while (getline(myfile,line)){
		count = 0;
		while ((pos = line.find(" ")) != string::npos){
			if (count >= 2){
				cout << "Too many elements in line" << endl;
				myfile.close();
				return 1;
			}
			elem[count] = line.substr(0,pos);
			count++;
			line.erase(0,pos+1);
		}
		if (count >= 2){
			cout << "Too many elements in line" << endl;
			myfile.close();
			return 1;
		}
		if (count == 0){
			if (line.compare(terminate)){
				cout << "Too few elements in line" << endl;
				myfile.close();
				return 1;
			}
			else
				break;
		}
		elem[count]=line;
		for(i=0;i<=count;i++){
			for(j=0;j<elem[i].length();j++){
				if(isdigit(elem[i][j]) == 0){
					cout << "Elements in every line except the last must be integers" << endl;
					myfile.close();
					return 1;
				}
			}
			num[i] = atoi(elem[i].c_str());
		}
		/*Replace with code for insertion to graph*/
		cout << "Edge: " << num[0] << "->" << num[1] << endl;
	}
  
	myfile.close();
	return 0;
}
