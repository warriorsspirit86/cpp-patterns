#include <iostream>
#include <memory>

using namespace std;

// base class
class Daemon
{
public:
    virtual string getVersion() = 0;
};

// maybe confidential implementations
class DaemonConcrete : public Daemon
{
private:
    const string ver = "11.5";
public:
    DaemonConcrete() = default;

    string getVersion() override {
        return std::__cxx11::string(ver);
    }
};

// as an sdk to the outside world
class DaemonProxy : public Daemon
{
public:
    std::unique_ptr<DaemonConcrete> concrete {new DaemonConcrete()};

    string getVersion() override {
        return concrete->getVersion();
    }
};

// client -- outside world
int main() {
    std::unique_ptr<Daemon> daemon {new DaemonProxy()};
    std::cout << daemon->getVersion() << std::endl;

    return 0;
}
