/*
*
* The MIT License (MIT)
*
* Copyright (c) 2019 shitaro2016
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
*/

#ifndef DUAL_NUMBER_HPP__
#define DUAL_NUMBER_HPP__

namespace dual_num {
    template<typename T = double>
    struct DualNumber {
        using value_type = T;

        constexpr DualNumber(const T& real = T(), const T& dual = T())
            : _real{real}, _dual{dual} {}
        constexpr DualNumber(const DualNumber&) = default;

        constexpr T real() const { return _real; }
        constexpr void real(T real){ _real = real; }

        constexpr T dual() const { return _dual; }
        constexpr void dual(T dual){ _dual = dual; }

        // Add a scalar value to *this
        constexpr DualNumber<T>& operator+=(const T& other) {
            _real += other;
            return *this;
        }

        // Subtract a scalar value from *this
        constexpr DualNumber<T>& operator-=(const T& other) {
            _real -= other;
            return *this;
        }

        // Multiply *this by a scalar
        constexpr DualNumber<T>& operator*=(const T& other) {
            _real *= other;
            _dual *= other;
            return *this;
        }

        // Divide *this by a scalar
        constexpr DualNumber<T>& operator/=(const T& other) {
            _real /= other;
            _dual /= other;
            return *this;
        }

        // Add another dual number to *this
        template<typename U>
        constexpr DualNumber<T>& operator+=(const DualNumber<U>& other) {
            _real += other.real();
            _dual += other.dual();
            return *this;
        }

        // Subtract another dual number from *this
        template<typename U>
        constexpr DualNumber<T>& operator-=(const DualNumber<U>& other) {
            _real -= other.real();
            _dual -= other.dual();
            return *this;
        }

        // Multiply *this by another dual number
        template<typename U>
        constexpr DualNumber<T>& operator*=(const DualNumber<U>& other) {
            _dual = _real * other.dual() + _dual * other.real();
            _real = _real * other.real();
            return *this;
        }

        private:
        T _real;
        T _dual;
    };

    // Return true if respective parts of lhs are equal to rhs
    template<typename T>
    inline constexpr bool operator==(const DualNumber<T>& lhs, const DualNumber<T>& rhs) {
        return lhs.real() == rhs.real() && lhs.dual() == rhs.dual();
    }

    template<typename T>
    inline constexpr bool operator==(const DualNumber<T>& lhs, const T& rhs) {
        return lhs.real() == rhs && lhs.dual() == T();
    }

    template<typename T>
    inline constexpr bool operator==(const T& lhs, const DualNumber<T>& rhs) {
        return lhs == rhs.real() && T() == rhs.dual();
    }

    // Return false if respective parts of lhs are equal to rhs
    template<typename T>
    inline constexpr bool operator!=(const DualNumber<T>& lhs, const DualNumber<T>& rhs) {
        return lhs.real() != rhs.real() || lhs.dual() != rhs.dual();
    }

    template<typename T>
    inline constexpr bool operator!=(const DualNumber<T>& lhs, const T& rhs) {
        return lhs.real() != rhs || lhs.dual() != T();
    }

    template<typename T>
    inline constexpr bool operator!=(const T& lhs, const DualNumber<T>& rhs) {
        return lhs != rhs.real() || T() != rhs.dual();
    }
} // namespace dual_num

#endif /* end of include guard */
