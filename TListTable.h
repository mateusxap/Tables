#pragma once
#include "TTable.h"
#include <list>

class TListTable : public TTable
{
protected:
    std::list<TRecord> records;
    std::list<TRecord>::iterator currIterator;

public:
    TListTable() : TTable()
    {
        Reset();
    }

    bool Find(int key) override
    {
        for (currIterator = records.begin(); currIterator != records.end(); ++currIterator)
        {
            efficiency++;
            if (currIterator->key == key)
            {
                return true;
            }
        }
        return false;
    }

    bool Insert(TRecord record) override
    {
        if (Find(record.key))
        {
            return false;
        }
        records.push_back(record);
        dataCount++;
        return true;
    }

    bool Delete(int key) override
    {
        if (this->IsEmpty())
        {
            throw std::exception();
        }

        if (Find(key))
        {
            currIterator = records.erase(currIterator);
            dataCount--;
            return true;
        }
        return false;
    }

    void Reset() override
    {
        currIterator = records.begin();
    }

    void GoNext() override
    {
        if (currIterator != records.end())
        {
            ++currIterator;
        }
    }

    bool IsEnd() override
    {
        return currIterator == records.end();
    }

    TRecord GetCurrentRecord() override
    {
        if (currIterator != records.end())
        {
            return *currIterator;
        }
        else
        {
            throw std::exception();
        }
    }

    void SetCurrentRecord(TRecord record) override
    {
        if (currIterator != records.end())
        {
            *currIterator = record;
        }
        else
        {
            throw std::exception();
        }
    }

    bool IsFull() const override
    {
        return false; // Список не ограничен по размеру
    }

    void Print() override
    {
        TTable::Print();
    }
};
