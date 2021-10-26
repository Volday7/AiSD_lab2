#include "pch.h"
#include "D:/Лабы/AiSD_lab2/Header.h"
#include "gtest/gtest.h"
#include "complex"



TEST(Polynom, MakePolynom) {
	EXPECT_THROW(Polynom<int> test(-1), const char*);
	EXPECT_THROW(Polynom<double> test(-100), const char*);
	EXPECT_THROW(Polynom<std::complex<double>> test(-5), const char*);
}

TEST(Polynom, IndexPolynom) {
	Polynom<int> test1(1);
	EXPECT_THROW(test1[5], const char*);
	EXPECT_THROW(test1[-1], const char*);
	EXPECT_EQ(1, test1[1]);
	EXPECT_EQ(1, test1[0]);
	Polynom<double> test2(1);
	EXPECT_EQ((double)1, test2[1]);
	EXPECT_EQ((double)1, test2[0]);
	Polynom<std::complex<double>> test3(1);
	EXPECT_EQ((std::complex<double>)1, test3[1]);
	EXPECT_EQ((std::complex<double>)1, test3[0]);
}

TEST(Polynom, SetInPolynom) {
	Polynom<int> test1(1);
	EXPECT_THROW(test1.Set(1, 5), const char*);
	EXPECT_THROW(test1.Set(1, -1), const char*);
	test1.Set(10, 1);
	EXPECT_EQ(10, test1[1]);
	Polynom<std::complex<double>> test2(1);
	test2.Set((3.5, 1.5), 1);
	EXPECT_EQ((3.5,1.5), test2[1]);
}

TEST(Polynom, OperatorPlus) {
	Polynom<int> test1(1), test2(1);
	test1 = test1 + test2;
	EXPECT_EQ(2, test1[1]);
	EXPECT_EQ(2, test1[0]);
	Polynom<double> test3(1), test4(1);
	test3 = test3 + test4;
	EXPECT_EQ((double)2, test3[1]);
	EXPECT_EQ((double)2, test3[0]);
	Polynom<std::complex<double>> test5(1), test6(1);
	test5 = test5 + test6;
	EXPECT_EQ((std::complex<double>)2, test5[1]);
	EXPECT_EQ((std::complex<double>)2, test5[0]);
}

TEST(Polynom, OperatorMinus) {
	Polynom<int> test1(1), test2(1);
	test1.Set(2, 1);
	test1.Set(2, 0);
	test1 = test1 - test2;
	EXPECT_EQ(1, test1[1]);
	EXPECT_EQ(1, test1[0]);
	Polynom<double> test3(1), test4(1);
	test3.Set((double)2, 1);
	test3.Set((double)2, 0);
	test3 = test3 - test4;
	EXPECT_EQ((double)1, test3[1]);
	EXPECT_EQ((double)1, test3[0]);
	Polynom<std::complex<double>> test5(1), test6(1);
	test5.Set((std::complex<double>)2, 1);
	test5.Set((std::complex<double>)2, 0);
	test5 = test5 - test6;
	EXPECT_EQ((std::complex<double>)1, test5[1]);
	EXPECT_EQ((std::complex<double>)1, test5[0]);
}

TEST(Polynom, OperatorMultiplication) {
	Polynom<int> test1(1);
	test1 = test1 * 3;
	EXPECT_EQ(3, test1[1]);
	EXPECT_EQ(3, test1[0]);
	Polynom<double> test2(1);
	test2 = test2 * 3;
	EXPECT_EQ((double)3, test2[1]);
	EXPECT_EQ((double)3, test2[0]);
	Polynom<std::complex<double>> test3(1);
	test3 = test3 * 3;
	EXPECT_EQ((std::complex<double>)3, test3[1]);
	EXPECT_EQ((std::complex<double>)3, test3[0]);
}

TEST(Polynom, Result) {
	Polynom<int> test1(1);
	EXPECT_EQ(3, test1.Result(2));
	Polynom<double> test2(1);
	EXPECT_EQ((double)3, test2.Result(2));
	Polynom<std::complex<double>> test3(1);
	EXPECT_EQ((std::complex<double>)3, test3.Result(2));
}

