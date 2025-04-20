#include "Vector.h" 
#include <iostream> //Чумаченко Никита 

int main() {
    // Вывод информации об авторе
    std::cout << "Author: Nikita Chumachenko\n\n";

    try {
        // Создаем два вектора для демонстрации операций
        Vector v1({ 1.0, 2.0, 3.0 });
        Vector v2({ 4.0, 5.0, 6.0 });

        // Вывод исходных векторов
        std::cout << "v1: " << v1 << std::endl;
        std::cout << "v2: " << v2 << std::endl;

        // Сложение векторов
        Vector sum = v1 + v2;
        std::cout << "Sum: " << sum << std::endl;

        // Вычитание векторов
        Vector diff = v1 - v2;
        std::cout << "Difference: " << diff << std::endl;

        // Умножение вектора на скаляр
        Vector scaled = v1 * 2.5;
        std::cout << "Scaled (x2.5): " << scaled << std::endl;

        // Скалярное произведение
        double dotProduct = v1.dot(v2);
        std::cout << "Dot product: " << dotProduct << std::endl;

        // Сохранение и загрузка вектора из файла
        v1.saveToFile("vector.txt");
        Vector loadedVec;
        loadedVec.loadFromFile("vector.txt");
        std::cout << "Loaded vector: " << loadedVec << std::endl;

    }
    catch (const std::exception& e) {
        // Обработка возможных ошибок
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

