module;

#include <guiddef.h>

#include <string>

#include <stdexcept>

#include <chrono>

export module CHV4DTBASIC:CHV4DCHRONO;

export namespace CHV4DTBASIC
{
	class CHV4DCHRONO
	{
	public:
		CHV4DCHRONO();

		CHV4DCHRONO(std::chrono::system_clock::time_point const& chrono);

		CHV4DCHRONO(CHV4DCHRONO const& chrono);

	public:
		void operator = (uint64_t const& chrono);

		void operator = (std::chrono::system_clock::time_point const& chrono);

		void operator = (CHV4DCHRONO const& chrono);

		bool operator == (uint64_t const& chrono) const;

		bool operator == (std::chrono::system_clock::time_point const& chrono) const;

		bool operator == (CHV4DCHRONO const& chrono) const;

		bool operator != (uint64_t const& chrono) const;

		bool operator != (std::chrono::system_clock::time_point const& chrono) const;

		bool operator != (CHV4DCHRONO const& chrono) const;

		bool operator < (uint64_t const& chrono) const;

		bool operator < (std::chrono::system_clock::time_point const& chrono) const;

		bool operator < (CHV4DCHRONO const& chrono) const;

		bool operator > (uint64_t const& chrono) const;

		bool operator > (std::chrono::system_clock::time_point const& chrono) const;

		bool operator > (CHV4DCHRONO const& chrono) const;

		std::chrono::system_clock::time_point operator()() const;

		void Current();

	private:
		std::chrono::system_clock::time_point tagCHRONO;

	};

}