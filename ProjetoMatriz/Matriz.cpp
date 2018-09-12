#include "Matriz.h"


namespace tp2 {

Matriz::Matriz(int quantidadeDeLinhas, int quantidadeDeColunas):
    quantidadeDeLinhas(0),
    quantidadeDeColunas(0),
    ptMatriz(0)
{
    if(quantidadeDeLinhas<=0) throw QString("Quantidade de linhas fora do intervalo válido.");
    if(quantidadeDeColunas<=0) throw QString("Quantidade de colunas fora do intervalo válido.");

    try {
        ptMatriz = new int[quantidadeDeLinhas*quantidadeDeColunas];
        this->quantidadeDeLinhas=quantidadeDeLinhas;
        this->quantidadeDeColunas=quantidadeDeColunas;
    } catch (std::bad_alloc &erro) {
        throw QString("Matriz não foi criada.");
    }

}

void Matriz::setElemento(int linha, int coluna, int valor)
{
    if(linha<0 || coluna<0 || linha>=quantidadeDeLinhas || coluna>=quantidadeDeColunas)
        throw QString("Posição da linha ou coluna fora do intervalo válido.");

    int pos = linha*quantidadeDeColunas+coluna;
    *(ptMatriz+pos) = valor;

}

int Matriz::getElemento(int linha, int coluna) const
{
    if(linha<0 || coluna<0 || linha>=quantidadeDeLinhas || coluna>=quantidadeDeColunas)
        throw QString("Posição da linha ou coluna fora do intervalo válido.");

    int pos = linha*quantidadeDeColunas+coluna;
    return *(ptMatriz+pos);
}

QString Matriz::getMatriz() const
{
    QString saida = "";

    for(int linha=0;linha<quantidadeDeLinhas;linha++)
    {
        for(int coluna=0;coluna<quantidadeDeColunas;coluna++)
        {
            saida+= QString::number(getElemento(linha,coluna));
            saida+= "   ";
        }
        saida+="\n";
    }
    return saida;
}

Matriz* Matriz::operator +(Matriz const * const objeto) const
{
    if(quantidadeDeLinhas != objeto->getQuantidadeDeLinhas() || quantidadeDeColunas != objeto->getQuantidadeDeColunas())
        throw QString("Não podem ser adicionadas matrizes de tamanho difente.");

    try {
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0;linha<quantidadeDeLinhas;linha++){
            for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
                int valor = this->getElemento(linha,coluna) +
                        objeto->getElemento(linha,coluna);
                aux->setElemento(linha,coluna,valor);
            }
        }
        return aux;
    } catch (std::bad_alloc&) {
        throw QString("Problema na alocação de memória.");
    } catch(QString &erro){
        throw QString(erro);
    }
}

Matriz* Matriz::operator -(Matriz const * const objeto) const
{
    if(quantidadeDeLinhas != objeto->getQuantidadeDeLinhas() || quantidadeDeColunas != objeto->getQuantidadeDeColunas())
        throw QString("Não podem ser subtraídas matrizes de tamanho difente.");

    try {
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0;linha<quantidadeDeLinhas;linha++){
            for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
                int valor = this->getElemento(linha,coluna) -
                        objeto->getElemento(linha,coluna);
                aux->setElemento(linha,coluna,valor);
            }
        }
        return aux;
    } catch (std::bad_alloc&) {
        throw QString("Problema na alocação de memória.");
    } catch(QString &erro){
        throw QString(erro);
    }
}

