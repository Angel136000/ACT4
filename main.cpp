#include "crow.h" // Incluye la biblioteca Crow
#include <vector>
#include <string>
#include <nlohmann/json.hpp> 

using json = nlohmann::json;

// Definición de un auto
struct Auto {
    std::string marca;
    std::string modelo;
    int año;
    double precio;
    std::string color;

    // Conversión a JSON
    json to_json() const {
        return {
            {"marca", marca},
            {"modelo", modelo},
            {"año", año},
            {"precio", precio},
            {"color", color}
        };
    }
};

// Catálogo básico de autos
std::vector<Auto> catalogo_autos = {
    {"Chevrolet", "Onix", 2024, 320000, "Rojo Rubí"},
    {"Chevrolet", "Trax", 2023, 480000, "Azul Marino"},
    {"Chevrolet", "Silverado", 2022, 750000, "Negro Ébano"},
    {"Chevrolet", "Aveo", 2024, 290000, "Gris Titanio"},
    {"Chevrolet", "Captiva", 2023, 520000, "Blanco Perla"}
};

int main() {
    crow::SimpleApp app; // Inicializa la aplicación

    // Ruta para obtener el catálogo de autos
    CROW_ROUTE(app, "/catalogo_autos")
    ([]() {
        json respuesta = json::array();
        for (const auto& auto_ : catalogo_autos) {
            respuesta.push_back(auto_.to_json());
        }
        return crow::response(respuesta.dump());
    });

    // Inicia el servidor en el puerto 18080
    app.port(18080).multithreaded().run();
    return 0;
}
