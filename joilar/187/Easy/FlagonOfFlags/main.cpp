
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::istream;
using std::ostream;
using std::string;
using std::stringstream;

//========================================
// Flag
//
// This class contains the available flags
// which may be passed to this program.
//========================================

struct Flag {
	string short_form = "";
	string long_form = "";
	bool accepts_parameter = false;
};

//========================================
// Flags
//
// This is a container class for the available flags
// which may be passed to this program.
//========================================

class Flags {
	private:
		std::map< string, std::shared_ptr<Flag> > flags;
	public:
		Flags(istream&);

		auto begin () -> decltype( flags.begin() ) { return flags.begin(); }
		auto end () -> decltype( flags.end() ) { return flags.end(); }

		auto find (const string& key) -> decltype( flags.end() )
			{ return flags.find(key); }

		auto find (const char key) -> decltype( flags.end() )
			{ string s; s = key; return flags.find(s); }

		std::shared_ptr<Flag> operator[] (const string& key) { return flags[key]; }
		std::shared_ptr<Flag> operator[] (const char key)
			{ string s; s = key; return flags[s]; }
};

Flags::Flags(istream& in) {
	// Get the number of lines to read to build our table of flags.
	string line;
	std::getline(in, line);
	int num_lines = std::stoi(line);

	// Read the lines into our table.
	while (num_lines > 0) {
		std::getline(in, line);
		auto flag = std::make_shared<Flag> ();

		if (line[0] == '*') {
			flag->accepts_parameter = true;
			line.erase(0, 1);
		}

		int delim_pos = line.find(':');
		flag->short_form = line.substr(0, delim_pos);
		flag->long_form = line.substr(delim_pos + 1);

		flags[ flag->short_form ] = flag;
		flags[ flag->long_form ] = flag;

		num_lines--;
	}
}

//========================================
// Argument
//
// This class contains an argument which
// has been passed to this program.
//========================================

struct Argument {
	string flag = "";
	string parameter = "";
};

//========================================
// Arguments
//
// This is a container class which contains the actual flags which
// were passed to this invocation of the program.
//========================================

class Arguments {
	private:
		std::vector< std::shared_ptr<Argument> > arguments;
	public:
		Arguments(istream&, Flags&);
		friend ostream& operator<< (ostream& out, const Arguments& args);
};

Arguments::Arguments(istream& in, Flags& flags) {
	string line;
	std::getline(in, line);
	stringstream line_ss(line);

	std::vector<string> tokens;
	string token;

	while ( getline(line_ss, token, ' ') ) {
		tokens.push_back(token);
	}

	for ( auto it = tokens.begin(); it != tokens.end(); it++ ) {
		token = *it;

		// Figure out whether each token is a:
		// short form flag - prefix '-'
		// long form flag - prefix '--'
		// parameter - no prefix
		if ( token[0] == '-' ) {
			if ( token[1] == '-' ) {
				// prefix is '--' - this is a long form flag
				token.erase(0, 2); // remove prefix

				auto argument = std::make_shared<Argument> ();
				int delim_pos = token.find('=');

				argument->flag = token.substr(0, delim_pos);

				auto flag_it = flags.find( argument->flag );

				if (flag_it != flags.end()) {
					auto flag = flag_it->second;
					if (flag->accepts_parameter) {
						argument->parameter = token.substr(delim_pos + 1);
					}
				}

				arguments.push_back(argument);
			} else {
				// prefix is '-' - this token is one or more short form flags
				token.erase(0, 1); // remove prefix

				for ( auto c = token.begin(); c != token.end(); c++ ) {
					auto flag_it = flags.find( *c );
					if (flag_it != flags.end()) {
						auto flag = flag_it->second;
						auto argument = std::make_shared<Argument> ();

						argument->flag = flag->long_form;

						if (flag->accepts_parameter) {
							it++;
							argument->parameter = *it;
						}

						arguments.push_back(argument);
					}
				}
			}
		} else {
			// no prefix - this is a parameter to the program
			auto argument = std::make_shared<Argument> ();
			argument->parameter = token;
			arguments.push_back(argument);
		}
	}
}

ostream& operator<< (ostream& out, const Arguments& args) {
	for ( auto it = args.arguments.begin(); it != args.arguments.end(); it++ ) {
		auto arg = *it;
		if ( arg->flag != "" ) {
			out << "flag: " << arg->flag;

			if ( arg->parameter != "" ) {
				out << " (value: " << arg->parameter << ")";
			}

			out << endl;
		} else if ( arg->parameter != "" ) {
			out << "parameter: " << arg->parameter << endl;
		}
	}
	return out;
}

//========================================
// main
//========================================

int main (int argc, char** argv) {
	Flags flags(cin);
	Arguments arguments(cin, flags);
	cout << arguments << flush;
	return 0;
}

