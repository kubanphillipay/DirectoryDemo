#include <iostream>
#include "tinydir.h"

using namespace std;


int main(int argc , char* argv[] ) {

	//if (argc < 2)
	//	return 1;

	
	tinydir_dir dir;
	tinydir_open(&dir, "./");

	while (dir.has_next)
	{
		tinydir_file file;
		tinydir_readfile(&dir, &file);

		printf("%s", file.name);
		if (file.is_dir)
		{
			printf("/");
		}
		printf("\n");

		tinydir_next(&dir);
	}

	tinydir_close(&dir);

	

	/*
	tinydir_dir dir;
	int i;
	tinydir_open_sorted(&dir, "./");

	for (i = 0; i < dir.n_files; i++)
	{
		tinydir_file file;
		tinydir_readfile_n(&dir, &file, i);

		printf("%s", file.name);
		if (file.is_dir)
		{
			printf("/");
		}
		printf("\n");
	}

	tinydir_close(&dir);
	*/

	cout << "Press something to continue..." << endl;
	cin.get();

	return 0;
}