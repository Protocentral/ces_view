#ifndef MTQUEUE_H
#define MTQUEUE_H

#include <qthread.h>
#include <qqueue.h>
#include <QMutex>

template<class T> class MTQueue
{
        public:

                MTQueue(uint max = -1)
                        : max_(max)
                {
                }

                ~MTQueue()
                {
                        flush();
                }

                uint count() const
                {
                        mutex_.lock();
                        int count = queue_.count();
                        mutex_.unlock();
                        return count;
                }

                bool isFull() const
                {
                        if (-1 == max_)
                                return false;

                        mutex_.lock();
                        int count = queue_.count();
                        mutex_.unlock();
                        return count >= max_;
                }

                bool isEmpty() const
                {
                        mutex_.lock();
                        bool empty = queue_.isEmpty();
                        mutex_.unlock();
                        return empty;
                }

                void flush()
                {
                        mutex_.lock();
                        queue_.clear();
                        mutex_.unlock();
                }

                void enqueue(T t)
                {
                        mutex_.lock();
                        queue_.enqueue(t);
                        mutex_.unlock();
                }

                T dequeue()
                {
                        mutex_.lock();
                        T i = queue_.dequeue();
                        mutex_.unlock();
                        return i;
                }

        private:

                QQueue<T> queue_;
                mutable QMutex mutex_;
                int max_;
};

#endif
