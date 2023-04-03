#include "cl_base.h"


std::vector <cl_base*> PARENTS;
cl_base::cl_base(cl_base* p_head_object, std::string s_object_name) { // Параметризированный конструктор с параметрами;
    this->p_head_object = p_head_object;
    this->s_object_name = s_object_name;
    if (p_head_object)
    {   
        p_head_object->subordinate_objects.push_back(this);
    }

}
bool cl_base::change_name_object(std::string object_name) {
        //Метод редактирования имени объекта. Один параметр строкового типа, содержит новое наименование объекта. Если нет дубляжа имени подчиненных объектов у головного, то редактирует имя и возвращает «истину», иначе возвращает «ложь»;
        for (int i = 0; i < PARENTS.size(); i++) {
            if (PARENTS[i]->get_name() != object_name and PARENTS[i]->get_subordinate_object_by_name(object_name) == nullptr) {
                this->s_object_name = object_name;
                return true;
            }
        }
        return false;
    }



cl_base* cl_base::find_object_by_name_from_root(std::string object_name) { //new
    return PARENTS[0]->find_object_by_name_from_current(object_name);
}

cl_base* cl_base::find_object_by_name_from_current(std::string object_name) { //new
    for (int i = 0; i < this->subordinate_objects.size(); i++) {
        if (this->subordinate_objects[i]->get_name() == object_name) return this->subordinate_objects[i];
    }

    for (int i = 0; i < this->subordinate_objects.size(); i++) {
        if (this->subordinate_objects[i]->find_object_by_name_from_current(object_name)) return this->subordinate_objects[i]->find_object_by_name_from_current(object_name);
    }

    return nullptr;
}

void cl_base::print_tree_recur(int n=0) {
        for (int space = 0; space < n; space++) std::cout << "    ";
        std::cout << this->get_name() << '\n';
        for (int i = 0; i < this->subordinate_objects.size(); i++) {
            this->subordinate_objects[i]->print_tree_recur(n + 1);
        }
        
}

void cl_base::print_tree_recur_with_readiness(int n = 0) {
    if (this->get_readiness() != 0) {
        std::cout << '\n';
        for (int space = 0; space < n; space++) std::cout << "    ";
        std::cout << this->get_name() << " is ready";
    }
    else {
        std::cout << '\n';
        for (int space = 0; space < n; space++) std::cout << "    ";
        std::cout << this->get_name() << " not is ready";
    }
    for (int i = 0; i < this->subordinate_objects.size(); i++) {
        this->subordinate_objects[i]->print_tree_recur_with_readiness(n + 1);
    }
}

void cl_base::turn_of_downer() {
    this->readiness = 0;
    for (int i = 0; i < this->subordinate_objects.size(); i++) {
        this->subordinate_objects[i]->turn_of_downer();
    }
}

void cl_base::set_readiness(int value) {
    this->readiness = value;
}
int cl_base::get_readiness() {
    return this->readiness;
}


std::string cl_base::get_name() {
        //Метод получения имени объекта;
        return s_object_name;
    }

cl_base* cl_base::get_head_object() {
        //Метод получения указателя на головной объект текущего объекта;
        return p_head_object;
    }

void cl_base::show_tree_objects() {
        //Метод вывода наименований объектов в дереве иерархии слева направо и сверху вниз;
        for (int i = 0; i < PARENTS.size(); i++) {
            if (PARENTS[i]->get_head_object() == nullptr) {
                std::cout << PARENTS[i]->get_name() << '\n';
                break;
            }
        }
        for (int i = 0; i < PARENTS.size(); i++) {
            std::cout << PARENTS[i]->get_name() << "  ";
            for (int j = 0; j < PARENTS[i]->subordinate_objects.size(); j++) {
                if (j != PARENTS[i]->subordinate_objects.size() - 1) {
                    std::cout << (PARENTS[i]->subordinate_objects[j])->get_name() << "  ";
                }
                else std::cout << (PARENTS[i]->subordinate_objects[j])->get_name() << "  ";

            } if (i != PARENTS.size() - 1) {
                std::cout << '\n';
            }
        }
    }

void cl_base::unparse_string(std::string text, std::vector<std::string>& arr) {
    std::string tmp = "";
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ') {
            arr.push_back(tmp);
            tmp = "";
        }
        else tmp += text[i];
    }
    arr.push_back(tmp);
}

cl_base* cl_base::get_subordinate_object_by_name(std::string object_name) {
    //Метод получения указателя на подчиненный объект по его имени
    if (object_name.size() != 0) {
        for (int i = 0; i < subordinate_objects.size(); i++) {
            if (subordinate_objects[i]->get_name() == object_name) {
                return subordinate_objects[i];
            }
        }
    }
    return nullptr;
}

