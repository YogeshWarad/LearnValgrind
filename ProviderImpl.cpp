// ServiceProvider.hpp
#pragma once
#include <unordered_map>
#include <memory>
#include <functional>
#include <typeindex>

class ServiceProvider;

class ServiceCollection {
public:
    enum class Lifetime { Singleton, Transient };

    struct ServiceDescriptor {
        Lifetime lifetime;
        std::function<std::shared_ptr<void>(ServiceProvider&)> factory;
        std::shared_ptr<void> singletonInstance;
    };

    template<typename Interface, typename Implementation>
    void AddSingleton() {
        descriptors[typeid(Interface)] = {
            Lifetime::Singleton,
            [](ServiceProvider&) {
                return std::make_shared<Implementation>();
            },
            nullptr
        };
    }

    template<typename Interface, typename Implementation>
    void AddTransient() {
        descriptors[typeid(Interface)] = {
            Lifetime::Transient,
            [](ServiceProvider&) {
                return std::make_shared<Implementation>();
            },
            nullptr
        };
    }

private:
    friend class ServiceProvider;
    std::unordered_map<std::type_index, ServiceDescriptor> descriptors;
};
