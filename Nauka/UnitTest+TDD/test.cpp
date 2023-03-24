#include "pch.h"

//TEST(TestName, Subtest_1) {
//
//	EXPECT_EQ(1,2);
//	std::cout << "After assertion" << std::endl;
//}
// ASSERTIONS  if 1 expect fails whole test fails 



//------------------------------------------------------------------------------


//unit test = arrange- required to run, act- runing test, assert- verify output
/*class MyClass {

	std::string id;

public:
	MyClass(std::string id_) : id(id_ ) {}
	std::string GetId() { return id; }

};

TEST(TestName, checkId) {
	
		//arrange 
		MyClass mc("root");
	
		//act
		std::string value = mc.GetId();
	
		//assert
		ASSERT_STREQ(value.c_str(), "root"); //without str it fails
	}
	*/
//-----------------------------------------------------------------------------------

//TEST(TestName, incremetByFive) {
//
//	//arrange 
//	int value = 100;
//	int increment = 5;
//
//	//act
//	value += increment;
//
//	//assert
//	ASSERT_EQ(value, 105);
//}
//
//TEST(TestName, incrementByTen) {
//
//	//arrange 
//	int value = 100;
//	int increment = 10;
//
//	//act
//	value += increment;
//
//	//assert
//	ASSERT_EQ(value, 110);
//}
//
////independent form each other and from ext input 

//----------------------------------------------------------------------------

class MyClassint {

	int baseValue;
public:
	MyClassint(int bv_) : baseValue(bv_) {};
	void Increment(int byValue_) { baseValue += byValue_; }
	int GetValue() { return baseValue; }

};
struct MyClassTest : public testing::Test {

	MyClassint* mc;
	void SetUp() { mc = new MyClassint(100); }
	void TearDown() { delete mc; }
};


TEST_F(MyClassTest, IncrementBy5) {

	mc->Increment(5);

	ASSERT_EQ(mc->GetValue(), 105);

}

int main(int argc, char **argv) {

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}