#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

typedef struct ListElement
{
    int val;
    struct ListElement *next;
} List;

void wstawElem(int val, List **head)
{
    if(*head == NULL)
    {
        *head = (List *)malloc(sizeof(List));
        (*head)->val = val;
        (*head)->next = NULL;
    }
    else
    {
        List *current = *head;
        while(current->next != NULL)
            current = current->next;
        current->next = (List*)malloc(sizeof(List));
        current->next->val = val;
        current->next->next = NULL;
    }
}

void usunElem(List **head)
{
    List *tmp = NULL;
    if(*head != NULL)
    {
        tmp = (*head)->next;
        delete *head;
        *head = tmp;
    }
    else cout << "Lista jest pusta!" << endl;
}

void wypisz(List *head)
{
    if(head == NULL)
        cout << "Lista jest pusta!" << endl;
    else
    {
        List *current = head;
        do{
            cout << current->val << " ";
            current = current->next;
        }while(current != NULL);
    }
}

void wyswietlGlownyInterfejs()
{
    cout << "** Lista jednokierunkowa **" << endl << endl
    << "1. Dodaj element" << endl
    << "2. Usun element" << endl
    << "3. Wyswietl wszystkie elementy" << endl
    << "0. Zakoncz" << endl << endl
    << "Wybierz opcje: ";
}

int main()
{
    List *head;
    head = (List *)malloc(sizeof(List));
    head = NULL;
    int input;
    do
    {
        wyswietlGlownyInterfejs();
        cin >> input;
        switch(input)
        {
            case 1:
                cout << "Podaj liczbe calkowita: ";
                int el;
                cin >> el;
                wstawElem(el, &head);
                break;
            case 2:
                usunElem(&head);
                break;
            case 3:
                wypisz(head);
                getch();
                break;
            case 0:
                cout << "Do zobaczenia :D" << endl;
                getch();
                break;
            default:
                cout << "Nie ma takiej opcji!" << endl;

        }
        system("cls");
    }
    while(input != 0);
    return 0;
}
