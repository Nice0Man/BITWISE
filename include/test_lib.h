#ifndef TEST_LIB_H
#define TEST_LIB_H

#include <stdio.h>
#include <windows.h>

// Определения для тестов
#define TEST_OK (1)
#define TEST_FAIL (0)

// Максимальное количество тестов
#define MAX_TESTS (100)

// Структура для хранения тестов
typedef struct {
    int (*func)(void);
    const char *name;
} TestCase;

// Глобальные переменные для тестов
static TestCase test_cases[MAX_TESTS];
static int test_count = 0;

// Функция для установки цвета консоли
static void set_console_color(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Функция для регистрации теста
static void register_test(int (*test_func)(void), const char *test_name) {
    if (test_count < MAX_TESTS) {
        test_cases[test_count].func = test_func;
        test_cases[test_count].name = test_name;
        test_count++;
    } else {
        printf("Error: Maximum number of tests exceeded!\n");
    }
}

// Макрос для создания и регистрации теста
#define TEST_CASE(name) \
    static int test_##name(void); \
    static void register_##name(void) { \
        register_test(test_##name, #name); \
    } \
    static int test_##name(void) {

// Макрос для завершения теста
#define TEST_CASE_END \
    set_console_color(FOREGROUND_GREEN | FOREGROUND_INTENSITY); \
    printf("Test passed: %s\n", __func__); \
    set_console_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); \
    return TEST_OK; \
    }

// Макросы для проверок
#define ASSERT_TRUE(condition) \
    do { \
        if (!(condition)) { \
            set_console_color(FOREGROUND_RED | FOREGROUND_INTENSITY); \
            printf("Assertion failed:\n  condition: %s\n  file: %s\n  line: %d\n", #condition, __FILE__, __LINE__); \
            set_console_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); \
            return TEST_FAIL; \
        } \
    } while (0)

#define ASSERT_FALSE(condition) ASSERT_TRUE(!(condition))
#define ASSERT_EQUAL(expected, actual) ASSERT_TRUE((expected) == (actual))
#define ASSERT_NOT_EQUAL(expected, actual) ASSERT_TRUE((expected) != (actual))

// Макрос для выполнения всех тестов
#define RUN_ALL_TESTS() \
    do { \
        int passed = 0, failed = 0; \
        printf("Running all tests...\n"); \
        for (int i = 0; i < test_count; i++) { \
            printf("Running test: %s\n", test_cases[i].name); \
            if (test_cases[i].func() == TEST_OK) { \
                passed++; \
            } else { \
                failed++; \
            } \
        } \
        printf("\nTest Summary:\n"); \
        printf("  Passed: %d\n", passed); \
        printf("  Failed: %d\n", failed); \
        if (failed == 0) { \
            set_console_color(FOREGROUND_GREEN | FOREGROUND_INTENSITY); \
            printf("All tests passed!\n"); \
        } else { \
            set_console_color(FOREGROUND_RED | FOREGROUND_INTENSITY); \
            printf("Some tests failed.\n"); \
        } \
        set_console_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); \
    } while (0)

#endif /* TEST_LIB_H */
