#include "platform.h"
#include "general.h"
#include "test_lib.h" 

// Определение тестов

// TEST_CASE(get_bit)
//     U8 result;
//     STD_RESULT status = get_bit(0b1010, 1, &result);
//     ASSERT_EQUAL(1, result);

//     status = get_bit(0b1010, 32, &result);
//     ASSERT_EQUAL(NOK, status);
// TEST_CASE_END

// TEST_CASE(set_bit)
//     U32 number = 0;
//     STD_RESULT status = set_bit(&number, 1, 3);
//     ASSERT_EQUAL(0b1000, number);

//     status = set_bit(&number, 0, 3);
//     ASSERT_EQUAL(0, number);
// TEST_CASE_END

// TEST_CASE(count_ones)
//     ASSERT_EQUAL(3, count_ones(0b1011));
// TEST_CASE_END

// TEST_CASE(to_binary)
//     U8 output[32] = {0};
//     STD_RESULT status = to_binary(0b1010, output);
//     ASSERT_EQUAL(1, output[1]);
//     ASSERT_EQUAL(1, output[3]);
// TEST_CASE_END

// TEST_CASE(concatenate_bytes)
//     U32 result = concatenate_bytes(0xAB, 0xCD, 0xEF, 0x01);
//     ASSERT_EQUAL(0xABCDEF01, result);
// TEST_CASE_END

// TEST_CASE(split_into_bytes)
//     U8 output[4] = {0};
//     STD_RESULT status = split_into_bytes(0xAABBCCDD, output);
//     ASSERT_EQUAL(0xAA, output[0]);
//     ASSERT_EQUAL(0xBB, output[1]);
//     ASSERT_EQUAL(0xCC, output[2]);
//     ASSERT_EQUAL(0xDD, output[3]);
// TEST_CASE_END


// Пример успешного теста
TEST_CASE(example_test)
    int x = 5;
    int y = 10;
    ASSERT_EQUAL(x + y, 15);  // Проверка: x + y должно быть равно 15
TEST_CASE_END

// Пример теста с ошибкой
TEST_CASE(failing_test)
    int x = 3;
    ASSERT_TRUE(x > 5);  // Проверка: x больше 5 (ожидается провал)
TEST_CASE_END

int main() {
    // Ручной вызов регистрации тестов
    register_example_test();
    register_failing_test();

    // Запуск всех тестов
    RUN_ALL_TESTS();
    return 0;
}





