#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;


int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    string s;
    while (getline(in, s)) {
        s.insert(0, "<p>");
        s += "</p>";
        out << s << '\n';
    }
    //沒屁用www
    in.close();
    out.close();
}
