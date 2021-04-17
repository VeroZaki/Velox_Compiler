#include <iostream>
#include <string>
#include <conio.h>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;

void del(string arr[], int rep) {
	for (int i = rep; i >= 0; i--) {
		arr[i] = " ";
	}
}
string loop(string arr) {
	ifstream NUMBER;
	string dig, word;
	NUMBER.open("numbers.txt");
	while (NUMBER >> dig >> word) {
		if (dig == arr) {
			return word;
		}
	}
	NUMBER.close();
}



string convert(int x) {
	int  y, sum;
	sum = x + 3;
	stringstream ss;
	ss << hex << sum; // from decimal to hexa 
	string res(ss.str()); // al hexa to string
	//cout << res;
	return res;
}
string hex(int x, string g) {
	int sum, y;
	//cout << g;
	stringstream geek(g); //from a string to int
	geek >> hex >> y;
	//cout << y << endl;
	sum = x + y;
	//cout << sum;
	stringstream ss;
	ss << hex << sum; // from decimal to hexa
	string res(ss.str()); // from hexa to string ya wald
	//cout << res;
	return res;
}
string hex_sub(string x, string g) {
	int sum, y, m;
	//cout << g;
	stringstream geek(g); //from a string to int
	geek >> hex >> y;
	stringstream gee(x); //from a string to int
	gee >> hex >> m;
	//cout << y << endl;
	sum = y - m;
	//cout << sum;
	stringstream ss;
	ss << hex << sum; // int decimal_value
	string res(ss.str());
	//cout << res;
	return res;
}
string hex_add(string x, string g) {
	int sum, y, m;
	//cout << g;
	stringstream geek(g); //from a string to int
	geek >> hex >> y;
	stringstream gee(x); //from a string to int
	gee >> hex >> m;
	//cout << y << endl;
	sum = y + m;
	//cout << sum;
	stringstream ss;
	ss << hex << sum; // int decimal_value
	string res(ss.str());
	//cout << res;
	return res;
}
string Dec_Hex(int num) {
	stringstream ss;
	ss << hex << num; // int decimal_value
	string res(ss.str());
	return res;
}
int del(string s) {
	string d = "X";
	int num;
	//cout << s;
	if (s.find(d) != string::npos) {
		//cout << "found";
		s.erase(remove(s.begin(), s.end(), 'X'), s.end());
		int n = s.length() - 2;
		num = n / 2;
	}
	else {
		s.erase(remove(s.begin(), s.end(), 'C'), s.end());
		num = s.length() - 2;
	}
	return num;
}
string string_Hex(string s) {
	int x;
	stringstream geek(s); //from a string to int
	geek >> x;
	stringstream ss;
	ss << hex << x; // int decimal_value
	string res(ss.str());
	return res;
}
string Search(string s) {
	string d = "X";
	int num;
	//cout << s;
	if (s.find(d) != string::npos) {
		s.erase(remove(s.begin(), s.end(), 'X'), s.end());
		s.erase(s.begin());
		s.erase(s.end() - 1);
		return s;
	}
	else {
		ifstream ascii;
		char sym;
		string temp;
		string code;
		s.erase(remove(s.begin(), s.end(), 'C'), s.end());
		s.erase(s.begin());
		s.erase(s.end() - 1);
		for (int k = 0; k < s.length(); k++) {
			ascii.open("C:\\D\\Collage\\Past Years\\Third year\\First Term\\System Programming\\System_Project\\kolo\\ASCII.txt");
			while (ascii >> sym >> code) {
				//cout << sym << "  " << code << endl;
				if (s[k] == sym) {
					//cout << s[k] << "  " << code << endl;
					temp = temp + code;
				}
			}
			ascii.close();
		}
		return temp;;
	}
}
string files(ifstream& filefinal) {
	string location, lable3, operation, OP_CODE, OBJECTCODE;
	string king;
	int sd, count = 0, summ;
	while (filefinal >> location >> lable3 >> operation >> OP_CODE >> OBJECTCODE) {
		//ObjectProgram << "H^" << lable3 << "^" << co << "^" << gee;
		if (operation == "RESW" || operation == "RESB" || operation == "BYTE" || operation == "WORD" || operation == "START" || operation == "END") {
			//cout << operation << endl;
			if (operation == "BYTE") {
				sd = del(OP_CODE);
				king = Dec_Hex(sd);
				//cout << king << endl;
			}
		}
		else {
			//cout << operation << endl;
			count = count + 1;
			if (count <= 10) {
				summ = count * 3;
			}
			else if (count >= 10) {
				summ = count * 3;
				break;
			}
		}
	}
	stringstream ss;
	ss << hex << summ; // int decimal_value
	string res(ss.str());
	string koko = hex_add(res, king);
	return koko;
}
string to_upper(string& s) {
	for (int i = 0; i < s.length(); i++)
		if (s[i] >= 'a' and s[i] <= 'z')
			s[i] = s[i] - 32;
	return s;
}

