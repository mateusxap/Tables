#pragma once
#include<string>
#include<iostream>

constexpr auto MAX_SIZE = 999;
struct TRecord
{
	int key;     //Ключ
	std::string value; //Запись

	TRecord()
	{
		key = 0;
		value = "";
	}

	TRecord(int key, std::string value)
	{
		this->key = key;
		this->value = value;
	}

	TRecord& operator=(const TRecord& other)
	{
		key = other.key;
		value = other.value;
		return *this;
	}

	void output()
	{
		std::cout << "( " << key << "  " << value << " )" << std::endl;
	}
	bool operator == (TRecord other)
	{
		if (this->value == other.value)
			return true;
		else
			return false;
	}
	bool operator != (const TRecord& other)
	{
		return !(*this == other);
	}
};

class TTable
{
protected:
	int dataCount;   //Количество записей в таблице на данный момент
	int efficiency;

public:
	TTable() { dataCount = 0; efficiency = 0; };

	int GetDataCount() const { return dataCount; }       
	int GetEfficiency() const { return efficiency; }     
	void ClearEfficiency() { efficiency = 0; }   

	bool IsEmpty() const { return dataCount == 0; }
	virtual bool IsFull() const = 0;

	virtual bool Find(int) = 0;                           //Поиск записи в таблице по ключу
	virtual bool Insert(TRecord record) = 0;               //Вставка записи в таблицу
	virtual bool Delete(int key) = 0;                     //Удаление записиси из таблицы

	virtual void GoNext() = 0;
	virtual void Reset() = 0;
	virtual bool IsEnd() = 0;

	virtual TRecord GetCurrentRecord() = 0;                //Возвращает текущую запись с ключём
	virtual void SetCurrentRecord(TRecord record) = 0;     //Устанавливает текущую запись с ключём????
	
	virtual void Print()
	{
		Reset();
		while (!IsEnd())
		{
			GetCurrentRecord().output();
			GoNext();
		}
		std::cout << std::endl;
	}
	
};

