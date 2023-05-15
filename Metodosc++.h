
Class metodos++{


public:
    void ver_zapatos_tipo();
    void ver_opciones_zapato(, char*nombre);
    void agregar_a_cesta(sqlite3 *db, char *nombre, char *color, int talla, double precio);
    void ver_cesta();
    void obtener_precio(sqlite3 *db, char *nombre, char *color, int talla, double *precio);
    void mostrar_usuario(const char *username);
    void comprar_cesta(sqlite3 *db, char *username);
    void create_user();


}