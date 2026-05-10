#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
pthread_mutex_t mutex;
pthread_mutex_t log_mutex; //when editing the simulation file
sem_t sem_empty;
sem_t sem_full;
bool running = false;

void* producer(void* arg) {
    long tid = (long)arg;
    while (running) {
        int item = rand() % 100;
        sem_wait(&sem_empty);
        if (!running) break;
        pthread_mutex_lock(&mutex);
        int slot = in;
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&sem_full);
        pthread_mutex_lock(&log_mutex);
        FILE* f =fopen("simulation_log.txt", "a");
        if (f) {
            time_t now = time(0);
            struct tm* t = localtime(&now);
            fprintf(f, "[%02d:%02d:%02d] [Producer %ld] Inserted item %d at slot %d\n",
                    t->tm_hour, t->tm_min, t->tm_sec, tid, item, slot);
            fclose(f);
        }
        pthread_mutex_unlock(&log_mutex);
        sleep(4);
    }
    return NULL;
}

void* consumer(void* arg) {
    long tid = (long)arg;
    while (running) {
        sem_wait(&sem_full);
        if (!running) break;
        pthread_mutex_lock(&mutex);
        int slot =out;
        int item =buffer[out];
        buffer[out] = -1;
        out = (out +1)% BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&sem_empty);
        pthread_mutex_lock(&log_mutex);
        FILE* f = fopen("simulation_log.txt", "a");
        if (f) { //this is only the timing stuff:
            time_t now = time(0);
            struct tm* t = localtime(&now);
            fprintf(f, "[%02d:%02d:%02d] [Consumer %ld] Removed item %d from slot %d\n",
                    t->tm_hour, t->tm_min, t->tm_sec, tid, item, slot);
            fclose(f);
        }
        pthread_mutex_unlock(&log_mutex);
        sleep(3);
    }
    return NULL;
}

//edit 2 race condition test
void* producer_no_mutex(void* arg) {
    long tid = (long)arg;
    int count = 0;
    while (running && count < 5) {
        int item = rand() % 100;
        //NO SEM OR MUTEX
        int old_in = in;  //both threads read same index

        usleep(10);
        buffer[old_in] = item;  //both threads write to same slot
        in = (old_in + 1) % BUFFER_SIZE;

        pthread_mutex_lock(&log_mutex);
        FILE* f = fopen("simulation_log.txt", "a");
        if (f) {
            time_t now = time(0);
            struct tm* t = localtime(&now);
            fprintf(f, "[%02d:%02d:%02d] [Producer %ld] Wrote item %d to slot %d\n",
                    t->tm_hour, t->tm_min, t->tm_sec, tid, item, old_in);
            fclose(f);
        }
        pthread_mutex_unlock(&log_mutex);
        count++;
        sleep(2);
    }
    running = false;
    return NULL;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Producer-Consumer Simulation");
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::refreshUI);
}

MainWindow::~MainWindow() {
    running = false;
    delete ui;
}

void MainWindow::on_startButton_clicked() {
    running =true;


    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&log_mutex, NULL);
    sem_init(&sem_empty, 0, BUFFER_SIZE);
    sem_init(&sem_full, 0, 0);
    for (int i = 0; i < BUFFER_SIZE; i++) buffer[i] = -1;
    in = 0;
    out = 0;

    remove("simulation_log.txt");
    //CAN REMOVE THIS LINE IF WANT TO CONTINUE THE SIMULATION ON EVERY START.
    ui->logDisplay->clear();
    ui->logDisplay->append("Simulation started...");
    pthread_t p1, p2, c1;


    pthread_create(&p1, NULL, producer, (void*)1);
    pthread_create(&p2, NULL, producer, (void*)2);
    pthread_create(&c1, NULL, consumer, (void*)1);
    //pthread_create(&c2, NULL, consumer, (void*)2);


    pthread_detach(p1);
    pthread_detach(p2);
    pthread_detach(c1);
    //pthread_detach(c2);
    timer->start(500);
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
}

void MainWindow::on_stopButton_clicked() {
    running = false;

    timer->stop();
    sleep(1); //give threads time to die

    //wakeup producer n consumer

    sem_post(&sem_empty);
    sem_post(&sem_full);

    ui->logDisplay->append("Simulation stopped.");
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&log_mutex);
    sem_destroy(&sem_empty);
    sem_destroy(&sem_full);
}

