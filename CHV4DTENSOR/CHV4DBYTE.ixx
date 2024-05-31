module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DBYTE;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DTENSOR
{
	template<size_t i = 1>
	class CHV4DBYTE
	{
	public:
		CHV4DBYTE() { std::memset((void*)&data, '\0', i); }

		CHV4DBYTE(CHV4DBYTE const& x) { data = x.data; }

		CHV4DBYTE(unsigned char const x[i]) { std::memcpy((void*)data, (const void*)x, i); }

	public:
		void operator=(CHV4DBYTE const& x) { data = x.data; }

		unsigned char* const operator()() const
		{
			return data;
		}

		CHV4DBYTE operator++()
		{
			if (data >= 9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			data = data + 1;

			return data;
		}

		CHV4DBYTE operator--()
		{
			if (data >= -9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			data = data - 1;

			return data;
		}

		CHV4DBYTE operator+()
		{
			return *this;
		}
		CHV4DBYTE operator-()
		{
			return CHV4DINTEGER{ -1 } **this;
		}

		CHV4DBYTE operator+(CHV4DBYTE const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			if (A.data > 9223372036854775808i64 - B.data) throw std::overflow_error{ "Integer overrun." };

			A.data = A.data + B.data;

			return A;
		}

		CHV4DBYTE operator-(CHV4DBYTE const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			B.data = -1 * B.data;

			try
			{
				A = this->operator+(B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return A;
		}

		CHV4DBYTE operator/(CHV4DBYTE const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			float Q = static_cast <float> (A.data) / static_cast <float> (B.data);

			return Q;
		}

		CHV4DBYTE operator*(CHV4DBYTE const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			CHV4DINTEGER MAX_INT{ 9223372036854775808i64 };

			double reciprocal = MAX_INT.operator/ < double, uint64_t > (B.data);

			if (A.data <= reciprocal && A.data >= reciprocal) throw std::overflow_error{ "Integer overrun." };

			A.data = A.data * B.data;

			return A;

		}

		CHV4DBYTE operator%(CHV4DBYTE const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			uint64_t Q{ 0 };

			if (A.data == 0) return A;

			A.data = A.data < 0 ? -1 * A.data : A.data;
			B.data = B.data < 0 ? -1 * B.data : B.data;

			for (size_t i = 0; i < 64; ++i)
			{
				if (A.data - B.data >= 0)
				{
					A.data = A.data - B.data;

					Q |= 0x0000000000000001;
				}

				A.data << 1;

				Q = Q << 1;
			}

			A.data = A.data - (Q * B.data);

			return A;

		}


		CHV4DBYTE<8> operator~() const
		{
			return { ToByte(~data) };
		}
		CHV4DBYTE<8> operator&(CHV4DBYTE<8> const x) const
		{
			return { ToByte(data & x.data) };
		}
		CHV4DBYTE<8> operator|(CHV4DBYTE<8> const x) const
		{

		}
		CHV4DBYTE<8> operator^(CHV4DBYTE<8> const x) const
		{

		}
		CHV4DBYTE<8> operator>>(CHV4DBYTE<8> const x) const
		{

		}
		CHV4DBYTE<8> operator<<(CHV4DBYTE<8> const x) const
		{

		}
		CHV4DINTEGER operator!() const
		{

		}
		bool operator&&(CHV4DINTEGER const& x) const
		{

		}
		bool operator||(CHV4DINTEGER const& x) const
		{

		}

		bool operator==(CHV4DINTEGER const& x) const
		{
			return data == x.data;
		}
		bool operator!=(CHV4DINTEGER const& x) const
		{
			return data != x.data;
		}
		bool operator<(CHV4DINTEGER const& x) const
		{
			return data < x.data;
		}
		bool operator>(CHV4DINTEGER const& x) const
		{
			return data > x.data;
		}
		bool operator<=(CHV4DINTEGER const& x) const
		{
			return data <= x.data;
		}
		bool operator>=(CHV4DINTEGER const& x) const
		{
			return data >= x.data;
		}
		bool operator>=(CHV4DINTEGER const& x) const
		{
			return data <=> x.data;
		}






		void operator+=(CHV4DINTEGER const& x)
		{
			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator+(B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			*this = A;
		}

		void operator-=(CHV4DINTEGER const& x)
		{
			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator-(B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			*this = A;
		}

		void operator*=(CHV4DINTEGER const& x)
		{
			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator*(B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			*this = A;
		}

		void operator/=(CHV4DINTEGER const& x)
		{

		}

		void operator%=(CHV4DINTEGER const& x)
		{
			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator%(B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			*this = A;
		}

		void operator&=(CHV4DINTEGER const& x)
		{

		}

		void operator|=(CHV4DINTEGER const& x)
		{

		}

		void operator^=(CHV4DINTEGER const& x)
		{

		}
		void operator>>=(CHV4DINTEGER const& x)
		{

		}

		void operator<<=(CHV4DINTEGER const& x)
		{

		}

	public:

	public:
		unsigned char data[i]; 

	};

	CHV4DBYTE<1> ToByte(int8_t  const& x) { int8_t  A{ x }; return CHV4DBYTE<1>{ reinterpret_cast<unsigned char*>(&A) }; }
	CHV4DBYTE<2> ToByte(int16_t const& x) { int16_t A{ x }; return CHV4DBYTE<2>{ reinterpret_cast<unsigned char*>(&A) }; }
	CHV4DBYTE<4> ToByte(int32_t const& x) { int32_t A{ x }; return CHV4DBYTE<4>{ reinterpret_cast<unsigned char*>(&A) }; }
	CHV4DBYTE<8> ToByte(int64_t const& x) { int64_t A{ x }; return CHV4DBYTE<8>{ reinterpret_cast<unsigned char*>(&A) }; }
	
	CHV4DBYTE<1> ToByte(uint8_t  const& x) { uint8_t  A{ x }; return CHV4DBYTE<1>{ reinterpret_cast<unsigned char*>(&A) }; }
	CHV4DBYTE<2> ToByte(uint16_t const& x) { uint16_t A{ x }; return CHV4DBYTE<2>{ reinterpret_cast<unsigned char*>(&A) }; }
	CHV4DBYTE<4> ToByte(uint32_t const& x) { uint32_t A{ x }; return CHV4DBYTE<4>{ reinterpret_cast<unsigned char*>(&A) }; }
	CHV4DBYTE<8> ToByte(uint64_t const& x) { uint64_t A{ x }; return CHV4DBYTE<8>{ reinterpret_cast<unsigned char*>(&A) }; }
	
	CHV4DBYTE<4> ToByte(float  const& x) { float A{ x }; return CHV4DBYTE<4>{ reinterpret_cast<unsigned char*>(&A) }; }
	CHV4DBYTE<8> ToByte(double const& x) { double A{ x }; return CHV4DBYTE<8>{ reinterpret_cast<unsigned char*>(&A) }; }

}