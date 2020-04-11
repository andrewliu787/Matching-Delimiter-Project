#include <iostream>
#include <cassert>
#include "project_1.hpp"

//Function declarations
int main();
void print_program();
bool does_delimiter_match( char delimiter );
bool do_delimiters_nest();

int main(){
	print_program();
	do_delimiters_nest();

	return 0;
}

void print_program(){

	//initialize a placeholder char
	char curr;

	//begin reading through file
	ece150::start_reading_file();

	//stepping through the file and printing out  each character
	while(!ece150::at_eof()){

		curr = ece150::get_next_character();

		std::cout << curr;

	}

}

bool does_delimiter_match(char delimiter){

	//identify the possible types of delimiters
		char oPara = '(';
		char cPara = ')';
		char oBrack = '[';
		char cBrack = ']';
		char oBrace = '{';
		char cBrace = '}';
		char curr;

	//create counters for each type of delimiter
		int count = 0;


	//start reading the file
		ece150::start_reading_file();

	//start looping
		while(!ece150::at_eof()){

	//Initialize the current char

		curr = ece150::get_next_character();


	//check if the provided parameter is a delimiter
		if(delimiter == oPara || delimiter == oBrack || delimiter == oBrace ){


	//keep track of the number of occurrences of each type of delimiter
			if(delimiter == oPara){
				if(curr == oPara){
					++count;
				}

				if(curr == cPara){
					--count;
				}

				//check for unmatched
				if(count < 0){
					std::cout << "Unmatched " << cPara << std::endl;
					count = 0;
				}
			}

			if(delimiter == oBrack){

				if(curr == oBrack){
					++count;
				}

				if(curr == cBrack){
					--count;
				}

				if(count < 0){
					std::cout << "Unmatched " << cBrack << std::endl;
					count = 0;
				}

			}

			if(delimiter == oBrace){
				if(curr ==oBrace){
					++count;
				}

				if(curr == cBrace){
					--count;
				}

				//check for unmatched
				if(count < 0){
					std::cout << "Unmatched " << cBrace << std::endl;
					count = 0;
			}

	}
	}
	else {

		return false;
	}
		}



		if(delimiter == oPara){
					if(count > 0){
						std::string s = "";
					//concatenate the number of closing delimiters missing
						for(int i = 0; i <= count; ++i){
							s += cPara;
						}
							std::cout << "Missing " << cPara << std::endl;
					}
		}

		if(delimiter == oBrack){

				if(count > 0){
				std::string s = "";
				//concatenate the number of closing delimiters missing
				for(int i = 0; i <= count; ++i){
					s += cBrack;
				}
					std::cout << "Missing " << cBrack << std::endl;
				}

		}

		if(delimiter == oBrace){
				if(count > 0){
				std::string s = "";
				//concatenate the number of closing delimiters missing
				for(int i = 0; i <= count; ++i){
					s += cBrace;
				}
					std::cout << "Missing " << cBrace << std::endl;
				}
		}

	return true;
}

bool do_delimiters_nest(){

	//identify the possible types of delimiters
		char oPara = '(';
		char cPara = ')';
		char oBrack = '[';
		char cBrack = ']';
		char oBrace = '{';
		char cBrace = '}';

	//initialize a place holder char
		char curr;

	//initialize a table
	ece150::initialize_table();

	//start by reading the file
	ece150::start_reading_file();

	//begin looping through
	while(!ece150::at_eof()){

		curr = ece150::get_next_character();

		//if the current character is an opening delimiter, place it on the table

		if(curr == oPara || curr == oBrack || curr == oBrace){

			ece150::place_character(curr);

		}

		//if the current character is a closing delimiter, verify if it's a match to the last opening entry
		if(curr == cPara || curr == cBrack || curr == cBrace){

			if(ece150::get_right_most_character() == oPara && curr == cPara){

				ece150::erase_right_most_character();

			}else if(ece150::get_right_most_character() == oBrack && curr == cBrack){

				ece150::erase_right_most_character();

			}else if(ece150::get_right_most_character() == oBrace && curr == cBrace){

					ece150::erase_right_most_character();

			}else{

				std::cout << "Unmatched " << curr << std::endl;
			}
		}
	}

	if(ece150::is_table_empty()){

		return true;

	}else{

		std::string s = "";
		while(!ece150::is_table_empty()){
			char d;
			curr = ece150::get_right_most_character();
			if(curr == oPara){
				d = cPara;

				s += d;
			}

			if(curr == oBrack){
				d = cBrack;
				s += d;
			}

			if(curr == oBrace){
				d = cBrace;
				s += d;

			}

			ece150::erase_right_most_character();

		}

		std::cout << "Missing " << s << std::endl;

		return false;

	}

}

