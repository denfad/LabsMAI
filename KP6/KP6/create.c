//
//  create.c
//  KP6
//
//  Created by Денис Фадеев on 4/13/22.
//

#include "repository.h"

int main() {
    FILE *f;
    f = fopen("//Users//denisfadeev//Documents//LabsMAI//KP6//KP6//BD.bin", "wb");
    Student s1 = {"Fadeev", "DV", "M", "M103", NULL};
    test t11 = {"MATH", 5};
    test t12 = {"INFA", 4};
    test t13 = {"RUS", 3};
    add_test_to_student(&t11, &s1);
    add_test_to_student(&t12, &s1);
    add_test_to_student(&t13, &s1);
    add_student(&s1, f);
    Student s2 = {"MIXAIL", "DP", "M", "M102", NULL};
    test t21 = {"MATH", 3};
    test t22 = {"INFA", 5};
    test t23 = {"RUS", 4};
    add_test_to_student(&t21, &s2);
    add_test_to_student(&t22, &s2);
    add_test_to_student(&t23, &s2);
    add_student(&s2, f);
    Student s3 = {"MASHA", "BV", "W", "M105", NULL};
    test t31 = {"RUS", 4};
    test t32 = {"HISTORY", 2};
    add_test_to_student(&t31, &s3);
    add_test_to_student(&t32, &s3);
    add_student(&s3, f);
    Student s5 = {"DASH", "GV", "W", "M108", NULL};
    test t51 = {"OFP", 5};
    test t52 = {"TRMX", 4};
    add_test_to_student(&t51, &s5);
    add_test_to_student(&t52, &s5);
    add_student(&s5, f);
    Student s6 = {"BASH", "GV", "W", "M108", NULL};
    test t63 = {"OFP", 5};
    test t64 = {"TRMX", 5};
    add_test_to_student(&t63, &s6);
    add_test_to_student(&t64, &s6);
    add_student(&s6, f);
    fclose(f);
    
    return 0;
}
