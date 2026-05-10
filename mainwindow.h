#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <pthread.h>
#include <semaphore.h>


#define BUFFER_SIZE 5

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void logMessage(QString msg);

private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_testFullButton_clicked();
    void on_testEmptyButton_clicked();
    void on_testRaceButton_clicked();
    void on_testMultiProdButton_clicked();
    void on_testMultiConsButton_clicked();
    void on_exitButton_clicked();
    void on_balancedTestButton_clicked();
    void refreshUI();

private:
    Ui::MainWindow *ui;
    QTimer *timer;   //refreshes GUI every 500ms

};

//GLOABAL VARS
extern int buffer[BUFFER_SIZE];
extern int in, out;
extern pthread_mutex_t mutex;
extern pthread_mutex_t log_mutex;
extern sem_t sem_empty;
extern sem_t sem_full;
extern bool running; //controls when threads stop ->threads delete krega if false


void* producer(void* arg);
void* consumer(void* arg);
void* producer_no_mutex(void* arg);

#endif // MAINWINDOW_H