void assembler() {
	// myfile->instuction set.....myfile2->program....myfile3->directives....
	char filename;
	int x = 0, i = 0, y, g = 0;
	string arr[100];
	ifstream myfile, myfile2, myfile3, myfile4, symbolread, ascii, readobject, test, filefinal, kolo, OP, H, S, ISA, LastRead;
	ofstream out, symbol, object, ObjectProgram, file, habal, start, FinalObjectProgram, yarab, lastOut;
	object.open("object_code.txt");
	out.open("test.txt");
	symbol.open("SymbolTable.txt");
	myfile2.open("program.txt");
	if (!myfile2.is_open()) {
		cout << "not found";
		exit(EXIT_FAILURE);
	}
	string f, a;
	string name;
	string opcode;
	string lable;
	string mnomic;
	string names;
	string direct;
	string l, m, n, o;
	string lable2, value;
	string symb, val;
	string obj;
	string na, va, no, vo;
	string location, lable3, operation, OP_CODE, OBJECTCODE;
	string opa, opaaa, gee, co;
	string ko, op;
	string totalstring, totalstart, tot;
	while (myfile2 >> lable >> mnomic >> names) {
		string s = names;
		arr[i] = s;
		i++;
		arr[i] = s;
		i++;
		stringstream geek(s); //from a string to int
		geek >> hex >> x; // al x dy decimal
		//cout << x;
		break;
	}
	while (myfile >> name >> opcode) {
		n = name;
		o = opcode;
		break;
	}
	while (myfile2 >> lable >> mnomic >> names) {
		myfile.open("Ass.txt");
		//cout << name << endl;
		while (myfile >> name >> opcode) {
			//cout << mnomic << "    " << name << endl;
			if (mnomic == name) {
				string c = convert(x);
				arr[i] = c;
				//cout << arr[i];
				x = x + 3;
				i++;
				myfile.close();
				break;
			}
		}
	}
	myfile2.close();
	myfile2.open("program.txt");
	while (myfile2 >> lable >> mnomic >> names) {
		myfile3.open("directives.txt");
		while (myfile3 >> direct) {
			if (mnomic == direct) {
				if (mnomic == "BYTE") {
					string temp = names;
					int r = del(temp);
					string h = hex(r, arr[i - 1]);
					arr[i] = h;
					i++;
				}
				else if (mnomic == "WORD") {
					string h = hex(3, arr[i - 1]);
					arr[i] = h;
					i++;
				}
				else if (mnomic == "RESB") {
					string temp = names;
					//cout << temp << endl;
					stringstream geek(temp); //from a string to int
					geek >> y;
					//cout << y;
					string h = hex(y, arr[i - 1]);
					arr[i] = h;
					i++;
				}
				else if (mnomic == "RESW") {
					string temp = names;
					//cout << temp << endl;
					stringstream geek(temp); //from a string to int
					geek >> y;
					int mul = y * 3;
					string f = hex(mul, arr[i - 1]);
					arr[i] = f;
					i++;
				}

			}
		}
		myfile3.close();
	}
	myfile2.close();
	myfile2.open("program.txt");
	while (myfile2 >> lable >> mnomic >> names) {
		string fg = "0";
		string mn = "0";
		if (arr[g].length() == 4) {
			out << lable << " " << to_upper(arr[g]) << endl;
			g++;
		}
		else {
			for (int k = 3; k > arr[g].length(); k--) {
				fg = fg + mn;
			}
			string str = fg + arr[g];
			out << lable << " " << to_upper(str) << endl;
			g++;
		}
	}
	// kol aly fo2 bi3mil al location
	out.close();
	myfile4.open("test.txt");
	while (myfile4 >> lable2 >> value) {
		if (lable2 != "BLANK") {
			symbol << lable2 << " " << value << endl;
		}
	}
	// For the Symbol Table Creation
	myfile4.close();
	symbol.close();
	myfile.close();
	myfile2.close();
	myfile3.close();
	//myfile2.open("C:\\D\\Collage\\Past Years\\Third year\\First Term\\System Programming\\System_Project\\kolo\\program.txt");
	//symbolread.open("C:\\D\\Collage\\Past Years\\Third year\\First Term\\System Programming\\System_Project\\kolo\\SymbolTable.txt");
	//myfile.open("C:\\D\\Collage\\Past Years\\Third year\\First Term\\System Programming\\System_Project\\kolo\\Ass.txt");
	myfile2.open("program.txt");
	while (myfile2 >> lable >> mnomic >> names) {
		symbolread.open("SymbolTable.txt");
		while (symbolread >> symb >> val) {
			//cout << names << "  " << symb << endl;
			string p = ",X";
			string conc = symb + p;
			//cout << conc << endl;
			if (names == symb || names == conc || mnomic == "RSUB" || mnomic == "BLANK") {
				myfile.open("Ass.txt");
				while (myfile >> name >> opcode) {
					//cout << "jnkcnkd";
					//cout << names << endl;
					if (names == symb) {
						if (mnomic == name) {

							string con;
							con = opcode + val;
							object << names << "  " << con << endl;;
							//cout << opcode << val << endl;
							//cout << mnomic << "  " << name << endl;
						}
					}
					else if (names == conc) {
						if (mnomic == name) {
							char s = val.at(0);
							int ia = s - '0';
							ia = ia + 8;
							stringstream ss;
							ss << hex << ia; // int decimal_value
							string res(ss.str());
							string h = val;
							h.replace(0, 1, res);
							string con;
							con = opcode + h;
							object << names << "  " << con << endl;
							//cout << h << endl;
							//cout << res << endl;
							//cout << opcode << h << endl;
							//cout << mnomic << "  " << name << endl;
						}
					}
					else if (mnomic == name) {
						//cout << mnomic << endl;
						object << "BLANK" << "  " << opcode + "0000" << endl;
					}

				}
				myfile.close();
				break;
			}
			else if (mnomic == "START") {
				object << names << "  " << "BLANK" << endl;
				break;
			}
		}
		symbolread.close();
	}
	myfile2.close();
	myfile2.open("program.txt");
	while (myfile2 >> lable >> mnomic >> names) {
		myfile3.open("directives.txt");
		while (myfile3 >> direct) {
			if (mnomic == direct) {
				//cout << direct;
				if (mnomic == "WORD") {
					string temp = names;
					string d = string_Hex(temp);
					int z = d.length();
					f = "0";
					a = "0";
					for (int k = 5; k > z; k--) {
						a = a + f;
					}
					string coc = a + d;
					object << names << "  " << coc << endl;
					//cout << coc << endl;
				}
				else if (mnomic == "BYTE") {
					string temp;
					temp = names;
					//cout << temp;
					string p = Search(temp);
					object << names << "  " << p << endl;
					//cout << p;
				}
				else if (mnomic == "BLANK") {
					object << names << "  " << "BLANK" << endl;
				}
				else if (mnomic == "RESW") {
					object << names << "  " << "BLANK" << endl;
				}
				else if (mnomic == "RESB") {
					object << names << "  " << "BLANK" << endl;
				}
				break;
			}
			else if (mnomic == "END") {
				object << names << "  " << "BLANK" << endl;
				break;
			}
		}
		myfile3.close();
	}
	object.close();
	myfile2.close();
	out.close();
	test.open("test.txt"); //ha2ra meno
	myfile2.open("C:\\D\\Collage\\Past Years\\Third year\\First Term\\System Programming\\System_Project\\kolo\\program.txt");
	file.open("file.txt"); //haktib fih
	readobject.open("object_code.txt"); // ha2ra meno
	while (test >> na >> va) {
		file << va << " " << na << " ";
		while (myfile2 >> lable >> mnomic >> names) {
			file << mnomic << " " << names << " ";
			while (readobject >> no >> vo) {
				file << to_upper(vo) << endl;
				break;
			}
			break;
		}
	}
	filefinal.open("file.txt");
	while (filefinal >> location >> lable3 >> operation >> OP_CODE >> OBJECTCODE) {
		//cout << location << "  " << "  "<<lable3 << "  "<< operation << "  "<<OP_CODE<<"  "<<OBJECTCODE<< endl;
		if (operation == "START") {
			opa = location;
		}
		else if (operation == "END") {
			opaaa = location;
		}
	}
	//cout << opa << "   " << opaaa;
	string print = hex_sub(opa, opaaa);
	f = "0";
	a = "0";
	string pl = "0";
	for (int k = 5; k > print.length(); k--) {
		a = a + f;
	}
	gee = a + print;
	for (int k = 5; k > opa.length(); k--) {
		pl = pl + f;
	}
	co = pl + opa;
	//cout << co;
	int count = 0, summ, sd, flag, NUM;
	string king;
	string st;
	filefinal.close();
	start.open("start.txt");
	habal.open("habal.txt");
	filefinal.open("file.txt");
	ObjectProgram.open("objectprogram.txt");
	while (filefinal >> location >> lable3 >> operation >> OP_CODE >> OBJECTCODE) {
		ObjectProgram << "H^" << lable3 << "^" << co << "^" << to_upper(gee);
		break;
	}
	filefinal.close();
	filefinal.open("file.txt");
	//ObjectProgram.open("C:\\D\\Collage\\Past Years\\Third year\\First Term\\System Programming\\System_Project\\kolo\\objectprogram.txt");
	st = co;
	start << "BLANK" << endl;
	habal << "BLANK" << endl;
	while (filefinal >> location >> lable3 >> operation >> OP_CODE >> OBJECTCODE) {
		if (operation != "START") {
			//cout << operation << endl;
			kolo.open("kolo.txt");
			while (kolo >> ko >> op) {
				//cout << ko << "\t" << operation << endl;
				if (operation == ko) {
					if (operation != "BYTE" && operation != "WORD" && operation != "END" && operation != "RESW" && operation != "RESB") {
						//cout << operation << "   " << ko << endl;
						string gg = "0", kk = "0";
						if (count == 0) {
							for (int kok = 4; kok > location.length(); kok--) {
								gg = gg + kk;
							}
							start << gg + location << endl;
							ObjectProgram << endl << "T^" << gg + location << "^";
							habal << endl;
						}
						count = count + 3;
						//cout << count << endl;
						habal << OBJECTCODE << "^";
						if (count >= 30) {
							//cout << count << endl;
							string S = Dec_Hex(count);
							//habal << OBJECTCODE << "^";
							//cout << to_upper(S) << endl; // hasfarooo
							ObjectProgram << to_upper(S);
							//cout << count;
							count = 0;
							//ObjectProgram << endl << "T^";
						}
						else {

							flag = count;
							//habal << endl << "T^";
						}

					}
					else {
						if (operation == "BYTE") {
							string gg = "0", kk = "0";
							if (count == 0) {
								for (int kok = 4; kok > location.length(); kok--) {
									gg = gg + kk;
								}
								start << gg + location << endl;
								ObjectProgram << endl << "T^" << gg + location << "^";
								habal << endl;
							}
							string KA = OP_CODE;
							//cout << KA;
							NUM = del(KA);
							if (NUM + count <= 30)
							{
								string gg = "0", kk = "0";
								if (count == 0) {
									for (int kok = 4; kok > location.length(); kok--) {
										gg = gg + kk;
									}
									start << gg + location << endl;
									ObjectProgram << endl << "T^" << gg + location << "^";
									habal << endl;
								}
								count = NUM + count;

								habal << OBJECTCODE << "^";
								//string S = Dec_Hex(count);
								//cout << to_upper(S) << endl; // hasfarooo
								//ObjectProgram << to_upper(S);
								//count = 0;
								//cout << SUM;
								if ((30 - count) < 3) {
									count = 0;
								}
							}
							else {
								start << location << endl;
								//habal << endl;
								//cout << count << endl;
								string S = Dec_Hex(count);
								//habal << OBJECTCODE << "^";
								//cout << to_upper(S) << endl; // hasfarooo
								ObjectProgram << to_upper(S);
								count = 0;
							}
						}
						if (operation == "WORD") {
							int myriam = 3;
							string gg = "0", kk = "0";
							if (count == 0) {
								for (int kok = 4; kok > location.length(); kok--) {
									gg = gg + kk;
								}
								start << gg + location;
								habal << endl;
								ObjectProgram << endl << "T^" << gg + location << "^";
							}
							if (myriam + count <= 30)
							{
								//cout << count << endl;
								count = count + myriam;
								string S = Dec_Hex(myriam);
								//cout << SUM
								habal << OBJECTCODE << "^";
								//cout << S << endl;
							}
							else {
								//habal << endl;
								string S = Dec_Hex(count);
								//habal << OBJECTCODE << "^";
								//cout << to_upper(S) << endl; // hasfarooo
								ObjectProgram << to_upper(S);
								count = 0;
								ObjectProgram << endl << "T^";
								habal << endl;
							}
						}
						else if (operation == "END") {
							if (count != 0)
							{
								string S = Dec_Hex(count);
								//habal << OBJECTCODE << "^";
								//cout << to_upper(S) << endl; // hasfarooo
								ObjectProgram << to_upper(S);
								//count = 0;
							}
						}
						else if (operation == "RESW" || operation == "RESB") {
							if (count != 0) {
								string S = Dec_Hex(count);
								//cout << to_upper(S) << endl; // hasfarooo
								ObjectProgram << to_upper(S);
							}
							if (operation == "RESW") {
								count = 0;
							}
							else if (operation == "RESB") {
								//cout << "vhhgj";
								count = 0;
							}
						}
					}
				}
			}
			kolo.close();

		}
	}
	habal.close();
	yarab.open("yarab.txt");
	H.open("habal.txt");
	string astorha;
	while (H >> astorha) {
		yarab << astorha << endl;
	}
	H.close();
	habal.close();
	ObjectProgram.close();
	start.close();
	OP.open("objectprogram.txt");
	S.open("start.txt");
	FinalObjectProgram.open("FinalObjectProgram.txt");
	ISA.open("yarab.txt");
	while (OP >> totalstring) {
		FinalObjectProgram << totalstring;
		//FinalObjectProgram << "^" << totalstart;
		while (ISA >> tot) {
			FinalObjectProgram << "^" << tot << endl;
			break;
		}
	}
	FinalObjectProgram << "E^" << st;
}

