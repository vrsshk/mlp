#pragma once
#include "matrix.h"
#include "func.h"
#include "include.h"

/**
 * @struct data_network
 * @brief Структура для хранения конфигурационных данных сети.
 * 
 * Эта структура используется для хранения количества слоев и количества нейронов на каждом слое
 */
struct data_network {
    /**
     * @brief Количество слоев в сети.
     */
    int L;

    /**
     * @brief Вектор размеров слоев.
     */
    std::vector<int> size;
};

/**
 * @class Network
 * @brief Класс для представления нейронной сети.
 * 
 * Этот класс предоставляет интерфейс для создания и манипулирования нейронными сетями.
 * Он позволяет создавать сеть с указанной конфигурацией, задавать входные значения,
 * выполнять прямое распространение, обратное распространение ошибки и обновление весов, а также сохранять и читать веса.
 */
class Network {
private:
    /**
     * @brief Количество слоев в сети.
     */
    int L;

    /**
     * @brief Вектор размеров слоев.
     */
    std::vector<int> size;

public:
    /**
     * @brief Функция активации.
     */
    Func f;

    /**
     * @brief Вектор матриц весов.
     * 
     * Хранит матрицы весов для каждого слоя в сети.
     */
    std::vector<Matrix> weights;

    /**
     * @brief Вектор значений смещения.
     * 
     * Хранит значения смещения для каждого слоя в сети.
     */
    std::vector<std::vector<double>> bias;

    /**
     * @brief Вектор значений нейронов.
     * 
     * Хранит значения каждого нейрона в сети.
     */
    std::vector<std::vector<double>> neurons_val;

    /**
     * @brief Вектор ошибок нейронов.
     * 
     * Хранит ошибки каждого нейрона в сети.
     */
    std::vector<std::vector<double>> neurons_err;

    /**
     * @brief Вектор значений смещения нейронов.
     * 
     * Хранит значения смещения каждого нейрона в сети.
     */
    std::vector<double> neurons_bias_val;

    /**
     * @brief Конструктор по умолчанию.
     * 
     * Инициализирует сеть с значениями по умолчанию.
     */
    Network() : L(0), size() {}

    /**
     * @brief Конструктор с конфигурационными данными.
     * 
     * Инициализирует сеть с указанными конфигурационными данными.
     * 
     * @param data Конфигурационные данные для сети.
     */
    Network(const data_network& data);

    /**
     * @brief Печатает конфигурацию сети.
     * 
     * Выводит конфигурацию сети в консоль.
     */
    void PrintConfig();

    /**
     * @brief Задает входные значения для сети.
     * 
     * @param values Входные значения для сети.
     */
    void SetInput(const std::vector<double>& values);

    /**
     * @brief Выполняет прямое распространение.
     * 
     * @return Выходное значение сети.
     */
    double ForwardFeed();

    /**
     * @brief Ищет индекс максимального значения в векторе.
     * 
     * @param value Вектор для поиска.
     * @return Индекс максимального значения в векторе.
     */
    int SearchMaxIndex(const std::vector<double>& value);

    /**
     * @brief Печатает значения нейронов.
     * 
     * @param layers Количество слоев для печати.
     */
    void PrintValues(int layers);

     /**
     * @brief Выполняет обратное распространение ошибки.
     * 
     * Выполняет обратное распространение ошибки через сеть.
     * 
     * @param expect Ожидаемое выходное значение.
     */
    void BackPropogation(double expect);

    /**
     * @brief Обновляет веса.
     * 
     * Обновляет веса сети с помощью указанной скорости обучения.
     * 
     * @param lr Скорость обучения.
     */
    void WeightsUpdater(double lr);

    /**
     * @brief Сохраняет веса в файл.
     * 
     * Сохраняет веса сети в файл.
     */
    void SaveWeights();

    /**
     * @brief Читает веса из файла.
     * 
     * Читает веса сети из файла.
     */
    void ReadWeights();
};
