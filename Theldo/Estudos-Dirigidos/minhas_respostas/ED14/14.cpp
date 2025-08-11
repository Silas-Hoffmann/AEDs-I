#include <iostream>

class MeuTexto {
private:
    std::string conteudo;

    // Funcao auxiliar para checar se char e letra minuscula
    bool isLower(char c) {
        return c >= 'a' && c <= 'z';
    }

    // Funcao auxiliar para checar se char e letra maiuscula
    bool isUpper(char c) {
        return c >= 'A' && c <= 'Z';
    }

    // Funcao auxiliar para converter letra minuscula para maiucula
    char toUpperChar(char c) {
        if (isLower(c)){
            return c - 'a' + 'A';
        }
        return c;
    }

    // Funcao auxiliar para converter letra maiuscula para minuscula
    char toLowerChar(char c) {
        if (isUpper(c)){
             return c - 'A' + 'a';
        }
        return c;
    }

public:
    MeuTexto(const std::string& s) : conteudo(s) {}

    // 1 - tenta converter para int, ou -1
    int getInt() {
        int sinal = 1;
        int resultado = 0;
        size_t i = 0;

        if (conteudo.empty()){
            return -1;
        }
        
        if (conteudo[0] == '-') {
            sinal = -1;
            i = 1;
            if (conteudo.size() == 1){
                return -1;
            }
        }
        else if (conteudo[0] == '+') {
            i = 1;
            if (conteudo.size() == 1){
                return -1;
            }
        }

        for (; i < conteudo.size(); i++) {
            char c = conteudo[i];
            if (c < '0' || c > '9'){
                return -1;
            }
            int digito = c - '0';
            resultado = resultado * 10 + digito;
        }
        return resultado * sinal;
    }

    // 2 - tenta converter para double, ou 0.0
    double getDouble() {
        int sinal = 1;
        double resultado = 0.0;
        double fatorDecimal = 0.1;
        bool depoisVirgula = false;

        size_t i = 0;
        if (conteudo.empty()){
            return 0.0;
        }


        if (conteudo[0] == '-') {
            sinal = -1;
            i = 1;
            if (conteudo.size() == 1){
                return 0.0;
            }
        }
        else if (conteudo[0] == '+') {
            i = 1;
            if (conteudo.size() == 1){
                return 0.0;
            }
        }

        bool temDigito = false;
        for (; i < conteudo.size(); i++) {
            char c = conteudo[i];
            if (c == '.') {
                if (depoisVirgula){
                    return 0.0;
                }
                depoisVirgula = true;
            }
            else if (c >= '0' && c <= '9') {
                temDigito = true;
                int digito = c - '0';
                if (!depoisVirgula){
                    resultado = resultado * 10 + digito;
                } else {
                    resultado = resultado + digito * fatorDecimal;
                    fatorDecimal /= 10;
                }
            }
            else return 0.0;
        }
        if (!temDigito){
            return 0.0;
        }
        return resultado * sinal;
    }

    // 3 - tenta converter para bool
    bool getBoolean() {
        std::string s = toLowerCase();

        if (s == "false" || s == "f" || s == "0"){
            return false;
        }
        else if (s == "true" || s == "t" || s == "1"){
            return true;
        }
        return false;
    }

    // 4 - contains(subtexto)
    bool contains(std::string subtexto) {
        if (subtexto.size() > conteudo.size()){
            return false;
        }

        for (size_t i = 0; i <= conteudo.size() - subtexto.size(); i++) {
            bool achou = true;
            for (size_t j = 0; j < subtexto.size(); j++) {
                if (conteudo[i + j] != subtexto[j]) {
                    achou = false;
                    break;
                }
            }
            if (achou){
                return true;
            }
        }
        return false;
    }

    // 5 - toUpperCase()
    std::string toUpperCase() {
        std::string s = conteudo;
        for (size_t i = 0; i < s.size(); i++) {
            s[i] = toUpperChar(s[i]);
        }
        return s;
    }

    // 6 - toLowerCase()
    std::string toLowerCase() {
        std::string s = conteudo;
        for (size_t i = 0; i < s.size(); i++) {
            s[i] = toLowerChar(s[i]);
        }
        return s;
    }

