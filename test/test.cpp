#include "../src/dual_number/dual_number.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(T_double, fn_real) {
    dual_num::DualNumber<double> dual_num(1.2, 3.4);

    EXPECT_EQ(1.2, dual_num.real());
    EXPECT_NE(2.1, dual_num.real());

    dual_num.real(5.6);
    EXPECT_EQ(5.6, dual_num.real());
    EXPECT_NE(6.5, dual_num.real());
}

TEST(T_double, fn_dual) {
    dual_num::DualNumber<double> dual_num(1.2, 3.4);

    EXPECT_EQ(3.4, dual_num.dual());
    EXPECT_NE(4.3, dual_num.dual());

    dual_num.dual(5.6);
    EXPECT_EQ(5.6, dual_num.dual());
    EXPECT_NE(6.5, dual_num.dual());
}

TEST(T_double, default_constructor) {
    dual_num::DualNumber<double> dual_num0;
    EXPECT_EQ(0.0, dual_num0.real());
    EXPECT_EQ(0.0, dual_num0.dual());

    dual_num::DualNumber<double> dual_num(1.0, 2.0);
    EXPECT_EQ(1.0, dual_num.real());
    EXPECT_EQ(2.0, dual_num.dual());

    dual_num::DualNumber<double> dual_num_imp = {3.1, 4.2};
    EXPECT_EQ(3.1, dual_num_imp.real());
    EXPECT_EQ(4.2, dual_num_imp.dual());
}

TEST(T_double, copy_constructor) {
    dual_num::DualNumber<double> dn1(1.2, 3.4);
    dual_num::DualNumber<double> dn2;
    dual_num::DualNumber<double> expect(1.2, 3.4);

    dn2 = dn1;
    EXPECT_EQ(expect, dn2);
}

TEST(T_double, op_add_eq) {
    dual_num::DualNumber<double> dn(1.2, 3.4);

    dn += 3.4;
    EXPECT_DOUBLE_EQ(4.6, dn.real());
    EXPECT_DOUBLE_EQ(3.4, dn.dual());

    dual_num::DualNumber<double> other(5.6, 7.8);
    dn += other;
    EXPECT_DOUBLE_EQ(10.2, dn.real());
    EXPECT_DOUBLE_EQ(11.2, dn.dual());
}

TEST(T_double, op_sub_eq) {
    dual_num::DualNumber<double> dn(1.2, 3.4);

    dn -= 3.4;
    EXPECT_DOUBLE_EQ(-2.2, dn.real());
    EXPECT_DOUBLE_EQ(3.4, dn.dual());

    dual_num::DualNumber<double> other(5.6, 7.8);
    dn -= other;
    EXPECT_DOUBLE_EQ(-7.8, dn.real());
    EXPECT_DOUBLE_EQ(-4.4, dn.dual());
}

TEST(T_double, op_mul_eq) {
    dual_num::DualNumber<double> dn(1.2, 3.4);

    dn *= 5.6;
    EXPECT_DOUBLE_EQ(6.72, dn.real());
    EXPECT_DOUBLE_EQ(19.04, dn.dual());

    dual_num::DualNumber<double> other(5.6, 7.8);
    dn *= other;
    EXPECT_DOUBLE_EQ(37.632, dn.real());
    EXPECT_DOUBLE_EQ(159.04, dn.dual());
}

TEST(T_double, op_div_eq) {
    dual_num::DualNumber<double> dn(1.2, 3.4);

    dn /= 0.5;
    EXPECT_DOUBLE_EQ(2.4, dn.real());
    EXPECT_DOUBLE_EQ(6.8, dn.dual());

    dual_num::DualNumber<double> other(0.2, 0.4);
    dn /= other;
    EXPECT_DOUBLE_EQ(12.0, dn.real());
    EXPECT_DOUBLE_EQ(10.0, dn.dual());
}

TEST(T_double, op_is_equal) {
    dual_num::DualNumber<double> dn1(1.2, 3.4);
    dual_num::DualNumber<double> dn2(5.6, 7.8);
    dual_num::DualNumber<double> expect(1.2, 3.4);

    EXPECT_TRUE (expect == dn1);
    EXPECT_FALSE(expect == dn2);

    dual_num::DualNumber<double> dn_real(1.3, 0);
    EXPECT_TRUE (dn_real == 1.3);
    EXPECT_FALSE(dn_real == 1.2);
    EXPECT_TRUE (1.3 == dn_real);
    EXPECT_FALSE(1.2 == dn_real);
}

TEST(T_double, op_is_not_equal) {
    dual_num::DualNumber<double> dn1(1.2, 3.4);
    dual_num::DualNumber<double> dn2(5.6, 7.8);
    dual_num::DualNumber<double> expect(1.2, 3.4);

    EXPECT_TRUE (expect != dn2);
    EXPECT_FALSE(expect != dn1);

    dual_num::DualNumber<double> dn_real(1.3, 0);
    EXPECT_FALSE(dn_real != 1.3);
    EXPECT_TRUE (dn_real != 1.2);
    EXPECT_FALSE(1.3 != dn_real);
    EXPECT_TRUE (1.2 != dn_real);
}
