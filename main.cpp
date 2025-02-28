#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
namespace fs = std::filesystem;
 


int main(int argc, char* argv[]) {
	if (argv[1] == nullptr) {
		std::cout << "bro forgor args 💀💀💀💀💀💀💀💀\n";
		return 0;
	}
	if (argv[2] == nullptr) {
		//unpacking mode
	std:: ifstream archive(argv[1]);
	std::string myline;
	std::string mystr = "";
	if ( archive.is_open() ) {
	while ( archive ) {
	std::getline (archive, myline);
	mystr += myline + '\n';
	}
	}
	mystr.erase(mystr.length() - 1);// read file done
	  // now i need to parse it
	  // *sigh*
	  // fucking HATE string manipulation
	for (; ;) {
	std::string name = mystr.substr(0, mystr.find('/'));
	mystr.erase(0, mystr.find('/')+1);
	std::ofstream newout(name, std::ios::binary);
	int len = stoi(mystr.substr(0, 13));
	mystr.erase(0, 13);
	newout << mystr.substr(0, len);
	mystr.erase(0, len);
	if (mystr.empty()) {
		break;
	}
	}


	return 0;
	}
	std::filesystem::path p{argv[1]};
	std::ifstream myfile(argv[1]);
	std::ofstream myout(argv[argc-1], std::ios::binary);
	std::string myline;
	std::string mystring = "";
	std::string outstr = "";

for (int i = 1; i != argc-1; i++) {
mystring = "";
std::ifstream myfile(argv[i]);
if ( myfile.is_open() ) {
while ( myfile ) {
std::getline (myfile, myline);
mystring += myline + "\n";
}
}
//std::cout << mystring.length();
mystring.erase(mystring.length()-1);
p = argv[i];
std::string fname= p.filename();
std::string fileSize = std::to_string(std::filesystem::file_size(p));
std::string add(13 - fileSize.length(), '0');
fileSize = add + fileSize;

mystring = fname + (std::string)"/" + fileSize + mystring;
outstr += mystring;
}
myout << outstr;
}
