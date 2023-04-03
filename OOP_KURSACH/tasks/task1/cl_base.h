#ifndef CL_BASE_H
#define CL_BASE_H
#include<vector>
#include<iostream>
#include <string>
class cl_base;
extern std::vector <cl_base*> PARENTS;
class cl_base {
protected:
    cl_base* p_head_object; // Указатель на головной объект для текущего объекта (для корневого объекта значение указателя равно nullptr);
    std::string s_object_name; // Наименование объекта(строкового типа);
    
    int readiness = 0;
public:
    std::vector < cl_base* > subordinate_objects; // Динамический массив указателей на объекты, подчиненные к текущему объекту в дереве иерархии // new
    void set_readiness(int value); // new // done
    int get_readiness(); // new // done
    int classification = 1;
    void turn_of_downer(); // new // done
    void unparse_string(std::string text, std::vector<std::string>& array); // new // done
    cl_base(cl_base* p_head_object = nullptr, std::string s_object_name = "Base_object");
    cl_base* find_object_by_name_from_root(std::string object_name); //new // done
    cl_base* find_object_by_name_from_current(std::string object_name); //new // done
    void print_tree_recur(int n); //new // done
    void print_tree_recur_with_readiness(int n); //new // done
    bool change_name_object(std::string object_name); //Метод редактирования имени объекта. Один параметр строкового типа, содержит новое наименование объекта. Если нет дубляжа имени подчиненных объектов у головного, то редактирует имя и возвращает «истину», иначе возвращает «ложь»;
    std::string get_name();//Метод получения имени объекта;
    cl_base* get_head_object(); //Метод получения указателя на головной объект текущего объекта;
    void show_tree_objects(); //Метод вывода наименований объектов в дереве иерархии слева направо и сверху вниз;
    cl_base* get_subordinate_object_by_name(std::string object_name);
};
#endif CL_BASE_H