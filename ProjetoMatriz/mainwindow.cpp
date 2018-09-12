#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    matA(0),
    matB(0)
{
    ui->setupUi(this);
    ui->textEditMatA->setReadOnly(true);
    ui->textEditMatB->setReadOnly(true);
    ui->textEditSaida->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    if(matA) delete matA;
    if(matB) delete matB;
    delete ui;
}

void MainWindow::on_pushButtonCriarMatrizA_clicked()
{
    try {
        int QuantidadeDeLinhas = ui->lineEditQLinhasMatA->text().toInt();
        int QuantidadeDeColunas = ui->lineEditQColunasMatA->text().toInt();

        if(matA) delete matA;
        matA = new tp2::Matriz(QuantidadeDeLinhas,QuantidadeDeColunas);

        for(int l=0;l<QuantidadeDeLinhas;l++)
        {
            for(int c=0;c<QuantidadeDeColunas;c++)
            {
                int elemento = QInputDialog::getInt(this,"Leitura",
                                                    "Matriz A [ "+QString::number(l)+", "+
                                                    QString::number(c)+"] = ");
                matA->setElemento(l,c,elemento);
            }
        }
        ui->textEditMatA->setText(matA->getMatriz());


        QTableWidgetItem *matATriangularSuperior = new QTableWidgetItem((matA->ehTriangularSuperior()) ? "Sim" : "Não");
        QTableWidgetItem *matATriangularInferior = new QTableWidgetItem((matA->ehTriangularInferior() ? "Sim" : "Não"));
        QTableWidgetItem *matASimetrica = new QTableWidgetItem((matA->ehSimetrica()) ? "Sim" : "Não");
        QTableWidgetItem *matAIdentidade = new QTableWidgetItem((matA->ehIdentidade()) ? "Sim" : "Não");
        //QTableWidgetItem *MatAOrtogonal = new QTableWidgetItem();
        //QTableWidgetItem *MatADePermutacao = new QTableWidgetItem();

        ui->tableWidgetSaida->setItem(0,0,matATriangularSuperior);
        ui->tableWidgetSaida->setItem(1,0,matATriangularInferior);
        ui->tableWidgetSaida->setItem(2,0,matASimetrica);
        ui->tableWidgetSaida->setItem(3,0,matAIdentidade);
        //ui->tableWidget->setItem(4,0,MatAOrtogonal);
        //ui->tableWidget->setItem(5,0,MatADePermutacao);
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro!",erro);
    } catch (std::bad_alloc &erro){
        QMessageBox::warning(this,"Erro!","Problema na alocação de memória.");
    }
}

void MainWindow::on_pushButtonCriarMatrizB_clicked()
{
    try {
        int QuantidadeDeLinhas = ui->lineEditQLinhasMatB->text().toInt();
        int QuantidadeDeColunas = ui->lineEditQColunasMatB->text().toInt();

        if(matB) delete matB;
        matB = new tp2::Matriz(QuantidadeDeLinhas,QuantidadeDeColunas);

        for(int l=0;l<QuantidadeDeLinhas;l++)
        {
            for(int c=0;c<QuantidadeDeColunas;c++)
            {
                int elemento = QInputDialog::getInt(this,"Leitura",
                                                    "Matriz B [ "+QString::number(l)+", "+
                                                    QString::number(c)+"] = ");
                matB->setElemento(l,c,elemento);
            }
        }
        ui->textEditMatB->setText(matB->getMatriz());

        QTableWidgetItem *matBTriangularSuperior = new QTableWidgetItem((matB->ehTriangularSuperior()) ? "Sim" : "Não");
        QTableWidgetItem *matBTriangularInferior = new QTableWidgetItem((matB->ehTriangularInferior() ? "Sim" : "Não"));
        QTableWidgetItem *matBSimetrica = new QTableWidgetItem((matB->ehSimetrica()) ? "Sim" : "Não");
        QTableWidgetItem *matBIdentidade = new QTableWidgetItem((matB->ehIdentidade()) ? "Sim" : "Não");
        //QTableWidgetItem *MatAOrtogonal = new QTableWidgetItem();
        //QTableWidgetItem *MatADePermutacao = new QTableWidgetItem();

        ui->tableWidgetSaida->setItem(0,1,matBTriangularSuperior);
        ui->tableWidgetSaida->setItem(1,1,matBTriangularInferior);
        ui->tableWidgetSaida->setItem(2,1,matBSimetrica);
        ui->tableWidgetSaida->setItem(3,1,matBIdentidade);
        //ui->tableWidget->setItem(4,1,MatBOrtogonal);
        //ui->tableWidget->setItem(5,1,MatBDePermutacao);
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro!",erro);
    } catch (std::bad_alloc &erro){
        QMessageBox::warning(this,"Erro!","Problema na alocação de memória.");
    }

}

