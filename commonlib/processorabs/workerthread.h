#pragma once

#include <QThread>

class WorkerThread : public QThread
{
        Q_OBJECT
    public:
        WorkerThread() = default;
        ~WorkerThread() = default;

    private:
        void run() override;
        WorkerThread(const WorkerThread&) = delete;
        WorkerThread(WorkerThread&&) = delete;
        WorkerThread& operator=(const WorkerThread&) = delete;
        WorkerThread& operator=(WorkerThread&&) = delete;
};

