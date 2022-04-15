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
    Student s2 = {"MIXAILOV", "DP", "M", "M103", NULL};
    test t21 = {"MATH", 3};
    test t22 = {"INFA", 5};
    test t23 = {"RUS", 4};
    add_test_to_student(&t21, &s2);
    add_test_to_student(&t22, &s2);
    add_test_to_student(&t23, &s2);
    add_student(&s2, f);
    Student s3 = {"SUBOTINA", "BV", "W", "M105", NULL};
    test t31 = {"RUS", 4};
    test t32 = {"HISTORY", 2};
    test t33 = {"VPIK", 2};
    add_test_to_student(&t31, &s3);
    add_test_to_student(&t32, &s3);
    add_test_to_student(&t33, &s3);
    add_student(&s3, f);
    Student s5 = {"GOROHOVA", "GV", "W", "M108", NULL};
    test t51 = {"OFP", 5};
    test t52 = {"TRMX", 4};
    add_test_to_student(&t51, &s5);
    add_test_to_student(&t52, &s5);
    add_student(&s5, f);
    Student s6 = {"BASHOROVA", "NK", "W", "M108", NULL};
    test t63 = {"OFP", 5};
    test t64 = {"TRMX", 5};
    add_test_to_student(&t63, &s6);
    add_test_to_student(&t64, &s6);
    add_student(&s6, f);
    Student s7 = {"INGNATYEV", "VB", "M", "M108", NULL};
    test t71 = {"MATH", 5};
    test t72 = {"TRMX", 3};
    test t73 = {"OOP", 3};
    test t74 = {"ALGBR", 4};
    add_test_to_student(&t71, &s7);
    add_test_to_student(&t72, &s7);
    add_test_to_student(&t73, &s7);
    add_test_to_student(&t74, &s7);
    add_student(&s7, f);
    Student s8 = {"KIRILOV", "DB", "M", "M109", NULL};
    test t81 = {"RUS", 5};
    test t82 = {"CPU", 3};
    test t83 = {"OS", 3};
    test t84 = {"JAVA", 4};
    add_test_to_student(&t81, &s8);
    add_test_to_student(&t82, &s8);
    add_test_to_student(&t83, &s8);
    add_test_to_student(&t84, &s8);
    add_student(&s8, f);
    Student s9 = {"SOKOLOV", "TU", "M", "M209", NULL};
    test t91 = {"MECHANIC", 4};
    test t92 = {"ENGENIRIC", 4};
    add_test_to_student(&t91, &s9);
    add_test_to_student(&t92, &s9);
    add_student(&s9, f);
    Student s10 = {"MAMONTOVA", "PV", "W", "M209", NULL};
    test t101 = {"RUS", 4};
    test t102 = {"MATH", 4};
    add_test_to_student(&t101, &s10);
    add_test_to_student(&t102, &s10);
    add_student(&s10, f);
    Student s11 = {"BASHAROV", "NV", "M", "M305", NULL};
    test t111 = {"C#", 5};
    test t112 = {"DB", 3};
    test t113 = {"THEORI", 3};
    add_test_to_student(&t111, &s11);
    add_test_to_student(&t112, &s11);
    add_test_to_student(&t113, &s11);
    add_student(&s11, f);

    fclose(f);
    
    return 0;
}
