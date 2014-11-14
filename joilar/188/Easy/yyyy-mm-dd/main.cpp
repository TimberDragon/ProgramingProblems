
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
using std::string;
using std::stoi;
using std::ostream;

//========================================
// ISO8601Converter - Base class & conversion interface.
//========================================

class ISO8601Converter {
    public:
        virtual bool convert (const string&) = 0;
        friend ostream& operator<< (ostream&, const ISO8601Converter&);

    protected:
        int day, month, year;
        static const std::unordered_map<string, int> month_map;
};

const std::unordered_map<string, int> ISO8601Converter::month_map = {
    { "Jan", 1 }, { "Feb", 2 }, { "Mar", 3 }, { "Apr", 4 },
    { "May", 5 }, { "Jun", 6 }, { "Jul", 7 }, { "Aug", 8 },
    { "Sep", 9 }, { "Oct", 10 }, { "Nov", 11 }, { "Dec", 12 }
};

ostream& operator<< (ostream& out, const ISO8601Converter& converter) {
    out
        << setw(4) << converter.year
        << "-" << setfill('0') << setw(2) << converter.month
        << "-" << setfill('0') << setw(2) << converter.day;

    return out;
}

//========================================
// Conversion class implementations.
//========================================

class DashConverter : public ISO8601Converter {
    public:
        virtual bool convert (const string& s) {
            if (s[4] == '-') {
                year = stoi( s.substr(0, 4) );
                month = stoi( s.substr(5, 2) );
                day = stoi( s.substr(8, 2) );
                return true;
            }
            return false;
        }
};

class SlashConverter : public ISO8601Converter {
    public:
        virtual bool convert (const string& s) {
            if (s[2] == '/') {
                month = stoi( s.substr(0, 2) );
                day = stoi( s.substr(3, 2) );
                year = stoi( s.substr(6, 2) );
                ( year >= 50 ) ? year += 1900 : year += 2000;
                return true;
            }
            return false;
        }
};

class SharpConverter : public ISO8601Converter {
    public:
        virtual bool convert (const string& s) {
            if (s[2] == '#') {
                month = stoi( s.substr(0, 2) );
                year = stoi( s.substr(3, 2) );
                day = stoi( s.substr(6, 2) );
                ( year >= 50 ) ? year += 1900 : year += 2000;
                return true;
            }
            return false;
        }
};

class StarConverter : public ISO8601Converter {
    public:
        virtual bool convert (const string& s) {
            if (s[2] == '*') {
                day = stoi( s.substr(0, 2) );
                month = stoi( s.substr(3, 2) );
                year = stoi( s.substr(6, 4) );
                return true;
            }
            return false;
        }
};

class ShortYearWordConverter : public ISO8601Converter {
    public:
        virtual bool convert (const string& s) {
            if ( (s[6] == ',') && (s.size() == 10) ) {
                month = month_map.at( s.substr(0, 3) );
                day = stoi( s.substr(4, 2) );
                year = stoi( s.substr(8, 2) );
                ( year >= 50 ) ? year += 1900 : year += 2000;
                return true;
            }
            return false;
        }
};

class LongYearWordConverter : public ISO8601Converter {
    public:
        virtual bool convert (const string& s) {
            if ( (s[6] == ',') && (s.size() == 12) ) {
                month = month_map.at( s.substr(0, 3) );
                day = stoi( s.substr(4, 2) );
                year = stoi( s.substr(8, 4) );
                return true;
            }
            return false;
        }
};

//========================================
// main
//========================================

int main (int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);

    std::vector< std::shared_ptr<ISO8601Converter> > converters;
    converters.push_back( std::make_shared<DashConverter>() );
    converters.push_back( std::make_shared<SlashConverter>() );
    converters.push_back( std::make_shared<SharpConverter>() );
    converters.push_back( std::make_shared<StarConverter>() );
    converters.push_back( std::make_shared<ShortYearWordConverter>() );
    converters.push_back( std::make_shared<LongYearWordConverter>() );

    string line;
    while ( std::getline(cin, line) ) {
        for ( auto it = converters.begin(); it != converters.end(); it++ ) {
            ISO8601Converter& converter = **it;
            if ( converter.convert(line) ) {
                cout << converter << endl;
                break;
            }
        }
    }

    return 0;
}

