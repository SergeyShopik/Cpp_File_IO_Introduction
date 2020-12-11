#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
bool checkFile(std::ifstream & f)
{
	if (!f.is_open()) //checking file for opening
	{
		std::cout << "File doesn't open.\n";
		return 0;
	}
	return true;
}

int main()
{
	//std::ifstream fin("Source.cpp"); //object initialization
	//if (checkFile(fin))
	//{
	//	char str[300];

	//	std::ofstream fout("output.txt");
	//	while (!fin.eof()) //while not the end of the file
	//	{
	//		fin.getline(str, 300);
	//		fout << str << std::endl;
	//	}
	//	fin.seekg(0, std::ios::beg); //moving file pointer to the beginning of the file
	//	fout.close();
	//}

	// 1. Two text files given. Check if strings are equal. If not - print those strings.

	//std::ifstream fin1("input1.txt"), fin2("input2.txt");

	//if (checkFile(fin1) && checkFile(fin2))
	//{
	//	char* str = new char[300];
	//	std::ofstream fout("output.txt");
	//	int count = 0;
	//	while (!fin1.eof())
	//	{
	//		fin1.getline(str, 300);
	//		count++;
	//	}
	//	char** file2 = new char* [count];
	//	for (size_t i = 0; i < count; i++)
	//	{
	//		file2[i] = new char[300];

	//	}
	//	fin1.close();
	//	fin1.open("Text1.txt");

	//	int i = 0;
	//	while (!fin1.eof())
	//	{
	//		fin1.getline(str, 300);

	//		strcpy(file2[i++], str);
	//	}
	//	while (!fin2.eof())
	//	{
	//		bool flag = false;
	//		fin2.getline(str, 300);
	//		for (i = 0; i < count; i++)
	//		{
	//			if (strcmp(file2[i], str) == 0)
	//			{
	//				flag = true;
	//				break;
	//			}
	//		}
	//		if (flag == false)
	//		{
	//			std::cout << str << std::endl;
	//		}

	//	}
	//	delete[]str;
	//	for (size_t i = 0; i < count; i++)
	//	{
	//		delete[]file2[i];
	//	}
	//	delete[]file2;
	//}

	// 2. Text file given, create new file and write in source file statistics.
	/*std::ifstream fin2Task("inputFor2Task.txt");
	if (checkFile(fin2Task))
	{
		std::ofstream fout("output2Task");
		int count = 0;
		char* str = new char[300];
		while (!fin2Task.eof())
		{
			fin2Task.getline(str, 300);
			count++;
		}
		fout << count << " lines,\n";
		fin2Task.close();
		fin2Task.open("inputFor2Task.txt");
		int allChars = 0;
		while (!fin2Task.eof())
		{
			fin2Task.getline(str, 300);
			allChars += strlen(str);
		}
		fout << allChars << " chars total,\n";
		fin2Task.close();
		fin2Task.open("inputFor2Task.txt");
		int vowels = 0, consonants = 0;
		while (!fin2Task.eof())
		{
			fin2Task.getline(str, 300);
			for (size_t i = 0; i < strlen(str); i++)
			{
				str[i] = tolower(str[i]);
				if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
					vowels++;
				else consonants++;
			}
		}
		fout << vowels << " vowels,\n";
		fout << consonants << " consonants,\n";
		fin2Task.close();
		fin2Task.open("inputFor2Task.txt");
		int digits = 0;
		while (!fin2Task.eof())
		{
			fin2Task.getline(str, 300);
			for (size_t i = 0; i < strlen(str); i++)
			{
				if (isdigit(str[i])) digits++;
			}
		}
		fout << digits << " digits,\n";
	}*/

	//3.

	//object initialization for reading and writing
	std::fstream bfile("BinFile.dat", std::ios::binary | std::ios::out), tfile("text.txt", std::ios::out); //open as a binary file
	std::ofstream fout3("output3Task");

	for (size_t i = 0; i < 20; i++)
	{
		int val = rand() % 40 - 20;
		tfile << val << " ";
		bfile.write(reinterpret_cast<char*>(&val), sizeof(val));
	}
	size_t bsize, tsize;
	bfile.seekp(0, std::ios::end);//going to the end of the file
	tfile.seekp(0, std::ios::end);
	bsize = bfile.tellp();
	tsize = tfile.tellp();
	std::cout << bsize << ", " << tsize << std::endl;
	bfile.close();
	tfile.close();

	bfile.open("BinFile.dat", std::ios::binary | std::ios::in);
	tfile.open("text.txt", std::ios::in);

	int tarr[20], barr[20];

	std::cout << "Text file" << std::endl;
	for (size_t i = 0; i < 20; i++)
	{
		tfile >> tarr[i];
		std::cout << tarr[i] << " ";
	}
	std::cout << std::endl;
	bfile.read(reinterpret_cast<char*>(barr), sizeof(barr));
	std::cout << "Binary file" << std::endl;
	for (size_t i = 0; i < 20; i++)
	{
		std::cout << barr[i] << " ";
	}
	std::cout << std::endl;

	int sum = 0, arithMean, lastEl, firstNeg, lastNeg, firstLastProduct;
	for (size_t i = 0; i < 20; i++)
	{
		sum += tarr[i];
		if (i == 19) lastEl = tarr[i];
	}
	arithMean = sum / 20;
	for (size_t i = 0; i < 20; i++)
	{
		if (tarr[i] < 0)
		{
			firstNeg = tarr[i];
			break;
		}
	}
	for (size_t i = 19; i >=0; i--)
	{
		if (tarr[i] < 0)
		{
			lastNeg = tarr[i];
			break;
		}
	}
	firstLastProduct = firstNeg * lastNeg;
	for (size_t i = 0; i < 20; i++)
	{
		tarr[i] = tarr[i] + lastEl;
		tarr[i] *= firstLastProduct;
		if (tarr[i] == 0) tarr[i] = arithMean;
		std::cout << tarr[i] << " ";
	}
	for (size_t i = 0; i < 20; i++)
	{
		fout3 << tarr[i] << " ";
	}

	system("pause");
	return 0;
}