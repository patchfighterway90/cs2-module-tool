#include <iostream>
#include <fstream>
#include <map>
#include <string>

class Config {
    std::map<std::string, std::string> data;
public:
    bool load(const std::string& path) {
        std::ifstream f(path);
        if (!f.is_open()) return false;
        std::string line;
        while (std::getline(f, line)) {
            auto eq = line.find("=");
            if (eq != std::string::npos)
                data[line.substr(0, eq)] = line.substr(eq + 1);
        }
        return true;
    }
    std::string get(const std::string& k) { return data[k]; }
};

int main() {
    Config c;
    c.load("app.ini");
    std::cout << c.get("name") << std::endl;
    return 0;
}
