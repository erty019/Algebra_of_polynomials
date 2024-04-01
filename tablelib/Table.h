#pragma once
#include <iostream>
#include <map>
#include "TPolinom.h"
#include <vector>
using namespace std;



// Замените типы KeyType и ValueType соответственно на типы ключей и значений, которые используете в вашей таблице
using KeyType = int; // пример типа ключа
using ValueType = string;

class Table {
public:
    // информационные методы
    virtual int GetDataCount() const = 0; // количество записей
    virtual bool IsEmpty() const = 0;     // пуста?
    virtual bool IsFull() const = 0;      // заполнена?

    // основные методы
    virtual ValueType* Find(const KeyType& key) = 0;   // найти запись
    virtual void Insert(const KeyType& key, const ValueType& value) = 0; // вставить
    virtual void Delete(const KeyType& key) = 0;       // удалить запись

    // навигация
    virtual int Reset() = 0;         // установить на первую запись
    virtual bool IsTabEnded() const = 0;  // таблица завершена?
    virtual int GoNext() = 0;         // переход к следующей записи

    // доступ
    virtual const KeyType& GetKey() const = 0;
    virtual const ValueType* GetValuePtr() const = 0;

    virtual ~Table() = default;  // Виртуальный деструктор
};

class ConcreteTable : public Table {
private:
    map<KeyType, ValueType> data;
    // Дополнительные поля и методы, если необходимо

public:
    int GetDataCount() const override {
        return data.size();
    }

    bool IsEmpty() const override {
        return data.empty();
    }

    bool IsFull() const override {
        // В данном примере не проверяем на полноту, так как std::map не имеет фиксированного размера
        return false;
    }

    ValueType* Find(const KeyType& key) override {
        auto it = data.find(key);
        if (it != data.end()) {
            return &(it->second);
        }
        return nullptr;
    }

    void Insert(const KeyType& key, const ValueType& value) override {
        data[key] = value;
    }

    void Delete(const KeyType& key) override {
        data.erase(key);
    }

    int Reset() override {
        // Установить на первую запись (первый элемент в std::map)
        it = data.begin();
        return data.size();
    }

    bool IsTabEnded() const override {
        // Проверяем, достигнут ли конец (итератор равен последнему элементу)
        return it == data.end();
    }

    int GoNext() override {
        // Переход к следующей записи
        if (!IsTabEnded()) {
            ++it;
        }
        return data.size();
    }

    const KeyType& GetKey() const override {
        return it->first;
    }

    const ValueType* GetValuePtr() const override {
        return &(it->second);
    }

private:
    map<KeyType, ValueType>::iterator it;
};