void MainWindow::refreshUI() {
    QLabel* slot0 = ui->slot0;
    QLabel* slot1 = ui->slot1;
    QLabel* slot2 = ui->slot2;
    QLabel* slot3 = ui->slot3;
    QLabel* slot4 = ui->slot4;

    pthread_mutex_lock(&mutex);


    if (buffer[0] != -1) { slot0->setText(QString::number(buffer[0])); slot0->setStyleSheet("background-color: #00897b  ; color: white;"); }
    else { slot0->setText("Empty"); slot0->setStyleSheet("background-color: #e0f7f4; color: teal;"); }

    if (buffer[1] != -1) { slot1->setText(QString::number(buffer[1])); slot1->setStyleSheet("background-color: #00897b  ; color: white;"); }
    else { slot1->setText("Empty"); slot1->setStyleSheet("background-color: #e0f7f4; color: teal;"); }

    if (buffer[2] != -1) { slot2->setText(QString::number(buffer[2])); slot2->setStyleSheet("background-color:#00897b  ; color: white;"); }
    else { slot2->setText("Empty"); slot2->setStyleSheet("background-color:#e0f7f4 ; color: teal;"); }

    if (buffer[3] != -1) { slot3->setText(QString::number(buffer[3])); slot3->setStyleSheet("background-color:  #00897b; color: white;"); }
    else { slot3->setText("Empty"); slot3->setStyleSheet("background-color: #e0f7f4; color: teal;"); }

    if (buffer[4] != -1) { slot4->setText(QString::number(buffer[4])); slot4->setStyleSheet("background-color:#00897b  ; color: white;"); }
    else { slot4->setText("Empty"); slot4->setStyleSheet("background-color: #e0f7f4; color: teal;"); }


    pthread_mutex_unlock(&mutex);

    FILE* f = fopen("simulation_log.txt", "r");
    if (f) {
        ui->logDisplay->clear();
        char line[256];
        while (fgets(line, sizeof(line), f)) {
            ui->logDisplay->append(QString(line).trimmed());
        }
        fclose(f);
    }

    //show sem values
    int emptyVal, fullVal;
    sem_getvalue(&sem_empty, &emptyVal);
    sem_getvalue(&sem_full, &fullVal);

    ui->semEmptyLabel->setText("Empty Slots (sem_empty): " + QString::number(emptyVal));
    ui->semFullLabel->setText("Full Slots (sem_full): " + QString::number(fullVal));

    //show mutex and blocking status
    if (emptyVal == 0) {
        ui->producerStatusLabel->setText("Producer Status: BLOCKED");
        ui->producerStatusLabel->setStyleSheet("color: red; font-weight: bold;");
    } else{
        ui->producerStatusLabel->setText("Producer Status: RUNNING");
        ui->producerStatusLabel->setStyleSheet("color: green; font-weight: bold;");
    }

    if(fullVal == 0) {
        ui->consumerStatusLabel->setText("Consumer Status: BLOCKED");
        ui->consumerStatusLabel->setStyleSheet("color: red; font-weight: bold;");
    } else{
        ui->consumerStatusLabel->setText("Consumer Status: RUNNING");
        ui->consumerStatusLabel->setStyleSheet("color: green; font-weight: bold;");
    }
}

void MainWindow::logMessage(QString msg) {
    ui->logDisplay->append(msg);
}

//edit 2 (race condition)
void MainWindow::on_testRaceButton_clicked() {

    remove("simulation_log.txt");
    running=true;


    //'mutex' no t intizialized
    pthread_mutex_init(&log_mutex, NULL);
    sem_init(&sem_empty, 0, BUFFER_SIZE);
    sem_init(&sem_full, 0, 0);
    for (int i = 0; i < BUFFER_SIZE; i++) buffer[i] = -1;
    in = 0; out = 0;

    ui->logDisplay->clear();

    FILE* f = fopen("simulation_log.txt", "a");
    if (f) {
        fprintf(f,"===== RACE CONDITION TEST (No Mutex) =====\n");
        fprintf(f,"Two producers running simultaneously without mutex\n");
        fclose(f);
    }


    pthread_t p1, p2, p3;
    pthread_create(&p1,NULL, producer_no_mutex, (void*)1);
    pthread_create(&p2,NULL, producer_no_mutex, (void*)2);

    //pthread_create(&p3,NULL, producer_no_mutex, (void*)3);


    pthread_detach(p1);
    pthread_detach(p2);

    //pthread_detach(p3);

    timer->start(500);

    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
}

