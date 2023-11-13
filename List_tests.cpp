#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST (test_empty)
{
    List<int> list;
    ASSERT_TRUE(list.empty());
}

TEST(test_push_front) {
    // Add test code here
    List<int> list;
    list.push_front(54);
    ASSERT_EQUAL(list.size(),1);
    ASSERT_EQUAL(list.front(),54);
    //ASSERT_EQUAL(list.back(),54);
}

TEST(test_pop_front)
{
    List<int> list;
    list.push_front(54);
    ASSERT_EQUAL(list.size(), 1);
    list.pop_front();
    ASSERT_EQUAL(list.size(),0);
    ASSERT_TRUE(list.empty());
}

TEST(test_push_back)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    ASSERT_EQUAL(list.size(),3);
    ASSERT_FALSE(list.empty());
    
    //cout << list.front() << endl;
    ASSERT_EQUAL(list.front(),1);
    ASSERT_EQUAL(list.back(),3);
    
    list.pop_back();
    
    ASSERT_EQUAL(list.size(),2);
    ASSERT_EQUAL(list.back(),2);
    list.pop_back();
    ASSERT_EQUAL(list.size(),1);
    ASSERT_EQUAL(list.back(),1);
    list.pop_back();
    ASSERT_TRUE(list.empty());
    
}
/*
TEST(test_clear) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    ASSERT_EQUAL(list.size(),3);
    ASSERT_FALSE(list.empty());

    list.clear();

    //ASSERT_EQUAL(list.size(),0);
    //ASSERT_TRUE(list.empty());
}
*/

TEST(test_stub) {
    // Add test code here
    ASSERT_TRUE(true);
}

TEST_MAIN()
