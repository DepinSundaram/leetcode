#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
int main()
{

    vector<string> str;
    str.push_back("test1");
    str.push_back("test2");
    str.push_back("test3");
    str.push_back("test4");
    str.push_back("test5");

    int id;
    cout << "Enter Id\n";
    cin >> id;
    char arr[125];
    char* name;
    if(id >=1)
    {

        memcpy(name, str[id-1], strlen(str[id-1]));
        memmove(arr,name,str[id-1].size());
    }
    else
        cout << "Nothing";

}

*/


int main()
{

    char **arr = (char **)malloc(5*sizeof(char*));
    for(int i = 0; i < 5; i++)
    {
        char enter[10];
        cin >> enter;
        arr[i] = (char*)malloc(6);
        memcpy(arr[i],enter, 6);
        cout << arr[i];
    }
    char arrD[125];
    int id;
    cin >> id;
    if(id >=1)
    {
        memmove(arrD, arr, 6);
        cout << arrD;
    }
}