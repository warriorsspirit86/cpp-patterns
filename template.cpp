#include <iostream>
#include <memory>

class ConnectionTemplate {
public:
    virtual bool getHardware() = 0;
    virtual bool hasConnectionProfile() = 0;
    virtual bool startConnection() = 0;
    virtual bool authenticate() = 0;
    virtual bool connectionCompete() = 0;

    ConnectionTemplate() = default;
    bool connect() {
        return getHardware() &&
               hasConnectionProfile() &&
               startConnection() &&
               authenticate() &&
               connectionCompete();
    }
};

class Bluetooth : public ConnectionTemplate {
private:
    const char* _class_;
public:
    Bluetooth() {
        _class_ = __func__ ;
    }
    bool getHardware() override {
        std::cout << _class_ << " :: " << __func__ << std::endl;
        return true;
    }

    bool hasConnectionProfile() override {
        std::cout << _class_ << " :: " << __func__ << std::endl;
        return true;
    }

    bool startConnection() override {
        std::cout << _class_ << " :: " << __func__ << std::endl;
        return true;
    }

    bool authenticate() override {
        std::cout << _class_ << " :: " << __func__ << std::endl;
        return true;
    }

    bool connectionCompete() override {
        std::cout << _class_ << " :: " << __func__ << std::endl;
        return true;
    }
};
class Wifi : public ConnectionTemplate {
private:
    const char* _class_;
public:
    Wifi() {
        _class_ = __func__ ;
    }
    bool getHardware() override {
        std::cout << _class_ << " :: " << __func__ << std::endl;
        return true;
    }

    bool hasConnectionProfile() override {
        std::cout << _class_ << " :: " << __func__ << std::endl;
        return true;
    }

    bool startConnection() override {
        std::cout << _class_ << " :: " << __func__ << std::endl;
        return true;
    }

    bool authenticate() override {
        std::cout << _class_ << " :: " << __func__ << std::endl;
        return true;
    }

    bool connectionCompete() override {
        std::cout << _class_ << " :: " << __func__ << std::endl;
        return true;
    }
};

int main()
{
    bool result;
    std::cout << __func__ << std:: endl;
    std::unique_ptr<ConnectionTemplate> dev = std::make_unique<Wifi>();
    dev->connect();
}