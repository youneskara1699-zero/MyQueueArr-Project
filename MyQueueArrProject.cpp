#include <iostream>
using namespace std;

template <class T>

class clsDynamicArray 
{

protected:
    int _Size = 0;
    T* _TempArray;
  
public:
    T* OriginalArray;

    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;

        _Size = Size;

        OriginalArray = new T[_Size];

    }

    ~clsDynamicArray()
    {

        delete[]  OriginalArray;

    }

    bool SetItem(int index, T Value)
    {

        if (index >= _Size || _Size <0)
        {
            return false;
        }

        OriginalArray[index] = Value;
        return true;

    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);

    }

    void PrintList()

    {

        for (int i = 0; i <= _Size - 1; i++)
        {
            cout << OriginalArray[i] << " ";
        }

        cout << "\n";

    }

    void Resize(int NewSize)
    {
       
        if (NewSize < 0)
        {
            NewSize = 0;
        };

        _TempArray = new T[NewSize];

        if (NewSize < _Size)
            _Size = NewSize;

        for (int i = 0; i < _Size; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _Size = NewSize;

        delete[] OriginalArray;
        OriginalArray = _TempArray;
    
    }
    
    void Reverse()
    {
        _TempArray = new T[_Size];
        int Counter = 0;

        for (int i = _Size-1; i >= 0; i--)
        {
            _TempArray[Counter] = OriginalArray[i];
            Counter++;
        }
        
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }
    
    void Clear()
    {
        _Size = 0;
        _TempArray = new T[0];
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }
    
    T GetItem(int Index)
    {
        return OriginalArray[Index];
    }
    
    bool DeleteItemAt(int Index)
    {
        if (Index > _Size || Index <0)
        {
            return false;
        }
        
        _Size--;
        _TempArray = new T[_Size];

        for (int i = 0; i < Index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        for (int i = Index+1; i <= _Size; i++)
        {
            _TempArray[i-1] = OriginalArray[i];
        }
        
        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;
    }
    
    void DeleteLastItem()
    {   
        DeleteItemAt(_Size-1);
    }
    
    void DeleteFirstItem()
    {
        DeleteItemAt(0);
    }

    int Find(T value)
    {
        for (int i = 0; i < _Size; i++)
        {
            if (OriginalArray[i] == value)
            {
                return i;
            }    
        }
        
        return -1;
    }
    
    bool DeleteItem(T value)
    {
        int Index = Find(value);

        if (Index == -1)
        {
           return false;
        }
        
        DeleteItemAt(Index);
        return true;
    }
    
    bool InsertAt(int Index, T value)
    {
        if (Index > _Size || Index <0)
        {
            return false;
        }
        
        _Size++;
        _TempArray = new T[_Size];

        for (int i = 0; i < Index; i++)
        {    
            _TempArray[i] = OriginalArray[i];
        }

        _TempArray[Index] = value;
  
        for (int i = Index; i < _Size-1; i++)
        {
            _TempArray[i+1] = OriginalArray[i]; 
        }
        
        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;      
    }
    
    bool InsertAtBeginning(T value)
    {
        return InsertAt(0,value);
    }
    
    bool InsertBefore(int Index, T value)
    {
        if (Index < 1)
            return InsertAt(0, value);
        else
           return InsertAt(Index-1, value);  
    }
    
    bool InsertAfter(int Index, T value)
    {
        if (Index >= _Size)
            return InsertAt(_Size-1, value);
        else
           return InsertAt(Index+1, value);
    }

    bool InsertAtEnd(T value)
    {
        return InsertAt(_Size,value);
    }
    
};

template <class T>

class clsMyQueueArr
{
protected:
   clsDynamicArray <T> _MyArray; 

public:

int Size()
{
    return _MyArray.Size();
}


void Clear()
{
    _MyArray.Clear();
}

void Print()
{
    _MyArray.PrintList();
}

void push(T value)
{
    _MyArray.InsertAtEnd(value);
}

void Reverse()
{
    _MyArray.Reverse();
}

void pop()
{
    _MyArray.DeleteFirstItem();
}

T UpdateItem(int Index, T NewValue)
{
   return _MyArray.SetItem(Index, NewValue);
}

void InsertAfter(int Index, T value)
{
    _MyArray.InsertAfter(Index, value);
}

void InsertAtFront(T value)
{
    _MyArray.InsertAtBeginning(value);
}

void InsertAtBack(T value)
{
    _MyArray.InsertAtEnd(value);
}

T GetItem(int Index)
{
    return _MyArray.GetItem(Index);
}

T front()
{
    return _MyArray.GetItem(0);
}

T back()
{
    return _MyArray.GetItem(Size()-1);
}

bool IsEmpty()
{
    return _MyArray.IsEmpty();
}

 
};




int main()
{ 
    clsMyQueueArr <int> MyQueueArr;
 
    MyQueueArr.push(10);
    MyQueueArr.push(20);
    MyQueueArr.push(30);
    MyQueueArr.push(40);
    MyQueueArr.push(50);
    
    cout << "\nQueue:\n";
    MyQueueArr.Print();

    cout << "\nQueue Size: " << MyQueueArr.Size();
    cout << "\nQueue Front: " << MyQueueArr.front();
    cout << "\nQueue Back: " << MyQueueArr.back();

    MyQueueArr.pop();

    cout << "\n\nQueue after pop() : \n";    
    MyQueueArr.Print();

    cout << "\n\nItem(2): " << MyQueueArr.GetItem(2);

    MyQueueArr.Reverse();
    cout << "\n\nQueue after reverse() : \n";    
    MyQueueArr.Print();

    MyQueueArr.UpdateItem(2,600);
    cout << "\n\nQueue after Updating Item(2) to 600 : \n";    
    MyQueueArr.Print();

    MyQueueArr.InsertAfter(2,800);
    cout << "\n\nQueue after Inserting 800 after Item(2) : \n";    
    MyQueueArr.Print();

    MyQueueArr.InsertAtFront(1000);
    cout << "\n\nQueue after Inserting 1000 at front : \n";    
    MyQueueArr.Print();

    MyQueueArr.InsertAtBack(2000);
    cout << "\n\nQueue after Inserting 2000 at back : \n";    
    MyQueueArr.Print();
    
    MyQueueArr.Clear();
    cout << "\n\nQueue after Clear() : \n";    
    MyQueueArr.Print();


    return 0;
}