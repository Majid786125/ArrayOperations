#include <iostream>
using namespace std;

class AlphabetArrayList {
public:
    AlphabetArrayList(int = 10);
    void getListValuesFromUser();
    bool insert(int);
    void display();
    int letterCount(char);
    bool isUnique();
    void replace(char, char);
    void mergeList(const AlphabetArrayList&);
    int size;
    int capacity;
    char *arraylist;
};

AlphabetArrayList::AlphabetArrayList(int list_capacity) {
    size = 0;
    capacity = list_capacity;
    arraylist = new char[capacity];

    for (int i = 0; i < capacity; i++)
        arraylist[i] = '_'; // to show empty elements while printing
}

bool AlphabetArrayList::insert(int new_element) {
    if (size != capacity) {
        arraylist[size] = new_element;
        size++;
        return true;
    }
    else
        return false;
}

void AlphabetArrayList::display() {
    // display is designed to show entire array including empty elements
    for (int i = 0; i < capacity; i++)
        cout << arraylist[i] << " ";
    cout << "\n";
}

void AlphabetArrayList::getListValuesFromUser() {
    cout << "Enter up to " << capacity << " characters to populate your list. Enter 0 to stop entering.\n";
    char element;
    for (int i = 0; i < 10; i++) {
        cout << "Enter " << i + 1 << ": ";
        cin >> element;
        if (element != '0')
            insert(element);
        else
            break;
    }
    cout << "Confirmation of list values entered: ";
    display();
}

int AlphabetArrayList::letterCount(char letter) {
    int C=0;
    for(int i=0;i<size;i++)
    {
        if(arraylist[i]==letter)
        {
            C++;
        }
    }
    return C;
}

void AlphabetArrayList::replace(char original, char replacement) {

    for(int i=0;i<size;i++)
    {
        if(arraylist[i]==original)
        {
            arraylist[i]=replacement;
        }
    }


}

bool AlphabetArrayList::isUnique() {
    for(int x=0;x<capacity;x++) {
        if (arraylist[x] != '_')
        {
            for (int i = x + 1; i < capacity; i++) {
                if (arraylist[x] == arraylist[i]) {
                    return false;
                }
            }
        }
    }

    return true;
}

void AlphabetArrayList::mergeList(const AlphabetArrayList &incoming_list)
{
    int A1=incoming_list.capacity;
    this->capacity=A1+capacity;
    int N=0;
    int P=0;
    char temp[20];
    for(int i=0;i<=10;i++)
    {
        if (arraylist[i] != '_') {
                temp[i] = arraylist[i];
                N++;
            }
        }

    for(int i=N-1;i<20;i++)
    {

        if(incoming_list.arraylist[P]!='_')
        {
            temp[i]=incoming_list.arraylist[P];
        }
        else
        {
            temp[i]=' ';
        }
        P++;

    }
    for(int i=0;i<10;i++)
    {
        arraylist[i]='-';
    }
    for(int i=0;i<20;i++)
    {

        arraylist[i]=temp[i];
    }

}

int main()
{
    AlphabetArrayList list1, list2;

    cout << "Getting list1: \n";
    list1.getListValuesFromUser();
    cout << "\nGetting list2: \n";
    list2.getListValuesFromUser();

    char letter_count;
    cout << "\nEnter a letter to determine count for: ";
    cin >> letter_count;

    cout << letter_count << " occurs " << list1.letterCount(letter_count) << " times in list1\n";
    cout << letter_count << " occurs " << list2.letterCount(letter_count) << " times in list2\n";

    cout << "\n";

    if (list1.isUnique()==true)
        cout << "List1 has unique values\n";
    else
        cout << "List1 has duplicate values\n";

    if (list2.isUnique()==true)
        cout << "List2 has unique values\n";
    else
        cout << "List2 has duplicate values\n";

    char old_char, new_char;
    cout << "\nEnter character to replace: ";
    cin >> old_char;
    cout << "Enter character to replace with: ";
    cin >> new_char;

    list1.replace(old_char, new_char);
    list2.replace(old_char, new_char);
    cout << "List1 after replacement: "; list1.display();
    cout << "List2 after replacement: "; list2.display();

    cout << "\nAfter merging list2 into list1:\n";
    list1.mergeList(list2);
    cout << "List1 after merge: "; list1.display();
    cout << "List2 after merge (unchanged): "; list2.display();
}