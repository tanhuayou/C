#include <iostream>

#include "filemap.h"

using namespace std;

int main(){
	CFileMap* fileMap = new CFileMap();
	fileMap->~CFileMap();
	return 0;
}