void MainWindow::on_pushButtonAdicao_clicked()
{
    try {
        tp2::Matriz *mat = (*matA) + matB;
        ui->textEditSaida->setText(mat->getMatriz());

        delete mat;
    } catch (std::bad_alloc&){
        QMessageBox::warning(this,"Erro!","Problema na alocação de memória.");
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro!",erro);
    }
}

void MainWindow::on_pushButtonSubtracao_clicked()
{
    try {
        tp2::Matriz *mat = (*matA) - matB;
        ui->textEditSaida->setText(mat->getMatriz());

        delete mat;
    } catch (std::bad_alloc&){
        QMessageBox::warning(this,"Erro!","Problema na alocação de memória.");
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro!",erro);
    }
}

void MainWindow::on_pushButtonTranspostaA_clicked()
{
    try {
        tp2::Matriz *mat = matA->gerarTransposta();
        ui->textEditSaida->setText(mat->getMatriz());

        delete mat;
    } catch (std::bad_alloc&){
        QMessageBox::warning(this,"Erro!","Problema na alocação de memória.");
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro!",erro);
    }
}

void MainWindow::on_pushButtonTranspostaB_clicked()
{
    try {
        tp2::Matriz *mat = matB->gerarTransposta();
        ui->textEditSaida->setText(mat->getMatriz());

        delete mat;
    } catch (std::bad_alloc&){
        QMessageBox::warning(this,"Erro!","Problema na alocação de memória.");
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro!",erro);
    }
}

void MainWindow::on_pushButtonMultiplicarAPorK_clicked()
{
    try {
        int k = QInputDialog::getInt(this,"Leitura","k = ");

        tp2::Matriz *mat = matA->multiplicarPorK(k);
        ui->textEditSaida->setText(mat->getMatriz());

        delete mat;
    } catch (std::bad_alloc&){
        QMessageBox::warning(this,"Erro!","Problema na alocação de memória.");
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro!",erro);
    }
}

void MainWindow::on_pushButtonMultiplicarBPorK_clicked()
{
    try {
        int k = QInputDialog::getInt(this,"Leitura","k = ");

        tp2::Matriz *mat = matB->multiplicarPorK(k);
        ui->textEditSaida->setText(mat->getMatriz());

        delete mat;
    } catch (std::bad_alloc&){
        QMessageBox::warning(this,"Erro!","Problema na alocação de memória.");
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro!",erro);
    }
}

void MainWindow::on_pushButtonMultiplicacao_clicked()
{
    try {
        tp2::Matriz *mat = (*matA) * matB;
        ui->textEditSaida->setText(mat->getMatriz());

        delete mat;
    } catch (std::bad_alloc&){
        QMessageBox::warning(this,"Erro!","Problema na alocação de memória.");
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro!",erro);
    }
}

void MainWindow::on_pushButtonSaoIguais_clicked()
{
    ui->textEditSaida->setText(((*matA)==matB) ? "Sim" : "Não");
}

void MainWindow::on_pushButtonSaoDiferentes_clicked()
{
    ui->textEditSaida->setText(((*matA)!=matB) ? "Sim" : "Não");
}
