#include <vector>
#include <algorithm>
#include <cstring>

class Str {
        friend std::istream& operator>> (std::istream&, Str&);
    public:
        typedef std::vector<char>::size_type size_type;
        Str () { }
        Str (size_type n, char c): data (n, c) { }
        Str (const char* c) {
            std::copy (c, c + strlen (c), std::back_inserter (data));
        }
        template <class In> Str (In b, In e) {
            std::copy (b, e, std::back_inserter (data));
        }

        char& operator[] (size_type i) { return data [i]; }
        const char& operator[] (size_type i) const { return data [i]; }

        size_type size () const { return data.size (); }

        Str& operator+= (const Str& s) {
            std::copy (s.data.begin (), s.data.end(), std::back_inserter (data));
            return *this;
        }

    private:
        std::vector<char> data;
};

std::ostream& operator<< (std::ostream& os, const Str& s);
Str operator+ (const Str& s, const Str& t);