    // 7 - troca todas as ocorrencias do original pelo novo
    std::string replace(char original, char novo) {
        bool trocou = false;
        std::string s = conteudo;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == original) {
                s[i] = novo;
                trocou = true;
            }
        }
        if (trocou){
            return s;
        } else{
            return conteudo;
        }
    }

    // 08 - codifica cifra de Cesar (+3)
    std::string encrypt() {
        std::string s = conteudo;
        for (size_t i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isUpper(c)) {
                s[i] = (c - 'A' + 3) % 26 + 'A';
            }
            else if (isLower(c)) {
                s[i] = (c - 'a' + 3) % 26 + 'a';
            }
        }
        return s;
    }

    // 09 - decodifica cifra de Cesar (-3)
    std::string decrypt() {
        std::string s = conteudo;
        for (size_t i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isUpper(c)) {
                s[i] = (c - 'A' + 26 - 3) % 26 + 'A';
            }
            else if (isLower(c)) {
                s[i] = (c - 'a' + 26 - 3) % 26 + 'a';
            }
        }
        return s;
    }

    // 10 - separa por espaço
    int split(std::string sequencia[]) {
        int count = 0;
        size_t i = 0;
        while (i < conteudo.size()) {
            while (i < conteudo.size() && conteudo[i] == ' '){
                i++;
            }
            if (i >= conteudo.size()){
                break;
            }

            std::string palavra = "";
            while (i < conteudo.size() && conteudo[i] != ' ') {
                palavra += conteudo[i];
                i++;
            }
            sequencia[count] = palavra;
            count++;
        }
        return count;
    }

    // E1 - separa com delimitador passado
    int split(char delimitador, std::string sequencia[]) {
        int count = 0;
        size_t i = 0;
        while (i < conteudo.size()) {
            while (i < conteudo.size() && conteudo[i] == delimitador){
                i++;
            }
            if (i >= conteudo.size()){
                break;
            }

            std::string palavra = "";
            while (i < conteudo.size() && conteudo[i] != delimitador) {
                palavra += conteudo[i];
                i++;
            }
            sequencia[count] = palavra;
            count++;
        }
        return count;
    }

    // E2 - inverte string
    std::string reverse() {
        std::string s = conteudo;
        size_t n = s.size();
        for (size_t i = 0; i < n / 2; i++) {
            char tmp = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = tmp;
        }
        return s;
    }
};

int main() {
    std::string entrada;
    std::cout << "Informe o texto: ";
    std::getline(std::cin, entrada);
    MeuTexto texto(entrada);

    int opcao = -1;
    while (opcao != 0) {
        std::cout << "\nEscolha a funcao para testar:\n";
        std::cout << "1 - getInt\n"; // transforma em int
        std::cout << "2 - getDouble\n"; // transforma em double
        std::cout << "3 - getBoolean\n"; // transforma em boolean
        std::cout << "4 - contains\n"; // verifica se trecho esta contido na string
        std::cout << "5 - toUpperCase\n"; // todo o texto em UpperCase
        std::cout << "6 - toLowerCase\n"; // todo o texto em LowerCase
        std::cout << "7 - replace\n"; // substitui um char por outro
        std::cout << "8 - encrypt\n"; // codifica na cifra de Cesar +3
        std::cout << "9 - decrypt\n"; // decodifica na cifra de Cesar -3
        std::cout << "10 - split (espaco)\n"; // quantidade de palavras pelos espacos
        std::cout << "11 - split (delimitador)\n"; // quantidade de palçavras pelo delimitador informado
        std::cout << "12 - reverse\n"; // inverte a string
        std::cout << "0 - sair\n"; // encerrar programa
        std::cout << "Opcao: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1:
                std::cout << "getInt: " << texto.getInt() << std::endl;
                break;
            case 2:
                std::cout << "getDouble: " << texto.getDouble() << std::endl;
                break;
            case 3:
                std::cout << "getBoolean: " << (texto.getBoolean() ? "true" : "false") << std::endl;
                break;
            case 4: {
                std::string subtexto;
                std::cout << "Informe subtexto: ";
                std::getline(std::cin, subtexto);
                std::cout << "contains: " << (texto.contains(subtexto) ? "sim" : "nao") << std::endl;
                break;
            }
            case 5:
                std::cout << "toUpperCase: " << texto.toUpperCase() << std::endl;
                break;
            case 6:
                std::cout << "toLowerCase: " << texto.toLowerCase() << std::endl;
                break;
            case 7: {
                char original, novo;
                std::cout << "Informe caractere original: ";
                std::cin >> original;
                std::cout << "Informe novo caractere: ";
                std::cin >> novo;
                std::cout << "replace: " << texto.replace(original, novo) << std::endl;
                std::cin.ignore();
                break;
            }
            case 8:
                std::cout << "encrypt: " << texto.encrypt() << std::endl;
                break;
            case 9:
                std::cout << "decrypt: " << texto.decrypt() << std::endl;
                break;
            case 10: {
                std::string sequencia[20];
                int qtd = texto.split(sequencia);
                std::cout << "split (espaco): " << qtd << " -> ";
                for (int i = 0; i < qtd; i++){
                    std::cout << "'" << sequencia[i] << "' ";
                }
                std::cout << std::endl;
                break;
            }
            case 11: {
                char delimitador;
                std::cout << "Informe delimitador: ";
                std::cin >> delimitador;
                std::string sequencia[20];
                int qtd = texto.split(delimitador, sequencia);
                std::cout << "split (delimitador): " << qtd << " -> ";
                for (int i = 0; i < qtd; i++){
                    std::cout << "'" << sequencia[i] << "' ";
                }
                std::cout << std::endl;
                std::cin.ignore();
                break;
            }
            case 12:
                std::cout << "reverse: " << texto.reverse() << std::endl;
                break;
            case 0:
                std::cout << "Encerrando..." << std::endl;
                break;
            default:
                std::cout << "Opcao invalida" << std::endl;
                break;
        }
    }

    return 0;
}