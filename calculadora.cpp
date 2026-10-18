#include <iostream>
#include <limits>
#include <cmath>

// Función para limpiar el buffer de entrada
void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Función para realizar la operación
double calcular(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                throw std::runtime_error("Error: División por cero");
            }
            return a / b;
        case '^': return std::pow(a, b);
        case '%': 
            if (b == 0) {
                throw std::runtime_error("Error: Módulo por cero");
            }
            return std::fmod(a, b);
        default:
            throw std::invalid_argument("Operador no válido");
    }
}

int main() {
    std::cout << "=====================================\n";
    std::cout << "     CALCULADORA EN C++ \n";
    std::cout << "=====================================\n";
    std::cout << "Operaciones soportadas: + - * / ^ %\n";
    std::cout << "Escribe 'q' para salir.\n\n";

    while (true) {
        double num1, num2;
        char op;
        std::string entrada;

        std::cout << "Ingresa el primer número (o 'q' para salir): ";
        std::cin >> entrada;

        if (entrada == "q" || entrada == "Q") {
            std::cout << "¡Hasta luego!\n";
            break;
        }

        try {
            num1 = std::stod(entrada);
        } catch (...) {
            std::cout << "Entrada inválida. Intenta de nuevo.\n";
            limpiarBuffer();
            continue;
        }

        std::cout << "Ingresa el operador (+, -, *, /, ^, %): ";
        std::cin >> op;

        std::cout << "Ingresa el segundo número: ";
        std::cin >> num2;

        if (std::cin.fail()) {
            std::cout << "Número inválido.\n";
            limpiarBuffer();
            continue;
        }

        try {
            double resultado = calcular(num1, num2, op);
            std::cout << "\nResultado: " << num1 << " " << op << " " << num2 << " = " << resultado << "\n\n";
        } catch (const std::exception& e) {
            std::cout << e.what() << "\n\n";
        }

        limpiarBuffer();
    }

    return 0;
}
