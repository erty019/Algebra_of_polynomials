#include "TPolinom.h"
#include <gtest.h>

TEST(Polinom, Created_polinom_is_empty) {
	TPolinom p;
	EXPECT_TRUE(p.IsEmpty());
}

TEST(Polinom, Created_polinom_with_one_monom_is_not_empty) {
	TPolinom p;
	TMonom m(1.0, 2, 3, 4);
	p.AddMonom(m);
	EXPECT_TRUE(p.IsEmpty() == false);
}

TEST(Polinom, Coefficients_add_up_if_degrees_are_equal) {
	TPolinom p;
	TMonom m1(1.5, 2, 3, 4);
	TMonom m2(2.0, 2, 3, 4);
	p.AddMonom(m1);
	p.AddMonom(m2);
	EXPECT_EQ(p.GetLength(), 1);
	EXPECT_EQ(p.GetCurrentItem().coef, 3.5);
}

TEST(Polinom, Coefficients_dont_add_up_if_degrees_are_different) {
	TPolinom polynom;
	TMonom monom1(1.0, 2, 1, 3);
	TMonom monom2(2.0, 2, 1, 3);
	polynom.AddMonom(monom1);
	polynom.AddMonom(monom2);
	EXPECT_EQ(polynom.GetLength(), 1);
	EXPECT_EQ(polynom.GetCurrentItem().coef, 3.0);
}

TEST(Polinom, Monom_delete_if_coefficient_equal_zero) {
	TPolinom polynom;
	TMonom monom1(1.0, 2, 1, 3);
	TMonom monom2(-1.0, 2, 1, 3);

	polynom.AddMonom(monom1);
	polynom.AddMonom(monom2);

	EXPECT_EQ(polynom.GetLength(), 0);
}


TEST(Polinom, Copied_polinom_is_equal_copiable) {
	TPolinom originalPolinom;
	originalPolinom.AddMonom(TMonom(1.0, 3, 0, 0));
	TPolinom copiedPolinom(originalPolinom);
	bool flag = originalPolinom == copiedPolinom;
	EXPECT_EQ(flag, true);
}

TEST(Polinom, Assigned_polinom_is_equal_assignable) {
	TPolinom originalPolinom;
	originalPolinom.AddMonom(TMonom(1.0, 3, 0, 0));
	TPolinom assignedPolinom;
	assignedPolinom = originalPolinom;
	EXPECT_EQ(assignedPolinom.ToString(), originalPolinom.ToString());
}

TEST(Polinom, Correct_adding_operator) {
	TPolinom temp;
	temp.AddMonom(TMonom(1.0, 3, 0, 0));
	temp.AddMonom(TMonom(1.0, 3, 0, 0));
	TPolinom temp2;
	temp2.AddMonom(TMonom(2.0, 3, 0, 0));
	EXPECT_EQ(temp.ToString(), temp2.ToString());
}

TEST(Polinom, Correct_constant_multiply) {
	TPolinom temp;
	temp.AddMonom(TMonom(1.0, 3, 0, 0));
	temp = temp * 4.0;
	TPolinom temp2;
	temp2.AddMonom(TMonom(4.0, 3, 0, 0));
	EXPECT_EQ(temp.ToString(), temp2.ToString());
}


