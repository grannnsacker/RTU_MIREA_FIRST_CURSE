#include "cl_application.h"


cl_application::cl_application(cl_application* p_head_object, std::string s_object_name) {
        this->p_head_object = p_head_object; // Указатель на головной объект
        this->s_object_name = s_object_name;

        if (p_head_object)
        {   
            p_head_object->subordinate_objects.push_back(this); // добавление в состав подчиненных головного объекта
        }
    }


void cl_application::bild_tree_objects() {
    //Метод построения исходного дерева иерархии объектов (конструирования моделируемой системы);
    std::string a, b;
    int c;
    std::cin >> s_object_name;
    bool flag3 = true;
    while (flag3) {
        std::cin >> a;
        if (a == "endtree") {
            break;
        }
        std::cin >> b >> c;
        if (a == b) {
            flag3 = false;
        }
        else {
            bool flag1 = true;
            int index = -1;
            for (int i = 0; i < PARENTS.size(); i++) {
                if (PARENTS[i]->get_name() == a) {
                    index = i;
                    flag1 = false;
                    break;
                }
            }
            if (flag1) {
                for (int i = 0; i < PARENTS.size(); i++) {
                    if (PARENTS[i]->get_subordinate_object_by_name(a) != nullptr) {
                        PARENTS.push_back(PARENTS[i]->get_subordinate_object_by_name(a));
                        index = PARENTS.size() - 1;
                        break;
                    }
                }
            }
            if (index != -1) {
                cl_base* object = new cl_base(PARENTS[index], b);
                object->classification = c;

            }
            else if (this->get_name() == a) {
                this->readiness = 1;
                PARENTS.push_back(this);
                cl_base* object = new cl_base(this, b);
                object->classification = c;

            }
        }
    }
    std::cin.clear();
    std::getline(std::cin, a, '\n');
    std::getline(std::cin, a, '\n');
    while (flag3) {
        std::string line;
        std::vector<std::string> arr;
        std::getline(std::cin, line, '\n');
        if (line.length() == 0) break;
        unparse_string(line, arr);
        a = arr[0];
        b = arr[1];
        if (a == b) {
            flag3 = false;
            break;
        }
        else if (a == PARENTS[0]->get_name()) {
            if (std::stoi(b) == 0) {
                PARENTS[0]->turn_of_downer();
            }
            else {
                PARENTS[0]->set_readiness(std::stoi(b));
            }

        }
        else if (find_object_by_name_from_root(a)->get_head_object()->get_readiness() != 0) {
            if (std::stoi(b) == 0) {
                find_object_by_name_from_root(a)->turn_of_downer();

            }
            else {
                find_object_by_name_from_root(a)->set_readiness(std::stoi(b));
            }
        }
    }
}

int cl_application::exec_app() {
        // Метод запуска приложения (начало функционирования системы, выполнение алгоритма решения задачи).
        //this->show_tree_objects();
        this->print_tree_recur_with_readiness(0);
        return 0;
    }

