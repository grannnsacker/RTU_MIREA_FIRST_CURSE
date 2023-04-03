#include "main.h"


int main()
{   

    cl_application ob_cl_application(nullptr); // создание корневого
    ob_cl_application.bild_tree_objects();       // конструирование системы, построение 
    std::cout << "Object tree\n";
    ob_cl_application.print_tree_recur(0);
    std::cout << "The tree of objects and their readiness";   
    return ob_cl_application.exec_app();         // запуск системы
}
