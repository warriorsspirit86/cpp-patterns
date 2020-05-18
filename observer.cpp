#include <iostream>
#include <memory>
#include <list>

/**
 * Implement me and register to listen from subject.
 */
class IObserver {
private:
public:
    virtual ~IObserver(){};
    virtual void Update (const std::string & message) = 0;
};

/**
 * I will update you
 */
class Subject {

private:
    std::list<std::shared_ptr<IObserver>> observerList;

    void notifyListeners() {
        for(auto itr = observerList.begin(); itr != observerList.end(); itr++) {
            (*itr)->Update("LOW_POWER");
        }
    }

public:
    void regListener(std::shared_ptr<IObserver> observer) {
        observerList.push_back(observer);
    }

    void unRegListener(std::shared_ptr<IObserver> observer) {
        observerList.remove(observer);
    }

    void batteryLevel(int val) {
        int BATTERY_THRESHOLD = 40;
        std::cout << "Battery level: " << val << std::endl;
        if(val <= BATTERY_THRESHOLD) {
            notifyListeners();
        }
    }
};

class Display : public IObserver {
private:
    std::string __class__;
public:
    Display() {
        __class__ = __func__ ;
    }
    void Update(const std::string &message) override {
        std::cout << __class__<< " :: " << message << std::endl;
    }
};

class Audio : public IObserver {
private:
    std::string __class__;
public:
    Audio() {
        __class__ = __func__ ;
    }
    void Update(const std::string &message) override {
        std::cout << __class__<< " :: " << message << std::endl;
    }
};

int main() {
    std::unique_ptr<Subject> subject = std::make_unique<Subject>();
    std::shared_ptr<IObserver> display = std::make_shared<Display>();
    std::shared_ptr<IObserver> audio = std::make_shared<Audio>();

    subject->regListener(display);
    subject->batteryLevel(70);
    subject->batteryLevel(50);
    subject->batteryLevel(40);
    subject->regListener(audio);
    subject->batteryLevel(20);
    subject->unRegListener(display);
    subject->batteryLevel(10);

    return 0;
}