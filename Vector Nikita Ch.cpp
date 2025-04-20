#include "Vector.h"
#include <fstream>
#include <iostream> //Чумаченко Никита

// Конструктор, инициализирующий вектор значениями
Vector::Vector(const std::vector<double>& values) : data(values) {}

// Оператор сложения векторов
Vector Vector::operator+(const Vector& other) const {
    if (data.size() != other.size()) {
        throw std::runtime_error("Vector sizes don't match!");
    }
    Vector result(data);
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] += other[i];  // Поэлементное сложение
    }
    return result;
}

// Оператор вычитания векторов
Vector Vector::operator-(const Vector& other) const {
    if (data.size() != other.size()) {
        throw std::runtime_error("Vector sizes don't match!");
    }
    Vector result(data);
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] -= other[i];  // Поэлементное вычитание
    }
    return result;
}

// Оператор умножения вектора на скаляр
Vector Vector::operator*(double scalar) const {
    Vector result(data);
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] *= scalar;  // Умножение каждого элемента
    }
    return result;
}

// Скалярное произведение векторов
double Vector::dot(const Vector& other) const {
    if (data.size() != other.size()) {
        throw std::runtime_error("Vector sizes don't match!");
    }
    double result = 0.0;
    for (size_t i = 0; i < data.size(); ++i) {
        result += data[i] * other[i];  // Накопление суммы произведений
    }
    return result;
}

// Сохранение вектора в файл
void Vector::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing!");
    }
    for (double val : data) {
        file << val << " ";  // Запись значений через пробел
    }
    file.close();
}

// Загрузка вектора из файла
void Vector::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for reading!");
    }
    data.clear();
    double val;
    while (file >> val) {
        data.push_back(val);  // Чтение значений до конца файла
    }
    file.close();
}

// Возвращает размер вектора
size_t Vector::size() const { return data.size(); }

// Оператор доступа к элементам (неконстантный)
double& Vector::operator[](size_t index) { return data[index]; }

// Оператор доступа к элементам (константный)
const double& Vector::operator[](size_t index) const { return data[index]; }

// Оператор вывода вектора в поток
std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "[ ";
    for (double val : vec.data) {
        os << val << " ";  // Форматированный вывод элементов
    }
    os << "]";
    return os;
