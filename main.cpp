#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct product {
    string name;
    float price;
    int amount;
    
    product *next;
};

void addTop(product *& top, product newproduct)
{
    product* tmp = top;
    string newname = newproduct.name;
    while (tmp != NULL)
    {
        if (tmp->name == newname)
        {
            cout << "The list contains already this element" << endl;
            return;
        }
        tmp = tmp -> next;
    }
    product * newProduct = new product;
    newProduct -> name = newproduct.name;
    newProduct -> price = newproduct.price;
    newProduct -> amount = newproduct.amount;
    newProduct -> next = top;
    top = newProduct;
    return;
}

// Printing informations of each element
void printList(product *top)
{
    if ( top == NULL )
    {
        cout << "Empty list";
        return;
    }
    product *tmp = top;
    while (tmp != NULL)
    {
        cout << "Product: " << tmp -> name << "\nPrice:" << tmp -> price << " RUBLES"<<"\nAmount: " << tmp -> amount << " pcs"<< "\n\n";
        tmp = tmp -> next;
        cout <<"*************************************"<<endl;
    }
    return;
}


void printEle(product *& top, string Elename)
{
    if (top == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    product *tmp = top;
    while (tmp != NULL && tmp -> name != Elename)
        tmp = tmp -> next;
    if (tmp == NULL)
    {
        cout << "This element is not in the list" << endl;
        return;
    }
    else
       {
           cout << "\nProduct: " << tmp -> name << "\nPrice:" << tmp -> price << " RUBLES"<<"\nAmount: " << tmp -> amount << " pcs"<< "\n\n";
       }
        return;
}




void addLast(product *& top, product newproduct)
{
    product *tmp = top;
    string newname = newproduct.name;
    while (tmp != NULL)
    {
        if (tmp->name == newname)
        {
            cout << "The list contains already this element" << endl;
            return;
        }
        tmp = tmp -> next;
    }
    tmp = top;
    if ( tmp == NULL )
    {
        addTop( top, newproduct);
        return;
    }
    while ( tmp -> next ) tmp = tmp -> next;
    product *newpproduct = new product;
    newpproduct -> name = newproduct.name;
    newpproduct -> price = newproduct.price;
    newpproduct -> amount = newproduct.amount;
    newpproduct -> next = NULL;
    tmp -> next = newpproduct;
    return;
}



int addAfter(product *top, product newproduct, string nameAfter)
{
    if ( top == NULL )
    {
        cout << "Empty list" << endl;
        return 1;
    }
    product *tmp = top;
    string newname = newproduct.name;
    while(tmp != NULL)
    {
        if (tmp -> name == newname)
        {
            cout <<  "The list contains already this element" << endl;
            return 1;
        }
        tmp = tmp -> next;
    }
    tmp = top;
    while (tmp != NULL && tmp -> name != nameAfter) tmp = tmp -> next;
    if (tmp == NULL)
    {
        cout << "This element is not in the list" << endl;
        return 1;
    }
    product *newpproduct = new product;
    newpproduct -> name = newproduct.name;
    newpproduct -> price = newproduct.price;
    newpproduct -> amount = newproduct.amount;
    newpproduct -> next = tmp -> next;
    tmp -> next = newpproduct;
    return 0;
}


int addBefore(product *top, product newproduct, string nameBefore)
{
    if ( top == NULL )
    {
        cout << "Empty list!" << endl;
        return 1;
    }
    if (top -> name == nameBefore )
    {
        addTop( top, newproduct);
        return 0;
    }
    if ( top -> next == NULL ) return 1;
    product *prev = top, *tmp = top;
    string newname = newproduct.name;
    while(tmp != NULL)
    {
        if (tmp -> name == newname)
        {
            cout << "The list contains already this element" << endl;
            return 1;
        }
        tmp = tmp -> next;
    }
    tmp = top -> next;
    while (tmp -> next != NULL && tmp -> name != nameBefore)
    {
        tmp = tmp -> next;
        prev = prev -> next;
    }
    if (tmp -> next == NULL && tmp -> name != nameBefore)
    {
        cout << "There is not this element in the list" << endl;
        return 1;
    }
    product *newpproduct = new product;
    newpproduct -> name = newproduct.name;
    newpproduct -> price = newproduct.price;
    newpproduct -> amount = newproduct.amount;
    newpproduct -> next = tmp;
    prev -> next = newpproduct;
    return 0;
}




int del(product *& top, string delname)
{
    if (top == NULL )
    {
        cout << "Empty list";
        return 1;
    }
    product *tmp = top;
    if ( top -> name == delname)
    {
        top = top -> next;
        delete tmp;
        return 0;
    }
    if ( top -> next == NULL )
    {
        cout << "Element is not in the list" << endl;
        return 1;
    }
    product *prev = top;
    tmp = top -> next;
    while (tmp -> next != NULL && tmp -> name != delname)
    {
        prev = prev -> next;
        tmp = tmp -> next;
    }
    if ( tmp -> next == NULL && tmp -> name != delname)
    {
        cout << "Element is not in the list" << endl;
        return 1;
    }
    prev -> next = tmp -> next;
    delete tmp;
    return 0;
}


int main(){
    product *bufet = NULL;
    int k = 100;
    string nameAfter;
    product tmp;
    string newname;

    while (k != 0){
        while (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7){
            cout <<"\t\t -----WELCOME TO OUR STORE!-----"<<endl;
            cout << "            Enter: \n            1: to add an element at the end of the list;\n\
            2: to add an element to the top of the list;\n\
            3: to delete an element; \n\
            4: to add after an element;\n\
            5: to add before an element;\n\
            6: to find an element;\n\
            7: to print a list;\n\
            0: to exit.\n";
            cout <<":";
            cin >> k;
            cout << "\n\n";

            if (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7){
                cout << "Wrong code!\n\n";
                system("pause");
            } else{
                switch(k){
                    case 0:{
                        
                        return 0;
                    }
                    case 1:{
                        
                        cout << "New product name: ";
                        cin >> tmp.name;
                        cout << "Price of a new product: ";
                        cin >> tmp.price;
                        cout << "Amount of a new product: ";
                        cin >> tmp.amount;
                        addLast(bufet, tmp);
                        k = 100;
                        break;
                    }
                    case 2:{
                        
                        cout << "New product name: ";
                        cin >> tmp.name;
                        cout << "Price of a new product: ";
                        cin >> tmp.price;
                        cout << "Amount of a new product: ";
                        cin >> tmp.amount;
                        addTop(bufet, tmp);
                        k = 100;
                        break;
                    }

                    case 3:{
                        
                        cout << "Name of the item you want to delete:";
                        cin >> newname;
                        del(bufet, newname);
                        k = 100;
                        break;
                    }
                    case 4:{
                        
                        cout << "Name of the item after which you want to add new one:";
                        cin >> newname;
                        cout << "New product name: ";
                        cin >> tmp.name;
                        cout << "Price of a new product: ";
                        cin >> tmp.price;
                        cout << "Amount of a new product: ";
                        cin >> tmp.amount;
                        addAfter(bufet, tmp, newname);
                        k = 100;
                        break;
                    }
                    case 5:{
                        
                        cout << "Name of the item before which you want to add new one:";
                        cin >> newname;
                        cout << "Name of a new product: ";
                        cin >> tmp.name;
                        cout << "Price of a new product: ";
                        cin >> tmp.price;
                        cout << "Amount of a new product: ";
                        cin >> tmp.amount;
                        addBefore(bufet, tmp, newname);
                        k = 100;
                        break;
                    }
                    case 6:{
                        
                        cout << "Enter the name of the element about which you want to get information:";
                        cin >> newname;
                        
                        printEle(bufet, newname);
                        k = 100;
                        break;
                    }
                    case 7:{
                        
                        printList(bufet);
                        k = 100;
                        break;
                    }
                }
            }
            cout << "\n\n";
        }
    }

    return 0;
}