//edit 3- testfull button case
void MainWindow::on_testFullButton_clicked() {
    remove("simulation_log.txt");
    running = true;

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&log_mutex, NULL);

    sem_init(&sem_empty, 0,BUFFER_SIZE);
    sem_init(&sem_full, 0,0);

    //fill entire buffer
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = rand()%100;
        sem_wait(&sem_empty);
        sem_post(&sem_full);
    }
    in = 0;
    out = 0;

    FILE* f = fopen("simulation_log.txt", "a");
    if (f) {
        fprintf(f, "===== BUFFER FULL TEST =====\n");
        fprintf(f,"All 5 slots are full, sem_empty = 0\n");
        fprintf(f,"Producer is now BLOCKED\n");
        fclose(f);
    }


    pthread_t p1;
    pthread_create(&p1, NULL, producer, (void*)1);
    pthread_detach(p1);

    timer->start(500);
    refreshUI();
    ui->stopButton->setEnabled(true);
    ui->startButton->setEnabled(false);
}

//edit4 test empty buffer case

void MainWindow::on_testEmptyButton_clicked() {
    remove("simulation_log.txt");
    running = true;

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&log_mutex, NULL);
    sem_init(&sem_empty, 0, BUFFER_SIZE);
    sem_init(&sem_full, 0, 0);

    // Buffer stays empty
    for (int i = 0; i < BUFFER_SIZE; i++) buffer[i] = -1;
    in = 0; out = 0;

    FILE* f = fopen("simulation_log.txt", "a");
    if (f) {
        fprintf(f, "=== BUFFER EMPTY TEST ===\n");
        fprintf(f, "Buffer is empty. sem_full = 0\n");
        fprintf(f, "Consumer is now BLOCKED\n");
        fclose(f);
    }


    pthread_t c1;
    pthread_create(&c1, NULL, consumer, (void*)1);
    pthread_detach(c1);

    timer->start(500);
    refreshUI();
    ui->stopButton->setEnabled(true);
    ui->startButton->setEnabled(false);
}

//edit4 multi producer test button

void MainWindow::on_testMultiProdButton_clicked() {
    remove("simulation_log.txt");
    running = true;

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&log_mutex, NULL);
    sem_init(&sem_empty, 0, BUFFER_SIZE);
    sem_init(&sem_full, 0, 0);

    for (int i = 0; i < BUFFER_SIZE; i++) buffer[i] = -1;
    in = 0; out = 0;

    FILE* f = fopen("simulation_log.txt", "a");
    if (f) {
        fprintf(f, "===MULTIPLE PRODUCERS TEST===\n");
        fprintf(f, "4 producers vs 1 consumer\n");
        fclose(f);
    }

    // 4 producers 1 consumer
    pthread_t p1, p2, p3, p4, c1;
    pthread_create(&p1,NULL, producer, (void*)1);
    pthread_create(&p2,NULL, producer, (void*)2);
    pthread_create(&p3,NULL, producer, (void*)3);
    pthread_create(&p4,NULL, producer, (void*)4);
    pthread_create(&c1,NULL, consumer, (void*)1);
    pthread_detach(p1);
    pthread_detach(p2);
    pthread_detach(p3);
    pthread_detach(p4);
    pthread_detach(c1);

    timer->start(500);
    refreshUI();
    ui->stopButton->setEnabled(true);
    ui->startButton->setEnabled(false);
}

//edit 5.1 multi cons button
void MainWindow::on_testMultiConsButton_clicked() {
    remove("simulation_log.txt");
    running = true;

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&log_mutex, NULL);
    sem_init(&sem_empty, 0, BUFFER_SIZE);
    sem_init(&sem_full, 0, 0);

    for(int i = 0; i<BUFFER_SIZE; i++) buffer[i] = -1;
    in = 0; out = 0;

    FILE* f = fopen("simulation_log.txt", "a");
    if (f) {
        fprintf(f, "=== MULTIPLE CONSUMERS TEST ===\n");
        fprintf(f, "1 producer vs 4 consumers\n");
        fprintf(f, "Consumers will start blocking when buffer is empty\n");
        fclose(f);
    }

    //1 producer 4 consumers
    pthread_t p1, c1, c2, c3, c4;
    pthread_create(&p1,NULL, producer, (void*)1);
    pthread_create(&c1,NULL,consumer, (void*)1);
    pthread_create(&c2, NULL,consumer, (void*)2);
    pthread_create(&c3, NULL,consumer, (void*)3);
    pthread_create(&c4, NULL, consumer, (void*)4);
    pthread_detach(p1);
    pthread_detach(c1);
    pthread_detach(c2);
    pthread_detach(c3);
    pthread_detach(c4);

    timer->start(500);
    refreshUI();
    ui->stopButton->setEnabled(true);
    ui->startButton->setEnabled(false);
}


//exit button stuff
void MainWindow::on_exitButton_clicked() {
    running =false;
    close();
}

//NORMAL TEST WHICH IS ALSO THE START BUTTON - BALANCED
void MainWindow::on_balancedTestButton_clicked() {
    on_startButton_clicked();
}
