#include <iostream>
#include <stack> // Biblioteca utilizada para implementar a Pilha padrao do C++
#include <conio.h> // Biblioteca utilizada para usar a função getch();
#include <stdlib.h> // Biblioteca utilizada para usar o system("cls");

struct Coordenadas {
    int x, y;
};

bool resolveLabirinto(int labirinto[20][21], std::stack<Coordenadas> caminho);
void printLabirinto(int labirinto[20][21]);

int main()
{

    // 20 Linhas (Eixo y)
    // 21 Colunas (Eixo x)

    int labirinto[20][21] = {

        // 1 Entrada
        // 2 Saida
        // 9 Parede
        // 0 Caminho vazio
        // 5 Caminho percorrido
        // -1 Caminho percorrido sem saida valida

        9,1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
        9,0,0,2,0,0,9,0,0,0,0,0,9,0,0,0,0,0,9,0,9,
        9,9,0,9,9,0,9,9,9,9,9,0,9,0,9,0,9,0,0,0,9,
        9,0,0,0,9,0,0,0,0,0,0,0,9,9,9,9,9,9,9,0,9,
        9,0,9,0,9,0,9,9,9,9,9,9,9,0,0,0,9,0,0,0,9,
        9,0,9,0,0,0,9,0,0,0,9,0,9,0,9,0,0,0,9,0,9,
        9,0,9,9,9,9,9,0,9,0,9,0,0,0,9,9,9,9,9,0,9,
        9,0,9,0,0,0,0,0,9,0,9,9,9,0,0,9,0,0,0,0,9,
        9,0,9,0,9,0,9,0,9,0,0,0,9,9,0,9,9,0,9,9,9,
        9,0,9,0,9,9,9,0,9,0,9,0,0,0,0,0,9,0,0,0,9,
        9,0,9,0,9,0,9,0,9,0,9,9,9,9,9,0,9,9,0,9,9,
        9,0,0,0,0,0,9,0,9,0,0,0,9,0,9,0,9,0,0,0,9,
        9,0,9,9,9,9,9,0,9,9,9,0,9,0,9,9,9,0,9,0,9,
        9,0,9,0,0,0,0,0,0,0,9,0,9,0,0,0,9,0,9,0,9,
        9,0,0,0,9,9,9,0,9,0,9,0,9,9,9,0,9,0,9,0,9,
        9,9,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,9,9,
        9,0,9,0,0,0,9,0,9,0,0,0,9,0,0,0,9,0,0,0,9,
        9,0,9,9,9,0,9,9,9,9,9,9,9,9,9,0,9,9,9,0,9,
        9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,9,
        9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9
    };

    std::stack<Coordenadas> caminho;

    // Entrada do labirinto x=0; y=1;
    Coordenadas entrada = Coordenadas({ 1,0 });
    caminho.push(entrada);

    int op = -1;
    bool encontrou = false;

    do
    {

        std::cout << std::endl << "-->  Labirinto  <--" << std::endl << std::endl;
        std::cout << "(1) Inciar" << std::endl;
        std::cout << "(2) Sair" << std::endl << std::endl;
        std::cout << "Escolha uma opcao: " << std::endl;
        std::cin >> op;

        switch (op) {
            case 1:{
                if (!encontrou) {
                    do {

                        bool encontrou = resolveLabirinto(labirinto, caminho);

                    } while (encontrou);
                    if (!encontrou) {
                        printLabirinto(labirinto);
                        std::cout << std::endl << std::endl<< "Saida encontrada\n\n";
                        system("pause");
                        break;
                    }
                }
                else {
                    std::cout << "Labirinto ja resolvido" << std::endl;
                    break;
                }
            }

            case 2:{
                system("cls");
                std::cout << "Saindo..." << std::endl;
                break;
            }

            default: {
                system("cls");
                std::cout << "Opcao invalida" << std::endl;
            }
        }
    } while ((op != 2) || (encontrou));
    return 0;
}

void printLabirinto(int labirinto[20][21])
{
    system("cls");
    int linha, coluna;

    for (linha = 0; linha < 20; linha++) {
        for (coluna = 0; coluna < 21; coluna++) {
            if (labirinto[linha][coluna] == 0) { std::cout << " "; }
            if (labirinto[linha][coluna] == 9) { std::cout << "X"; }
            if (labirinto[linha][coluna] == 1) { std::cout << "E"; }
            if (labirinto[linha][coluna] == 2) { std::cout << "S"; }
            if (labirinto[linha][coluna] == 5) { std::cout << "*"; }
            if (labirinto[linha][coluna] == 6) { std::cout << " "; }
        }
        printf("\n");
    }
}

bool resolveLabirinto(int labirinto[20][21], std::stack<Coordenadas> caminho) {
    do {
        printLabirinto(labirinto);

        bool aux = false;
        for (int i = caminho.top().x - 1; i <= caminho.top().x + 1; i++) {
            if (aux) {
                break;
            }
            // Verifica se esta dentro do intervalo do labirinto
            if (i >= 0 || i <= 21) {
                if (labirinto[caminho.top().y][i] == 0) {
                    // Se for caminho vazio -> Seta posicao com valor = 5
                    labirinto[caminho.top().y][i] = 5;

                    // Push na pilha a posicao com valor 5
                    caminho.push(Coordenadas({ (int)i, (int)caminho.top().y }));
                    aux = true;
                    break;
                    // 2 = Saida
                } if (labirinto[caminho.top().y][i] == 2) {
                    // Se for caminho vazio -> Seta posicao com valor = 5
                    labirinto[caminho.top().y][caminho.top().x] = 5;
                    // Retorna true para a funcao resolveLabirinto
                    // ENCONTROU A SAIDA!
                    return true;
                }

                // Se nao estiver no intervalo do labirinto ele 'breaks on iteration'
            }
            else {
                continue;
            }
        }
        for (int j = caminho.top().y - 1; j <= caminho.top().y + 1; j++) {
            if (aux) {
                break;
            }

            if (j >= 0 || j <= 20) {
                if (labirinto[j][caminho.top().x] == 0) {
                    // Se for caminho vazio -> Seta posicao com valor = 5
                    labirinto[j][caminho.top().x] = 5;
                    // Push na pilha a posicao com valor 5
                    caminho.push(Coordenadas({ (int)caminho.top().x, (int)j }));
                    aux = true;
                    break;
                    // 2 = Saida
                } if (labirinto[j][caminho.top().x] == 2) {
                    // Se for caminho vazio -> Seta posicao com valor = 5
                    labirinto[caminho.top().y][caminho.top().x] = 5;
                    // Retorna true para a funcao resolveLabirinto
                    return true;
                }
                else {
                    continue;
                }
            }
        }
        if (!aux) {
            labirinto[caminho.top().y][caminho.top().x] = 6;
            caminho.pop();
        }
        // Se caminho estiver vazio o codigo tera percorrido todos os caminhos possiveis
    } while (!caminho.empty());
    return false;
}