// TListHash.h
#pragma once
#include "THashTable.h"
#include <list>

class TListHash : public THashTable
{
protected:
    std::list<TRecord>* pList;
    int size, CurrList;
    std::list<TRecord>::iterator pCurr;
public:
    TListHash(int _size = MAX_SIZE)
    {
        if (_size > MAX_SIZE)
        {
            throw std::exception();
        }
        size = _size;
        pList = new std::list<TRecord>[size];
    }

    ~TListHash()
    {
        delete[] pList;
    }

    bool Find(int _key)
    {
        CurrList = HashFunc(_key) % size;
        for (pCurr = pList[CurrList].begin(); pCurr != pList[CurrList].end(); ++pCurr)
        {
            efficiency++;
            if (pCurr->key == _key)
            {
                return true;
            }
        }
        return false;
    }

    bool Insert(TRecord record)
    {
        bool isfind = Find(record.key);
        if (isfind) { return false; }
        else
        {
            pList[CurrList].push_front(record);
            dataCount++;
        }
        return true;
    }

    bool Delete(int _key)
    {
        if (this->IsEmpty())
        {
            throw std::exception();
        }

        bool isfind = Find(_key);
        if (!isfind) { return false; }
        else
        {
            pList[CurrList].erase(pCurr);
            dataCount--;
        }
        return true;
    }

    void Reset()
    {
        CurrList = 0;
        pCurr = pList[CurrList].begin();
        while (CurrList < size && pCurr == pList[CurrList].end())
        {
            ++CurrList;
            if (CurrList < size)
            {
                pCurr = pList[CurrList].begin();
            }
        }
    }

    void GoNext()
    {
        if (CurrList >= size)
            return;

        ++pCurr;
        while (CurrList < size && pCurr == pList[CurrList].end())
        {
            ++CurrList;
            if (CurrList < size)
            {
                pCurr = pList[CurrList].begin();
            }
        }
    }

    bool IsEnd()
    {
        return CurrList >= size;
    }

    int GetSize() { return size; }

    bool IsFull() const
    {
        return dataCount == size;
    }

    virtual int GetCurrentPos() { return CurrList; }

    virtual void SetCurrentPos(int _curPos)
    {
        if (_curPos < size)
        {
            CurrList = _curPos;
            pCurr = pList[CurrList].begin();
        }
        else {
            throw std::exception();
        }
    }

    TRecord GetCurrentRecord()
    {
        if (CurrList < size && pCurr != pList[CurrList].end())
        {
            return *pCurr;
        }
        else
        {
            throw std::exception();
        }
    }

    void SetCurrentRecord(TRecord record)
    {
        if (CurrList < 0 || CurrList >= size)
        {
            throw std::exception();
        }
        pList[CurrList].push_front(record);
    }
};
