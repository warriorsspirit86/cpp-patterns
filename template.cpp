#include <iostream>
#include <memory>

/**
 * Template method pattern base class, most of the time abstract
 */
class ConnectionTemplate {
public:
    virtual bool getHardware() = 0;

    virtual bool hasConnectionProfile() = 0;

    virtual bool startConnection() = 0;

    virtual bool authenticate() = 0;

    virtual bool connectionComplete() = 0;

    ConnectionTemplate() = default;

    /**
     * This is the key for template method design pattern
     * @return
     */
    bool connect() {
        return getHardware() &&
        hasConnectionProfile() &&
        startConnection() &&
        authenticate() &&
        connectionComplete();
    }
};

class BluetoothConn : public ConnectionTemplate {
private:
    const char * _class_;
public:
    BluetoothConn() {
        _class_ = __func__ ;
    }
    bool getHardware() override {
        //logical implementation
        std::cout << _class_ << "::" << __func__ << std::endl;
        return true;
    }

    bool hasConnectionProfile() override {
        //logical implementation
        std::cout << _class_ << "::" << __func__ << std::endl;
        return true;
    }

    bool startConnection() override {
        //logical implementation
        std::cout << _class_ << "::" << __func__ << std::endl;
        return true;
    }

    bool authenticate() override {
        //logical implementation
        std::cout << _class_ << "::" << __func__ << std::endl;
        return true;
    }

    bool connectionComplete() override {
        //logical implementation
        std::cout << _class_ << "::" << __func__ << std::endl;
        return true;
    }
};

class WifiConn : public ConnectionTemplate {
private:
    const char * _class_;
public:
    WifiConn() {
        _class_ = __func__ ;
    }
    bool getHardware() override {
        //logical implementation
        std::cout << _class_ << "::" << __func__ << std::endl;
        return true;
    }

    bool hasConnectionProfile() override {
        //logical implementation
        std::cout << _class_ << "::" << __func__ << std::endl;
        return true;
    }

    bool startConnection() override {
        //logical implementation
        std::cout << _class_ << "::" << __func__ << std::endl;
        return true;
    }

    bool authenticate() override {
        //logical implementation
        std::cout << _class_ << "::" << __func__ << std::endl;
        return true;
    }

    bool connectionComplete() override {
        //logical implementation
        std::cout << _class_ << "::" << __func__ << std::endl;
        return true;
    }
};

// lets test over here
int main () {
    bool result;
    std::cout << __func__ << std::endl;

    std::unique_ptr<ConnectionTemplate> dev = std::make_unique<WifiConn>();
    dev->connect();
}