#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H
#include "cl_base.h"

class cl_application : public cl_base {
public:
    cl_application(cl_application* p_head_object, std::string s_object_name = "Base_object");
    void bild_tree_objects(); //Метод построения исходного дерева иерархии объектов (конструирования моделируемой системы);
    int exec_app();// Метод запуска приложения (начало функционирования системы, выполнение алгоритма решения задачи).
 
};
#endif