Matriz* Matriz::operator *(Matriz const * const objeto)const{
    if(quantidadeDeColunas != objeto->getQuantidadeDeLinhas()) throw QString("Quantidade de colunas da Matriz A deve ser\nigual à quantidade de linhas da Matriz B.");

    try {
        Matriz *aux = new Matriz(quantidadeDeLinhas,objeto->getQuantidadeDeColunas());
        int elemento = 0;
        for(int linha=0;linha<quantidadeDeLinhas;linha++){
            for(int coluna=0;coluna<objeto->getQuantidadeDeColunas();coluna++){
                for(int propriedadeComum=0;propriedadeComum<quantidadeDeColunas;propriedadeComum++){
                    elemento += this->getElemento(linha,propriedadeComum) * objeto->getElemento(propriedadeComum,coluna);
                }
                aux->setElemento(linha, coluna, elemento);
                elemento = 0;
            }
        }
        return aux;
    } catch (std::bad_alloc&) {
        throw QString("Problema na alocação de memória.");
    } catch(QString &erro){
        throw QString(erro);
    }
}

Matriz* Matriz::gerarTransposta() const
{
    try {
        if(!ptMatriz) throw QString("Matriz não existe.");
        Matriz *aux = new Matriz(quantidadeDeColunas,quantidadeDeLinhas);
        for(int linha=0;linha<quantidadeDeColunas;linha++){
            for(int coluna=0;coluna<quantidadeDeLinhas;coluna++){
                aux->setElemento(linha,coluna,getElemento(coluna,linha));
            }
        }
        return aux;
    } catch (std::bad_alloc&) {
        throw QString("Problema na alocação de memória.");
    } catch(QString &erro){
        throw QString(erro);
    }

}

Matriz* Matriz::multiplicarPorK(int k) const
{
    try {
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0;linha<quantidadeDeLinhas;linha++){
            for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
                int valor = this->getElemento(linha,coluna) * k;
                aux->setElemento(linha,coluna,valor);
            }
        }
        return aux;
    } catch (std::bad_alloc&) {
        throw QString("Problema na alocação de memória.");
    } catch(QString &erro){
        throw QString(erro);
    }
}

bool Matriz::operator ==(Matriz const * const objeto) const
{
    if(this->quantidadeDeColunas == objeto->quantidadeDeColunas && this->quantidadeDeLinhas == objeto->quantidadeDeLinhas){
        for(int linha=0;linha<quantidadeDeLinhas;linha++){
            for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
                if(this->getElemento(linha,coluna) != objeto->getElemento(linha,coluna)) return false;
            }
        }

        return true;
    }else return false;
}

bool Matriz::operator !=(Matriz const * const objeto) const
{
    if(this->quantidadeDeColunas != objeto->quantidadeDeColunas || this->quantidadeDeLinhas != objeto->quantidadeDeLinhas){
        return true;
    }else{
        for(int linha=0;linha<quantidadeDeLinhas;linha++){
            for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
                if(this->getElemento(linha,coluna) != objeto->getElemento(linha,coluna)) return true;
            }
        }

        return false;
    }
}

bool Matriz::ehTriangularSuperior() const
{
    for(int linha=0;linha<quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
            if(linha>coluna){
                if(getElemento(linha,coluna)!=0) return false;
            }
        }
    }

    return true;
}

bool Matriz::ehTriangularInferior() const
{
    for(int linha=0;linha<quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
            if(linha<coluna){
                if(getElemento(linha,coluna)!=0) return false;
            }
        }
    }

    return true;
}

bool Matriz::ehSimetrica() const
{
    try {
        Matriz *aux = this->gerarTransposta();

        if(quantidadeDeColunas!=quantidadeDeLinhas){
            delete aux;
            return false;
        }else{
            for(int linha=0;linha<quantidadeDeLinhas;linha++){
                for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
                    if(linha<coluna){
                        if(getElemento(linha,coluna)!=aux->getElemento(linha,coluna)){
                            delete aux;
                            return false;
                        }
                    }
                }
            }
        }

        delete aux;
        return true;
    }catch (std::bad_alloc&) {
        throw QString("Problema na alocação de memória.");
    } catch(QString &erro){
        throw QString(erro);
    }
}

bool Matriz::ehIdentidade() const
{
    for(int linha=0;linha<quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
            if(linha==coluna){
                if(getElemento(linha,coluna)!=1) return false;
            }
        }
    }

    return true;
}

}

