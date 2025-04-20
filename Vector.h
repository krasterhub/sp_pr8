#pragma once
#include <vector>
#include <string>
#include <stdexcept> //Чумаченко Никита 

class Vector {
private:
    std::vector<double> data;

public:
    // Конструкторы
    Vector() = default;
    Vector(const std::vector<double>& values);

    // Основные операции
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(double scalar) const;
    double dot(const Vector& other) const;  // Скалярное произведение

    // Работа с файлами
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    // Вспомогательные методы
    size_t size() const;
    double& operator[](size_t index);
    const double& operator[](size_t index) const;

    // Вывод вектора
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
};
