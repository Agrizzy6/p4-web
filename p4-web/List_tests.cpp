#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST (test_empty)
{
    List<int> list;
    ASSERT_TRUE(list.empty());
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(4);
    list.push_front(5);
    list.push_front(6);

    ASSERT_FALSE(list.empty());

}

TEST(test_push_front) {
    List<int> list;
    list.push_front(54);
    ASSERT_EQUAL(list.size(),1);
    ASSERT_EQUAL(list.front(),54);
    ASSERT_EQUAL(list.back(),54);
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

TEST(test_clear) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(4);
    list.push_front(5);
    list.push_front(6);

    ASSERT_EQUAL(list.size(),6);
    ASSERT_FALSE(list.empty());

    list.clear();

    ASSERT_EQUAL(list.size(),0);
    ASSERT_TRUE(list.empty());
}

TEST(test_pop_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(4);
    list.push_front(5);
    list.push_front(6);

    ASSERT_EQUAL(list.size(),6);
    ASSERT_FALSE(list.empty());

    for (int i = 0; i < 6; ++i)
    {
        list.pop_back();
    }

    ASSERT_EQUAL(list.size(),0);
    ASSERT_TRUE(list.empty());
}

TEST(test_size) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(4);
    list.push_front(5);
    list.push_front(6);

    ASSERT_EQUAL(list.size(),6);
    ASSERT_FALSE(list.empty());
}

TEST(test_front) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(4);
    list.push_front(5);
    list.push_front(6);

    ASSERT_EQUAL(list.front(),6);
}

TEST(test_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(4);
    list.push_front(5);
    list.push_front(6);

    ASSERT_EQUAL(list.back(),3);
}



//Test iterator
TEST(test_iterator_minus)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    List<int>::Iterator itBegin = list.begin();
    List<int>::Iterator itEnd = list.end();
    --itEnd;
    --itEnd;
    ASSERT_EQUAL(itBegin, itEnd);
    ASSERT_EQUAL(itEnd, itBegin);
}

TEST(test_iterator_add)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    List<int>::Iterator itBegin = list.begin();
    List<int>::Iterator itEnd = list.end();
    ++itBegin;
    ++itBegin;
    ASSERT_EQUAL(itBegin, itEnd);
    ASSERT_EQUAL(itEnd, itBegin);
}


TEST(test_iterator_minus_inequality)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    List<int>::Iterator itBegin = list.begin();
    List<int>::Iterator itEnd = list.end();
    --itEnd;
    ASSERT_NOT_EQUAL(itBegin, itEnd);
    ASSERT_NOT_EQUAL(itEnd, itBegin);
}

TEST(test_iterator_add_inequality)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    List<int>::Iterator itBegin = list.begin();
    List<int>::Iterator itEnd = list.end();
    ++itBegin;
    ASSERT_NOT_EQUAL(itBegin, itEnd);
    ASSERT_NOT_EQUAL(itEnd, itBegin);
}

TEST(test_stub) {
    // Add test code here
    ASSERT_TRUE(true);
}

TEST_MAIN()
