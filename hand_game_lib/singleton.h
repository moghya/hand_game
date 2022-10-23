//
// Created by Shubham Sawant on 22/10/22.
//

#ifndef RPS_GAME_SINGLETON_H
#define RPS_GAME_SINGLETON_H

#include <iostream>
#include <memory>
#include <mutex>

namespace moghya {
    template<typename T>
    class Singleton {
        public:
            typedef std::shared_ptr<T> TPtr;
            static TPtr Instance() {
                if (!instance) instance = TPtr(new T());
                return instance;
            }
            Singleton(const Singleton &) = delete;
            Singleton &operator=(const Singleton) = delete;
        protected:
            Singleton()= default;
            virtual ~Singleton() = default;
        private:
            inline static TPtr instance = nullptr;
    };
}

#endif//RPS_GAME_SINGLETON_H
