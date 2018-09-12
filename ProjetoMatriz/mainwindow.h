#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<Matriz.h>
#include<QString>
#include<QMessageBox>
#include<QInputDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonCriarMatrizA_clicked();

    void on_pushButtonCriarMatrizB_clicked();

    void on_pushButtonAdicao_clicked();

    void on_pushButtonSubtracao_clicked();

    void on_pushButtonTranspostaA_clicked();

    void on_pushButtonTranspostaB_clicked();

    void on_pushButtonMultiplicarAPorK_clicked();

    void on_pushButtonMultiplicarBPorK_clicked();

    void on_pushButtonMultiplicacao_clicked();

    void on_pushButtonSaoIguais_clicked();

    void on_pushButtonSaoDiferentes_clicked();

private:
    Ui::MainWindow *ui;
    tp2::Matriz *matA;
    tp2::Matriz *matB;
};

#endif // MAINWINDOW_H
