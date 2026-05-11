Algoritmo Vértices_Objeto_Geométrico

var vertices, faces, arestas: inteiro;
início
    escreva("Entre com o número de faces do objeto geométrico: ");
    leia(faces);
    escreva("Entre com o número de arestas do objeto geométrico: ");
    leia(arestas);
    vertices ← arestas + 2 - faces;
    escreva("O número de vértices do objeto especificado é: ", vertices);
fim