int main() {

	ifstream myfile, myfile2, NUMBER, mix, lexicalRead, CUT2Read, symbolread, readcode, readdir;
	ofstream out, lexical_analysis, CUT2, code, DIR, symbol, print;
	myfile.open("prog.txt");
	out.open("cut.txt");
	lexical_analysis.open("lexical_analysis.txt");
	CUT2.open("CUT2.txt");
	code.open("code.txt");
	DIR.open("DIR.txt");
	symbol.open("symbol.txt");
	print.open("program.txt");
	int flag = 0, error;
	bool Flag;
	string read, stat, type, stat2, str, str2, op, type2, temp, temp2, op2, type3, NUM, dig, word, OP, TYPE;
	string arr[300], arr2[300], arr3[300];
	string cha;
	while (myfile >> read) {
		if (read.at(0) == '$') {
			read.erase();
		}
		else {
			//cout << read << endl;
			out << read << endl;
		}
	}
	myfile2.open("cut.txt");
	while (myfile2 >> stat2) {
		mix.open("mix.txt");
		while (mix >> stat >> type) {
			if (stat == stat2) {
				lexical_analysis << stat << " " << type << endl;
				flag = 0;
				break;
			}
			else {
				str = stat2;
				str2 = type;
				flag = 1;
			}
		}
		mix.close();
		if (flag == 1) {
			lexical_analysis << str << " IS_NOT_VALID " << endl;
		}
	}
	int j = 0, yy;
	string null = " ";
	lexicalRead.open("lexical_analysis.txt");
	while (lexicalRead >> op >> type2) {
		CUT2 << op << " " << type2 << endl;
	}
	CUT2.close();
	//CUT2Read.open("C:\\D\\Collage\\Past Years\\Third year\\First Term\\System Programming\\System_Project\\kolo\\CUT2.txt");
	CUT2Read.open("CUT2.txt");
	while (CUT2Read >> op2 >> type3) {
		if (op2 != ";")
		{
			arr[j] = type3;
			j++;
			//cout << arr[j] << endl;
			//cout << op2 << "  " << type3 << endl;
			//type3.erase();
			yy = j;
		}
		else {
			j = 0;
			for (int i = 0; i < arr->length(); i++) {
				cout << arr[i] << "  " << i << endl;
			}
			for (int i = 0; i < arr->length(); i++) {
				if (arr[i] == "keyword") {
					if (arr[i + 1] == "identifier") {
						if (arr[i + 2] == "operator") {
							if (arr[i + 3] == "identifier") {
								if (arr[i + 4] == "operator") {
									if (arr[i + 5] == "identifier") {
										if (arr[i + 6] == " " || arr[i + 6] == "") {
											Flag = true;
											del(arr, yy);
											break;
										}
										else {
											cout << "syntax error" << endl;
											del(arr, yy);
											_getch();
											exit(0);
										}
									}
									else if (arr[i + 5] == "number") {
										if (arr[i + 6] == " " || arr[i + 6] == "") {
											Flag = true;
											del(arr, yy);
											break;
										}
										else {
											cout << "syntax error" << endl;
											del(arr, yy);
											_getch();
											exit(0);
										}
									}
									else {
										cout << "Syntax error " << endl;
										cout << "It must be <keyword> <identifier> <operator> <identifier> <operator> <identifier> or <number> not <keyword> <identifier> <operator> <identifier> <operator> <" << arr[i + 5] << ">" << endl;
										del(arr, yy);
										_getch();
										exit(0);
									}
								}
								// warning
								else if (arr[i + 4] == " " || arr[i + 4] == "") {
									Flag = true;
									del(arr, yy);
									break;
								}
								else {
									cout << "Syntax error " << endl;
									cout << "It must be <keyword> <identifier> <operator> <identifier> <operator> not <keyword> <identifier> <operator> <identifier> <" << arr[i + 4] << ">" << endl;
									del(arr, yy);
									_getch();
									exit(0);
								}
							}
							else if (arr[i + 3] == "number") {
								if (arr[i + 4] == "operator") {
									if (arr[i + 5] == "identifier") {
										if (arr[i + 6] == " " || arr[i + 6] == "") {
											Flag = true;
											del(arr, yy);
											break;
										}
										else {
											cout << "syntax error" << endl;
											del(arr, yy);
											_getch();
											exit(0);
										}
									}
									else if (arr[i + 5] == "number") {
										if (arr[i + 6] == " " || arr[i + 6] == "") {
											Flag = true;
											del(arr, yy);
											break;
										}
										else {
											cout << "syntax error" << endl;
											del(arr, yy);
											_getch();
											exit(0);
										}
									}
									else {
										cout << "Syntax error " << endl;
										cout << "It must be <keyword> <identifier> <operator> <number> <operator> <identifier> or <number> not <keyword> <identifier> <operator> <number> <operator> <" << arr[i + 5] << ">" << endl;
										del(arr, yy);
										_getch();
										exit(0);
									}
								}
								else if (arr[i + 4] == " " || arr[i + 4] == "") {
									Flag = true;
									del(arr, yy);
									break;
								}
								else {
									cout << "Syntax error " << endl;
									cout << "It must be <keyword> <identifier> <operator> <number> <operator> not <keyword> <identifier> <operator> <number> <" << arr[i + 4] << ">" << endl;
									del(arr, yy);
									_getch();
									exit(0);
								}
							}
							else {
								cout << "Syntax error " << endl;
								cout << "It must be <keyword> <identifier> <operator> <identifier> or <number> not <keyword> <identifier> <operator> <" << arr[i + 3] << ">" << endl;
								del(arr, yy);
								_getch();
								exit(0);
							}
						}
						else if (arr[i + 2] == " " || arr[i + 2] == "") {
							Flag = true;
							del(arr, yy);
							break;
						}
						else {
							cout << "Syntax error " << endl;
							cout << "It must be <keyword> <identifier> <operator> not <keyword> <identifier> <" << arr[i + 2] << ">" << endl;
							del(arr, yy);
							_getch();
							exit(0);
						}
					}
					else if (arr[i + 1] == "delimeter") {
						if (arr[i + 2] == "identifier") {
							if (arr[i + 3] == "operator2") {
								if (arr[i + 4] == "number") {
									if (arr[i + 5] == "delimeter") {
										if (arr[i + 6] == "delimeter") {
											//cout << arr[i + 7] << " " << arr[i + 8] << " " << arr[i + 9] << " " << arr[i + 10];
											if (arr[i + 7] == "identifier") {
												if (arr[i + 8] == "operator") {
													if (arr[i + 9] == "identifier") {
														if (arr[i + 10] == "operator") {
															if (arr[i + 11] == "identifier") {
																if (arr[i + 12] == "delimeter") {
																	if (arr[i + 13] == " " || arr[i + 13] == "") {
																		Flag = true;
																		del(arr, yy);
																		break;
																	}
																	else {
																		cout << "syntax error" << endl;
																		del(arr, yy);
																		_getch();
																		exit(0);
																	}
																}
																else {
																	cout << "Syntax error " << endl;
																	del(arr, yy);
																	_getch();
																	exit(0);
																}
															}
															else if (arr[i + 11] == "number") {
																if (arr[i + 12] == "delimeter") {
																	if (arr[i + 13] == " " || arr[i + 13] == "") {
																		Flag = true;
																		del(arr, yy);
																		break;

																	}
																	else {
																		cout << "syntax error" << endl;
																		del(arr, yy);
																		_getch();
																		exit(0);
																	}
																}
																else {
																	cout << "Syntax error " << endl;
																	del(arr, yy);
																	_getch();
																	exit(0);
																}
															}
															else {
																cout << "Syntax error " << endl;
																cout << "It must be <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <identifier> <operator> " << endl;
																cout << "<identifier> <operator> <identifier> or <number>" << endl;
																cout << " not <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <identifier> <operator> <identifier> <operator> <" << arr[i + 11] << ">" << endl;
																del(arr, yy);
																_getch();
																exit(0);
															}
														}
														else if (arr[i + 10] == "delimeter") {
															if (arr[i + 11] == " " || arr[i + 11] == "") {
																Flag = true;
																del(arr, yy);
																break;
															}
															else {
																cout << "syntax error" << endl;
																_getch();
																exit(0);
															}
														}
														else {
															cout << "Syntax error " << endl;
															cout << "It must be <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <identifier> <operator> " << endl;
															cout << "<identifier> <operator> or <delimeter>" << endl;
															cout << " not <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <identifier> <operator> <identifier> <" << arr[i + 10] << ">" << endl;
															del(arr, yy);
															_getch();
															exit(0);
														}
													}
													else if (arr[i + 9] == "number") {
														if (arr[i + 10] == "operator") {
															if (arr[i + 11] == "identifier") {
																if (arr[i + 12] == "delimeter") {
																	if (arr[i + 13] == " " || arr[i + 13] == "") {
																		Flag = true;
																		del(arr, yy);
																		break;
																	}
																	else {
																		cout << "syntax error" << endl;
																		del(arr, yy);
																		_getch();
																		exit(0);
																	}
																}
																else {
																	cout << "Syntax error " << endl;
																	del(arr, yy);
																	_getch();
																	exit(0);
																}
															}
															else if (arr[i + 11] == "number") {
																if (arr[i + 12] == "delimeter") {
																	if (arr[i + 13] == " " || arr[i + 13] == "") {
																		Flag = true;
																		del(arr, yy);
																		break;
																	}
																	else {
																		cout << "syntax error" << endl;
																		del(arr, yy);
																		_getch();
																		exit(0);
																	}
																}
																else {
																	cout << "Syntax error " << endl;
																	del(arr, yy);
																	_getch();
																	exit(0);
																}
															}
															else {
																cout << "Syntax error " << endl;
																cout << "It must be <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <identifier> <operator> " << endl;
																cout << "<number> <operator> <identifier> or <number>" << endl;
																cout << " not <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <identifier> <operator> <number> <operator> <" << arr[i + 11] << ">" << endl;
																del(arr, yy);
																_getch();
																exit(0);
															}
														}
														else if (arr[i + 10] == "delimeter") {
															if (arr[i + 11] == " " || arr[i + 11] == "") {
																Flag = true;
																del(arr, yy);
																break;
															}
															else {
																cout << "syntax error" << endl;
																del(arr, yy);
																_getch();
																exit(0);
															}
														}
														else {
															cout << "Syntax error " << endl;
															cout << "It must be <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <identifier> <operator> " << endl;
															cout << "<number> <operator> or <delimeter>" << endl;
															cout << " not <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <identifier> <operator> <number> <" << arr[i + 10] << ">" << endl;
															del(arr, yy);
															_getch();
															exit(0);
														}
													}
													else {
														cout << "Syntax error " << endl;
														cout << "It must be <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <identifier> <operator> " << endl;
														cout << "<identifier> or <number>" << endl;
														cout << " not <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <identifier> <operator> <" << arr[i + 9] << ">" << endl;
														del(arr, yy);
														_getch();
														exit(0);
													}
												}
												else {
													cout << "Syntax error " << endl;
													cout << "It must be <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <identifier> <operator>" << endl;
													cout << " not <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <identifier> <" << arr[i + 8] << ">" << endl;
													del(arr, yy);
													_getch();
													exit(0);
												}
											}
											else {
												cout << "Syntax error " << endl;
												cout << "It must be <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <identifier>" << endl;
												cout << " not <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter> <" << arr[i + 7] << ">" << endl;
												del(arr, yy);
												_getch();
												exit(0);
											}
										}
										else {
											cout << "Syntax error " << endl;
											cout << "It must be <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <delimeter>" << endl;
											cout << " not <keyword> <delimeter> <identifier> <operator2> <number> <delimeter> <" << arr[i + 6] << ">" << endl;
											del(arr, yy);
											_getch();
											exit(0);
										}
									}
									else {
										cout << "Syntax error " << endl;
										cout << "It must be <keyword> <delimeter> <identifier> <operator2> <number> <delimeter>" << endl;
										cout << " not <keyword> <delimeter> <identifier> <operator2> <number> <" << arr[i + 5] << ">" << endl;
										del(arr, yy);
										_getch();
										exit(0);
									}
								}
								else if (arr[i + 4] == "identifier") {
									if (arr[i + 5] == "delimeter") {
										if (arr[i + 6] == "delimeter") {
											if (arr[i + 7] == "identifier") {
												if (arr[i + 8] == "operator") {
													if (arr[i + 9] == "identifier") {
														if (arr[i + 10] == "operator") {
															if (arr[i + 11] == "identifier") {
																if (arr[i + 12] == "delimeter") {
																	if (arr[i + 13] == " " || arr[i + 13] == "") {
																		Flag = true;
																		del(arr, yy);
																		break;
																	}
																	else {
																		cout << "syntax error" << endl;
																		del(arr, yy);
																		_getch();
																		exit(0);
																	}
																}
																else {
																	cout << "Syntax error " << endl;
																	del(arr, yy);
																	_getch();
																	exit(0);
																}
															}
															else if (arr[i + 11] == "number") {
																if (arr[i + 12] == "delimeter") {
																	if (arr[i + 13] == " " || arr[i + 13] == "") {
																		Flag = true;
																		del(arr, yy);
																		break;
																	}
																	else {
																		cout << "syntax error" << endl;
																		del(arr, yy);
																		_getch();
																		exit(0);
																	}
																}
																else {
																	cout << "Syntax error " << endl;
																	del(arr, yy);
																	_getch();
																	exit(0);
																}
															}
															else {
																cout << "Syntax error " << endl;
																cout << "It must be <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <identifier> <operator> " << endl;
																cout << "<identifier> <operator> <idenifier> or <number>" << endl;
																cout << " not <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <identifier> <operator> <identifier> <operator> <" << arr[i + 10] << ">" << endl;
																del(arr, yy);
																_getch();
																exit(0);
															}
														}
														else if (arr[i + 10] == "delimeter") {
															cout << arr[i + 11];
															if (arr[i + 11] == " " || arr[i + 11] == "") {
																Flag = true;
																del(arr, yy);
																break;
															}
															else {
																cout << "syntax error" << endl;
																del(arr, yy);
																_getch();
																exit(0);
															}
														}
														else {
															cout << "Syntax error " << endl;
															cout << "It must be <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <identifier> <operator> " << endl;
															cout << "<identifier> <operator> or <delimeter>" << endl;
															cout << " not <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <identifier> <operator> <identifier> <" << arr[i + 10] << ">" << endl;
															del(arr, yy);
															_getch();
															exit(0);
														}
													}
													else if (arr[i + 9] == "number") {
														if (arr[i + 10] == "operator") {
															if (arr[i + 11] == "identifier") {
																if (arr[i + 12] == "delimeter") {
																	if (arr[i + 13] == " " || arr[i + 13] == "") {
																		Flag = true;
																		del(arr, yy);
																		break;
																	}
																	else {
																		cout << "syntax error" << endl;
																		_getch();
																		exit(0);
																	}
																}
																else {
																	cout << "Syntax error " << endl;
																	del(arr, yy);
																	_getch();
																	exit(0);
																}
															}
															else if (arr[i + 11] == "number") {
																if (arr[i + 12] == "delimeter") {
																	if (arr[i + 13] == " " || arr[i + 13] == "") {
																		Flag = true;
																		del(arr, yy);
																		break;
																	}
																	else {
																		cout << "syntax error" << endl;
																		del(arr, yy);
																		_getch();
																		exit(0);
																	}
																}
																else {
																	cout << "Syntax error " << endl;
																	del(arr, yy);
																	_getch();
																	exit(0);
																}
															}
															else {
																cout << "Syntax error " << endl;
																cout << "It must be <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <identifier> <operator> " << endl;
																cout << "<number> <operator> <identifier> or <number>" << endl;
																cout << " not <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <identifier> <operator> <number> <operator> <" << arr[i + 11] << ">" << endl;
																del(arr, yy);
																_getch();
																exit(0);
															}
														}
														else if (arr[i + 10] == "delimeter") {
															if (arr[i + 11] == " " || arr[i + 11] == "") {
																Flag = true;
																del(arr, yy);
																break;
															}
															else {
																cout << "syntax error" << endl;
																del(arr, yy);
																_getch();
																exit(0);
															}
														}
														else {
															cout << "Syntax error " << endl;
															cout << "It must be <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <identifier> <operator> " << endl;
															cout << "<number> <operator> or <delimeter>" << endl;
															cout << " not <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <identifier> <operator> <number> <" << arr[i + 10] << ">" << endl;
															del(arr, yy);
															_getch();
															exit(0);
														}
													}
													else {
														cout << "Syntax error " << endl;
														cout << "It must be <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <identifier> <operator> <identifier> or <number>" << endl;
														cout << " not <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <identifier> <operator> <" << arr[i + 9] << ">" << endl;
														del(arr, yy);
														_getch();
														exit(0);
													}
												}
												else {
													cout << "Syntax error " << endl;
													cout << "It must be <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <identifier> <operator>" << endl;
													cout << " not <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <identifier> <" << arr[i + 8] << ">" << endl;
													del(arr, yy);
													_getch();
													exit(0);
												}
											}
											else {
												cout << "Syntax error " << endl;
												cout << "It must be <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <identifier> " << endl;
												cout << " not <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter> <" << arr[i + 7] << ">" << endl;
												del(arr, yy);
												_getch();
												exit(0);
											}
										}
										else {
											cout << "Syntax error " << endl;
											cout << "It must be <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <delimeter" << endl;
											cout << " not <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> <" << arr[i + 6] << ">" << endl;
											del(arr, yy);
											_getch();
											exit(0);
										}
									}
									else {
										cout << "Syntax error " << endl;
										cout << "It must be <keyword> <delimeter> <identifier> <operator2> <identifier> <delimeter> " << endl;
										cout << " not <keyword> <delimeter> <identifier> <operator2> <identifier> <" << arr[i + 5] << ">" << endl;
										del(arr, yy);
										_getch();
										exit(0);
									}
								}
								else {
									cout << "Syntax error " << endl;
									cout << "It must be <keyword> <delimeter> <identifier> <operator2> <identifier> or <number> " << endl;
									cout << " not <keyword> <delimeter> <identifier> <operator2> <" << arr[i + 4] << ">" << endl;
									del(arr, yy);
									_getch();
									exit(0);
								}
							}
							else {
								cout << "Syntax error " << endl;
								cout << "It must be <keyword> <delimeter> <identifier> <operator2>" << endl;
								cout << " not <keyword> <delimeter> <identifier> <" << arr[i + 3] << ">" << endl;
								del(arr, yy);
								_getch();
								exit(0);
							}
						}
						else {
							cout << "Syntax error " << endl;
							cout << "It must be <keyword> <delimeter> <identifier>" << endl;
							cout << " not <keyword> <delimeter>  <" << arr[i + 2] << ">" << endl;
							del(arr, yy);
							_getch();
							exit(0);
						}
					}
					else {
						cout << "Syntax error " << endl;
						cout << "It must be <keyword> <delimeter> or <identifier> not <keyword> <" << arr[i + 1] << ">" << endl;
						del(arr, yy);
						_getch();
						exit(0);
					}
				}
				else if (arr[i] == "identifier") {
					if (arr[i + 1] == "operator") {
						if (arr[i + 2] == "identifier") {
							if (arr[i + 3] == "operator") {
								if (arr[i + 4] == "identifier") {
									if (arr[i + 5] == " " || arr[i + 5] == "") {
										Flag = true;
										del(arr, yy);
										break;
									}
									else {
										cout << "syntax error" << endl;
										del(arr, yy);
										_getch();
										exit(0);
									}
								}
								else if (arr[i + 4] == "number") {
									if (arr[i + 5] == " " || arr[i + 5] == "") {
										Flag = true;
										del(arr, yy);
										break;
									}
									else {
										cout << "syntax error" << endl;
										del(arr, yy);
										_getch();
										exit(0);
									}
								}
								else {
									cout << "Syntax error " << endl;
									cout << "It must be <identifier> <operator> <identifier> <operator> <identifier> or <number> not <identifier> <operator> <identifier> <operator> <" << arr[i + 4] << ">" << endl;
									del(arr, yy);
									_getch();
									exit(0);
								}
							}
							// warning
							else if (arr[i + 3] == " " || arr[i + 3] == "") {
								Flag = true;
								del(arr, yy);
								break;
							}
							else {
								cout << "Syntax error " << endl;
								cout << "It must be <identifier> <operator> <identifier> <operator> not <identifier> <operator> <identifier> <" << arr[i + 3] << ">" << endl;
								del(arr, yy);
								_getch();
								exit(0);
							}
						}
						else if (arr[i + 2] == "number") {
							if (arr[i + 3] == "operator") {
								if (arr[i + 4] == "identifier") {
									if (arr[i + 5] == " " || arr[i + 5] == "") {
										Flag = true;
										del(arr, yy);
										break;
									}
									else {
										cout << "syntax error" << endl;
										del(arr, yy);
										_getch();
										exit(0);
									}
								}
								else if (arr[i + 4] == "number") {
									if (arr[i + 5] == " " || arr[i + 5] == "") {
										Flag = true;
										del(arr, yy);
										break;
									}
									else {
										cout << "syntax error" << endl;
										del(arr, yy);
										_getch();
										exit(0);
									}
								}
								else {
									cout << "Syntax error " << endl;
									cout << "It must be <identifier> <operator> <number> <operator> <identifir> or <number> not <identifier> <operator> <number> <operator> <" << arr[i + 4] << ">" << endl;
									del(arr, yy);
									_getch();
									exit(0);
								}
							}
							else if (arr[i + 3] == " " || arr[i + 3] == "") {
								Flag = true;
								del(arr, yy);
								break;
							}
							else {
								cout << "Syntax error " << endl;
								cout << "It must be <identifier> <operator> <number> <operator> not <identifier> <operator> <number> <" << arr[i + 3] << ">" << endl;
								del(arr, yy);
								_getch();
								exit(0);
							}
						}
						else if (arr[i + 3] == " ") {
							Flag = true;
							del(arr, yy);
							break;
						}
						else {
							cout << "Syntax error " << endl;
							cout << "It must be <identifier> <operator> <number> or <identifier> not <identifier> <operator> <" << arr[i + 2] << ">" << endl;
							del(arr, yy);
							_getch();
							exit(0);
						}
					}
					else {
						cout << "Syntax error " << endl;
						cout << "It must be <identifier> <operator> not <identifier> <" << arr[i + 1] << ">" << endl;
						del(arr, yy);
						_getch();
						exit(0);
					}
				}
				else {
					cout << "Syntax error " << endl;
					cout << "It must be <keyword> or <identifier> not <" << arr[i] << ">" << endl;
					del(arr, yy);
					_getch();
					exit(0);
				}
			}
		}
	}
	string newop2[100], newtype3[100];
	int h = 0;
	CUT2Read.close();
	lexicalRead.close();
	lexicalRead.open("C:\\D\\Collage\\Past Years\\Third year\\First Term\\System Programming\\System_Project\\kolo\\lexical_analysis.txt");
	CUT2Read.open("C:\\D\\Collage\\Past Years\\Third year\\First Term\\System Programming\\System_Project\\kolo\\CUT2.txt");
	while (CUT2Read >> op2 >> type3) {
		newop2[h] = op2;
		newtype3[h] = type3;
		//cout << newop2[h] << endl;
		h++;
	}
	int p = h;
	int g = h;
	for (int i = 0; i < p; i++)
	{
		for (int j = i + 1; j < p; j++)
		{
			//If any duplicate found */
			if (newop2[i] == newop2[j])
			{
				// Delete the current duplicate element
				for (int k = j; k < p; k++)
				{
					newop2[k] = newop2[k + 1];
					newtype3[k] = newtype3[k + 1];
				}
				p--;
				j--;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		//cout << newop2[i] << endl;
		symbol << newop2[i] << " " << newtype3[i] << endl;
	}
	symbol.close();
	NUMBER.close();
	symbolread.open("symbol.txt");
	while (symbolread >> OP >> TYPE) {
		if (TYPE == "identifier") {
			DIR << OP << " RESW " << "1 " << endl;
		}
		else if (TYPE == "number") {
			NUMBER.open("numbers.txt");
			while (NUMBER >> dig >> word) {
				if (dig == OP) {
					DIR << word << " WORD " << OP << endl;
				}
			}
			NUMBER.close();
		}
	}
	code << "COPY START 0000" << endl;
	string a;
	int rep;
	CUT2Read.close();
	CUT2Read.open("CUT2.txt");
	while (CUT2Read >> op2 >> type3) {
		if (op2 != ";")
		{
			arr2[j] = op2;
			arr3[j] = type3;
			j++;
			rep = j;
		}
		else {
			j = 0;
			for (int i = 0; i < rep; i++) {
				cout << arr2[i] << " " << i << endl;
			}
			for (int i = 0; i < arr2->length(); i++) {
				// int x = c 
				if (arr2[i] == "int" && ((arr2[i + 1] >= "a" && arr2[i + 1] <= "z") || (arr2[i + 1] >= "A" && arr2[i + 1] <= "Z")) && (arr2[i + 2] == "=") && ((arr2[i + 3] >= "a" && arr2[i + 3] <= "z") || (arr2[i + 3] >= "A" && arr2[i + 3] <= "Z")) && arr2[i + 4] <= " ") {
					//cout << "jjj";
					if (arr2[i + 3] == a) {
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
					}
					else {
						code << "BLANK LDA " << arr2[i + 3] << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				// int x = 9 ;
				else if (arr2[i] == "int" && ((arr2[i + 1] >= "a" && arr2[i + 1] <= "z") || (arr2[i + 1] >= "A" && arr2[i + 1] <= "Z")) && (arr2[i + 2] == "=") && (arr2[i + 3] >= "0" && arr2[i + 3] <= "9") && arr2[i + 4] <= " ") {
					if (arr2[i + 3] == a) {
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
					}
					else {
						cha = loop(arr2[i + 3]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
					}
				}
				// int x = x + c ;
				else if (arr2[i] == "int" && ((arr2[i + 1] >= "a" && arr2[i + 1] <= "z") || (arr2[i + 1] >= "A" && arr2[i + 1] <= "Z")) && (arr2[i + 2] == "=") && ((arr2[i + 3] >= "a" && arr2[i + 3] <= "z") || (arr2[i + 3] >= "A" && arr2[i + 3] <= "Z")) && (arr2[i + 4] == "+") && ((arr2[i + 5] >= "a" && arr2[i + 5] <= "z") || (arr2[i + 5] >= "A" && arr2[i + 5] <= "Z"))) {

					if (a == arr2[i + 3]) {
						code << "BLANK ADD " << arr2[i + 5] << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						//break;
						del(arr2, rep);
						del(arr3, rep);
					}
					else if (a == arr2[i + 5]) {
						code << "BLANK ADD " << arr2[i + 3] << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						//break;
						del(arr2, rep);
						del(arr3, rep);
					}
					else {
						//cout << "kkkkk";
						code << "BLANK LDA " << arr2[i + 3] << endl;
						code << "BLANK ADD " << arr2[i + 5] << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						//break;
						del(arr2, rep);
						del(arr3, rep);
					}
				}
				// int x = m * n ;
				else if (arr2[i] == "int" && ((arr2[i + 1] >= "a" && arr2[i + 1] <= "z") || (arr2[i + 1] >= "A" && arr2[i + 1] <= "Z")) && (arr2[i + 2] == "=") && ((arr2[i + 3] >= "a" && arr2[i + 3] <= "z") || (arr2[i + 3] >= "A" && arr2[i + 3] <= "Z")) && (arr2[i + 4] == "*") && ((arr2[i + 5] >= "a" && arr2[i + 5] <= "z") || (arr2[i + 5] >= "A" && arr2[i + 5] <= "Z"))) {
					if (a == arr2[i + 3]) {
						code << "BLANK MUL " << arr2[i + 5] << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 5]) {
						code << "BLANK MUL " << arr2[i + 3] << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						code << "BLANK LDA " << arr2[i + 3] << endl;
						code << "BLANK MUL " << arr2[i + 5] << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				// int x = 3 * 5 ;
				else if (arr2[i] == "int" && ((arr2[i + 1] >= "a" && arr2[i + 1] <= "z") || (arr2[i + 1] >= "A" && arr2[i + 1] <= "Z")) && (arr2[i + 2] == "=") && (arr2[i + 3] >= "0" && arr2[i + 3] <= "9") && (arr2[i + 4] == "*") && (arr2[i + 5] >= "0" && arr2[i + 5] <= "9")) {
					if (a == arr2[i + 3]) {
						cha = loop(arr2[i + 5]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 5]) {
						cha = loop(arr2[i + 3]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						cha = loop(arr2[i + 3]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 5]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				// int x = 5 + 5 ;
				else if (arr2[i] == "int" && ((arr2[i + 1] >= "a" && arr2[i + 1] <= "z") || (arr2[i + 1] >= "A" && arr2[i + 1] <= "Z")) && (arr2[i + 2] == "=") && (arr2[i + 3] >= "0" && arr2[i + 3] <= "9") && (arr2[i + 4] == "+") && (arr2[i + 5] >= "0" && arr2[i + 5] <= "9")) {
					if (a == arr2[i + 3]) {
						cha = loop(arr2[i + 5]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 5]) {
						cha = loop(arr2[i + 3]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						cha = loop(arr2[i + 3]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 5]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				// int x = x + 4 ;
				else if (arr2[i] == "int" && ((arr2[i + 1] >= "a" && arr2[i + 1] <= "z") || (arr2[i + 1] >= "A" && arr2[i + 1] <= "Z")) && (arr2[i + 2] == "=") && ((arr2[i + 3] >= "a" && arr2[i + 3] <= "z") || (arr2[i + 3] >= "A" && arr2[i + 3] <= "Z")) && (arr2[i + 4] == "+") && (arr2[i + 5] >= "0" && arr2[i + 5] <= "9")) {
					if (a == arr2[i + 3]) {
						cha = loop(arr2[i + 5]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 5]) {
						code << "BLANK ADD " << arr2[i + 3] << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						cha = loop(arr2[i + 5]);
						code << "BLANK LDA " << arr2[i + 3] << endl;
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}

				}
				// int x = x * 4;
				else if (arr2[i] == "int" && ((arr2[i + 1] >= "a" && arr2[i + 1] <= "z") || (arr2[i + 1] >= "A" && arr2[i + 1] <= "Z")) && (arr2[i + 2] == "=") && ((arr2[i + 3] >= "a" && arr2[i + 3] <= "z") || (arr2[i + 3] >= "A" && arr2[i + 3] <= "Z")) && (arr2[i + 4] == "*") && (arr2[i + 5] >= "0" && arr2[i + 5] <= "9")) {
					if (a == arr2[i + 3]) {
						cha = loop(arr2[i + 5]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 5]) {
						code << "BLANK MUL " << arr2[i + 3] << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						cha = loop(arr2[i + 5]);
						code << "BLANK LDA " << arr2[i + 3] << endl;
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				// int x = 4 + c ;
				else if (arr2[i] == "int" && ((arr2[i + 1] >= "a" && arr2[i + 1] <= "z") || (arr2[i + 1] >= "A" && arr2[i + 1] <= "Z")) && (arr2[i + 2] == "=") && ((arr2[i + 3] >= "0" && arr2[i + 3] <= "9")) && (arr2[i + 4] == "+") & ((arr2[i + 5] >= "a" && arr2[i + 5] <= "z") || (arr2[i + 5] >= "A" && arr2[i + 5] <= "Z"))) {
					if (a == arr2[i + 3]) {
						code << "BLANK ADD " << arr2[i + 5] << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 5]) {
						cha = loop(arr2[i + 3]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						cha = loop(arr2[i + 3]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK ADD " << arr2[i + 5] << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				// int x = 3 * c ;
				else if (arr2[i] == "int" && ((arr2[i + 1] >= "a" && arr2[i + 1] <= "z") || (arr2[i + 1] >= "A" && arr2[i + 1] <= "Z")) && (arr2[i + 2] == "=") && ((arr2[i + 3] >= "0" && arr2[i + 3] <= "9")) && (arr2[i + 4] == "*") & ((arr2[i + 5] >= "a" && arr2[i + 5] <= "z") || (arr2[i + 5] >= "A" && arr2[i + 5] <= "Z"))) {
					if (a == arr2[i + 3]) {
						code << "BLANK MUL " << arr2[i + 5] << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 5]) {
						cha = loop(arr2[i + 3]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						cha = loop(arr2[i + 3]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK MUL " << arr2[i + 5] << endl;
						code << "BLANK STA " << arr2[i + 1] << endl;
						a = arr2[i + 1];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				//x = 3 * x ;
				else if (((arr2[i] >= "a" && arr2[i] <= "z") || (arr2[i] >= "A" && arr2[i] <= "Z")) && (arr2[i + 1] == "=") && ((arr2[i + 2] >= "0" && arr2[i + 2] <= "9")) && (arr2[i + 3] == "*") & ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z"))) {
					if (a == arr2[i + 2]) {
						code << "BLANK MUL " << arr2[i + 4] << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 4]) {
						cha = loop(arr2[i + 2]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						cha = loop(arr2[i + 2]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK MUL " << arr2[i + 4] << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				// x = c ;
				else if (((arr2[i] >= "a" && arr2[i] <= "z") || (arr2[i] >= "A" && arr2[i] <= "Z")) && (arr2[i + 1] == "=") && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] <= " ") {
					if (arr2[i + 2] == a) {
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
					}
					else
					{
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
					}
				}
				// x = 3 ;
				else if (((arr2[i] >= "a" && arr2[i] <= "z") || (arr2[i] >= "A" && arr2[i] <= "Z")) && (arr2[i + 1] == "=") && (arr2[i + 2] >= "0" && arr2[i + 2] <= "9") && arr2[i + 3] <= " ") {
					if (arr2[i + 2] == a) {
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
					}
					else
					{
						cha = loop(arr2[i + 2]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
					}
				}
				// x = x + c ;
				else if (((arr2[i] >= "a" && arr2[i] <= "z") || (arr2[i] >= "A" && arr2[i] <= "Z")) && (arr2[i + 1] == "=") && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && (arr2[i + 3] == "+") && ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z"))) {
					//cout << arr2[i + 3];
					if (a == arr2[i + 2]) {
						code << "BLANK ADD " << arr2[i + 4] << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 4]) {
						code << "BLANK ADD " << arr2[i + 2] << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK ADD " << arr2[i + 4] << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				// x = m * n ;
				else if (((arr2[i] >= "a" && arr2[i] <= "z") || (arr2[i] >= "A" && arr2[i] <= "Z")) && (arr2[i + 1] == "=") && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && (arr2[i + 3] == "*") && ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z"))) {
					if (a == arr2[i + 2]) {
						code << "BLANK MUL " << arr2[i + 4] << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 4]) {
						code << "BLANK MUL " << arr2[i + 2] << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK MUL " << arr2[i + 4] << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				// x = 3 * 5 ;
				else if (((arr2[i] >= "a" && arr2[i] <= "z") || (arr2[i] >= "A" && arr2[i] <= "Z")) && (arr2[i + 1] == "=") && (arr2[i + 2] >= "0" && arr2[i + 2] <= "9") && (arr2[i + 3] == "*") && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9")) {
					if (a == arr2[i + 2]) {
						cha = loop(arr2[i + 4]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 4]) {
						cha = loop(arr2[i + 2]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						cha = loop(arr2[i + 2]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 4]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				// x = 5 + 5 ;
				else if (((arr2[i] >= "a" && arr2[i] <= "z") || (arr2[i] >= "A" && arr2[i] <= "Z")) && (arr2[i + 1] == "=") && (arr2[i + 2] >= "0" && arr2[i + 2] <= "9") && (arr2[i + 3] == "+") && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9")) {
					if (a == arr2[i + 2]) {
						cha = loop(arr2[i + 4]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 4]) {
						cha = loop(arr2[i + 2]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						cha = loop(arr2[i + 2]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 4]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				//  x = x + 4 ;
				else if (((arr2[i] >= "a" && arr2[i] <= "z") || (arr2[i] >= "A" && arr2[i] <= "Z")) && (arr2[i + 1] == "=") && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && (arr2[i + 3] == "+") && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9")) {
					if (a == arr2[i + 2]) {
						cha = loop(arr2[i + 4]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 4]) {
						code << "BLANK ADD " << arr2[i + 2] << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						cha = loop(arr2[i + 4]);
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				// x = x * 4;
				else if (((arr2[i] >= "a" && arr2[i] <= "z") || (arr2[i] >= "A" && arr2[i] <= "Z")) && (arr2[i + 1] == "=") && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && (arr2[i + 3] == "*") && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9")) {
					if (a == arr2[i + 2]) {
						cha = loop(arr2[i + 4]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 4]) {
						code << "BLANK MUL " << arr2[i + 2] << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						cha = loop(arr2[i + 4]);
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				// x = 4 + c ;
				else if (((arr2[i] >= "a" && arr2[i] <= "z") || (arr2[i] >= "A" && arr2[i] <= "Z")) && (arr2[i + 1] == "=") && ((arr2[i + 2] >= "0" && arr2[i + 2] <= "9")) && (arr2[i + 3] == "+") & ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z"))) {
					if (a == arr2[i + 2]) {
						code << "BLANK ADD " << arr2[i + 4] << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else if (a == arr2[i + 4]) {
						cha = loop(arr2[i + 2]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
					else {
						cha = loop(arr2[i + 2]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK ADD " << arr2[i + 4] << endl;
						code << "BLANK STA " << arr2[i] << endl;
						a = arr2[i];
						del(arr2, rep);
						del(arr3, rep);
						//break;
					}
				}
				// if( x == 3 ) { x = 3 };
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9") && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && (arr2[i + 9] >= "0" && arr2[i + 9] <= "9") && arr2[i + 10] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						cha = loop(arr2[i + 4]);
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						cha = loop(arr2[i + 4]);
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if( x == a ) { x = 3 };
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z")) && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && (arr2[i + 9] >= "0" && arr2[i + 9] <= "9") && arr2[i + 10] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if( x == a ) { x = d };
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z")) && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && ((arr2[i + 9] >= "a" && arr2[i + 9] <= "z") || (arr2[i + 9] >= "A" && arr2[i + 9] <= "Z")) && arr2[i + 10] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if( x == 3 ) { x = d };
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9") && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && ((arr2[i + 9] >= "a" && arr2[i + 9] <= "z") || (arr2[i + 9] >= "A" && arr2[i + 9] <= "Z")) && arr2[i + 10] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						cha = loop(arr2[i + 4]);
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						cha = loop(arr2[i + 4]);
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == 3 ) { x = r + u } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9") && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && ((arr2[i + 9] >= "a" && arr2[i + 9] <= "z") || (arr2[i + 9] >= "A" && arr2[i + 9] <= "Z")) && arr2[i + 10] == "+" && ((arr2[i + 11] >= "a" && arr2[i + 11] <= "z") || (arr2[i + 11] >= "A" && arr2[i + 11] <= "Z")) && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						cha = loop(arr2[i + 4]);
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK ADD " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK ADD " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						cha = loop(arr2[i + 4]);
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK ADD " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == 3 ) { x = 3 + u } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9") && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && (arr2[i + 9] >= "0" && arr2[i + 9] <= "9") && arr2[i + 10] == "+" && ((arr2[i + 11] >= "a" && arr2[i + 11] <= "z") || (arr2[i + 11] >= "A" && arr2[i + 11] <= "Z")) && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						cha = loop(arr2[i + 4]);
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK ADD " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK ADD " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						cha = loop(arr2[i + 4]);
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK ADD " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == 3 ) { x = r + 3 } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9") && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && ((arr2[i + 9] >= "a" && arr2[i + 9] <= "z") || (arr2[i + 9] >= "A" && arr2[i + 9] <= "Z")) && arr2[i + 10] == "+" && (arr2[i + 11] >= "0" && arr2[i + 11] <= "9") && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						cha = loop(arr2[i + 4]);
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						cha = loop(arr2[i + 4]);
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == 3 ) { x = 3 + 3 } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9") && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && (arr2[i + 9] >= "0" && arr2[i + 9] <= "9") && arr2[i + 10] == "+" && (arr2[i + 11] >= "0" && arr2[i + 11] <= "9") && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						cha = loop(arr2[i + 4]);
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						cha = loop(arr2[i + 4]);
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == 3 ) { x = 3 * 3 } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9") && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && (arr2[i + 9] >= "0" && arr2[i + 9] <= "9") && arr2[i + 10] == "*" && (arr2[i + 11] >= "0" && arr2[i + 11] <= "9") && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						cha = loop(arr2[i + 4]);
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK MULL " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						cha = loop(arr2[i + 4]);
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == 3 ) { x = r * 3 } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9") && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && ((arr2[i + 9] >= "a" && arr2[i + 9] <= "z") || (arr2[i + 9] >= "A" && arr2[i + 9] <= "Z")) && arr2[i + 10] == "*" && (arr2[i + 11] >= "0" && arr2[i + 11] <= "9") && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						cha = loop(arr2[i + 4]);
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						cha = loop(arr2[i + 4]);
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == 3 ) { x = 3 * u } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9") && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && (arr2[i + 9] >= "0" && arr2[i + 9] <= "9") && arr2[i + 10] == "*" && ((arr2[i + 11] >= "a" && arr2[i + 11] <= "z") || (arr2[i + 11] >= "A" && arr2[i + 11] <= "Z")) && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						cha = loop(arr2[i + 4]);
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK MUL " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK MUL " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						cha = loop(arr2[i + 4]);
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK MUL " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == 3 ) { x = r * u } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && (arr2[i + 4] >= "0" && arr2[i + 4] <= "9") && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && ((arr2[i + 9] >= "a" && arr2[i + 9] <= "z") || (arr2[i + 9] >= "A" && arr2[i + 9] <= "Z")) && arr2[i + 10] == "*" && ((arr2[i + 11] >= "a" && arr2[i + 11] <= "z") || (arr2[i + 11] >= "A" && arr2[i + 11] <= "Z")) && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						cha = loop(arr2[i + 4]);
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK MUL " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK MUL " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						cha = loop(arr2[i + 4]);
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << cha << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK MUL " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == C ) { x = r + u } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z")) && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && ((arr2[i + 9] >= "a" && arr2[i + 9] <= "z") || (arr2[i + 9] >= "A" && arr2[i + 9] <= "Z")) && arr2[i + 10] == "+" && ((arr2[i + 11] >= "a" && arr2[i + 11] <= "z") || (arr2[i + 11] >= "A" && arr2[i + 11] <= "Z")) && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK ADD " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK ADD " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK ADD " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == c ) { x = 3 + u } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z")) && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && (arr2[i + 9] >= "0" && arr2[i + 9] <= "9") && arr2[i + 10] == "+" && ((arr2[i + 11] >= "a" && arr2[i + 11] <= "z") || (arr2[i + 11] >= "A" && arr2[i + 11] <= "Z")) && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK ADD " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK ADD " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK ADD " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == c ) { x = r + 3 } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z")) && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && ((arr2[i + 9] >= "a" && arr2[i + 9] <= "z") || (arr2[i + 9] >= "A" && arr2[i + 9] <= "Z")) && arr2[i + 10] == "+" && (arr2[i + 11] >= "0" && arr2[i + 11] <= "9") && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == c ) { x = 3 + 3 } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z")) && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && (arr2[i + 9] >= "0" && arr2[i + 9] <= "9") && arr2[i + 10] == "+" && (arr2[i + 11] >= "0" && arr2[i + 11] <= "9") && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK ADD " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == c ) { x = 3 * 3 } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z")) && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && (arr2[i + 9] >= "0" && arr2[i + 9] <= "9") && arr2[i + 10] == "*" && (arr2[i + 11] >= "0" && arr2[i + 11] <= "9") && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == c ) { x = r * 3 } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z")) && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && ((arr2[i + 9] >= "a" && arr2[i + 9] <= "z") || (arr2[i + 9] >= "A" && arr2[i + 9] <= "Z")) && arr2[i + 10] == "*" && (arr2[i + 11] >= "0" && arr2[i + 11] <= "9") && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						cha = loop(arr2[i + 11]);
						code << "BLANK MUL " << cha << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == c ) { x = 3 * u } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z")) && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && (arr2[i + 9] >= "0" && arr2[i + 9] <= "9") && arr2[i + 10] == "*" && ((arr2[i + 11] >= "a" && arr2[i + 11] <= "z") || (arr2[i + 11] >= "A" && arr2[i + 11] <= "Z")) && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK MUL " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK MUL " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						cha = loop(arr2[i + 9]);
						code << "BLANK LDA " << cha << endl;
						code << "BLANK MUL " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
				// if ( x == c ) { x = r * u } ;
				else if (arr2[i] == "if" && arr2[i + 1] == "(" && ((arr2[i + 2] >= "a" && arr2[i + 2] <= "z") || (arr2[i + 2] >= "A" && arr2[i + 2] <= "Z")) && arr2[i + 3] == "==" && ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z")) && arr2[i + 5] == ")" && arr2[i + 6] == "{" && ((arr2[i + 7] >= "a" && arr2[i + 7] <= "z") || (arr2[i + 7] >= "A" && arr2[i + 7] <= "Z")) && arr2[i + 8] == "=" && ((arr2[i + 9] >= "a" && arr2[i + 9] <= "z") || (arr2[i + 9] >= "A" && arr2[i + 9] <= "Z")) && arr2[i + 10] == "*" && ((arr2[i + 11] >= "a" && arr2[i + 11] <= "z") || (arr2[i + 11] >= "A" && arr2[i + 11] <= "Z")) && arr2[i + 12] == "}") {
					//cout << "hhhh";
					if (arr2[i + 2] == a) {
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK MUL " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else if (arr2[i + 4] == a) {
						code << "BLANK COMP " << arr2[i + 2] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK MUL " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
					else {
						code << "BLANK LDA " << arr2[i + 2] << endl;
						code << "BLANK COMP " << arr2[i + 4] << endl;
						code << "BLANK JGT " << "EXIT" << endl;
						code << "BLANK JLT " << "EXIT" << endl;
						code << "BLANK LDA " << arr2[i + 9] << endl;
						code << "BLANK MUL " << arr2[i + 11] << endl;
						code << "BLANK STA " << arr2[i + 7] << endl;
						code << "EXIT " << "BLANK " << "BLANK" << endl;
						a = arr2[i + 7];
					}
				}
			}
		}
	}
	string dir1, dir2, dir3, code1, code2, code3;
	code.close();
	DIR.close();
	readcode.open("code.txt");
	readdir.open("DIR.txt");
	while (readcode >> code1 >> code2 >> code3) {
		print << code1 << " " << code2 << " " << code3 << endl;
	}
	while (readdir >> dir1 >> dir2 >> dir3) {
		print << dir1 << " " << dir2 << " " << dir3 << endl;
	}
	print << "BLANK END 0000";
	/*CUT2Read.close();
	CUT2Read.open("C:\\D\\Collage\\Past Years\\Third year\\First Term\\System Programming\\System_Project\\kolo\\CUT2.txt");
	while (CUT2Read >> op2 >> type3) {
	cout << op2 << "  " << type3 << endl;
	}*/
	assembler();
	_getch();
	return 0;
	// ((arr2[i + 4] >= "a" && arr2[i + 4] <= "z") || (arr2[i + 4] >= "A" && arr2[i + 4] <= "Z"))
	// (arr2[i + 4] >= "0" && arr2[i + 4] <= "9")
}
